/*
 * init_LCD.h
 *
 * Created: 4/8/2024 11:38:59 PM
 *  Author: Moamen
 */ 


#ifndef INIT_LCD_H_
#define INIT_LCD_H_


void init_LCD(void)
{
	LCD_sendCommand(0x02);					//Send for 4-bit initialization of LCD
	LCD_sendCommand(0x28);					//2 line, 5*7 matrix in 4-bit mode
	LCD_clearScreen();						//Clear LCD display
	_delay_ms(5);
	LCD_sendCommand(0x0c);					 //Display on, Cursor off
	_delay_ms(5);
	LCD_sendCommand(0x82);					//Go to first line and 2nd position
	_delay_ms(5);
	LCD_displayString("Which mode ?");
	_delay_ms(20);
	LCD_sendCommand(0x82);				   //Delete previous line
	LCD_displayString("            ");
	_delay_ms(5);
	LCD_sendCommand(0x82);				   //Go to first line and 2nd position
	LCD_displayString("1:Volt 2:Amp");
	_delay_ms(5);
	LCD_sendCommand(0xc6);				   //Go to second line and 6th position
	LCD_displayString("3:Ohm");
	_delay_ms(5);
}


#endif /* INIT_LCD_H_ */