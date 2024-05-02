/*
 * FIGER_PRINT_Interface.h
 *
 *  Created on: Mar 22, 2024
 *      Author: Super Magic
 */

#ifndef FIGER_PRINT_INTERFACE_H_
#define FIGER_PRINT_INTERFACE_H_


u8 FingerPS_AuraControl(void);
#if    FINGERPRINT_MODE == FINGERPRINT_SYCH

u8 FingerPS_handShake(void) ;
u8 FingerPS_genImg(void);
u8 FingerPS_convertImg1CharFile(void);
u8 FingerPS_convertImg2CharFile(void);
u8 FingerPS_genTemplate(void);
u8 FingerPS_strTemplate(void);
u8 FingerPS_searchFinger(void);
u8 FingerPS_emptyLibrary(void);
u8 FingerPS_deleteFinger(void);
u8 FingerPS_LoadCharFile(void);
u8 FingerPS_calcCheckSum(void);
u8 FingerPS_match(void);



void ReceiveFun(void);

#elif	FINGERPRINT_MODE == FINGERPRINT_ASYCH

void FingerPS_handShake(void) ;
void FingerPS_genImg(void);
void FingerPS_convertImg1CharFile(void);
void FingerPS_convertImg2CharFile(void);
void FingerPS_genTemplate(void);
void FingerPS_strTemplate(void);
void FingerPS_searchFinger(void);
void FingerPS_emptyLibrary(void);
void FingerPS_deleteFinger(void);
void FingerPS_LoadCharFile(void);
u8 FingerPS_calcCheckSum(void);
void FingerPS_match(void);



#endif


#endif /* FIGER_PRINT_INTERFACE_H_ */
