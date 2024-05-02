/*
 * UART_Private.h
 *
 *  Created on: Mar 19, 2024
 *      Author: M.Moussa
 */

#ifndef UART_PRIVATE_H_
#define UART_PRIVATE_H_

/*************************** UART ***************************************/



// UART Data Register
#define UDR     *((volatile unsigned char*)0x2C)

// UART Control and Status Registers A, B, and C
#define UCSRA   *((volatile unsigned char*)0x2B)
#define UCSRB   *((volatile unsigned char*)0x2A)
#define UCSRC   *((volatile unsigned char*)0x40)

// UART Baud Rate Registers High and Low
#define UBRRH   *((volatile unsigned char*)0x40)
#define UBRRL   *((volatile unsigned char*)0x29)


// UART Control and Status Register A (UCSRA) Bits
#define UCSRA_MPCM    0 // Multi-Processor Communication Mode
#define UCSRA_U2X     1 // Double the USART Transmission Speed
#define UCSRA_PE      2 // Parity Error
#define UCSRA_DOR     3 // Data OverRun
#define UCSRA_FE      4 // Frame Error
#define UCSRA_UDRE    5 // USART Data Register Empty
#define UCSRA_TXC     6 // USART Transmit Complete
#define UCSRA_RXC     7 // USART Receive Complete

// UART Control and Status Register B (UCSRB) Bits
#define UCSRB_TXB8    0 // Transmit Data Bit 8
#define UCSRB_RXB8    1 // Receive Data Bit 8
#define UCSRB_UCSZ2   2 // Character Size (Bit 2)
#define UCSRB_TXEN    3 // Transmitter Enable
#define UCSRB_RXEN    4 // Receiver Enable
#define UCSRB_UDRIE   5 // USART Data Register Empty Interrupt Enable
#define UCSRB_TXCIE   6 // USART Transmit Complete Interrupt Enable
#define UCSRB_RXCIE   7 // USART Receive Complete Interrupt Enabl

// UART Control and Status Register C (UCSRC) Bits
#define UCSRC_UCPOL   0 // Clock Polarity
#define UCSRC_UCSZ0   1 // Character Size (Bit 0)
#define UCSRC_UCSZ1   2 // Character Size (Bit 1)
#define UCSRC_USBS    3 // Stop Bit Select
#define UCSRC_UPM0    4 // Parity Mode Bit 0
#define UCSRC_UPM1    5 // Parity Mode Bit 1
#define UCSRC_UMSEL   6 // USART Mode Select
#define UCSRC_URSEL   7 // Register Select Bit


#define 	ISR(vector)		void vector(void)__attribute__((signal));\
							void vector(void)

/* USART , RX Complete */
#define 	UART_RX_vect		__vector_13
/* USART Data Register Empty */
#define 	UART_UDRE_vect		__vector_14
/* USART , TX Complete */
#define 	UART_TX_vect		__vector_15

#endif /* UART_PRIVATE_H_ */
