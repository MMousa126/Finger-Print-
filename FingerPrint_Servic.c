/*
 * FingerPrint_Servic.c
 *
 *  Created on: Mar 28, 2024
 *      Author: M.Moussa
 */

#include "StdTypes.h"
#include "FingerPrint_Servic.h"
#include "HAL/FINGER PRINT/FIGER_PRINT_Interface.h"
#include <util/delay.h>


u8 FingerPrint_EnrollmentFSFunc(void)
{

	FingerPS_AuraControlPurple();
	u8 local = 0;

	if (FingerPS_handShake() == 0)
	{

	}
	else
	{
		local = 1;
		return local;
	}



	LCD_WRITESTRING((u8*)"put Your Finger");
	LCD_SETCURSOR(1, 0);
	LCD_WRITESTRING((u8*)"Don't Remove");
	_delay_ms(2000);

	while (FingerPS_genImg() != 0);
	if ( FingerPS_genImg() == 0 )
	{

	}
	else
	{
		local = 2;
		return local;
	}
	if ( FingerPS_convertImg1CharFile() == 0)
	{

	}
	else
	{
		local = 3 ;
		return local;
	}

	if (FingerPS_genImg() == 0 )
	{

	}
	else
	{
		local = 4;
		return local;

	}
	if ( FingerPS_convertImg2CharFile() == 0)
	{

	}
	else
	{
		local = 5 ;
		return local;
	}
	if (FingerPS_genTemplate() == 0 )
	{

	}
	else
	{
		local = 6;
		return local;
	}
	if ( FingerPS_strTemplate() == 0)
	{

	}
	else
	{
		local = 7;
		return local;

	}



	return local;


}
u8 FingerPrint_MatchFunc(void)
{


	u8 local = 0;
	LCD_CLEAR();

	LCD_WRITESTRING("put to match");

	while(FingerPS_genImg() != 0);

	if(FingerPS_genImg() == 0)
	{

	}
	else
	{
		local = 1;
	}

	/* put generated image to be store in char file 2*/
	if (FingerPS_convertImg2CharFile() == 0)
	{

	}
	else
	{
		local =2;
	}
	if (FingerPS_LoadCharFile() == 0)
	{


	}
	else
	{
		local = 3;
	}
	if ( FingerPS_match() == 0)
	{

	}
	else
	{
		local = 4;
	}

	return local ;
}

