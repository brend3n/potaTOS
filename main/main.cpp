#include "Arduino.h"

// Standard Library Includes
#include <stdio.h>
#include <stdlib.h>

// OS includes
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

// Board includes
#include "board_config.h"

// Task Includes
#include "task_info.h"
#include "utilities.h"

#include <Arduino.h>

void setup_tasks()
{
  if (register_tasks() != pdTRUE)
  {
    Serial.println("Failed to register tasks");
  }
}

void do_setup()
{

  setup_global_objects();

  setup_tasks();
}

extern "C" void app_main(void) 
{

    // Set up necessary Arduino ops
    initArduino();
    // Setup Serial (arduino)
    Serial.begin(115200);
    Serial.setDebugOutput(true); 
    Serial.setTimeout(5000); // Wait 5 seconds for serial

    do_setup();

    for(;;) 
    {
        Serial.println("Hello, ESP32!\n");
        vTaskDelay(pdMS_TO_TICKS(1000)); // Delay for 1 second
    }
    
}