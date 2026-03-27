---
title: K / Signal Description / Power Connections
manual: hardware
chapter: hardware
section: k-signal-description-power-connections-2
functions: []
libraries: []
---

# K / Signal Description / Power Connections

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The expansion bus provides several different voltages designed to supply
expansion devices.  These are basically the same for the Zorro III bus as
they were for the Zorro II bus, with the exception of one pin, and that
the specification has been clarified a bit.  Note that all Zorro III PICs
must list their power consumption specifications.

Digital Ground (Ground)
   This is the digital supply ground used by all expansion cards as the
   return path for all expansion supplies.

Main Supply (+5VDC)
   This is the main power supply for all expansion cards, and it is
   capable of sourcing large currents; each PIC can draw up to
   2.0 Amps @ +5VDC.

Negative Supply (-5VDC)
   This is a negative version of the main supply, for small current
   loads only; each PIC can draw up to 60 mA @ -5VDC.

High Voltage Supply (+12VDC)
   This is a higher voltage supply, useful for communications cards and
   other devices requiring greater that digital voltage levels.  This is
   intended for relatively small current loads only; each PIC can draw
   up to 500mA @ +12VDC.

Negative High Supply (-12VDC)
   Negative version of the high voltage supply, also used in
   communications applications, and similarly intended for small loads
   only; each PIC can draw up to 60 mA @ -12VDC.

