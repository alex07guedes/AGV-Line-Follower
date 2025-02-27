#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdlib.h>
#include "sensores_linha/sensores_linha.h"
#include "sensores_ultrassom/sensores_ultrassom.h"
#include "encoders/encoders.h"
#include "display/display.h"
#include "motores/motores.h"
#include "LED/LED.h"

int main(void) {
	init_linha();
	init_wave();
	init_motores();
	init_I2C();
	init_LCD();
	init_encoders();
	init_timer1();
	
	init_ultrasonic();
	sei();
	
	char buffer_esq[16];
	char buffer_dir[16];
	int curva_esq = 0, frente = 0, curva_dir = 0;

	while (1) {
		
		
		int distancia = measure_distance();

		if (distancia == 0) {
			reset_sensor(); 
		}

		if (distancia > 0 && distancia < 10) {
			motor_esquerdo(0, 0);
			motor_direito(0, 0);
		} 
		else if (distancia >= 10 && distancia <= 20) {
			motor_esquerdo(1, 130);
			motor_direito(1, 130);
		}
		else {
				if ((sensor[0] == 1 && sensor[1] == 0 && sensor[2] == 1) ||
				(sensor[0] == 0 && sensor[1] == 0 && sensor[2] == 0) ||
				(sensor[0] == 0 && sensor[1] == 0 && sensor[2] == 1) ||
				(sensor[0] == 1 && sensor[1] == 0 && sensor[2] == 0)) {
					motor_direito(1, 165);
					motor_esquerdo(1, 165);
					frente = 1;
					curva_esq = 0;
					curva_dir = 0;
					} else if ((sensor[0] == 0 && sensor[1] == 1 && sensor[2] == 1) || (sensor[0] == 0 && sensor[1] == 0 && sensor[2] == 1)) {
					motor_direito(1, 165);
					motor_esquerdo(0, 0);
					curva_esq = 1;
					frente = 0;
					curva_dir = 0;
					} else if ((sensor[0] == 1 && sensor[1] == 1 && sensor[2] == 0) || (sensor[0] == 1 && sensor[1] == 0 && sensor[2] == 0)) {
					motor_direito(0, 0);
					motor_esquerdo(1, 165);
					curva_dir = 1;
					curva_esq = 0;
					curva_dir = 0;
				}
			}
				
		LCD_Command(0x80);  
		LCD_String("Velocidade cm/s");

		dtostrf(velocidade_esq, 5, 2, buffer_esq); 
		dtostrf(velocidade_dir, 5, 2, buffer_dir);
		LCD_Command(0xC0); 
		LCD_String("L");
		LCD_String(buffer_esq);
		LCD_String(" R");
		LCD_String(buffer_dir);
	}
}


