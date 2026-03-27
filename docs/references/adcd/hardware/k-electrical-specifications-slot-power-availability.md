---
title: K / Electrical Specifications / Slot Power Availability
manual: hardware
chapter: hardware
section: k-electrical-specifications-slot-power-availability
functions: []
libraries: []
---

# K / Electrical Specifications / Slot Power Availability

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The system power for the Zorro III bus is totally based on the slot
configurations.  A backplane is always free to supply extra power, but it
must meet the minimum requirements specified here.  All PICs must be
designed with the minimum specifications in mind, especially the
tolerances.

	Pin	Supply
        ---     ------
	5,6     [+5VDC](hardware/k-signal-description-power-connections-2.md)  +/- 5% @ 2 Amps
	8       [-5VDC](hardware/k-signal-description-power-connections-2.md)  +/- 5% @ 60 mA
	10      [+12VDC](hardware/k-signal-description-power-connections-2.md)  +/- 5% @ 500mA
	20      [-12VDC](hardware/k-signal-description-power-connections-2.md)  +/- 5% @ 60mA

