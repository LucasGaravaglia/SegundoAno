#include <stdio.h>
#include <stdlib.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#include "fs300a/fs300a.h"

#define UART_BAUD_RATE 2400
#include "uart/uart.h"

int main(void)
{
	char printbuff[100];

	//init uart
	uart_init( UART_BAUD_SELECT(UART_BAUD_RATE,F_CPU) );

	//init fs300a
	fs300a_init();

	//init interrupt
	sei();

	uint16_t flow = 0;
	for (;;) {
		flow = fs300a_getflow();

		itoa(flow, printbuff, 10);
		uart_puts(printbuff); uart_puts("\r\n");

		_delay_ms(1000);
	}

	return 0;
}
