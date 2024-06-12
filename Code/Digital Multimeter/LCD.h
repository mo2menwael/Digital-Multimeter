/*
 * LCD.h
 *
 * Created: 4/8/2024 11:34:22 PM
 *  Author: Moamen
 */ 


#ifndef LCD_H_
#define LCD_H_


#define LCD_port PORTC				//port C is selected as LCD Data port
#define rs PA4						//Register Select signal is connected to port C pin 4
#define en PA5						//Enable signal is connected to port C pin 5

void LCD_displayString(char *txt)         //Data sub routine LCD
{
	while(*txt!='\0')
	{
		// Send higher nibble
		LCD_port = (*txt & 0xF0);		// Mask lower nibble, send higher nibble
		PORTA |= (1<<rs);				// RS = 1 for data
		PORTA |= (1<<en);				// Enable high
		_delay_ms(5);					// Short delay
		PORTA &= ~(1<<en);				// Enable low
		
		// Send lower nibble
		LCD_port = ((*txt << 4) & 0xF0); // Shift lower nibble to higher nibble position
		PORTA |= (1<<en);                // Enable high
		_delay_ms(5);                    // Short delay
		PORTA &= ~(1<<en);               // Enable low
		_delay_ms(10);                   // Wait for the data to write
		txt++;
	}
}

void LCD_sendCommand(char cmd)           //Command sub routine LCD
{
	// Send higher nibble
	LCD_port = (cmd & 0xF0);		// Mask lower nibble, send higher nibble
	PORTA &= ~(1<<rs);				// RS = 0 for command
	PORTA |= (1<<en);				// Enable high
	_delay_ms(5);					// Short delay
	PORTA &= ~(1<<en);				// Enable low
	
	// Send lower nibble
	LCD_port = ((cmd << 4) & 0xF0); // Shift lower nibble to higher nibble position
	PORTA |= (1<<en);               // Enable high
	_delay_ms(5);                   // Short delay
	PORTA &= ~(1<<en);              // Enable low
	_delay_ms(10);                  // Wait for the command to execute
}

void LCD_clearScreen(void)
{
	LCD_sendCommand(0x01);
}

#endif /* LCD_H_ */