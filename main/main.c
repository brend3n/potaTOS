// Standard Library Includes
#include <stdio.h>
#include <stdlib.h>

// OS includes
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

// Board includes
#include "board_config.h"

// Task Includes
#include "tasks/task_info.h"
#include "utilities/utilities.h"

void setup_tasks()
{
  if (register_tasks() != pdTRUE)
  {
    printf("Failed to register tasks");
  }
}

void setup()
{
  setup_global_objects();

  setup_tasks();
}

void app_main(void) {

    for(;;) 
    {
        printf("Hello, ESP32!\n");  
        vTaskDelay(pdMS_TO_TICKS(1000)); // Delay for 1 second
    }
}