#include "StdTypes.h"
#include "Utils.h"
#include "MCAL/UART/UART_Interface.h"
#include "MCAL/DIO/DIO_Interface.h"
#include "HAL/LCD/LCD_Interface.h"
#include "HAL/FINGER PRINT/FIGER_PRINT_Interface.h"
#include "FingerPrint_Servic.h"
#include "avr/interrupt.h"
#include <util/delay.h>

extern volatile u8 array_receive[];

void ReceiveFun(void);

int main() {

	UART_Init();
	DIO_Init();
	LCD_INIT();

//	LCD_WRITESTRING((u8*)" he ");
//
//	UART_receiveByteAsynchCallBack(ReceiveFun);
//	UART_RX_InterruptEnable();
//	sei();

	u8 flag = 0;
	u8 LocalMain = FingerPrint_EnrollmentFSFunc();

	if (LocalMain == 0)
	{
		LCD_CLEAR();
		LCD_WRITESTRING((u8*)"stored successfully ");
		FingerPS_AuraControlBlue();
		flag =1;
	}
	else
	{
		LCD_CLEAR();
		FingerPS_AuraControlRed();
	}

	_delay_ms(5000);


	FingerPS_AuraControlPurple();

	_delay_ms(5000);
	if (FingerPrint_MatchFunc() == 0)
	{
		LCD_CLEAR();
		LCD_WRITESTRING("you are here");
		DIO_WritePin(PINA0, HIGH);
		FingerPS_AuraControlBlue();
	}
	else
	{
		LCD_CLEAR();
		LCD_WRITESTRING("wrong finger print");
		FingerPS_AuraControlRed();
	}

	while (1) {

	}
	return 0;
}


//	DIO_WritePin(PINA0, LOW);
//	_delay_ms(2000);
//	if (FingerPS_handShake() == 0)
//	{
//		DIO_WritePin(PINA0, HIGH);
//
//	}
//
//	_delay_us(5000);
//	DIO_WritePin(PINA0, HIGH);

	 //FingerPS_AuraControl();
//
//	LCD_WRITENUMBER(x);



//	FingerPS_handShake();

//	FingerPS_genImg();


//	FingerPS_convertImg1CharFile();
//	FingerPS_convertImg2CharFile();
//	FingerPS_genTemplate();
//	FingerPS_strTemplate();
//	FingerPS_searchFinger();
//	FingerPS_emptyLibrary();
//	FingerPS_deleteFinger();
//	FingerPS_LoadCharFile();
//	FingerPS_calcCheckSum();
//	FingerPS_match();

