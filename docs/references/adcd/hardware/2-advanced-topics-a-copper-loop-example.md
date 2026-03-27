---
title: 2 / Advanced Topics / A Copper Loop Example
manual: hardware
chapter: hardware
section: 2-advanced-topics-a-copper-loop-example
functions: []
libraries: []
---

# 2 / Advanced Topics / A Copper Loop Example

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

This example will instruct the Copper to issue an interrupt every 16 scan
lines.  It might seem that the way to do this would be to use a mask of
$0F and then compare the result with $0F. This should compare "true" for
$1F, $2F, $3F, etc. Since the test is for greater than or equal to, this
would seem to allow checking for every 16th scan line. However, the
highest order bit cannot be masked, so it will always appear in the
comparisons. When the Copper is waiting for $0F and the vertical position
is past 128 (hex $80), this test will always be true. In this case, the
minimum value in the comparison will be $80, which is always greater than
$0F, and the interrupt will happen on every scan line. Remember, the
Copper only checks for greater than or equal to.

In the following example, the Copper lists have been made to loop. The
 [COP1LC and COP2LC](hardware/2-using-the-copper-registers-location-registers.md)  values are either set via the CPU or in the Copper
list before this section of Copper code. Also, it is assumed that you have
correctly installed an interrupt server for the Copper interrupt that will
be generated every 16 lines. Note that these are non-interlaced scan lines.

Here's how it works.  Both loops are, for the most part, exactly the same.
In each, the Copper waits until the vertical position register has $xF
(where x is any hex digit) in it, at which point we issue a Copper
interrupt to the Amiga hardware. To make sure that the Copper does not
loop back before the vertical position has changed and cause another
interrupt on the same scan line, wait for the horizontal position to be
$E2 after each interrupt. Position $E2 is horizontal position 113 for the
Copper and the last real horizontal position available. This will force
the Copper to the next line before the next  [WAIT](hardware/2-coprocessor-hardware-the-wait-instruction.md) . The loop is executed
by writing to the  [COPJMP1](hardware/2-using-the-copper-registers-jump-strobe-address.md)  register. This causes the Copper to jump to
the address that was initialized in  [COP1LC](hardware/2-using-the-copper-registers-location-registers.md) .

The masking problem described above makes this code fail after vertical
position 127.  A separate loop must be executed when vertical position is
greater than or equal 127. When the vertical position becomes greater than
or equal to 127, the the first loop instruction is skipped, dropping the
Copper into the second loop. The second loop is much the same as the
first, except that it waits for $xF with the high bit set (binary
1xxx1111). This is true for both the vertical and the horizontal  [WAIT](hardware/2-coprocessor-hardware-the-wait-instruction.md) 
instructions. To cause the second loop, write to the  [COPJMP2](hardware/2-using-the-copper-registers-jump-strobe-address.md)  register.
The list is put into an infinite wait when VP >= 255 so that it will end
before the vertical blank. At the end of the  [vertical blanking](hardware/7-setting-and-clearing-bits-vertical-blanking-interrupt.md)  period
 [COP1LC](hardware/2-using-the-copper-registers-location-registers.md)  is written to by the operating system, causing the first loop to
start up again.

```c
    [COP1LC](hardware/2-using-the-copper-registers-location-registers.md)  is written at the end of  [vertical blanking](hardware/7-setting-and-clearing-bits-vertical-blanking-interrupt.md) .
```
   ------------------------------------------------------
   The  [COP1LC](hardware/2-using-the-copper-registers-location-registers.md)  register is written at the end of the  [vertical blanking](hardware/7-setting-and-clearing-bits-vertical-blanking-interrupt.md) 
   period by a graphics interrupt handler which is in the vertical blank
   interrupt server chain.  As long as this server is intact,  [COP1LC](hardware/2-using-the-copper-registers-location-registers.md) 
   will be correctly strobed at the end of each vertical blank.

;
;  This is the data for the Copper list.
;
;  It is assumed that COPPERL1 is loaded into  [COP1LC](hardware/2-using-the-copper-registers-location-registers.md)  and
;  that COPPERL2 is loaded into  [COP2LC](hardware/2-using-the-copper-registers-location-registers.md)  by some other code.
;
COPPERL1:

```c
        DC.W    $0F01,$8F00   ; Wait for VP=0xxx1111
        DC.W    [INTREQ](hardware/7-interrupts-interrupt-control-registers.md),$8010  ; Set the copper interrupt bit...

        DC.W    $00E3,$80FE   ; Wait for Horizontal $E2
                              ; This is so the line gets finished before
                              ; we check if we are there  (The wait above)

        DC.W    $7F01,$7F01   ; Skip if VP>=127
        DC.W    [COPJMP1](hardware/2-using-the-copper-registers-jump-strobe-address.md),$0    ; Force a jump to  [COP1LC](hardware/2-using-the-copper-registers-location-registers.md) 
```
COPPERL2:

```c
        DC.W    $8F01,$8F00   ; Wait for VP=1xxx1111
        DC.W    [INTREQ](hardware/7-interrupts-interrupt-control-registers.md),$8010  ; Set the copper interrupt bit...

        DC.W    $80E3,$80FE   ; Wait for Horizontal $E2
                              ; This is so the line gets finished before
                              ; we check if we are there  (The wait above)

        DC.W    $FF01,$FE01   ; Skip if VP>=255
        DC.W    [COPJMP2](hardware/2-using-the-copper-registers-jump-strobe-address.md),$0    ; Force a jump to  [COP2LC](hardware/2-using-the-copper-registers-location-registers.md) 
```
; Whatever cleanup copper code that might be needed here...
; Since there are 262 lines in NTSC, and we stopped at 255, there is a
; bit of time available

```c
        DC.W    $FFFF,$FFFE     ; End of Copper list
```
;

