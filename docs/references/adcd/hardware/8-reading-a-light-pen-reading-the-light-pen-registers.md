---
title: 8 / / Reading A Light Pen / Reading the Light Pen Registers
manual: hardware
chapter: hardware
section: 8-reading-a-light-pen-reading-the-light-pen-registers
functions: []
libraries: []
---

# 8 / / Reading A Light Pen / Reading the Light Pen Registers

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The light pen register is at the same address as the beam counters. The
bits are as follows:

   VPOSR:     Bit 15       Long frame/short frame.  0=short frame

```c
              Bits 14-1    Chip ID code.  Do not depend on value!
              Bit 0        V8 (most significant bit of vertical position)
```
   VHPOSR:    Bits 15-8    V7-V0 (vertical position)

```c
              Bits 7-0     H8-H1 (horizontal position)
```
The software can refer to this register set as a long word whose address
is VPOSR.

The positional resolution of these registers is as follows:

   Vertical      1 scan line in non-interlaced mode

```c
                 2 scan lines in interlaced mode (However, if you know
                 which interlaced frame is under display, you can
                 determine the correct position)
```
   Horizontal    2 low resolution pixels in either high or low resolution

The quality of the light pen will determine the amount of short-term
jitter.  For most applications, you should average several readings
together.

To enable the light pen input, write a 1 into bit 3 (LPEN) of  [BPLCON0](hardware/a-register-summary-bplcon0-bplcon1-bplcon2-bplcon3.md) .
Once the light pen input is enabled and the light pen issues a trigger
signal, the value in VPOSR is frozen. If no trigger is seen, the counters
latch at the end of the display field. It is impossible to read the
current beam location while the VPOSR register is latched. This freeze is
released at the end of internal  [vertical blanking](hardware/7-setting-and-clearing-bits-vertical-blanking-interrupt.md)  (vertical position
20). There is no single bit in the system that indicates a light pen
trigger. To determine if a trigger has occurred, use one of these methods:

   1. Read (long) VPOSR twice.

   2. If both values are not the same, the light pen has not triggered

```c
      since the last top-of-screen (V = 20).
```
   3. If both values are the same, mask off the upper 15 bits of the

```c
      32-bit word and compare it with the hex value of $10500 (V = 261).
```
   4. If the VPOSR value is greater than $10500, the light pen has not

      triggered since the last top-of-screen. If the value is less,
      the light pen has triggered and the value read is the screen
      position of the light pen.
A somewhat simplified method of determining the truth of the light pen
value involves instructing the system software to read the register only
during the internal  [vertical blanking](hardware/7-setting-and-clearing-bits-vertical-blanking-interrupt.md)  period of 0 < V20:

   1. Read (long) VPOSR once, during the period of 0 < V20.

   2. Mask off the upper 15 bits of the 32-bit word and compare it

```c
      with the hex value of $10500 (V = 261).
```
   3. If the VPOSR value is greater than $10500, the light pen has not

      triggered since the last top-of-screen. If the value is less,
      the light pen has triggered and the value read is the screen
      position of the light pen.
Note that when the light pen latch is enabled, the VPOSR register may be
latched at any time, and cannot be relied on as a counter.  This behavior
may cause problems with software that attempts to derive timing based on
VPOSR ticks.

