// Standard Library Includes
#include <stdlib.h>

#include "Arduino.h"

// Board includes
#include "src/config/board_config.h"

// Task Includes
#include "src/tasks/button/button.h"
#include "src/tasks/mqtt/mqtt.h"
#include "src/task_info.h"

extern PubSubClient client;

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
  register_tasks();
}

void setup()
{
  // Initialize Serial for Debugging
  serial_init();

  // Initialize MQTT
  mqtt_init();

  // Allow the hardware to sort itself out
  delay(1500);

  setup_global_objects();

  setup_tasks();
}

void loop()
{
  if (!client.connected()) {
    reconnect();
  }
  delay(2000);
  client.loop();
}
