#include <avr/io.h>
#include <util/delay.h>
#include "display.h"

void init_I2C() {
	// Configura frequência I2C para 100kHz
	TWBR = 72;
	TWCR = (1 << TWEN);  // Liga o TWI
}

void start_I2C() {
	TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);
	while (!(TWCR & (1 << TWINT)));
}

void stop_I2C() {
	TWCR = (1 << TWINT) | (1 << TWSTO) | (1 << TWEN);
}

void data_I2C(int data) {
	TWDR = data;
	TWCR = (1 << TWINT) | (1 << TWEN);
	while (!(TWCR & (1 << TWINT)));
}

void comando_LCD(int data) {
	data |= 0x08;

	start_I2C();
	data_I2C(0x27 << 1);
	data_I2C(data | 0x04);
	_delay_us(1);
	data_I2C(data & ~0x04);
	_delay_us(100);
	stop_I2C();
}

void LCD_SendByte(uint8_t rs, uint8_t data) {
	uint8_t high_nibble = (data & 0xF0) | rs;
	uint8_t low_nibble = ((data << 4) & 0xF0) | rs;

	comando_LCD(high_nibble);
	comando_LCD(low_nibble);
}

void LCD_Command(uint8_t cmd) {
	LCD_SendByte(0x00, cmd);  // RS = 0 (comando)
}

void LCD_Char(char data) {
	LCD_SendByte(0x01, data);  // RS = 1 (dados)
}

void init_LCD(void) {
	_delay_ms(10);
	LCD_Command(0x03);
	_delay_ms(5);
	LCD_Command(0x03);
	_delay_us(150);
	LCD_Command(0x03);
	LCD_Command(0x02); // Modo de 4 bits

	LCD_Command(0x28);  // Função: 2 linhas, 5x8 pontos
	LCD_Command(0x0C);  // Display ON, cursor OFF
	LCD_Command(0x06);  // Incrementa o cursor
	LCD_Command(0x01);  // Limpa o display
	LCD_Command(0x80 | 0x00);
	_delay_ms(2);
}

void LCD_String(char *str) {
	while (*str) {
		LCD_Char(*str++);
	}
}

