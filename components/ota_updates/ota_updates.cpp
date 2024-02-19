// #include "ota_updates.h"

// static const char *TAG = "OTA_Update";

// // OTA Update server URL
// const char *ota_update_url = "http://example.com/your_ota_update.bin";

// esp_err_t _http_event_handler(esp_http_client_event_t *evt) 
// {
//     switch (evt->event_id) {
//         case HTTP_EVENT_ERROR:
//             ESP_LOGI(TAG, "HTTP_EVENT_ERROR");
//             break;
//         case HTTP_EVENT_ON_CONNECTED:
//             ESP_LOGI(TAG, "HTTP_EVENT_ON_CONNECTED");
//             break;
//         case HTTP_EVENT_HEADER_SENT:
//             ESP_LOGI(TAG, "HTTP_EVENT_HEADER_SENT");
//             break;
//         case HTTP_EVENT_ON_HEADER:
//             ESP_LOGI(TAG, "HTTP_EVENT_ON_HEADER, key=%s, value=%s", evt->header_key, evt->header_value);
//             break;
//         case HTTP_EVENT_ON_DATA:
//             ESP_LOGI(TAG, "HTTP_EVENT_ON_DATA, len=%d", evt->data_len);
//             break;
//         case HTTP_EVENT_ON_FINISH:
//             ESP_LOGI(TAG, "HTTP_EVENT_ON_FINISH");
//             break;
//         case HTTP_EVENT_DISCONNECTED:
//             ESP_LOGI(TAG, "HTTP_EVENT_DISCONNECTED");
//             break;
//     }
//     return ESP_OK;
// }

// void ota_update_task(void *pvParameter) 
// {
//     ESP_LOGI(TAG, "Starting OTA update...");

//     esp_http_client_config_t config = {
//         .url = ota_update_url,
//         .event_handler = _http_event_handler,        
//     };

//     esp_err_t ret = esp_https_ota(&config);

//     if (ret == ESP_OK) {
//         ESP_LOGI(TAG, "OTA update successfully completed. Rebooting...");
//         esp_restart();
//     } else {
//         ESP_LOGE(TAG, "OTA update failed...");
//     }

//     // Delete task after completion
//     vTaskDelete(NULL);
// }