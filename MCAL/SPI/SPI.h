/*
 * SPI.h
 *
 * Created: 11/29/2023 6:20:24 PM
 *  Author: M.Moussa
 */ 


#ifndef SPI_H_
#define SPI_H_


typedef enum{
    MASTER,SLAVE
    }SPIMode_t;

#define SPI_SCK  7
#define SPI_MISO 6
#define SPI_MOSI 5
#define SPI_SS   4

void SPI_Init(SPIMode_t mode);

u8 SPI_SendRecive(u8 data);

// only for slave because slave doesn't initiate the communication and wait the master
u8 SPI_SlaveRecivePeriodic (u8 *pdata);

void SPI_SendNoBlockInBuffer(u8 data);
#endif /* SPI_H_ */
