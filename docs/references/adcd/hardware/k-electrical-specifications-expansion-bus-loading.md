---
title: K / Electrical Specifications / Expansion Bus Loading
manual: hardware
chapter: hardware
section: k-electrical-specifications-expansion-bus-loading
functions: []
libraries: []
---

# K / Electrical Specifications / Expansion Bus Loading

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The Zorro III bus loading is specified based on typical TTL family "F"
series buffer devices, though in reality, compatible CMOS devices are
likely to be used in some bus controllers or PICs.   Thus, it's important
to accept the TTL levels as a minimum voltage level, and make sure that
all inputs are the appropriate TTL levels, while outputs can be at TTL or
CMOS voltage levels as long as they provide the required source and sink.

While some A2000 designs used "LS" or "ALS" buffers instead of "F," the
bus will generally work with these older cards, at least with current
backplane designs such as the A3000 backplane.  However, Zorro III designs
must exactly obey these loading rules; it's very probable that some future
Zorro III machines will have a large number of slots.  In such machines,
PICs built on the Zorro II specification will still work in a lightly
loaded bus, but may not function in a fully loaded bus.  All Zorro III
PICs built to spec will work in any Zorro III backplane, without any
loading problems, if all loading and  [timing](hardware/k-zorro-expansion-bus-timing.md)  rules are followed by the
PIC designer. The bus signals are divided up into the four groups shown in
Table K-2, based on the loading characteristics of the particular signal.
The signals in each group are given here. Standard Signals

The majority of signals on the bus are in this group.  These are bussed
signals, driven actively on the bus by F-series (or compatible) drivers
such as 74F245, usually tri-stated when ownership of the signal changed
for master and slave, and generally terminated with a 220(omega)/330(omega)
thevenin terminator.  PICs can apply two standard loads to each of these
signals when necessary.



```c
        [/FCS](hardware/k-signal-description-address-and-related-control-signals.md)      [/CCS](hardware/k-signal-description-address-and-related-control-signals.md)       [/DS0-/DS3](hardware/k-signal-description-data-and-related-control-signals.md)   [/LOCK](hardware/k-advanced-mode-support-logic-bus-locking.md) 
        [A2-A7](hardware/k-signal-description-address-and-related-control-signals.md)     AD8-AD31   SD0-SD7     [READ](hardware/k-signal-description-address-and-related-control-signals.md) 
        [FC0-FC2](hardware/k-signal-description-address-and-related-control-signals.md)   [DOE](hardware/k-signal-description-data-and-related-control-signals.md)        [/IORST](hardware/k-signal-description-system-control-signals-2.md)      [/BCLR](hardware/k-signal-description-dma-control-signals-2.md) 
        [/MTCR](hardware/k-signal-description-data-and-related-control-signals.md)     [/MTACK](hardware/k-signal-description-data-and-related-control-signals.md) 
```
 [Clock Signals](hardware/k-expansion-bus-loading-clock-signals.md)      [Open Collector Signals](hardware/k-expansion-bus-loading-open-collector-signals.md)      [Non-bussed Signals](hardware/k-expansion-bus-loading-non-bussed-signals.md) 

