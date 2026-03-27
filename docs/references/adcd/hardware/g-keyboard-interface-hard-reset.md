---
title: G Keyboard Interface / Hard Reset
manual: hardware
chapter: hardware
section: g-keyboard-interface-hard-reset
functions: []
libraries: []
---

# G Keyboard Interface / Hard Reset

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   About Hard Reset.
   -----------------
   Hard Reset happens after  [Reset Warning](hardware/g-keyboard-interface-reset-warning.md) . Valid for all keyboards
   except the Amiga 500.

The keyboard Hard Resets the Amiga by pulling KCLK low and starting a 500
millisecond timer.   When one or more of the keys is released and 500
milliseconds have passed, the keyboard will release KCLK. 500 milliseconds
is the minimum time KCLK must be held low.  The maximum KCLK time depends
on how long the user holds the three  [reset keys](hardware/g-keyboard-interface-reset-warning.md)  down.  Circuitry on the
Amiga motherboard detects the 500 millisecond KCLK pulse.

After releasing KCLK, the keyboard jumps to its start-up code (internal
RESET).  This will initialize the keyboard in the same way as cold
 [power-on](hardware/g-keyboard-interface-power-up-sequence.md) .

   NOTE:
   -----
   The keyboard must resend the " [powerup key stream](hardware/g-keyboard-interface-power-up-sequence.md) "!

