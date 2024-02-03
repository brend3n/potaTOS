#ifndef BOARD_CONFIG_H
#define BOARD_CONFIG_H

#include "../task_info.h"

// Define the number of boards and adjust this file accordingly
#define NUM_BOARDS 1

// Board Roles
/* Uncomment one of them */
#define BOARD_ID 0
// #define BOARD_ID 1
// #define BOARD_ID 2
// #define BOARD_ID 3
// #define BOARD_ID 4
// #define BOARD_ID 5
// #define UDP_TEST 4


#if (BOARD_ID == 0)
    #define BOARD_STR "0"
    #define TEMP_HUM_PIN 8 
    #define US_TRIG_PIN 13
    #define US_ECHO_PIN 14

    // Tasks defined
    #define HELLO_TASK 0
    #define BUTTON_PUB 0
    #define BUTTON_SUB 0
    #define TEMP_HUM_PUB 0
    #define ULTRA_SONIC_PUB 0
    #define CLI_TASK 1

    #define TASK_LIST { \
    /*Common Tasks */ TASK_CLI_INPUT, TASK_CLI_EXEC, TASK_P2P_TX, TASK_P2P_RX, TASK_P2P_ASYNC, \
    {0} \
    }
#elif (BOARD_ID == 1)
    #define BOARD_STR "1"
    #define TEMP_HUM_PIN 8 
    #define US_TRIG_PIN 13
    #define US_ECHO_PIN 14

    // Tasks defined
    #define HELLO_TASK 0
    #define BUTTON_PUB 0
    #define BUTTON_SUB 0
    #define TEMP_HUM_PUB 1
    #define ULTRA_SONIC_PUB 1

    #define TASK_LIST {HELLO_TASK , BUTTON_PUB , BUTTON_SUB, TEMP_HUM_PUB, ULTRA_SONIC_PUB}
#elif(BOARD_ID == 2)
    #define BOARD_STR "2"
    #define BUTTON_PIN 18

    // Tasks defined
    #define HELLO_TASK 0
    #define BUTTON_PUB 1
    #define BUTTON_SUB 0
    #define TEMP_HUM_PUB 0
    #define ULTRA_SONIC_PUB 0

    #define TASK_LIST {HELLO_TASK , BUTTON_PUB , BUTTON_SUB, TEMP_HUM_PUB, ULTRA_SONIC_PUB}
#elif(BOARD_ID == 3)
    #define BOARD_STR "3"
    #define BUTTON_PIN 13

    // Tasks defined
    #define HELLO_TASK 0
    #define BUTTON_PUB 1
    #define BUTTON_SUB 0
    #define TEMP_HUM_PUB 0
    #define ULTRA_SONIC_PUB 0

    #define TASK_LIST {HELLO_TASK , BUTTON_PUB , BUTTON_SUB, TEMP_HUM_PUB, ULTRA_SONIC_PUB}
#elif(BOARD_ID == 4)
#define BOARD_STR "4"
#define US_TRIG_PIN -1
#define US_ECHO_PIN -1
#define TEMP_HUM_PIN 8

// Tasks defined
#define HELLO_TASK 1
#define BUTTON_PUB 0
#define BUTTON_SUB 0
#define TEMP_HUM_PUB 0
#define ULTRA_SONIC_PUB 0
#define TASK_LIST {HELLO_TASK , BUTTON_PUB , BUTTON_SUB, TEMP_HUM_PUB, ULTRA_SONIC_PUB}
#elif(BOARD_ID == 5)
#define BOARD_STR "5"
#define BUTTON_PIN 13
#define US_TRIG_PIN -1
#define US_ECHO_PIN -1
#define TEMP_HUM_PIN 8

// Tasks defined
#define HELLO_TASK 1
#define BUTTON_PUB 0
#define BUTTON_SUB 0
#define TEMP_HUM_PUB 0
#define ULTRA_SONIC_PUB 0
#define TASK_LIST {HELLO_TASK , BUTTON_PUB , BUTTON_SUB, TEMP_HUM_PUB, ULTRA_SONIC_PUB}
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