#include "esp_task_wdt.h"
#include "watchdog.h"

void watchdog_task(void *pvParameter)
{

    esp_task_wdt_config_t config = {
        .timeout_ms=5000,
        .idle_core_mask = 0,
        .trigger_panic = true
    };

    // Initialize the Task Watchdog Timer for a 5-second timeout and enable panic on timeout.
    esp_task_wdt_init(&config);

    // Add the current task to the watchdog timer.
    esp_task_wdt_add(NULL);

    for(;;) 
    {      
        // Reset the watchdog timer periodically to prevent the timeout.
        esp_task_wdt_reset();
        vTaskDelay(pdMS_TO_TICKS(1000)); // Delay for 1 second
    }

    // Remove the task from the watchdog timer if the task is ending.
    esp_task_wdt_delete(NULL);

}