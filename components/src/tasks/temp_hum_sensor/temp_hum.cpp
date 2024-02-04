
#include "temp_hum.h"

extern PubSubClient client;

DHT dht(TEMP_HUM_PIN, DHT11);

void update_temp_and_hum(QueueHandle_t* msg_queue, float* temp, float* humidity, float* heat_index)
{
    float t = dht.readTemperature(true);
    float h = dht.readHumidity();
    float hi = dht.computeHeatIndex(t,h);

    if (isnan(t) || isnan(h))
        return; // data not ready. Keep prev data and just return
    
    // Update values
    *temp = t;
    *humidity = h;
    *heat_index = hi;

    // Push temperature into message queue for ultra sonic sensor
    xQueueSend(*msg_queue, &hi, portMAX_DELAY);
}

void temp_hum_pub_task(void *pvParameters)
{
  char stringy[100];
  float temp = 0;
  float humidity = 0;
  float heat_index = 0;

  QueueHandle_t* msg_queue = (QueueHandle_t *)pvParameters;

  // Init DHT sensor (Temp/Humidity Sensor)
  dht.begin();

  for(;;)
  {
    update_temp_and_hum(msg_queue, &temp, &humidity, &heat_index);
    snprintf(stringy, sizeof(stringy), "Device_%d,%.2f,%.2f,%.2f",BOARD_ID, temp, humidity, heat_index); 
    client.publish(temp_hum_topic, stringy, strlen(stringy));
    delay(2000);
  }
}
