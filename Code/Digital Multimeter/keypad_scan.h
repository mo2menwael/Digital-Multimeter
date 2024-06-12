/*
 * keypad_scan.h
 *
 * Created: 4/8/2024 11:31:18 PM
 *  Author: Moamen
 */ 


#ifndef KEYPAD_SCAN_H_
#define KEYPAD_SCAN_H_

#define KEYPAD_PORT PORTB
#define KEYPAD_PIN PINB
#define KEYPAD_DDR DDRB

char keypad_scan(void)
{
	KEYPAD_PORT = 0b11111110;
	if((KEYPAD_PIN & (1<<PINB4))==0)
	{
		_delay_ms(3);
		return '7';
	}
	else if((KEYPAD_PIN &(1<<PINB5))==0)
	{
		_delay_ms(3);
		return '8';
	}
	else if((KEYPAD_PIN & (1<<PINB6))==0)
	{
		_delay_ms(3);
		return '9';
	}
	else if((KEYPAD_PIN & (1<<PINB7))==0)
	{
		_delay_ms(3);
		return '/';
	}
	KEYPAD_PORT = 0b11111101;
	if((KEYPAD_PIN & (1<<PINB4))==0)
	{
		_delay_ms(3);
		return '4';
	}
	else if((KEYPAD_PIN & (1<<PINB5))==0)
	{
		_delay_ms(3);
		return '5';
	}
	else if((KEYPAD_PIN & (1<<PINB6))==0)
	{
		_delay_ms(3);
		return '6';
	}
	else if((KEYPAD_PIN & (1<<PINB7))==0)
	{
		_delay_ms(3);
		return '*';
	}
	KEYPAD_PORT = 0b11111011;
	if((KEYPAD_PIN & (1<<PINB4))==0)
	{
		_delay_ms(3);
		return '1';
	}
	else if((KEYPAD_PIN & (1<<PINB5))==0)
	{
		_delay_ms(3);
		return '2';
	}
	else if((KEYPAD_PIN & (1<<PINB6))==0)
	{
		_delay_ms(3);
		return '3';
	}
	else if((KEYPAD_PIN & (1<<PINB7))==0)
	{
		_delay_ms(3);
		return '-';
	}
	KEYPAD_PORT = 0b11110111;
	if((KEYPAD_PIN & (1<<PINB4))==0)
	{
		_delay_ms(3);
		return 'C';
	}
	else if((KEYPAD_PIN & (1<<PINB5))==0)
	{
		_delay_ms(3);
		return '0';
	}
	else if((KEYPAD_PIN & (1<<PINB6))==0)
	{
		_delay_ms(3);
		return '=';
	}
	else if((KEYPAD_PIN & (1<<PINB7))==0)
	{
		_delay_ms(3);
		return '+';
	}
	
	return '\0';
}



#endif /* KEYPAD_SCAN_H_ */