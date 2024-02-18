#ifndef BOARD_CONFIG_H
#define BOARD_CONFIG_H

#include "../tasks/task_info.h"

// Define the number of boards and adjust this file accordingly
#define NUM_BOARDS 1

// Board Roles
/* Uncomment one of them */
// #define BOARD_ID 0
#define BOARD_ID 1
// #define BOARD_ID 2
// #define BOARD_ID 3
// #define BOARD_ID 4
// #define BOARD_ID 5
// #define UDP_TEST 4


#if (BOARD_ID == 0)
    #define BOARD_STR "0"

    #define TASK_LIST { \
    /*Common Tasks */ TASK_CLI_INPUT, TASK_CLI_EXEC, TASK_P2P_TX, TASK_P2P_RX, TASK_P2P_ASYNC, TASK_OTA_UPDATE, \
    {0} \
    }
#elif (BOARD_ID == 1)
    #define BOARD_STR "1"

    #define TASK_LIST { \
    /*Common Tasks */ TASK_CLI_INPUT, TASK_CLI_EXEC, \
    {0} \
    }
#else
#define BOARD_STR "?"
#endif


// WiFi Definitions
#define WIFI_SSID      "YOUR_SSID"
#define WIFI_PASS      "YOUR_SSID_PASSWORD"
#define MAXIMUM_RETRY  10
#define PORT 4323

#define IP_OCT1 192
#define IP_OCT2 168
#define IP_OCT3 1
#define IP_OCT4 224


#endif // BOARD_CONFIG_H