#include <Arduino.h>
#include <stdio.h>
#include "../utilities/utilities.h"
#include <string.h>

static const uint32_t freq_ms = 100;

void cli_input_task(void *pvParameters)
{
	(void)pvParameters;

	uint32_t count = 0;
	for(;;)
	{
		char buffer[100];
		snprintf(buffer, sizeof(buffer), "Inside %s count %d", __func__, count++);
		Serial.println(buffer);
		// vTaskDelay(pdMSTOTICKS(freq_ms));
		delay(freq_ms);
	}


	vTaskDelete(NULL);
}