/*
 * LCD.c
 *
 *  Created on: Oct 19, 2023
 *      Author: M.Moussa
 */
#include "../../StdTypes.h"
#include "../../Utils.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "LCD_Interface.h"
#include "LCD_Config.h"
#include "LCD_Private.h"
#include <util/delay.h>

/* write on DDRAM */

#if 	LCD_MODE == LCD_4_BIT_MODE

/* LCD 4 bit Mode */
static void LCD_WRITEINSTRACTION(u8 instraction) {

	DIO_WritePin(RS, LOW);


	/* so here we will get bit for every data that will be entered to lcd */
	/* i do that becouse i want to be generic and be able to put the pins any where i want */

	DIO_WritePin(D7, READ_BIT(instraction, 7));
	DIO_WritePin(D6, READ_BIT(instraction, 6));
	DIO_WritePin(D5, READ_BIT(instraction, 5));
	DIO_WritePin(D4, READ_BIT(instraction, 4));

	DIO_WritePin(EN, HIGH);
	_delay_ms(1);
	DIO_WritePin(EN, LOW);
	_delay_ms(1);

	DIO_WritePin(D7, READ_BIT(instraction, 3));
	DIO_WritePin(D6, READ_BIT(instraction, 2));
	DIO_WritePin(D5, READ_BIT(instraction, 1));
	DIO_WritePin(D4, READ_BIT(instraction, 0));

	DIO_WritePin(EN, HIGH);
	_delay_ms(1);
	DIO_WritePin(EN, LOW);
	_delay_ms(1);
}

static void LCD_WRITEDATA(u8 data) {

	DIO_WritePin(RS, HIGH);

	/* so here we will get bit for every data that will be entered to lcd */
	/* i do that becouse i want to be generic and be able to put the pins any where i want */

	DIO_WritePin(D7, READ_BIT(data, 7));
	DIO_WritePin(D6, READ_BIT(data, 6));
	DIO_WritePin(D5, READ_BIT(data, 5));
	DIO_WritePin(D4, READ_BIT(data, 4));

	DIO_WritePin(EN, HIGH);
	_delay_ms(1);
	DIO_WritePin(EN, LOW);
	_delay_ms(1);

	DIO_WritePin(D7, READ_BIT(data, 3));
	DIO_WritePin(D6, READ_BIT(data, 2));
	DIO_WritePin(D5, READ_BIT(data, 1));
	DIO_WritePin(D4, READ_BIT(data, 0));

	DIO_WritePin(EN, HIGH);
	_delay_ms(1);
	DIO_WritePin(EN, LOW);
	_delay_ms(1);
}

void LCD_INIT(void) {

	_delay_ms(50);
	LCD_WRITEINSTRACTION(0x02);
	LCD_WRITEINSTRACTION(0x28);
	LCD_WRITEINSTRACTION(0x0c);
	LCD_WRITEINSTRACTION(0x01);
	_delay_ms(1);
	LCD_WRITEINSTRACTION(0x06);

}

#elif	LCD_MODE == LCD_8_BIT_MODE
/* LCD 8 bit Mode */
static void LCD_WRITEINSTRACTION(u8 instraction) {

	DIO_WritePin(RS, LOW);
	DIO_WritePort(LCD_PORT, instraction); //0x38 -> f&n in datasheet
	DIO_WritePin(EN, HIGH); // for enabling trigger to micro of lcd to receive data from our micro
	_delay_ms(1);
	DIO_WritePin(EN, LOW); // have to trigger to low to tell that iam not sending data or finished reciving
	_delay_ms(1); // to know that's one massage
}

static void LCD_WRITEDATA(u8 data) {

	DIO_WritePin(RS, HIGH);
	DIO_WritePort(LCD_PORT, data); //0x38 -> f&n in datasheet
	DIO_WritePin(EN, HIGH); // for enabling trigger to micro of lcd to receive data from our micro
	_delay_ms(1);
	DIO_WritePin(EN, LOW); // have to trigger to low to tell that iam not sending data or finished reciving
	_delay_ms(1); // to know that's one massage
}

void LCD_INIT(void) {

	/***********************************//*Function Set*//****************************/
	_delay_ms(50);

	LCD_WRITEINSTRACTION(0b00111000);
	/***********************************//*Display on/off control*//******************/

	LCD_WRITEINSTRACTION(0b00001100);
	/***********************************//*Clear Screen*//*********   ****************/

	LCD_WRITEINSTRACTION(0b00000001);
	_delay_ms(1);
	/***********************************//*Enter Mode Set*//**************************/

	LCD_WRITEINSTRACTION(0b00000110);

}
#endif



void LCD_CLEAR(void) {

	LCD_WRITEINSTRACTION(0x01);
	_delay_ms(2);

}

void LCD_WRITENUMBER(s32 num) // 2504
{
	u8 i = 0, str[16];
	s8 j;

	if (num == 0) {
		LCD_WRITECHAR('0');
		return;
	}
	if (num < 0) {
		LCD_WRITECHAR('-');
		num = num * (-1);
	}
	while (num) {
		str[i] = (num % 10) + '0';
		num = num / 10;
		i++;
	}
	for (j = i - 1; j >= 0; j--) {
		LCD_WRITECHAR(str[j]);
	}
	
}



void LCD_WRITECHAR(u8 character) {

	LCD_WRITEDATA(character);
}

void LCD_WRITESTRING(c8*string) {


	u8 i;
	for (i = 0; string[i]; i++) {
		LCD_WRITECHAR(string[i]);
	}

}

void LCD_WRITEBINARY(u8 number) {

	u8 i;
	LCD_WRITESTRING("0b");
	for (i = sizeof(u8) * 8; i > 0; i--) {

		if (READ_BIT(number,i) == 1) {
			LCD_WRITECHAR('1');
		} else {
			LCD_WRITECHAR('0');
		}
	}
}

static void private(u8 num) {
	switch (num) {
	case 10:
		LCD_WRITECHAR('A');
		break;
	case 11:
		LCD_WRITECHAR('B');
		break;
	case 12:
		LCD_WRITECHAR('C');
		break;
	case 13:
		LCD_WRITECHAR('D');
		break;
	case 14:
		LCD_WRITECHAR('E');
		break;
	case 15:
		LCD_WRITECHAR('F');
		break;
	default:
		LCD_WRITENUMBER(num);
		break;
	}
}

void LCD_WRITEHEX(u8 number) {

	LCD_WRITESTRING("0x");
	u8 i, j = 0, sum = 0, res = 0;
	u8 str_iterate[4] = { 1, 2, 4, 8 };
	u8 str[8];
	for (i = 0; i < 8; i++) {
		str[i] = READ_BIT(number, i);
	}

	for (i = 4; i < 8; i++) {
		if (str[i] == 1) {
			res = res + (str[i] * str_iterate[j]);
		}
		j++;
	}
private(res);
	j = 0;

	for (i = 0; i < 4; i++) {
		if (str[i] == 1) {
			sum = sum + (str[i] * str_iterate[j]);
		}
		j++;
	}
private(sum);

}

#define LCD_R0_COMMAND                0x80
#define LCD_R1_COMMAND                0xC0
#define LCD_R2_COMMAND                0x94
#define LCD_R3_COMMAND                0xD4

void LCD_SETCURSOR(u8 line, u8 cell) {

	/*u8 address = 0;

	if (line == FIRST_LINE) {
		address = cell;
	} else if (line == SECOND_LINE) {
		address = cell + 0x40;
	}
	 LCD_WRITEINSTRACTION(address + 128);*/

	/* or */
//	if (line == FIRST_LINE) {
//		LCD_WRITEINSTRACTION(cell | 128); // -> cell + 128
//	} else if (line == SECOND_LINE) {
//		LCD_WRITEINSTRACTION(0x40 | cell | 128);
//}

	u8 Local_U8_Arr [4] = {LCD_R0_COMMAND , LCD_R1_COMMAND , LCD_R2_COMMAND , LCD_R3_COMMAND};
	LCD_WRITEINSTRACTION(Local_U8_Arr[line] + cell);
}

void LCD_WRITENUMBER_4DIGITE(u16 number) {

	u8 i = 0, j = 0;
	u8 str[4];

	if (number <= 9999) {
		for (i = 0; i < 4; i++) {
			str[3 - i] = number % 10 + '0';
			number = number / 10;
		}
	}
	else {
		number = number / 10;
		for (i = 0; i < 4; i++) {
			str[3 - i] = number % 10 + '0';
			number = number / 10;
		}
	}
	for (j = 0; j < 4; j++) {
		LCD_WRITECHAR(str[j]);
	}

}

void LCD_CLEARPOSITION(u8 line, u8 cell, u8 numofcells) {
	LCD_SETCURSOR(line, cell);
	for (u8 i = 0; i < numofcells; i++) {
		LCD_WRITECHAR(' ');
	}
	
}

// writing inside CGRAM -> have to had address of the position i want to write in
void LCD_WRITEPATTERN(u8* pattern, u8 blocknumber, u8 line, u8 cell) {


	// block number between 1 to 8

	u8 i, address = 0;

	address = blocknumber * 8; // position to not overwrite on the same position

	LCD_WRITEINSTRACTION(address + 64);

	for (i = 0; i < 8; i++) {

		LCD_WRITEDATA(pattern[i]);
	}

	LCD_SETCURSOR(line, cell);

	LCD_WRITEDATA(blocknumber);
}
