#include <avr/io.h>
#include "motores.h"

void init_motores() {
	DDRC |= (1 << PC3) | (1 << PC2); //IN1 e IN4
	DDRB |= (1 << PB2); //IN2
	DDRD |= (1 << PD1); //IN3
	DDRD |= (1 << PD6) | (1 << PD5); //ENA e ENB

	TCCR0A |= (1 << COM0A1) | (1 << COM0B1) | (1 << WGM00) | (1 << WGM01);
	TCCR0B |= (1 << CS00);
}

void motor_esquerdo(int direcao, int velocidade_esquerdo) {
	if (direcao == 1) {
		PORTC |= (1 << PC3);
		PORTB &= ~(1 << PB2);
	} else if (direcao == -1) {
		PORTC &= ~(1 << PC3);
		PORTB |= (1 << PB2);
	} else {
		PORTC &= ~(1 << PC3);
		PORTB &= ~(1 << PB2);
	}
	OCR0A = velocidade_esquerdo;
}

void motor_direito(int direcao, int velocidade_direito) {
	if (direcao == 1) {
		PORTD |= (1 << PD1);
		PORTC &= ~(1 << PC2);
	} else if (direcao == -1) {
		PORTD &= ~(1 << PD1);
		PORTC |= (1 << PC2);
	} else {
		PORTD &= ~(1 << PD1);
		PORTC &= ~(1 << PC2);
	}
	OCR0B = velocidade_direito;
} 
