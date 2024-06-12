/*
 * Digital Multimeter.c
 *
 * Created: 5/22/2024 5:46:42 PM
 * Author : Moamen
 */ 

#define	F_CPU 8000000UL			//Define CPU 8 MHZ
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdio.h>
#include "LCD.h"
#include "init_LCD.h"
#include "ADC_Read.h"
#include "init_ADC.h"
#include "ACcurrent.h"
#include "ACvoltage.h"
#include "DCcurrent.h"
#include "DCvoltage.h"
#include "ohm.h"
#include "acORdc.h"
#include "keypad_scan.h"

int main()
{
	char key;					//To store the pressed key
	DDRA=0xF0;					//Set first 4 bits of PORTA as an input and the other 4 bits as an output
	DDRD=0xFF;					//Set PORTD(MUX Selectors) as an output
	PORTD=0b11000110;			//Initialize PORTD
	DDRB=0x0F;					//Set PORTB first half(rows) as an output and the second half as an input(columns)
	PORTB=0xF0;					//Enable pull-up resistance
	
	init_LCD();					//Initialize LCD
	_delay_ms(10);
	init_ADC();					//Initialize ADC
	
	while (1)
	{
		key = keypad_scan();		//Scan the keypad
		if(key != '\0') {
			switch (key) {
				case '1':			//Voltmeter
				{
					PORTD=0b11001011;
					acORdc();
				}
				break;
				case '2':			//Ammeter
				{
					LCD_clearScreen();						 //Clear LCD display
					_delay_ms(5);
					LCD_sendCommand(0x0c);					 //Display on, Cursor off
					_delay_ms(5);
					LCD_sendCommand(0x82);					//Go to first line and 2nd position
					_delay_ms(5);
					LCD_displayString("7:2mA 8:20mA");
					_delay_ms(5);
					LCD_sendCommand(0xc5);					//Go to second line and 5th position
					LCD_displayString("9:200mA");
					_delay_ms(5);
				}
				break;
				case '3':			//Ohmmeter
				{
					LCD_clearScreen();						 //Clear LCD display
					_delay_ms(5);
					LCD_sendCommand(0x0c);					 //Display on, Cursor off
					_delay_ms(5);
					LCD_sendCommand(0x82);					//Go to first line and 2nd position
					_delay_ms(5);
					LCD_displayString("4:550 5:500K");
					_delay_ms(5);
					LCD_sendCommand(0xc3);					//Go to second line and 3rd position
					LCD_displayString("6:1M *:10M");
					_delay_ms(5);

				}
				break;
				case '7':			//2mA max.
				{
					PORTD=0b11010110;
					acORdc();
				}
				break;
				case '8':			//20mA max.
				{
					PORTD=0b11010101;
					acORdc();
				}
				break;
				case '9':			//200mA max.
				{
					PORTD=0b11010100;
					acORdc();
				}
				break;
				case '4':			//550 ohm
				{
					PORTD=0b00000111;
					LCD_clearScreen();
					while(key=='4' || key=='\0')
						{key = keypad_scan(); ohm();}
				}
				break;
				case '5':			//500k ohm
				{
					PORTD=0b01000111;
					LCD_clearScreen();
					while(key=='5' || key=='\0')
						{key = keypad_scan(); ohm();}
				}
				break;
				case '6':			//1M ohm
				{
					PORTD=0b10000111;
					LCD_clearScreen();
					while(key=='6' || key=='\0')
						{key = keypad_scan(); ohm();}
				}
				break;
				case '*':			//10M ohm
				{
					PORTD=0b11000111;
					LCD_clearScreen();
					while(key=='*' || key=='\0')
						{key = keypad_scan(); ohm();}
				}
				break;
				case '+':				//DC
				{
					if(PORTD==0b11010110 || PORTD==0b11010101 || PORTD==0b11010100)
					{
						while(key=='+' || key=='\0')
							{key = keypad_scan(); DCcurrent();}
					}
					else if(PORTD==0b11001011)
					{
						while(key=='+' || key=='\0')
							{key = keypad_scan(); DCvoltage();}
					}
				}
				break;
				case '-':				//AC
				{
					if(PORTD==0b11010110 || PORTD==0b11010101 || PORTD==0b11010100)
					{
						while(key=='-' || key=='\0')
							{key = keypad_scan(); ACcurrent();}
					}
					else if(PORTD==0b11001011)
					{
						while(key=='-' || key=='\0')
							{key = keypad_scan(); ACvoltage();}
					}
				}
				break;
			}
			_delay_ms(50);	//To avoid multiple clicks on the keypad
		}
	}
	return 0;
}


