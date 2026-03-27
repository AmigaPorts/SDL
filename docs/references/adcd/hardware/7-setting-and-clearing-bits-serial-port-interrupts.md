---
title: 7 / / Setting and Clearing Bits / Serial Port Interrupts
manual: hardware
chapter: hardware
section: 7-setting-and-clearing-bits-serial-port-interrupts
functions: []
libraries: []
---

# 7 / / Setting and Clearing Bits / Serial Port Interrupts

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The following serial interrupts are associated with the specified bits of
the  [interrupt registers](hardware/7-interrupts-interrupt-control-registers.md) .

Bit 11, RBF (for receive buffer full), specifies that the input buffer of
the UART has data that is ready to read. This bit generates a
 [level 5 interrupt](hardware/7-setting-and-clearing-bits-figure-7-4-interrupt-priorities.md) .

Bit 0, TBE (for "transmit buffer empty"), specifies that the output
buffer of the UART needs more data and data can now be written into this
buffer. This bit generates a  [level 1 interrupt](hardware/7-setting-and-clearing-bits-figure-7-4-interrupt-priorities.md) .

