/*
 * FIGER_PRINT_Private.h
 *
 *  Created on: Mar 22, 2024
 *      Author: Super Magic
 */

#ifndef FIGER_PRINT_PRIVATE_H_
#define FIGER_PRINT_PRIVATE_H_

#define  		FINGERPRINT_SYCH				0
#define  		FINGERPRINT_ASYCH				1

#define 		TOTAL_ACKLENGTH					12
#define			CONFIRM_CODE					9

#define			HEADER_1BYTE					0xEF
#define			HEADER_2BYTE					0x01

#define  		ADDMODE_1BYTES					0xFF
#define  		ADDMODE_2BYTES					0xFF
#define  		ADDMODE_3BYTES					0xFF
#define  		ADDMODE_4BYTES					0xFF

static void GeneralFunc_FingerPrint(u8 *arr, u8 size);

static u8 GeneralCheckSum_Calc(u8 *arr, u8 size);

#if    FINGERPRINT_MODE == FINGERPRINT_SYCH

static u8 GeneralFunc_ReturnFingerPrint(void);

#endif



#endif /* FIGER_PRINT_PRIVATE_H_ */
