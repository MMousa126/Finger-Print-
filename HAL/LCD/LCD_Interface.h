/*
 * LCD_Interface.h
 *
 *  Created on: Oct 19, 2023
 *      Author: M.Moussa
 */

#ifndef HAL_LCD_LCD_INTERFACE_H_
#define HAL_LCD_LCD_INTERFACE_H_
#include "../../StdTypes.h"
#define 	FIRST_LINE		0
#define 	SECOND_LINE		1

void LCD_INIT(void);

void LCD_CLEAR(void);

void LCD_WRITENUMBER(s32 num);

void LCD_WRITECHAR(u8 character);

void LCD_WRITESTRING(c8*string);

void LCD_WRITEBINARY(u8 number);

void LCD_WRITEHEX(u8 number);

//* line between 0:1 & cell between 0:15 *//
void LCD_SETCURSOR(u8 line, u8 cell);

void LCD_WRITENUMBER_4DIGITE(u16 number);

void LCD_CLEARPOSITION(u8 line, u8 cell, u8 numofcells);

void LCD_WRITEPATTERN(u8* pattern, u8 blocknumber, u8 line, u8 cell);

#endif /* HAL_LCD_LCD_INTERFACE_H_ */
