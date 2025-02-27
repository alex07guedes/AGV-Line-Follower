#include <avr/io.h>
#include <avr/interrupt.h>
#include "encoders.h"

volatile unsigned int voltas_esq = 0;
volatile unsigned int voltas_dir = 0;
volatile float velocidade_esq = 0.0; 
volatile float velocidade_dir = 0.0;

void init_encoders() {
	DDRD &= ~((1 << PD2) | (1 << PD3));  
	EICRA |= (1 << ISC00) | (1<< ISC10);   
	EIMSK |= (1 << INT0) | (1 << INT1);  
}

void init_timer1() {
	TCCR1B = (1 << WGM12) | (1 << CS12);  
	OCR1B = 31249; 
	TIMSK1 = (1 << OCIE1B); 
}

ISR(INT0_vect) {
	voltas_esq++; 
}

ISR(INT1_vect) {
	voltas_dir++;
}

ISR(TIMER1_COMPB_vect) {
	velocidade_esq = ((float)voltas_esq / 20) * (2 * 3.1415 * 0.68) / 0.5;
	velocidade_dir = ((float)voltas_dir / 20) * (2 * 3.1415 * 0.68) / 0.5;
	
	voltas_esq = 0; 
	voltas_dir = 0; 
}
