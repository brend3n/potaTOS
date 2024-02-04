
#include "ultra_sonic.h"
#include "../mqtt/mqtt.h"

extern PubSubClient client;

#define MAXRANGE 400
#define MINRANGE 0
void update_distance(QueueHandle_t* msg_queue, float* distance_)
{
  long duration;
  float distance;
  float temp = 0;

  
  // Get temperature from message queue
  xQueueReceive(*msg_queue, &temp, portMAX_DELAY);

  digitalWrite(US_TRIG_PIN, LOW);         // pull low before triger
  delayMicroseconds(2);               // to make sure the low is read
  digitalWrite(US_TRIG_PIN, HIGH);        // trigger the sensor
  delayMicroseconds(10);              // wait 10 us so the sensor can read the signal
  digitalWrite(US_TRIG_PIN, LOW);         // end of signal
  duration = pulseIn(US_ECHO_PIN, HIGH);  // us since trigger

  distance = (duration / 2.0) / 29.14;  // sound waves bounces back so double distance

  Serial.print("distance: ");
  if (distance >= MAXRANGE || distance <= MINRANGE) {   // limit the range
    Serial.println("Out of range");
  }
  else {
    Serial.print(distance, 1);    //print with one decimal: cmcm,mm
    Serial.println(" cm");
  }

  float speedOfSound = 331.3 + 0.606 * temp;      //formula for speed of sound in m/s
  Serial.print("speed of sound: ");
  Serial.print(speedOfSound);
  Serial.println(" m/s");

  float compensatedDistance = (duration / 20000.0) * speedOfSound;  //duration is in us, speed in m/s. /20k gives cm
  Serial.print("compensated distance: ");
  Serial.print(compensatedDistance, 1);         //one decimal
  Serial.println(" cm\n");                      //double new line

  *distance_ = compensatedDistance;
  delay(500);
}

void ultra_sonic_pub_task(void *pvParameters)
{
  char stringy[100];
  float distance = 0;

  QueueHandle_t* msg_queue = (QueueHandle_t *)pvParameters;

  // Setup pins
  pinMode(US_TRIG_PIN, OUTPUT);
  pinMode(US_ECHO_PIN, INPUT);


  for(;;)
  {

    update_distance(msg_queue, &distance);

    snprintf(stringy, sizeof(stringy), "Device_%d,%.2f",BOARD_ID, distance); 
    client.publish(ultra_sonic_topic, stringy, strlen(stringy));
    delay(300);
  }
}
