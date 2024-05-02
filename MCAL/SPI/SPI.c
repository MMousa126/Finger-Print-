/*
 * SPI.c
 *
 * Created: 11/29/2023 6:20:03 PM
 *  Author: M.Moussa
 */ 

#include "../../StdTypes.h"
#include "../../MemMap.h"
#include "../../Utils.h"
#include "SPI.h"
#include <util/delay.h>


void SPI_Init(SPIMode_t mode)
{
    if (mode == MASTER)
    {
        // clock 2MHZ

        // master
        SET_BIT(SPCR,MSTR); 
    }
    else
    {
        // slave
        CLR_BIT(SPCR,MSTR); 
    }

    // SPI Enable 
    SET_BIT(SPCR,SPE);
    
}

// busy wait 
u8 SPI_SendRecive(u8 data)
{

    SPDR = data; // write data to master and wait until it sent to slave 
    
    while(!READ_BIT(SPSR,SPIF));
 
    
    SET_BIT(SPSR,SPIF);
    
    return SPDR; // return what's inside slave 
       
    
}

// only for slave because slave doesn't initiate the communication and wait the master
u8 SPI_SlaveRecivePeriodic (u8 *pdata)
{                                                    
    if (READ_BIT(SPSR,SPIF))
    {
        *pdata = SPDR;
        return 1;
    }
    return 0 ;
    
}

void SPI_SendNoBlockInBuffer(u8 data)
{
    SPDR = data;
    
}

u8 SPI_SendRecive_RuntimeOut(u8 data,u8*ptrdata,u8 timeout)
{
    SPDR = data; // write data to master and wait until it sent to slave
    
    u8 counter = 0;
    
    while(!READ_BIT(SPSR,SPIF)&&(counter < timeout))
    {
        counter++;
        _delay_ms(1);
    }
    if (counter == timeout )
    {
        return 0;
    }
    
    *ptrdata = SPDR; // return what's inside slave
    return 1;
    
    
    
}
