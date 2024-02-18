#include <stdio.h>
#include <string.h>
#include "../../utilities/utilities.h"

#include "freertos/FreeRTOS.h"
#include "freertos/queue.h"

#include "../p2p.h"

void p2p_rx_task(void *pvParameters)
{	
    p2pNode_t* node = (p2pNode_t*)pvParameters;
    ASSERT(node != NULL);

    for (;;)
    {
        printf("Inside p2p_rx_task");
        vTaskDelay(pdMS_TO_TICKS((1000);)
    }

    vTaskDelete(NULL);
}

