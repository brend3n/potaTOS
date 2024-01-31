#ifndef TASK_INFO_H
#define TASK_INFO_H

#include <stdint.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

// Task ENUMS
enum task_enums
{
    HELLO_MQTT_TASK = 0,
    BUTTON_PUBLISHER,
    BUTTON_SUBSCRIBER,
    TEMP_HUM_PUBLISHER,
    ULTRA_SONIC_PUBLISHER,
    CLI_INPUT,
    NUM_TASKS
};

// Task Entry function
typedef void (*entry_func_t)(void*);

typedef struct Task_Info_Struct
{
    entry_func_t entry_function;
    char* name;
    uint16_t stack_size;
    void* params;
    uint8_t priority;
    TaskHandle_t *handle;
    uint8_t task_enum;

}Task_Info;

uint32_t register_tasks(void);
void setup_global_objects(void);


#endif // TASK_INFO_H