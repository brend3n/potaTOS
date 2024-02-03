#ifndef TASK_INFO_H
#define TASK_INFO_H

#include <stdint.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

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

}Task_Info;

uint32_t register_tasks(void);
void setup_global_objects(void);


#endif // TASK_INFO_H