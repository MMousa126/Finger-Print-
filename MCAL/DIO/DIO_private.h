/*
 * DIO_private.h
 *
 * Created: 10/31/2022 10:35:33 PM
 *  Author: lenovo
 */ 


#ifndef DIO_PRIVATE_H_
#define DIO_PRIVATE_H_

extern const DIO_PinStatus_type PinsStatusArray[TOTAL_PINS];
static void DIO_InitPin(DIO_Pin_type pin,DIO_PinStatus_type status);

#define  CelTOKilven   273


#endif /* DIO_PRIVATE_H_ */