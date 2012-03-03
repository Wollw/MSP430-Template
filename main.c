#include <stdint.h>
#include <msp430g2001.h>
#include <string.h>
#include "option.h"

int main(void) {
	volatile int i;

	// stop watchdog timer
	WDTCTL = WDTPW | WDTHOLD;
	// set up bit 0 and 6 of P1 as output
	P1DIR = 0x41;
	// intialize P1 to 0
	P1OUT = 0x00;

	// loop forever
	for (;;) {
		P1OUT |= option_value("GREEN");
		// delay for a while
		for (i = 0; i < 0x6000; i++);
		P1OUT &= ~option_value("GREEN");
		for (i = 0; i < 0x6000; i++);
	}
}
