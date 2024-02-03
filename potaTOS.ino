// Standard Library Includes
#include <stdlib.h>

#include "Arduino.h"

// Board includes
#include "src/config/board_config.h"

// Task Includes
#include "src/tasks/button/button.h"
#include "src/tasks/mqtt/mqtt.h"
#include "src/tasks/task_info.h"
#include "src/common/utilities/utilities.h"

// TODO: Move this elsewhere so common code isnt reliant on board specific tasks
// extern PubSubClient client;

void serial_init()
{
  //Initialize serial and wait for port to open:

  Serial.begin(115200);
  Serial.setDebugOutput(true); 

  // Wait 5 seconds for serial
  Serial.setTimeout(5000);
}

void setup_tasks()
{
  if (register_tasks() != pdTRUE)
  {
    Serial.println("Failed to register tasks");
  }
}

void setup()
{
  // Initialize Serial for Debugging
  serial_init();

  // TODO: Move this elsewhere so common code isnt reliant on board specific tasks
  // Initialize MQTT
  // mqtt_init();

  // Allow the hardware to sort itself out
  // vTaskDelay(pdMSTOTICKS(1500));
  delay(1500);


  // TODO: Move this elsewhere so common code isnt reliant on board specific tasks
  setup_global_objects();

  setup_tasks();
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
  digitalWrite(LED_BUILTIN, HIGH);
  delay(2000);
  digitalWrite(LED_BUILTIN, LOW);
  delay(2000);
}
