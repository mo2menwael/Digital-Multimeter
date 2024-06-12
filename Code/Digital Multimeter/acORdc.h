/*
 * acORdc.h
 *
 * Created: 4/8/2024 11:44:11 PM
 *  Author: Moamen
 */ 


#ifndef ACORDC_H_
#define ACORDC_H_


void acORdc(void)
{
	LCD_clearScreen();						//Clear LCD display
	_delay_ms(5);
	LCD_sendCommand(0x0c);					 //Display on, Cursor off
	_delay_ms(5);
	LCD_sendCommand(0x86);					//Go to first line and 6th position
	_delay_ms(5);
	LCD_displayString("+:DC");
	_delay_ms(5);
	LCD_sendCommand(0xc6);					//Go to second line and 6th position
	LCD_displayString("-:AC");
	_delay_ms(5);
}


#endif /* ACORDC_H_ */