/*
. * LCD_Config.h
 *
 *  Created on: Oct 20, 2023
 *      Author: M.Moussa
 */

#ifndef HAL_LCD_LCD_CONFIG_H_
#define HAL_LCD_LCD_CONFIG_H_

/* defining Mode */
/* 4BIT OR 8 BIT*/

#define		LCD_MODE	LCD_4_BIT_MODE

/*****************************************************************************/

/* 8 bit mode only */
#define 	RS			PINA3

#define 	EN			PINA2


#define		LCD_PORT	PA

/****************************************************************************/

/* LCD 4bit Mode */

#define 	D7			PINB4

#define 	D6   		PINB2

#define 	D5			PINB1

#define 	D4			PINB0

#endif /* HAL_LCD_LCD_CONFIG_H_ */
