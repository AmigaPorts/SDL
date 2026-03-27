---
title: 8 / Serial I/O Interface / Introduction To Serial Circuitry
manual: hardware
chapter: hardware
section: 8-serial-i-o-interface-introduction-to-serial-circuitry
functions: []
libraries: []
---

# 8 / Serial I/O Interface / Introduction To Serial Circuitry

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The Paula custom chip contains a Universal Asynchronous
Receiver/Transmitter, or UART. This UART is programmable for any rate from
110 to over 1,000,000 bits per second.  It can receive or send data with a
programmable length of eight or nine bits.

The UART implementation provides a high degree of software control. The
UART is capable of detecting overrun errors, which occur when some other
system sends in data faster than you remove it from the data-receive
register.  There are also status bits and interrupts for the conditions of
receive buffer full and transmit buffer empty.  An additional status bit
is provided that indicates "all bits have been shifted out". All of these
topics are discussed in folowing sections.

