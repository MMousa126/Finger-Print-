/*
 * UART_Program.c
 *
 *  Created on: Mar 19, 2024
 *      Author: M.Moussa
 */


#include "../../StdTypes.h"
#include "../../Utils.h"
#include "UART_Config.h"
#include "UART_Interface.h"
#include "UART_Private.h"


void (*ptr_isr)(void)=0;

void UART_Init()
{

	// selection and 8bit data
	UCSRC = (1<<UCSRC_UCSZ0)|(1<<UCSRC_UCSZ1)|(1<<UCSRC_URSEL);

	UBRRL = UART_BOUDRATE_57600;


	// Enable TX and RX
	SET_BIT(UCSRB, UCSRB_TXEN);
	SET_BIT(UCSRB, UCSRB_RXEN);
}

void UART_sendByte(u8 ch)
{

	while(READ_BIT(UCSRA, UCSRA_UDRE)==0);
	UDR = ch;
}

void UART_sendString(u8* str)
{

	u8 i=0;

	UART_sendByte(str[i]);

	for(;str[i];)
	{
		i++;

		UART_sendByte(str[i]);
	}
	str[i] = '\0';

}

u8 UART_receiveByteSynch()
{

	while(READ_BIT(UCSRA, UCSRA_RXC)==0);
	return UDR;


}

void UART_RX_InterruptEnable(void)
{
    SET_BIT(UCSRB,UCSRB_RXCIE);
}

void UART_RX_InterruptDisable(void)
{
    CLR_BIT(UCSRB,UCSRB_RXCIE);
}


void UART_receiveByteAsynchCallBack(void (*ptr)(void))
{

	if (ptr != NULL)
	{
		ptr_isr = ptr;
	}


}
u8 UART_ReciveNoBlock(void)
{
    return UDR;
}

ISR(UART_RX_vect)
{

	if (ptr_isr != NULL)
	{
		ptr_isr();
	}

}
