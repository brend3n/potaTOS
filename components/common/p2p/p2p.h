#ifndef P2P_H
#define P2P_H

#include "freertos/FreeRTOS.h"
#include "freertos/queue.h"


typedef struct p2pNode_t
{
    uint32_t node_id;

    QueueHandle_t* tx_queue;
    QueueHandle_t* rx_queue;

    // Probably need to add things like sockets, etc.

}p2pNode_t;


void p2p_async_task(void *pvParameters);
int32_t p2p_node_init(p2pNode_t* node, QueueHandle_t* txq, QueueHandle_t* rxq);
int32_t change_ip_addr(p2pNode_t* node, const char* new_ip_addr);

// Node Discovery
void discoverPeers();

// Peer Management
void addPeer(const char *peerAddress);
void updatePeer(const char *peerAddress);
void removePeer(const char *peerAddress);

// Peer-to-Peer Communication Protocol
void sendMessage(const char *peerAddress, const char *message);
void broadcastMessage(const char* message);
void receiveMessage(const char *peerAddress, const char *message);

#endif //P2P_H