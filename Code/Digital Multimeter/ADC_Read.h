/*
 * ADC_Read.h
 *
 * Created: 4/8/2024 11:33:13 PM
 *  Author: Moamen
 */ 


#ifndef ADC_READ_H_
#define ADC_READ_H_

uint16_t ADC_Read(uint8_t channel)
{
	unsigned int value;
	ADCSRA |= (1<<ADIF);		//Clear ADIF flag
	_delay_ms(50);
	ADMUX &= 0xF0;				//Clear the previous channel
	ADMUX |= channel;
	ADCSRA |= (1<<ADSC);		//Start new conversion
	while(ADIF==0);				//ADIF is interrupt flag. When it equals 1, it means that the conversion from analog to digital has finished
		value=ADCL|ADCH<<8;		//Shift left ADCH by 8bits then combine it with ADCL with the OR operator "|"
	return value;
}



#endif /* ADC_READ_H_ */