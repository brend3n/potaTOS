#ifndef MQTT_H
#define MQTT_H

// WiFi Includes
#include <WiFi.h>
#include <WiFiClient.h>
#include <WiFiServer.h>
#include <WiFiUdp.h>

// MQTT Include
#include <PubSubClient.h>

// Standard Library Includes
#include <stdlib.h>
#include "../../config/board_config.h"


// Topics
#define topic "hello"
#define button_topic "button_event"
#define temp_hum_topic "temp_hum_event"
#define ultra_sonic_topic "ultra_sonic_event"

// Global objects used across all boards
#define mqtt_port 1883
#define client_name ("Device_" BOARD_STR)


void mqtt_task(void *pvParameters);
void callbackHandler(char *topic_, byte *payload, unsigned int length);
void reconnect(void);
void mqtt_init(void);
#endif // MQTT_H