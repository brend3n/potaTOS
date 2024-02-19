#ifndef OTA_UPDATES_H
#define OTA_UPDATES_H

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include "esp_ota_ops.h"
#include "esp_http_client.h"
#include "esp_https_ota.h"

/**
 * @brief Initialize and start the OTA update task.
 */
void ota_update_task(void *pvParameter);

#endif //OTA_UPDATES_H