// Includes
#include "task_info.h"
#include "board_config.h"
#include "utilities.h"

#include "Arduino.h"

// CLI
#include "cli.h"

// peer-to-peer includes
#include "p2p.h"
#include "p2p_tx.h"
#include "p2p_rx.h"
#include "p2p_message.h"

// Over the air updates include
#include "ota_updates.h"

#include "watchdog.h"

// Priority
#define CLI_INPUT_PRIORITY             1
#define CLI_EXEC_PRIORITY              1
#define P2P_TX_PRIORITY                5
#define P2P_RX_PRIORITY                5
#define P2P_ASYNC_PRIORITY             5
#define OTA_UPDATE_PRIORITY            5
#define WATCH_DOG_PRIORITY             5


// Stack Size
#define CLI_INPUT_STACK_SIZE             2* (1024 * 10)
#define CLI_EXEC_STACK_SIZE              2* (1024 * 10)
#define P2P_TX_STACK_SIZE                2* (1024 * 10)
#define P2P_RX_STACK_SIZE                2* (1024 * 10)
#define P2P_ASYNC_STACK_SIZE             2* (1024 * 10)
#define OTA_UPDATE_STACK_SIZE            2* (1024 * 8)
#define WATCH_DOG_STACK_SIZE             2* (1024 * 8)


// Task Handles
TaskHandle_t cli_input_handle;
TaskHandle_t cli_exec_handle;
TaskHandle_t p2p_tx_handle;
TaskHandle_t p2p_rx_handle;
TaskHandle_t p2p_async_handle;
TaskHandle_t ota_update_handle;
TaskHandle_t watch_dog_handle;


QueueHandle_t cli_cmd_queue;

p2pNode_t p2p;
QueueHandle_t p2p_tx_queue;
QueueHandle_t p2p_rx_queue;

#define TASK_CLI_INPUT \
    { \
        &cli_input_task, \
        "cli_input_task", \
        CLI_INPUT_STACK_SIZE, \
        &cli_cmd_queue, \
        CLI_INPUT_PRIORITY, \
        &cli_input_handle \
    }

#define TASK_CLI_EXEC \
    { \
        &cli_execute_task, \
        "cli_exec_task", \
        CLI_EXEC_STACK_SIZE, \
        &cli_cmd_queue, \
        CLI_EXEC_PRIORITY, \
        &cli_exec_handle \
    }

#define TASK_P2P_TX \
    { \
        &p2p_tx_task, \
        "p2p_tx_task", \
        P2P_TX_STACK_SIZE, \
        &p2p, \
        P2P_TX_PRIORITY, \
        &p2p_tx_handle \
    }

#define TASK_P2P_RX \
    { \
        &p2p_rx_task, \
        "p2p_rx_task", \
        P2P_RX_STACK_SIZE, \
        &p2p, \
        P2P_RX_PRIORITY, \
        &p2p_rx_handle \
    }

#define TASK_P2P_ASYNC \
    { \
        &p2p_async_task, \
        "p2p_async_task", \
        P2P_ASYNC_STACK_SIZE, \
        &p2p, \
        P2P_ASYNC_PRIORITY, \
        &p2p_async_handle \
    }

#define TASK_OTA_UPDATE \
    { \
        &ota_update_task, \
        "ota_update_task", \
        OTA_UPDATE_STACK_SIZE, \
        NULL, \
        OTA_UPDATE_PRIORITY, \
        &ota_update_handle \
    }

#define TASK_WATCHDOG \
    { \
        &watchdog_task, \
        "watchdog_task", \
        WATCH_DOG_STACK_SIZE, \
        NULL, \
        WATCH_DOG_PRIORITY, \
        &watch_dog_handle \
    }
    

Task_Info task_t [] = TASK_LIST;

// Returns 1 if all tasks registered, else returns 0
uint32_t register_tasks(void)
{
    uint32_t res = 1;    
    uint32_t num_tasks = sizeof(task_t) / sizeof(task_t[0]) - 1;

    for (uint32_t i = 0; i < num_tasks; i++)
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
                Serial.println(task_t[i].name);
                // printf("Failed to register %s\n", task_t[i].name);                                
            }
            else
            {
                Serial.print("Registered: ");
                Serial.println(task_t[i].name);
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
    cli_cmd_queue = xQueueCreate(15, sizeof(char)*(MAX_STRING_BUFFER_SIZE));
    ASSERT(cli_cmd_queue != NULL);

    p2p_tx_queue = xQueueCreate(15, sizeof(p2pMessage_t));
    ASSERT(p2p_tx_queue != NULL);

    p2p_rx_queue = xQueueCreate(15, sizeof(p2pMessage_t));
    ASSERT(p2p_rx_queue != NULL);

    p2p_node_init(&p2p, &p2p_tx_queue, &p2p_rx_queue);
}