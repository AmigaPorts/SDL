---
title: 8 / Serial I/O Interface / Setting The Baud Rate
manual: hardware
chapter: hardware
section: 8-serial-i-o-interface-setting-the-baud-rate
functions: []
libraries: []
---

# 8 / Serial I/O Interface / Setting The Baud Rate

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The rate of transmission (the baud rate) is controlled by the contents of
the register named  [SERPER](hardware/a-register-summary-serper.md) .  Bits 14-0 of  [SERPER](hardware/a-register-summary-serper.md)  are the baud-rate
divider bits.

All timing is done on the basis of a "color clock," which is 279.36ns long
on NTSC machines and 281.94ns on PAL machines.  If the  [SERPER](hardware/a-register-summary-serper.md)  divisor is
set to the number N, then N+1 color clocks occur between samples of the
state of the input pin (for receive) or between transmissions of output
bits (for transmit).  Thus  [SERPER](hardware/a-register-summary-serper.md) =(3,579,545/baud)-1. On a PAL machine,
 [SERPER](hardware/a-register-summary-serper.md) =(3,546,895/baud)-1.  For example, the proper  [SERPER](hardware/a-register-summary-serper.md)  value for
9600 baud on an NTSC machine is (3,579,545/9600)-1=371.

With a cable of a reasonable length, the maximum reliable rate is on the
order of 150,000-250,000 bits per second.  Maximum rates will vary between
machines.  At these high rate it is not possible to handle the overhead of
interrupts.  The receiving end will need to be in a tight read loop.
Through the use of low speed control information and high-speed bursts, a
very inexpensive communication network can be built.

