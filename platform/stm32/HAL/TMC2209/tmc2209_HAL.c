#include "TMC2209.h"
#include "tmc2209_HAL.h"
#include "malloc.h"

uint8_t tmc2209_table_ptr;
uint8_t tmc2209_table_size = 0;

uint8_t tmc2209_getNodeAddress(uint16_t icID) {
}

bool tmc2209_readWriteUART(uint16_t icID, uint8_t *data, size_t writeLength, size_t readLength)
{

}

HAL_StatusTypeDef tmc2209_hal_init() 
{
    tmc2209_table_size += 1;
    tmc2209_table_ptr = malloc(tmc2209_table_size);
}

HAL_StatusTypeDef tmc2209_hal_addDevice(uint16_t icID, UART_HandleTypeDef *bus, uint8_t nodeAdress)
{

}