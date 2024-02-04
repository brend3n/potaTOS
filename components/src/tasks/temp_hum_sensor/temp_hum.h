#ifndef TEMP_HUM_H
#define TEMP_HUM_H
#include <stdlib.h>

#include "freertos/FreeRTOS.h"
#include "freertos/queue.h"

#include <DHT.h>

#include "../mqtt/mqtt.h"
#include "../../config/board_config.h"

void temp_hum_pub_task(void *pvParameters);
#endif // TEMP_HUM_H