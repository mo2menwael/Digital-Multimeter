/*
 * ACcurrent.h
 *
 * Created: 4/8/2024 11:42:10 PM
 *  Author: Moamen
 */ 


#ifndef ACCURRENT_H_
#define ACCURRENT_H_

#define AC0DC PD5
void ACcurrent(void)			  //Sub routine to read current
{
	PORTD &= ~(1<<AC0DC);					//Set AC0DC(PD5) to zero to choose AC mode
	_delay_ms(50);
	char Ioutput[6] = {' '};
	float the_current = 0;
	int vout = ADC_Read(0);					//Read from ADC0
	float real_vout = vout*0.00488;			//To get the real value from the ADC (0.00488 = Vref/(2^#ADC bits))
	
	if(PORTD==0b11010100)
		the_current = real_vout/0.02;
	else if(PORTD==0b11010101)
		the_current = (real_vout-0.32)/0.2;
	else if(PORTD==0b11010110)
		the_current = (real_vout-0.3)/1.955;
	
	sprintf(Ioutput,"%.2f",the_current);	//Float(real_vout) to char(Ioutput) conversion for printing
											//(%.2f) means that it will take 2 digits after the dot
	LCD_sendCommand(0x82);							//bring cursor to position 2 of line 0
	LCD_displayString("I =");
	_delay_ms(50);
	LCD_sendCommand(0x86);
	LCD_displayString("      ");						//clear previous result
	_delay_ms(50);
	LCD_sendCommand(0x86);							//bring cursor to position 6 of line 0
	LCD_displayString(Ioutput);
	LCD_sendCommand(0x8d);							//bring cursor to position 13 of line 0
	LCD_displayString("mA");
	_delay_ms(50);
	LCD_sendCommand(0xc0);							//clear 2nd line
	LCD_displayString("                ");
	_delay_ms(50);
}


#endif /* ACCURRENT_H_ */