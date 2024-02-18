#include <stdint.h>
#include <string.h>
#include <stdlib.h>

#include "p2p.h"

#include "../utilities/utilities.h"

#include "freertos/FreeRTOS.h"

#include "Arduino.h"


/****
 *  P2P - Peer to Peer Network
 * 
 * 
 * 
 *  1) This interface shall allow p2p networking between any two nodes in the network
 * 
 *  2) This interface shall also support multicast
 * 
 *
 * 
****/
int32_t p2p_node_init(p2pNode_t* node, QueueHandle_t* txq, QueueHandle_t* rxq)
{
    if (!node || !txq || !rxq)
    {
        Serial.println("Error with node or txq or rxq in p2p_node_init");
        return -1;
    }
    node->rx_queue = rxq;
    node->tx_queue = txq;

    return 0;
}

int32_t change_ip_addr(p2pNode_t* node, const char* new_ip_addr)
{
    return 0;
}

// Node Discovery
void discoverPeers()
{
    
}

// Peer Management
void addPeer(const char* peerAddress)
{
    
}

void updatePeer(const char* peerAddress)
{
    
}
void removePeer(const char* peerAddress)
{
    
}

// Peer-to-Peer Communication Protocol
void sendMessage(const char* peerAddress, const char* message)
{
    
}
void broadcastMessage(const char* message)
{
    
}
void receiveMessage(const char* peerAddress, const char* message)
{
    
}

void p2p_async_task(void *pvParameters)
{
    p2pNode_t* node = (p2pNode_t*)pvParameters;
    ASSERT(node != NULL);

    for (;;)
    {
        Serial.println("Inside p2p_async_task");
        vTaskDelay(pdMS_TO_TICKS(1000));
    }

    vTaskDelete(NULL);
}

