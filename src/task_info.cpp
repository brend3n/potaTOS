// Includes
#include "task_info.h"
#include "config/board_config.h"
#include "common/utilities/utilities.h"

#include "tasks/mqtt/mqtt.h"
#include "tasks/button/button.h"
#include "tasks/temp_hum_sensor/temp_hum.h"
#include "tasks/ultra_sonic_sensor/ultra_sonic.h"
#include "common/cli/cli.h"

#include "common/p2p/p2p.h"
#include "common/p2p/message_structure/p2p_message.h"

// Priority
#define HELLO_MQTT_TASK_PRIORITY       3
#define BUTTON_PUBLISHER_PRIORITY      3
#define BUTTON_SUBSCRIBER_PRIORITY     3
#define TEMP_HUM_PUBLISHER_PRIORITY    3
#define ULTRA_SONIC_PUBLISHER_PRIORITY 3
#define CLI_INPUT_PRIORITY             1
#define CLI_EXEC_PRIORITY              1


// Stack Size
#define HELLO_MQTT_TASK_STACK_SIZE       (1024 * 10)
#define BUTTON_PUBLISHER_STACK_SIZE      (1024 * 10)
#define BUTTON_SUBSCRIBER_STACK_SIZE     (1024 * 10)
#define TEMP_HUM_PUBLISHER_STACK_SIZE    2* (1024 * 10)
#define ULTRA_SONIC_PUBLISHER_STACK_SIZE 2* (1024 * 10)
#define CLI_INPUT_STACK_SIZE             2*(1024 * 10)
#define CLI_EXEC_STACK_SIZE              2* (1024 * 10)

// Task Handles
TaskHandle_t hello_mqtt_handle;
TaskHandle_t button_pub_handle;
TaskHandle_t button_sub_handle;
TaskHandle_t temp_hum_pub_handle;
TaskHandle_t ultra_sonic_pub_handle;
TaskHandle_t cli_input_handle;
TaskHandle_t cli_exec_handle;

QueueHandle_t temp_hum_ultra_sonic_queue;
QueueHandle_t cli_cmd_queue;

p2pNode p2p;
QueueHandle_t p2p_tx_queue;
QueueHandle_t p2p_rx_queue;


#define TASK_MQTT \
    { \
        &mqtt_task, \
        "mqtt_task", \
        HELLO_MQTT_TASK_STACK_SIZE, \
        NULL, \
        HELLO_MQTT_TASK_PRIORITY, \
        &hello_mqtt_handle, \
        HELLO_MQTT_TASK \
    }

#define TASK_BUTTON_PUB \
    { \
        &button_pub_task, \
        "button_pub_task", \
        BUTTON_PUBLISHER_STACK_SIZE, \
        NULL, \
        BUTTON_PUBLISHER_PRIORITY, \
        &button_pub_handle, \
        BUTTON_PUBLISHER \
    }

#define TASK_BUTTON_SUB \
    { \
        &button_sub_task, \
        "button_sub_task", \
        BUTTON_SUBSCRIBER_STACK_SIZE, \
        NULL, \
        BUTTON_SUBSCRIBER_PRIORITY, \
        &button_sub_handle, \
        BUTTON_SUBSCRIBER \
    }

#define TASK_TEMP_HUM_PUB \
    { \
        &temp_hum_pub_task, \
        "temp_hum_pub_task", \
        TEMP_HUM_PUBLISHER_STACK_SIZE, \
        &temp_hum_ultra_sonic_queue, \
        TEMP_HUM_PUBLISHER_PRIORITY, \
        &temp_hum_pub_handle, \
        TEMP_HUM_PUBLISHER \
    }

#define TASK_ULTRA_SONIC_PUB \
    { \
        &ultra_sonic_pub_task, \
        "ultra_sonic_pub_task", \
        ULTRA_SONIC_PUBLISHER_STACK_SIZE, \
        &temp_hum_ultra_sonic_queue, \
        ULTRA_SONIC_PUBLISHER_PRIORITY, \
        &ultra_sonic_pub_handle, \
        ULTRA_SONIC_PUBLISHER \
    }

#define TASK_IN_CLI \
    { \
        &cli_input_task, \
        "cli_input_task", \
        CLI_INPUT_STACK_SIZE, \
        &cli_cmd_queue, \
        CLI_INPUT_PRIORITY, \
        &cli_input_handle, \
        CLI_INPUT \
    }

#define TASK_EXEC_CLI \
    { \
        &cli_execute_task, \
        "cli_exec_task", \
        CLI_EXEC_STACK_SIZE, \
        &cli_cmd_queue, \
        CLI_EXEC_PRIORITY, \
        &cli_exec_handle, \
        CLI_EXEC \
    }


Task_Info task_t [] = TASK_LIST;

// Returns 1 if all tasks registered, else returns 0
uint32_t register_tasks(void)
{
    uint32_t res = 1;    

    for (uint32_t i = 0; i < NUM_TASKS; i++)
    {
        if (task_t[i].handle)
        {
            BaseType_t ret_create = xTaskCreate(
                task_t[i].entry_function, 
                task_t[i].name,
                task_t[i].stack_size,
                task_t[i].params,
                task_t[i].priority,
                task_t[i].handle
            );

            if (ret_create != pdTRUE)
            {
                Serial.print("Failed to register ");
                Serial.print(task_t[i].name);
                Serial.println();
            }
            
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
        Serial.println("temp_hum_ultra_sonic_queue Queue failed to intialize.");
    }

    cli_cmd_queue = xQueueCreate(15, sizeof(char)*(MAX_STRING_BUFFER_SIZE));
    // ASSERT(cli_cmd_queue != NULL);|

    if (!cli_cmd_queue)
    {
        Serial.println("cli_cmd_queue Queue failed to initialize");
    }

    p2p_tx_queue = xQueueCreate(15, sizeof(p2pMessage_t));

    if (!p2p_tx_queue)
    {
        Serial.println("p2p_tx_queue Queue failed to initialize");
    }

    p2p_rx_queue = xQueueCreate(15, sizeof(p2pMessage_t));

    if (!p2p_rx_queue)
    {
        Serial.println("p2p_rx_queue Queue failed to initialize");
    }

    p2p_node_init(&p2p, &p2p_tx_queue, &p2p_rx_queue);
}