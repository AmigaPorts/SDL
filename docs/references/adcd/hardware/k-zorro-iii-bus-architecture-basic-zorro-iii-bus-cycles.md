---
title: K / Zorro III Bus Architecture / Basic Zorro III Bus Cycles
manual: hardware
chapter: hardware
section: k-zorro-iii-bus-architecture-basic-zorro-iii-bus-cycles
functions: []
libraries: []
---

# K / Zorro III Bus Architecture / Basic Zorro III Bus Cycles

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The basic Zorro III bus cycle is a  [multiplexed](hardware/k-zorro-iii-bus-architecture-multiple-transfer-cycles.md)  address/data cycle which
supplies a full 32 bits worth of address and data per simple cycle.  The
cycle is a fully  [asynchronous](hardware/k-basic-zorro-iii-bus-cycles-design-goals.md)  cycle.  The bus master for a given cycle
supplies strobes to indicate when address is valid, write data is valid,
and read data may be driven.  In return, the bus slave for a cycle
supplies a strobe to indicate that it is responding to a bus address, and
a strobe to indicate that it is done with the bus data for a write cycle,
or has supplied valid bus data for a read cycle.  The minimum theoretical
bus speed is governed only by setup and hold time requirements for the
various bus signals.  Actual bus speeds are always a function of the bus
master and bus slave active for a given cycle.  This is considerably
different than the Zorro II bus, and for several good reasons, which are
explained below.

 [Design Goals](hardware/k-basic-zorro-iii-bus-cycles-design-goals.md)      [Simple Bus Cycle Operation](hardware/k-basic-zorro-iii-bus-cycles-simple-bus-cycle-operation.md) 

