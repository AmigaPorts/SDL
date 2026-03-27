---
title: 7 / Interrupts / User Interface to the Interrupt System
manual: hardware
chapter: hardware
section: 7-interrupts-user-interface-to-the-interrupt-system
functions: []
libraries: []
---

# 7 / Interrupts / User Interface to the Interrupt System

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The system software has been designed to correctly handle all system
hardware interrupts at levels 1 through 6. A separate set of input
lines, designated INT2* and INT6* have been routed to the expansion
connector for use by external hardware for interrupts. These are known as
the external low- and external high-level interrupts.

These interrupt lines are connected to the peripherals chip and create
 [interrupt levels 2 and 6](hardware/7-setting-and-clearing-bits-figure-7-4-interrupt-priorities.md) , respectively. It is recommended that you take
advantage of the interrupt handlers built into the operating system by
using these external interrupt lines rather than generating interrupts
directly on the processor interrupt lines.

