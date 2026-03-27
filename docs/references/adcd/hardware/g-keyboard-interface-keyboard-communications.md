---
title: G Keyboard Interface / Keyboard Communications
manual: hardware
chapter: hardware
section: g-keyboard-interface-keyboard-communications
functions: []
libraries: []
---

# G Keyboard Interface / Keyboard Communications

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The keyboard transmits 8-bit data words serially to the main unit. Before
the transmission starts, both KCLK and KDAT are high.  The keyboard starts
the transmission by putting out the first data bit (on KDAT), followed by
a pulse on KCLK (low then high); then it puts out the second data bit and
pulses KCLK until all eight data bits have been sent.  After the end of
the last KCLK pulse, the keyboard pulls KDAT high again.

When the computer has received the eighth bit, it must pulse KDAT low for
at least 1 (one) microsecond, as a handshake signal to the keyboard.  The
handshake detection on the keyboard end will typically use a hardware
latch.  The keyboard must be able to detect pulses greater than or equal
to 1 microsecond.  Software MUST pulse the line low for 85 microseconds to
ensure compatibility with all keyboard models.

All codes transmitted to the computer are rotated one bit before
transmission.  The transmitted order is therefore 6-5-4-3-2-1-0-7. The
reason for this is to transmit the  [up/down flag](hardware/g-keyboard-interface-keycodes.md)  last, in order to cause
a key-up code to be transmitted in case the keyboard is forced to restore
 [lost sync](hardware/g-keyboard-interface-out-of-sync-condition.md)  (explained in more detail below).

The KDAT line is active low; that is, a high level (+5V) is interpreted as
0, and a low level (0V) is interpreted as 1.


```c
             _____   ___   ___   ___   ___   ___   ___   ___   _________
        KCLK      \_/   \_/   \_/   \_/   \_/   \_/   \_/   \_/
             ___________________________________________________________
        KDAT    \_____X_____X_____X_____X_____X_____X_____X_____/
                  (6)   (5)   (4)   (3)   (2)   (1)   (0)   (7)

                 First                                     Last
                 sent                                      sent
```
The keyboard processor sets the KDAT line about 20 microseconds before it
pulls KCLK low.  KCLK stays low for about 20 microseconds, then goes high
again.  The processor waits another 20 microseconds before changing KDAT.

Therefore, the bit rate during transmission is about 60 microseconds per
bit, or 17 kbits/sec.

