---
title: K / / Signal Description / Power Connections
manual: hardware
chapter: hardware
section: k-signal-description-power-connections
functions: []
libraries: []
---

# K / / Signal Description / Power Connections

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The Zorro III expansion bus provides several different  [voltages](hardware/k-signal-description-power-connections-2.md)  designed
to supply expansion devices.  There are no changes here that affect Zorro
II cards.

Digital Ground (Ground)
   This is the digital supply ground used by all expansion cards as the
   return path for all expansion supplies.

Main Supply (+5VDC)
   This is the main power supply for all expansion cards, and it is
   capable of sourcing large currents; each expansion slot can draw up
   to 2.0 Amps @ +5VDC. The extra power for one card in any backplane
   drawing up to  [4.0 Amps](hardware/k-changes-from-the-a2000-bus-power-supply-differences.md)  @ +5VDC is no longer supported.

Negative Supply (-5VDC)
   This is a negative version of the main supply, for small current
   loads only. There is no maximum load specified for the Zorro II bus
   on a per-slot basis; the A2000 implementation specifies  0.3 Amps @
   -5VDC for the entire system.

High Voltage Supply (+12VDC)
   This is a higher voltage supply, useful for communications cards and
   other devices requiring greater than digital voltage levels.  This is
   intended for relatively small current loads only. There is no maximum
   load specified for the Zorro II bus on a per-slot basis; the A2000
   implementation specifies 8.0 Amps @ +12VDC for the entire system,
   most of which is normally devoted to floppy and hard disk drive
   motors, not slots.

Negative High Supply (-12VDC)
   Negative version of the high voltage supply, also commonly used in
   communications applications, and similarly intended for small loads
   only. There is no maximum load specified for the Zorro II bus on a
   per-slot basis; the A2000 implementation specifies 0.3 Amps @ -12VDC
   for the entire.

