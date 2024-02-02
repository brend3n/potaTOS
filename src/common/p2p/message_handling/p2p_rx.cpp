#include <Arduino.h>
#include <stdio.h>
#include <string.h>
#include "../../utilities/utilities.h"

#include "freertos/FreeRTOS.h"
#include "freertos/queue.h"

void p2p_rx_task(void *pvParameters)
{	
	// QueueHandle_t* cmd_in_queue = (QueueHandle_t *)pvParameters;
	// // ASSERT(cmd_in_queue != NULL);
	// if (!cmd_in_queue)
	// {
	// 	Serial.println("cmd_in_queue failed to get");
	// 	vTaskDelete(NULL);
	// 	return;
	// }
	
	// for(;;)
	// {
		
	// 	if (xQueueReceive(*cmd_in_queue, cmd_in_buf, portMAX_DELAY) == pdPASS)
	// 	{
	// 		Serial.print("Command Rxed: <");
	// 		Serial.print(cmd_in_buf);
	// 		Serial.println(">");
	// 		memset(cmd_in_buf, 0x00, sizeof(cmd_in_buf));
	// 	}

	// 	delay(freq_ms);
	// }

	// vTaskDelete(NULL);
}

