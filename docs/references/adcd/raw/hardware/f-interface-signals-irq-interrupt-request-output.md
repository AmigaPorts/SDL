# F / / Interface Signals / IRQ - interrupt request output


IRQ is an open drain output normally connected to the processor interrupt
input.  An external pull-up resistor holds the signal high, allowing
multiple IRQ outputs to be connected together.  The IRQ output is normally
off (high impedance) and is activated low as indicated in the functional
description.

