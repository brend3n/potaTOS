#ifndef ULTRA_SONIC_H
#define ULTRA_SONIC_H
#include <stdlib.h>
#include "../../config/board_config.h"
#include "freertos/FreeRTOS.h"
#include "freertos/queue.h"

void ultra_sonic_pub_task(void *pvParameters);
#endif // ULTRA_SONIC_H