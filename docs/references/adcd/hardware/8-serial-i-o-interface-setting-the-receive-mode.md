---
title: 8 / Serial I/O Interface / Setting The Receive Mode
manual: hardware
chapter: hardware
section: 8-serial-i-o-interface-setting-the-receive-mode
functions: []
libraries: []
---

# 8 / Serial I/O Interface / Setting The Receive Mode

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The number of bits that are to be received before the system tells you
that the receive register is full may be defined either as eight or nine
(this allows for 8 bit transmission with parity).  In either case, the
receive circuitry expects to see one start bit, eight or nine data bits,
and at least one stop bit.

Receive mode is set by bit 15 of the write-only  [SERPER](hardware/a-register-summary-serper.md)  register. Bit 15
is a 1 if you chose nine data bits for the receive-register full signal,
and a 0 if you chose eight data bits. The normal state of this bit for
most receive applications is a 0.

