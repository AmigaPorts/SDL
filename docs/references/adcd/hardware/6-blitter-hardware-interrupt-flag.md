---
title: 6 Blitter Hardware / Interrupt Flag
manual: hardware
chapter: hardware
section: 6-blitter-hardware-interrupt-flag
functions: []
libraries: []
---

# 6 Blitter Hardware / Interrupt Flag

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The blitter also has an interrupt flag that is set whenever a blit
finishes.  This flag,  [INTF_BLIT](hardware/7-setting-and-clearing-bits-blitter-interrupt.md) , can generate a 680x0 interrupt if
enabled. For more information on  [interrupts](hardware/7-system-control-hardware-interrupts.md) , see Chapter 7: "System
Control Hardware."

