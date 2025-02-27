#include <avr/io.h>
#include <util/delay.h>
#include "sensores_ultrassom.h"

void init_ultrasonic() {
	DDRB |= (1 << PB4);
	DDRB &= ~(1 << PB5);
}

int measure_distance() {

	PORTB &= ~(1 << PB4);
	_delay_us(2);
	PORTB |= (1 << PB4);
	_delay_us(10);
	PORTB &= ~(1 << PB4);

	while (!(PINB & (1 << PB5)));

	int duration = 0;
	while (PINB & (1 << PB5)) {
		_delay_us(1);
		duration++;
		if (duration > 30000) return 0;
	}

	return duration / 58;
}

void reset_sensor() {
	PORTB &= ~(1 << PB4);
	_delay_ms(100);
}
