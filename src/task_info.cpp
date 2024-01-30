// Includes
#include "task_info.h"
#include "config/board_config.h"

#include "tasks/mqtt/mqtt.h"
#include "tasks/button/button.h"
#include "tasks/temp_hum_sensor/temp_hum.h"
#include "tasks/ultra_sonic_sensor/ultra_sonic.h"

// Priority
#define HELLO_MQTT_TASK_PRIORITY       10
#define BUTTON_PUBLISHER_PRIORITY      10
#define BUTTON_SUBSCRIBER_PRIORITY     10
#define TEMP_HUM_PUBLISHER_PRIORITY    10
#define ULTRA_SONIC_PUBLISHER_PRIORITY 10

// Stack Size
#define HELLO_MQTT_TASK_STACK_SIZE       (1024 * 10)
#define BUTTON_PUBLISHER_STACK_SIZE      (1024 * 10)
#define BUTTON_SUBSCRIBER_STACK_SIZE     (1024 * 10)
#define TEMP_HUM_PUBLISHER_STACK_SIZE    2* (1024 * 10)
#define ULTRA_SONIC_PUBLISHER_STACK_SIZE 2* (1024 * 10)

// Task Handles
TaskHandle_t hello_mqtt_handle;
TaskHandle_t button_pub_handle;
TaskHandle_t button_sub_handle;
TaskHandle_t temp_hum_pub_handle;
TaskHandle_t ultra_sonic_pub_handle;


QueueHandle_t temp_hum_ultra_sonic_queue;

static Task_Info task_stuct[]
{
    // MQTT Hello
    {
        &mqtt_task, 
        "mqtt_task", 
        HELLO_MQTT_TASK_STACK_SIZE, 
        NULL, 
        HELLO_MQTT_TASK_PRIORITY, 
        &hello_mqtt_handle,
        HELLO_MQTT_TASK
    },

    // Button Publisher
    {
        &button_pub_task, 
        "button_pub_task", 
        BUTTON_PUBLISHER_STACK_SIZE, 
        NULL, 
        BUTTON_PUBLISHER_PRIORITY, 
        &button_pub_handle,
        BUTTON_PUBLISHER
    },

    // Button Subscriber
    {
        &button_sub_task, 
        "button_sub_task", 
        BUTTON_SUBSCRIBER_STACK_SIZE, 
        NULL, 
        BUTTON_SUBSCRIBER_PRIORITY, 
        &button_sub_handle,
        BUTTON_SUBSCRIBER
    },
    // Temperature and Humidity Publisher
    {
        &temp_hum_pub_task, 
        "temp_hum_pub_task", 
        TEMP_HUM_PUBLISHER_STACK_SIZE, 
        &temp_hum_ultra_sonic_queue, 
        TEMP_HUM_PUBLISHER_PRIORITY, 
        &temp_hum_pub_handle,
        TEMP_HUM_PUBLISHER
    },
    // Ultra Sonic Sensor Publisher
    {
        &ultra_sonic_pub_task, 
        "ultra_sonic_pub_task", 
        ULTRA_SONIC_PUBLISHER_STACK_SIZE, 
        &temp_hum_ultra_sonic_queue, 
        ULTRA_SONIC_PUBLISHER_PRIORITY, 
        &ultra_sonic_pub_handle,
        ULTRA_SONIC_PUBLISHER
    },
    // Null Task to denote the end of the array
    {0}
};

// Returns 1 if all tasks registered, else returns 0
uint32_t register_tasks(void)
{
    uint32_t res = 1;
    uint32_t task_list [] = TASK_LIST;

    for (uint32_t i = 0; i < NUM_TASKS; i++)
    {
        if (task_list[i])
        {
            BaseType_t ret_create = xTaskCreate(
                task_stuct[i].entry_function, 
                task_stuct[i].name,
                task_stuct[i].stack_size,
                task_stuct[i].params,
                task_stuct[i].priority,
                task_stuct[i].handle
            );
            
            res &= ret_create;
        }
    }

    return res;
}

// Setup any global objects for the program
void setup_global_objects(void)
{
    // Setting up the message queue
    temp_hum_ultra_sonic_queue = xQueueCreate(10, sizeof(float));
    if(!temp_hum_ultra_sonic_queue)
    {
        Serial.println("Queue failed to intialize.");
    }
}