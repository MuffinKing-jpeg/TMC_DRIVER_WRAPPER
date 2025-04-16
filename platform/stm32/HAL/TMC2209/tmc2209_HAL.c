#include "TMC2209.h"
#include "tmc2209_HAL.h"
#include "malloc.h"

#define TMC2209_ENTRY_SIZE sizeof(tmc2209_EntryTypeDef)

tmc2209_EntryTypeDef *tmc2209_table_ptr;
uint8_t tmc2209_table_size = 0;

uint8_t tmc2209_getNodeAddress(uint16_t icID)
{
}

bool tmc2209_readWriteUART(uint16_t icID, uint8_t *data, size_t writeLength, size_t readLength)
{
}

HAL_StatusTypeDef tmc2209_hal_init()
{
    return HAL_OK;
}

HAL_StatusTypeDef tmc2209_hal_addDevice(uint16_t icID, UART_HandleTypeDef *bus, uint8_t nodeAdress)
{
    tmc2209_EntryTypeDef *tempPtr;
    tmc2209_table_size += 1;
    if (tmc2209_table_size <= 1)
    {
        
        tempPtr = malloc(TMC2209_ENTRY_SIZE * tmc2209_table_size);
    }
    else
    {
        tempPtr = realloc(tmc2209_table_ptr, TMC2209_ENTRY_SIZE * tmc2209_table_size);
    }
    if (tempPtr == NULL)
    {
        return HAL_ERROR;
    }
    else
    {
        tmc2209_table_ptr = tempPtr;
        tmc2209_table_ptr[tmc2209_table_size-1].bus = bus;
        tmc2209_table_ptr[tmc2209_table_size-1].icID = icID;
        tmc2209_table_ptr[tmc2209_table_size-1].nodeAdress = nodeAdress;
        return HAL_OK;
    }
}