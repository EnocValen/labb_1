#include <avr/io.h>
#include <util/delay.h>

#include "serial.h"


void uart_init(void) {
	/*Set baud rate */
	UBRR0H = (uint8_t)(25 >> 8);
	UBRR0L = (uint8_t)(25 & 0xff);
	/*Enable receiver and transmitter */
		UCSR0B |= (1 << RXEN0) | (1 << TXEN0);
	/* Set frame format: 8data, 1stop bit */
	UCSR0C = (1 << UCSZ01) | (3 << UCSZ00);

}

void uart_putstr(char text[])
{
	int i = 0;
	while (i<255) //less than max value
	{
		if (text[i] == '\0')break; //if array comes to an end then break
		uart_putchar(text[i]);//uses putchar to send one char at a time
		i++;
	}
}

void uart_putchar(char chr) {
	while (!(UCSR0A & (1 << UDRE0)));
	
		if (chr == '\n') {
			UDR0 = '\r';

			while (!(UCSR0A & (1 << UDRE0)));
				UDR0 = '\n';
		}
		else {
			UDR0 = chr;
		}
			
	
}


char uart_getchar(void) {

	/* Wait for data to be received */
	while (!(UCSR0A & (1 << RXC0)))
		;

	/* Get and return received data from buffer */
	return UDR0;
}

void uart_echo(void) { // receive char from uart and send it back

	uart_putchar(uart_getchar());

}