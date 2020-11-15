#include <avr/io.h>
#include <util/delay.h>
#include "serial.h"



void main (void) {

	uart_init();

	DDRB |= (1 << 0); // making the zero bit an output

	while (1) {
		PORTB |=00000001; //LED high
		_delay_ms(500);
		PORTB &=00000000;//LED low
		_delay_ms(500);
		uart_putchar('a');
		uart_echo();
		uart_putstr("Enoc\r");
	}
}
