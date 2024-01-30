
#include "mqtt.h"

WiFiClient wifi_;
PubSubClient client(wifi_);
IPAddress broker(IP_OCT1, IP_OCT2, IP_OCT3, IP_OCT4);


void mqtt_task(void *pvParameters)
{
  char stringy[100];
  strncpy(stringy, client_name, strlen(client_name));
  strncat(stringy, ": Hello\0", strlen(": Hello\0")+1);

  for(;;)
  {
    client.publish(topic, stringy, strlen(stringy));
    client.subscribe(topic);
    Serial.printf("Sent from task\n");
    delay(2000);
  }
}

void callbackHandler(char *topic_, byte *payload, unsigned int length) 
{
  Serial.print("Message in topic ");
  Serial.print(topic_);
  Serial.print(": ");

  for (int i = 0; i < length; i++) {
      Serial.print((char) payload[i]);
  }
  Serial.println();
}

void reconnect(void) 
{
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Attempt to connect
    if (client.connect(client_name)) {
      Serial.println("connected");
      // Once connected, publish an announcement...
      client.publish("snap/example","hello world");
      // ... and resubscribe
      client.subscribe("snap/example");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

void mqtt_init(void)
{
  WiFi.begin(WIFI_SSID, WIFI_PASS);

  Serial.print ("Connecting to AP");
  while(WiFi.status()!=WL_CONNECTED) {
    Serial.print (".");
    delay(100);
  }

  Serial.print ("Connected to WiFi AP, Got an IP address :");
  Serial.print (WiFi.localIP());

  client.setServer(broker, mqtt_port);
  client.setCallback(callbackHandler);

  if(client.connect (client_name)) {
    Serial.print ("Connected to MQTT Broker");
  } 
  else {
    Serial.print("MQTT Broker connection failed");
    Serial.print(client.state());
    delay(2000);
  }
}