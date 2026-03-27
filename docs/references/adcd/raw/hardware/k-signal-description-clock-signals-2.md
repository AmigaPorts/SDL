# K / Signal Description / Clock Signals


The expansion bus provides clock signals for expansion boards.  The main
use for these clocks on Zorro III cards is bus arbitration clocking. There
is no relationship between any of these clocks and normal Zorro III bus
activity. The relationship between these clocks is illustrated in
 [Figure K-3](../Hardware_Manual_guide/node029E.html#line33) .

/C1 Clock
   This is a 3.58 MHz clock (3.55 MHz on PAL systems) that's synched to
   the falling edge of the 7M system clock.

/C3 Clock
   This is a 3.58 MHz clock (3.55 MHz on PAL systems) that's synched to
   the rising edge of the 7M system clock.

CDAC Clock
   This is a 7.16 MHz system clock (7.09 MHz on PAL systems) which
   trails the 7M clock by 90 degrees (approximately 35ns).

E Clock
   This is the 68000 generated "E" clock, used for 6800 family
   peripherals driven by "E" and 6502 peripherals driven by phi(2). This
   clock is four 7M clocks high, six clocks low, as per the 68000 spec.

7M Clock
   This is the 7.16 MHz system clock (7.09 MHz on PAL systems).  This
   clock drives the bus master registration mechanism for Zorro III bus
   masters.

