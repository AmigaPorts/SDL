---
title: 7 / / Setting and Clearing Bits / External Interrupts
manual: hardware
chapter: hardware
section: 7-setting-and-clearing-bits-external-interrupts
functions: []
libraries: []
---

# 7 / / Setting and Clearing Bits / External Interrupts

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Bits 13 and 3 of the  [interrupt registers](hardware/7-interrupts-interrupt-control-registers.md)  are reserved for external
interrupts.

Bit 13, EXTER, becomes a 1 when the system line called INT6* becomes a
logic 0. Bit 13 generates a  [level 6 interrupt](hardware/7-setting-and-clearing-bits-figure-7-4-interrupt-priorities.md) .

Bit 3, PORTS, becomes a 1 when the system line called INT2* becomes a
logic 0. Bit 3 causes a  [level 2 interrupt](hardware/7-setting-and-clearing-bits-figure-7-4-interrupt-priorities.md) .

