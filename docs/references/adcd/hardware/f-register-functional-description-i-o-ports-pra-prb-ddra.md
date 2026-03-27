---
title: F / Register Functional Description / I/O Ports (PRA, PRB, DDRA, DDRB)
manual: hardware
chapter: hardware
section: f-register-functional-description-i-o-ports-pra-prb-ddra
functions: []
libraries: []
---

# F / Register Functional Description / I/O Ports (PRA, PRB, DDRA, DDRB)

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Ports A and B each consist of an 8-bit peripheral data register (PR) and
an 8-bit data direction register (DDR).  If a bit in the DDR is set to a
1, the corresponding bit position in the PR becomes an output.  If a DDR
bit is set to a 0, the corresponding PR bit is defined as an input.

When you READ a PR register, you read the actual current state of the I/O
pins (PA0-PA7, PB0-PB7, regardless of whether you have set them to be
inputs or outputs.

Ports A and B have passive pull-up devices as well as active pull-ups,
providing both CMOS and TTL compatibility.  Both ports have two TTL load
drive capability.

In addition to their normal I/O operations, ports PB6 and PB7 also provide
 [timer](hardware/f-register-functional-description-interval-timers-timer-a-b.md)  output functions.

