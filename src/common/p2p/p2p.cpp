#include "Arduino.h"
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

#include "p2p.h"


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

int32_t p2p_node_init(p2pNode* node, QueueHandle_t* txq, QueueHandle_t* rxq)
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
    
}

