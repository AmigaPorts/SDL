---
title: 8 / / Reading Controllers / Proportional Controller Registers
manual: hardware
chapter: hardware
section: 8-reading-controllers-proportional-controller-registers
functions: []
libraries: []
---

# 8 / / Reading Controllers / Proportional Controller Registers

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The following registers are used for the proportional controllers:

   [POT0DAT](hardware/a-register-summary-pot0dat-pot1dat.md)  - port 1 data (vertical/horizontal)
   [POT1DAT](hardware/a-register-summary-pot0dat-pot1dat.md)  - port 2 data (vertical/horizontal)

   Bit positions:

   Bits 15-8   POT0Y value or POT1Y value
   Bits 7-0    POT0X value or POT1X value

All counts are reset to zero when  [POTGO](hardware/8-controller-port-interface-digital-i-o-on-the-controller.md)  is written with bit zero high.
Counts are normally read one frame after the scan circuitry is enabled.

