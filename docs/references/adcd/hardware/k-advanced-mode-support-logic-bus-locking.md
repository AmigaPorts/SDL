---
title: K / / Advanced Mode Support Logic / Bus Locking
manual: hardware
chapter: hardware
section: k-advanced-mode-support-logic-bus-locking
functions: []
libraries: []
---

# K / / Advanced Mode Support Logic / Bus Locking

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The first advanced modification of the basic bus cycle is bus locking, via
the /LOCK signal.  Bus locking is a hardware convention that allows a bus
master to guarantee several cycles will be atomic on the bus. This is
necessary to support the sharing of special "mail-box" memory between a
bus master and an alternate PIC-based processor; Bridge Cards are an
example of this kind of device. The Zorro II bus itself supports bus
locking via the 68000 convention.  However, the 68000 style of bus locking
is often difficult to implement, and support for it was often ignored in
Zorro II designs, especially those not directly concerned with
multiprocessor support.

The Zorro III mechanism involves no change to the basic bus cycle, other
than the monitoring of this /LOCK signal, and as such is much more
reasonable to support.  The /LOCK signal is asserted by a bus master at
address time and maintained across cycles to lock out shared memory
coprocessors, allowing hardware backed semaphores to easily be used
between such coprocessors.  We expect multiprocessing will be a greater
concern on the Zorro III bus than it is at present;  video coprocessors,
RISC devices, and special purpose processors for image processing or
mathematics should find a comfortable home on the Zorro III bus.

