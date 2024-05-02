/*
 * FIGER_PRINT_Programe.c
 *
 *  Created on: Mar 22, 2024
 *      Author: Super Magic
 */

#include "../../StdTypes.h"
#include "../../Utils.h"
#include "../../MCAL/UART/UART_Interface.h"
#include "FIGER_PRINT_Interface.h"
#include "FIGER_PRINT_Private.h"
#include "FIGER_PRINT_Config.h"
#include "../LCD/LCD_Interface.h"
#include "avr/delay.h"
#include "avr/interrupt.h"

u8 GloblaArrACK[] = { 0 };

u8 Page_ID = 1;

u8 GSumCalc = 0;

volatile u8 array_receive[] = { 0 };

static void GeneralFunc_FingerPrint(u8 *arr, u8 size) {

	_delay_ms(200);

	/* Sending the header at first */
	UART_sendByte(HEADER_1BYTE);
	UART_sendByte(HEADER_2BYTE);

	/* Sending the Package Address */
	UART_sendByte(ADDMODE_1BYTES);
	UART_sendByte(ADDMODE_2BYTES);
	UART_sendByte(ADDMODE_3BYTES);
	UART_sendByte(ADDMODE_4BYTES);

	/* Sending package Id */
	/* sending Package Length */
	/* Sending Instruction Code */

	for (u8 i = 0; i < size; i++) {
		UART_sendByte(arr[i]);
	}
}
static u8 GeneralCheckSum_Calc(u8 *arr, u8 size) {
	u16 sumcalc = 0;
	for (u8 i = 0; i < size; i++)
		sumcalc += arr[i];

	GSumCalc = sumcalc;

	UART_sendByte(sumcalc >> 8);

	return ((u8)sumcalc);

}

u8 FingerPS_AuraControlPurple(void)
{
	u8 arr[] = { 0x01, 0x00, 0x07, 0x35, 0x03, 125, 0x03, 125 };

	u8 size = sizeof(arr) / sizeof(arr[0]);

	GeneralFunc_FingerPrint(arr,size);

	UART_sendByte(GeneralCheckSum_Calc(arr, size));

	return GeneralFunc_ReturnFingerPrint();

}
u8 FingerPS_AuraControlBlue(void)
{
	u8 arr[] = { 0x01, 0x00, 0x07, 0x35, 0x03, 125, 0x02, 125 };

	u8 size = sizeof(arr) / sizeof(arr[0]);

	GeneralFunc_FingerPrint(arr,size);

	UART_sendByte(GeneralCheckSum_Calc(arr, size));

	return GeneralFunc_ReturnFingerPrint();

}
u8 FingerPS_AuraControlRed(void)
{
	u8 arr[] = { 0x01, 0x00, 0x07, 0x35, 0x02, 125, 0x01, 125 };

	u8 size = sizeof(arr) / sizeof(arr[0]);

	GeneralFunc_FingerPrint(arr,size);

	UART_sendByte(GeneralCheckSum_Calc(arr, size));

	return GeneralFunc_ReturnFingerPrint();

}
#if    FINGERPRINT_MODE == FINGERPRINT_SYCH

static u8 GeneralFunc_ReturnFingerPrint(void) {

	for (u8 i = 0; i < TOTAL_ACKLENGTH; i++) {
		GloblaArrACK[i] = UART_receiveByteSynch();
	}

	return GloblaArrACK[CONFIRM_CODE];
}

u8 FingerPS_handShake(void) {

	u8 arr[] = { 0x01, 0x00, 0x03, 0x40 };

	u8 size = sizeof(arr) / sizeof(arr[0]);

	GeneralFunc_FingerPrint(arr, size);

	UART_sendByte(GeneralCheckSum_Calc(arr, 4));

	return GeneralFunc_ReturnFingerPrint();

}
u8 FingerPS_genImg(void) {

	u8 arr[] = { 0x01, 0x00, 0x03, 0x01 };

	u8 size = sizeof(arr) / sizeof(arr[0]);

	GeneralFunc_FingerPrint(arr, size);

	UART_sendByte(GeneralCheckSum_Calc(arr, size));

	return GeneralFunc_ReturnFingerPrint();

}
u8 FingerPS_convertImg1CharFile(void) {

	u8 arr[] = { 0x01, 0x00, 0x04, 0x02, FIRST_IDFILE };

	u8 size = sizeof(arr) / sizeof(arr[0]);

	GeneralFunc_FingerPrint(arr, size);

	UART_sendByte(GeneralCheckSum_Calc(arr, size));

	return GeneralFunc_ReturnFingerPrint();

}
u8 FingerPS_convertImg2CharFile(void) {

	u8 arr[] = { 0x01, 0x00, 0x04, 0x02, SECOND_IDFILE };

	u8 size = sizeof(arr) / sizeof(arr[0]);

	GeneralFunc_FingerPrint(arr, size);

	UART_sendByte(GeneralCheckSum_Calc(arr, size));

	return GeneralFunc_ReturnFingerPrint();

}
u8 FingerPS_genTemplate(void) {

	u8 arr[] = { 0x01, 0x00, 0x03, 0x05 };

	u8 size = sizeof(arr) / sizeof(arr[0]);

	GeneralFunc_FingerPrint(arr, size);

	UART_sendByte(GeneralCheckSum_Calc(arr, size));

	return GeneralFunc_ReturnFingerPrint();

}
u8 FingerPS_strTemplate(void) {


	u8 arr[] = { 0x01, 0x00, 0x06, 0x06, FIRST_IDFILE, (Page_ID>>8), ((u8)Page_ID) };

	u8 size = sizeof(arr) / sizeof(arr[0]);

	GeneralFunc_FingerPrint(arr, size);

	UART_sendByte(GeneralCheckSum_Calc(arr, size));

	return GeneralFunc_ReturnFingerPrint();

}
u8 FingerPS_searchFinger(void) {

	u8 arr[] = { 0x01, 0x00, 0x08, 0x04, FIRST_IDFILE, 0x00, 0x00, (Page_ID>>8), ((u8)Page_ID) };

	u8 size = sizeof(arr) / sizeof(arr[0]);

	GeneralFunc_FingerPrint(arr, size);

	UART_sendByte(GeneralCheckSum_Calc(arr, size));

	return GeneralFunc_ReturnFingerPrint();
}
u8 FingerPS_emptyLibrary(void) {

	u8 arr[] = { 0x01, 0x00, 0x03, 0x0d };

	u8 size = sizeof(arr) / sizeof(arr[0]);

	GeneralFunc_FingerPrint(arr, size);

	UART_sendByte(GeneralCheckSum_Calc(arr, size));

	return GeneralFunc_ReturnFingerPrint();

}
u8 FingerPS_deleteFinger(void) {

	u8 arr[] = { 0x01, 0x00, 0x07, 0x0c, (Page_ID>>8), ((u8)Page_ID), 0x01 };

	u8 size = sizeof(arr) / sizeof(arr[0]);

	GeneralFunc_FingerPrint(arr, size);

	UART_sendByte(GeneralCheckSum_Calc(arr, size));

	return GeneralFunc_ReturnFingerPrint();

}
u8 FingerPS_LoadCharFile(void) {

	u8 arr[] = { 0x01, 0x00, 0x06, 0x07, FIRST_IDFILE, (Page_ID>>8), ((u8)Page_ID) };

	u8 size = sizeof(arr) / sizeof(arr[0]);

	GeneralFunc_FingerPrint(arr, size);

	UART_sendByte(GeneralCheckSum_Calc(arr, size));

	return GeneralFunc_ReturnFingerPrint();

}
u8 FingerPS_calcCheckSum(void) {

	return GSumCalc;
}

u8 FingerPS_match(void) {

	u8 arr[] = { 0x01, 0x00, 0x03, 0x03 };

	u8 size = sizeof(arr) / sizeof(arr[0]);

	GeneralFunc_FingerPrint(arr, size);

	UART_sendByte(GeneralCheckSum_Calc(arr, size));

	return GeneralFunc_ReturnFingerPrint();

}


void ReceiveFun(void) {

	static u8 i = 0;

	array_receive[i] = UART_ReciveNoBlock();

	if (i == 11)
	{
		i=0;
	}
	else
		i++;
}

#elif	FINGERPRINT_MODE == FINGERPRINT_ASYCH

void FingerPS_handShake(void) {

	u8 arr[] = { 0x01, 0x00, 0x03, 0x40 };

	u8 size = sizeof(arr) / sizeof(arr[0]);

	GeneralFunc_FingerPrint(arr, size);

	UART_sendByte(GeneralCheckSum_Calc(arr, 4));

}
void FingerPS_genImg(void) {

	u8 arr[] = { 0x01, 0x00, 0x03, 0x01 };

	u8 size = sizeof(arr) / sizeof(arr[0]);

	GeneralFunc_FingerPrint(arr, size);

	UART_sendByte(GeneralCheckSum_Calc(arr, size));

}
void FingerPS_convertImg1CharFile(void) {

	u8 arr[] = { 0x01, 0x00, 0x04, 0x02, FIRST_IDFILE };

	u8 size = sizeof(arr) / sizeof(arr[0]);

	GeneralFunc_FingerPrint(arr, size);

	UART_sendByte(GeneralCheckSum_Calc(arr, size));

}
void FingerPS_convertImg2CharFile(void) {

	u8 arr[] = { 0x01, 0x00, 0x04, 0x02, SECOND_IDFILE };

	u8 size = sizeof(arr) / sizeof(arr[0]);

	GeneralFunc_FingerPrint(arr, size);

	UART_sendByte(GeneralCheckSum_Calc(arr, size));

}
void FingerPS_genTemplate(void) {

	u8 arr[] = { 0x01, 0x00, 0x03, 0x05 };

	u8 size = sizeof(arr) / sizeof(arr[0]);

	GeneralFunc_FingerPrint(arr, size);

	UART_sendByte(GeneralCheckSum_Calc(arr, size));

}
void FingerPS_strTemplate(void) {

	u8 arr[] = { 0x01, 0x00, 0x06, 0x06, FIRST_IDFILE, (Page_ID>>8), ((u8)Page_ID) };

	u8 size = sizeof(arr) / sizeof(arr[0]);

	GeneralFunc_FingerPrint(arr, size);

	UART_sendByte(GeneralCheckSum_Calc(arr, size));
}
void FingerPS_searchFinger(void) {

	u8 arr[] = { 0x01, 0x00, 0x08, 0x04, FIRST_IDFILE, 0x00, (Page_ID>>8), ((u8)Page_ID) };

	u8 size = sizeof(arr) / sizeof(arr[0]);

	GeneralFunc_FingerPrint(arr, size);

	UART_sendByte(GeneralCheckSum_Calc(arr, size));

}
void FingerPS_emptyLibrary(void) {

	u8 arr[] = { 0x01, 0x00, 0x03, 0x0d };

	u8 size = sizeof(arr) / sizeof(arr[0]);

	GeneralFunc_FingerPrint(arr, size);

	UART_sendByte(GeneralCheckSum_Calc(arr, size));

}
void FingerPS_deleteFinger(void) {

	u8 arr[] = { 0x01, 0x00, 0x07, 0x0c, Page_ID, 0x01 };

	u8 size = sizeof(arr) / sizeof(arr[0]);

	GeneralFunc_FingerPrint(arr, size);

	UART_sendByte(GeneralCheckSum_Calc(arr, size));

}
void FingerPS_LoadCharFile(void) {

	u8 arr[] = { 0x01, 0x00, 0x06, 0x07, FIRST_IDFILE, (Page_ID>>8), ((u8)Page_ID) };

	u8 size = sizeof(arr) / sizeof(arr[0]);

	GeneralFunc_FingerPrint(arr, size);

	UART_sendByte(GeneralCheckSum_Calc(arr, size));

}
u8 FingerPS_calcCheckSum(void) {

	return GSumCalc;

}
void FingerPS_match(void) {

	u8 arr[] = { 0x01, 0x00, 0x03, 0x03 };

	u8 size = sizeof(arr) / sizeof(arr[0]);

	GeneralFunc_FingerPrint(arr, size);

	UART_sendByte(GeneralCheckSum_Calc(arr, size));

}




#endif
