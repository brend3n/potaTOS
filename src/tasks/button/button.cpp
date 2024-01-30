
#include "button.h"
#include "../mqtt/mqtt.h"

extern PubSubClient client;

void button_pub_task(void *pvParameters)
{
  #ifdef BUTTON_PIN
  ezButton button(BUTTON_PIN);
  char stringy[100];
  const uint16_t str_size = strlen("Device_") + 1 + 1 + strlen(",button_press");
  snprintf(stringy, str_size, "Device_%d,button_press",BOARD_ID);

  for(;;)
  {
    button.loop();
    if (button.isPressed())
    {
      client.publish(button_topic, stringy, strlen(stringy));
    }
    delay(300);
  }
  #else
    for(;;)
    {
      delay(2000);
    }
  #endif
}


void button_sub_task(void *pvParameters)
{
  char stringy[100];
  strncpy(stringy, client_name, strlen(client_name));
  strncat(stringy, ": Button Event!", strlen(": Button Event!"));
  client.subscribe(button_topic);

  for(;;)
  {      
    delay(300);
  }
}