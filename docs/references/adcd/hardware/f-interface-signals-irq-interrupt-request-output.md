---
title: F / / Interface Signals / IRQ - interrupt request output
manual: hardware
chapter: hardware
section: f-interface-signals-irq-interrupt-request-output
functions: []
libraries: []
---

# F / / Interface Signals / IRQ - interrupt request output

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

IRQ is an open drain output normally connected to the processor interrupt
input.  An external pull-up resistor holds the signal high, allowing
multiple IRQ outputs to be connected together.  The IRQ output is normally
off (high impedance) and is activated low as indicated in the functional
description.

