#ifndef UTILS_H
#define UTILS_H

#include <Arduino.h>

/* Tick rate in Hz */
#define configTICK_RATE_HZ              ((TickType_t)1000)

#define pdMSTOTICKS( xTimeInMs ) ( ( TickType_t ) xTimeInMs * ( configTICK_RATE_HZ / ( ( TickType_t ) 1000 ) ) )

#endif //UTILS_H