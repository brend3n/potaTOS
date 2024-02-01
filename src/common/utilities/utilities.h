#ifndef UTILS_H
#define UTILS_H

#include <Arduino.h>
#include <stdio.h>
#include <stdlib.h>

#define ASSERT(condition) \
    do { \
        if (!(condition)) { \
            char temp_buf[100]; \
            sprintf(temp_buf, "Assertion failed: %s, file %s, line %d\n", \
                    #condition, __FILE__, __LINE__); \
            Serial.println(temp_buf); \
        } \
    } while (0);

#endif //UTILS_H