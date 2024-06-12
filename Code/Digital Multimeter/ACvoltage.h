/*
 * ACvoltage.h
 *
 * Created: 4/8/2024 11:40:38 PM
 *  Author: Moamen
 */ 


#ifndef ACVOLTAGE_H_
#define ACVOLTAGE_H_

#define AC0DC PD5
void ACvoltage(void)             //Sub routine to read voltage
{
	PORTD &= ~(1<<AC0DC);				//Set AC0DC(PD5) to zero to choose AC mode
	_delay_ms(50);
	char Voutput[6] = {' '};
	float volt;
	int vout = ADC_Read(0);				//Read from ADC0
	float real_vout = vout*0.00488;		//To get the real value from the ADC (0.00488 = Vref/(2^#ADC bits))
	int diff_gain = 10;
	volt = real_vout*diff_gain;
	
	sprintf(Voutput,"%.2f",volt);		//Float(volt) to char(Voutput) conversion for printing
										//(%.2f) means that it will take 2 digits after the dot
	LCD_sendCommand(0x82);						//bring cursor to position 3 of line 0
	LCD_displayString("V =");
	_delay_ms(5);
	LCD_sendCommand(0x86);
	LCD_displayString("     ");					//clear previous result
	_delay_ms(5);
	LCD_sendCommand(0x86);						//bring cursor to position 7 of line 0
	LCD_displayString(Voutput);
	LCD_sendCommand(0x8d);						//bring cursor to position 12 of line 0
	LCD_displayString("V");
	_delay_ms(5);
	LCD_sendCommand(0xc0);							//clear 2nd line
	LCD_displayString("                ");
	_delay_ms(5);
}


#endif /* ACVOLTAGE_H_ */