#ifndef SERIALH
#define SERIALH
#define CLOCK_SPEED 16000000UL
#define BAUD_RATE 38400
#define UBRR_VALUE CLOCK_SPEED / (16 * BAUD_RATE) -1


void uart_init(void);

void uart_putchar(char chr);
void uart_putstr(char text[]);
char uart_getchar(void);

void uart_echo(void);

#endif

