/*
 * init_ADC.h
 *
 * Created: 4/8/2024 11:32:24 PM
 *  Author: Moamen
 */ 


#ifndef INIT_ADC_H_
#define INIT_ADC_H_


void init_ADC(void)
{
	ADMUX |= (1<<REFS0);								//Voltage reference from AVCC
	ADCSRA |= (1<<ADEN);								//Turn on ADC
	ADCSRA |= (1<<ADSC);								//Start conversion from analog to digital
	ADCSRA |= ((1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0));		//8Mhz/128 = 62.5Khz which is the ADC reference clock
}


#endif /* INIT_ADC_H_ */