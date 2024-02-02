#include <Arduino.h>
#include <stdio.h>
#include <string.h>
#include "../../utilities/utilities.h"

#include "freertos/FreeRTOS.h"
#include "freertos/queue.h"


void p2p_tx_task(void *pvParameters)
{
	// QueueHandle_t* cmd_out_queue = (QueueHandle_t *)pvParameters;
	// // ASSERT(cmd_out_queue != NULL);
	// if (!cmd_out_queue)
	// {
	// 	Serial.println("cmd_out_queue failed to get");
	// 	vTaskDelete(NULL);
	// 	return;
	// }
	
	// uint32_t ch_index = 0;

	// for(;;)
	// {

	// 	while(!Serial.available()){};

	// 	char in_char = Serial.read();

	// 	if (in_char == '\n' || in_char == 10 || in_char == 0 || (int)in_char == 13)
	// 	{			
	// 		Serial.print("\n\r");
	// 		Serial.print("Command entered: ");
	// 		Serial.println(cmd_out_buf);
	// 		xQueueSend(*cmd_out_queue, cmd_out_buf, portMAX_DELAY);
	// 		memset(cmd_out_buf, 0x00, sizeof(cmd_out_buf));
	// 		ch_index = 0;


	// 	}
	// 	else
	// 	{
	// 		cmd_out_buf[ch_index++] = in_char;
	// 	}

	// 	Serial.print(in_char);
	// 	delay(freq_ms);
	// }

	// vTaskDelete(NULL);
}