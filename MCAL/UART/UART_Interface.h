/*
 * UART_Interface.h
 *
 *  Created on: Mar 19, 2024
 *      Author: M.Moussa
 */

#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_

void UART_Init(void);

void UART_sendByte(u8 ch);

void UART_sendString(u8* str);

u8 UART_receiveByteSynch(void);

void UART_RX_InterruptEnable(void);

void UART_RX_InterruptDisable(void);

u8 UART_ReciveNoBlock(void);

void UART_receiveByteAsynchCallBack(void (*ptr)(void));

#endif /* UART_INTERFACE_H_ */
