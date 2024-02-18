#include <stdio.h>
#include <string.h>

#include "../utilities/utilities.h"
#include "../utilities/cli_utils.h"

#include "freertos/FreeRTOS.h"
#include "freertos/queue.h"

#include "cli.h"

static const uint32_t freq_ms = 50;

char cmd_out_buf[MAX_STRING_BUFFER_SIZE];
char cmd_in_buf[MAX_STRING_BUFFER_SIZE];

void cli_input_task(void *pvParameters)
{
	QueueHandle_t* cmd_out_queue = (QueueHandle_t *)pvParameters;
	ASSERT(cmd_out_queue != NULL);
	
	uint32_t ch_index = 0;

	for(;;)
	{

		while(!Serial.available()){};

		char in_char = Serial.read();

		if (in_char == '\n' || in_char == 10 || in_char == 0 || (int)in_char == 13)
		{			
			Serial.print("\n\r");
			Serial.print("Command entered: ");
			Serial.println(cmd_out_buf);
			xQueueSend(*cmd_out_queue, cmd_out_buf, portMAX_DELAY);
			memset(cmd_out_buf, 0x00, sizeof(cmd_out_buf));
			ch_index = 0;


		}
		else
		{
			cmd_out_buf[ch_index++] = in_char;
		}

		Serial.print(in_char);
		delay(freq_ms);
	}

	vTaskDelete(NULL);
}

void cli_execute_task(void *pvParameters)
{	
	QueueHandle_t* cmd_in_queue = (QueueHandle_t *)pvParameters;
	ASSERT(cmd_in_queue != NULL);
	
	for(;;)
	{
		
		if (xQueueReceive(*cmd_in_queue, cmd_in_buf, portMAX_DELAY) == pdPASS)
		{
			Serial.print("Command Rxed: <");
			Serial.print(cmd_in_buf);
			Serial.println(">");
			memset(cmd_in_buf, 0x00, sizeof(cmd_in_buf));
		}

		delay(freq_ms);
	}

	vTaskDelete(NULL);
}

