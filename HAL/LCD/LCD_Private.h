/*
 * LCD_Private.h
 *
 *  Created on: Oct 20, 2023
 *      Author: M.Moussa
 */

#ifndef HAL_LCD_LCD_PRIVATE_H_
#define HAL_LCD_LCD_PRIVATE_H_

/* defining Mode */

#define		LCD_4_BIT_MODE	0

#define		LCD_8_BIT_MODE	1
/*****************************************************************************/

static void LCD_WRITEINSTRACTION(u8 instraction);

static void LCD_WRITEDATA(u8 data);

static void private(u8 num);


#endif /* HAL_LCD_LCD_PRIVATE_H_ */
