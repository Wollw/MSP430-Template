#include <stdint.h>
#include <msp430g2001.h>
#include <string.h>
#include "option.h"

int main(void) {
	volatile int i;

	// stop watchdog timer or the the mcu will keep resetting.
	WDTCTL = WDTPW | WDTHOLD;
	// Set P1.0 and P1.6 as Output pins and make sure they
    // start out set low.
	P1DIR = 0x41;
	P1OUT = 0x00;

    // Blink on and off periodically.
	for (;;) {
		P1OUT |= option_value("GREEN");
		for (i = 0; i < 0x6000; i++);
		P1OUT &= ~option_value("GREEN");
		for (i = 0; i < 0x6000; i++);
	}
}
