

#include <avr/io.h>
#include <avr/interrupt.h>
#include "sensores_linha.h"

volatile int sensor[3] = {0, 0, 0};

void init_linha() {
	DDRB &= ~(1 << PB0);
	DDRD &= ~((1 << PD0) | (1 << PD7));
	
	PCICR |= (1 << PCIE0) | (1 << PCIE2);

	PCMSK0 |= (1 << PCINT0);
	PCMSK2 |= (1 << PCINT16) | (1 << PCINT23);
}

ISR(PCINT0_vect) {
	if (PINB & (1 << PB0)) {
		sensor[0] = 1;
	}
	else{
		sensor[0] = 0;
	}
}

ISR(PCINT2_vect) {
	if (PIND & (1 << PD0)) {
		sensor[1] = 1;
	}
	else {
		sensor[1] = 0;
	}
	if (PIND & (1 << PD7)) {
		sensor[2] = 1;
	}
	else {
		sensor[2] = 0;
	}
}