/*
 * ohm.h
 *
 * Created: 4/8/2024 11:43:13 PM
 *  Author: Moamen
 */ 


#ifndef OHM_H_
#define OHM_H_


void ohm(void)				//Sub routine to read resistance
{
	char R_output[6] = {' '};
	float resistance = 0;
	int vout = ADC_Read(1);					//Read from ADC1
	float real_vout = vout*0.00488;			//To get the real value from the ADC (0.00488 = Vref/(2^#ADC bits))
		
	if(PORTD==0b00000111)
		resistance = (real_vout*185)/(5-real_vout);
	else if(PORTD==0b01000111)
		resistance = (real_vout*20085)/(5-real_vout);
	else if(PORTD==0b10000111)
		resistance = (real_vout*500e3)/(5-real_vout);
	else if(PORTD==0b11000111)
		resistance = (real_vout*1e6)/(5-real_vout);
	
	LCD_sendCommand(0x80);							//bring cursor to position 0 of line 0
	LCD_displayString("R =");
	_delay_ms(5);
	
	if(resistance>=1000 && resistance<1e6)
	{
		resistance=resistance/1000;
		sprintf(R_output,"%.2f",resistance);	//Float(resistance) to char(R_output) conversion for printing
												//(%.2f) means that it will take 2 digits after the dot
		LCD_sendCommand(0x84);
		LCD_displayString("        ");					//clear previous result
		_delay_ms(5);
		LCD_sendCommand(0x84);							//bring cursor to position 4 of line 0
		LCD_displayString(R_output);
		LCD_sendCommand(0x8c);							//bring cursor to position 12 of line 0
		LCD_displayString("KOhm");
		_delay_ms(5);
	}
	else if(resistance>=1e6)
	{
		resistance=resistance/1e6;
		sprintf(R_output,"%.2f",resistance);	//Float(resistance) to char(R_output) conversion for printing
												//(%.2f) means that it will take 2 digits after the dot
		LCD_sendCommand(0x84);
		LCD_displayString("        ");					//clear previous result
		_delay_ms(5);
		LCD_sendCommand(0x84);							//bring cursor to position 4 of line 0
		LCD_displayString(R_output);
		LCD_sendCommand(0x8c);							//bring cursor to position 12 of line 0
		LCD_displayString("MOhm");
		_delay_ms(5);
	}
	else
	{
		sprintf(R_output,"%.2f",resistance);			//Float(resistance) to char(R_output) conversion for printing
														//(%.2f) means that it will take 2 digits after the dot
		LCD_sendCommand(0x84);
		LCD_displayString("        ");					//clear previous result
		_delay_ms(5);
		LCD_sendCommand(0x84);							//bring cursor to position 4 of line 0
		LCD_displayString(R_output);
		LCD_sendCommand(0x8c);							//bring cursor to position 12 of line 0
		LCD_displayString("Ohm ");
		_delay_ms(5);
	}
}


#endif /* OHM_H_ */