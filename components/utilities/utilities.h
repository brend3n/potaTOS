#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <stdlib.h>

#define ASSERT(condition) \
    do { \
        if (!(condition)) { \
            char temp_buf[150]; \
            sprintf(temp_buf, "Assertion failed: %s\n\rFile: %s\n\rLine: %d\n\r", \
                    #condition, __FILE__, __LINE__); \
            printf(temp_buf); \
            vTaskDelete(NULL); \
        } \
    } while (0);

#endif //UTILS_H