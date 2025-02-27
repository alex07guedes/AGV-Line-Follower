#include <avr/io.h>
#include "LED.h"

void init_wave() {
	DDRB |= (1<<PB1);
	
	TCCR1A |= (1<<COM1A0);
	TCCR1B |= (1<<WGM12) | (1<<CS12);

	OCR1A = 31249;
}