#ifndef __TMC2209_HAL_H_
#define __TMC2209_HAL_H_

#include "TMC2209.h"
#include "usart.h"

typedef struct {
    UART_HandleTypeDef bus;
    uint8_t nodeAdress;
    uint16_t icID;
} tmc2209_EntryTypeDef;

HAL_StatusTypeDef tmc2209_hal_init ();
HAL_StatusTypeDef tmc2209_hal_addDevice(uint16_t icID, UART_HandleTypeDef *bus, uint8_t nodeAdress);

#endif