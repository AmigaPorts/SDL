---
title: C / ECS Hardware and Graphics Library / Interpretational Differences
manual: hardware
chapter: hardware
section: c-ecs-hardware-and-graphics-library-interpretational
functions: []
libraries: []
---

# C / ECS Hardware and Graphics Library / Interpretational Differences

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The following registers have the same functionality as the standard chip
set, however, their behavior is interpreted differently.

The POT0 and POT1 registers each read a pair of 8-bit pot counters as
before.

   POT0DAT   012   R   P      Pot counter data left pair
```c
                                  (vertical, horiz)
```
   POT1DAT   014   R   P      Pot counter data right pair

```c
                                  (vertical, horiz)
```
However, with programmable scan rates, the values read from these
registers will differ. Generally, the faster the scan rate, the smaller
these values become. Adjustments to the scan rate are reflected in these
values. See Appendix A for more detail on standard operation of these
registers.

Another register where the interpretation has been extended for the ECS is
COPCON.

   COPCON    02E   W   A      Coprocessor control

This 1-bit register, the danger bit (CDANG), when set allows the
Coprocessor to write to the Blitter hardware. In the standard chip set, if
this is set, the Copper can access the address range from $DFF03E through
$DFF07E.  Now, in the ECS, if this bit is set, the Copper can access all
of the Amiga chip registers.  If this bit is clear, the Copper can access
the address range from $DFF03E through $DFF07E, the same range as when the
danger bit is set in the standard chip set.

The AUDxPER register is another register value that varies according to
the programmable scan rate.

   AUDxPER   0A6   W   P      Audio channel x period

With programmable scan rates, the maximum value read from this register
will differ. Generally, the faster the scan rate, the smaller the maximum
period becomes. Adjustments to the scan rate are reflected in this maximum
value.

For more information on the AUDxPER register, and any other register in
the Amiga standard chip set, see  [Appendix A](hardware/amiga-hardware-reference-manual-a-register-summary.md)  and  [Appendix B](hardware/amiga-hardware-reference-manual-b-register-summary-address.md) .

