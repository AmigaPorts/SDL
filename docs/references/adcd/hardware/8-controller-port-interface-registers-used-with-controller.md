---
title: 8 / Controller Port Interface / Registers used with Controller Port
manual: hardware
chapter: hardware
section: 8-controller-port-interface-registers-used-with-controller
functions: []
libraries: []
---

# 8 / Controller Port Interface / Registers used with Controller Port

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The Amiga chip registers that handle the  [controller port](hardware/8-interface-hardware-controller-port-interface.md)  I/O are listed
below.

   [JOY0DAT](hardware/a-register-summary-joy0dat-joy1dat.md)  ($DFF00A)  Counter for digital (mouse) input (port 1)
   [JOY1DAT](hardware/a-register-summary-joy0dat-joy1dat.md)  ($DFF00C)  Counter for digital (mouse) input (port 2)
   [CIAAPRA](hardware/amiga-hardware-reference-manual-f-8520-complex-interface.md)  ($BFE001)  Input and output for pin 6 (port 1 & 2 fire buttons)
   [POT0DAT](hardware/a-register-summary-pot0dat-pot1dat.md)  ($DFF012)  Counter for proportional input (port 1)
   [POT1DAT](hardware/a-register-summary-pot0dat-pot1dat.md)  ($DFF014)  Counter for proportional input (port 2)
   [POTGO](hardware/8-controller-port-interface-digital-i-o-on-the-controller.md)    ($DFF034)  Write proportional pin values and start counters
   [POTGOR](hardware/8-controller-port-interface-digital-i-o-on-the-controller.md)   ($DFF016)  Read proportional pin values
   [BPLCON0](hardware/a-register-summary-bplcon0-bplcon1-bplcon2-bplcon3.md)  ($DFF100)  Bit 3  [enables the light pen](hardware/8-reading-a-light-pen-reading-the-light-pen-registers.md)  latch
   [VPOSR](hardware/8-reading-a-light-pen-reading-the-light-pen-registers.md)    ($DFF004)  Read  [light pen position](hardware/8-reading-a-light-pen-reading-the-light-pen-registers.md)  (high order bits)
   [VHPOSR](hardware/8-reading-a-light-pen-reading-the-light-pen-registers.md)   ($DFF006)  Read  [light pen position](hardware/8-reading-a-light-pen-reading-the-light-pen-registers.md)  (low order bits)

