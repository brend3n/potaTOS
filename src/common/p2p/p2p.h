#ifndef P2P_H
#define P2P_H

#include "freertos/FreeRTOS.h"
#include "freertos/queue.h"


typedef struct p2pNode
{
    uint32_t node_id;

    QueueHandle_t* tx_queue;
    QueueHandle_t* rx_queue;

    // Probably need to add things like sockets, etc.

}p2pNode;

int32_t p2p_node_init(p2pNode* node, QueueHandle_t* txq, QueueHandle_t* rxq);

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