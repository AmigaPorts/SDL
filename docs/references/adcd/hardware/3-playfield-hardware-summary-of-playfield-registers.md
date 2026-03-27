---
title: 3 Playfield Hardware / Summary of Playfield Registers
manual: hardware
chapter: hardware
section: 3-playfield-hardware-summary-of-playfield-registers
functions: []
libraries: []
---

# 3 Playfield Hardware / Summary of Playfield Registers

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

This section summarizes the registers used in this chapter and the meaning
of their bit settings. The  [color registers](hardware/3-playfield-hardware-summary-of-color-selection-registers.md)  are summarized in the next
section. See  [Appendix A](hardware/amiga-hardware-reference-manual-a-register-summary.md)  for a summary of all registers.

BPLCON0 - Bitplane Control

   (Warning: Bits in this register cannot be independently set.)

   Bit 0 - unused

   Bit 1 - ERSY (external synchronization enable)

```c
      1 = External synchronization enabled (allows genlock
          synchronization to occur)
      0 = External synchronization disabled
```
   Bit 2 -  [LACE](hardware/3-basic-playfield-selecting-horizontal-and-vertical.md)  (interlace enable)

```c
      1 = interlaced mode enabled
      0 = non-interlaced mode enabled
```
   Bit 3 -  [LPEN](hardware/8-reading-a-light-pen-reading-the-light-pen-registers.md)  (light pen enable)

   Bits 4-7 not used (make 0)

   Bit 8 - GAUD (genlock audio enable)

```c
      1 = Genlock audio enabled
      0 = Genlock audio disabled
      (This bit also appears on Denise pin ZD during blanking period)
```
   Bit 9 -  [COLOR_ON](hardware/3-forming-a-basic-playfield-enabling-the-color-display.md)  (color enable)

```c
      1 = composite video color-burst enabled
      0 = composite video color-burst disabled
```
   Bit 10 -  [DBLPF](hardware/3-forming-a-dual-playfield-display-activating-dual.md)  (double-playfield enable)

```c
      1 = dual playfields enabled
      0 = single playfield enabled
```
   Bit 11 -  [HOMOD](hardware/3-advanced-topics-hold-and-modify-mode.md)  (hold-and-modify enable)

```c
      1 = hold-and-modify enabled
      0 = hold-and-modify disabled; extra-half brite ( [EHB](hardware/3-color-selection-color-selection-in-extra-half-brite-ehb.md) ) enabled
          if  [DBLPF](hardware/3-forming-a-dual-playfield-display-activating-dual.md) =0 and  [BPUx](hardware/3-bitplanes-and-color-selecting-the-number-of-bitplanes.md) =6
```
   Bits 14, 13, 12 -  [BPU2, BPU1, BPU0](hardware/3-bitplanes-and-color-selecting-the-number-of-bitplanes.md) 

```c
      Number of bitplanes used.

      000 = only a background color
      001 = 1 bitplane, PLANE 1
      010 = 2 bitplanes, PLANES 1 and 2
      011 = 3 bitplanes, PLANES 1 - 3
      100 = 4 bitplanes, PLANES 1 - 4
      101 = 5 bitplanes, PLANES 1 - 5
      110 = 6 bitplanes, PLANES 1 - 6
      111 not used
```
   Bit 15 -  [HIRES](hardware/3-basic-playfield-selecting-horizontal-and-vertical.md)  (high resolution enable)


```c
      1 = high resolution mode
      0 = low resolution mode
```
 [BPLCON1](hardware/3-horizontal-scrolling-specifying-amount-of-delay.md)  - Bitplane Control

   Bits 3-0 - PF1H(3-0)  Playfield 1 delay

   Bits 7-4 - PF2H(3-0)  Playfield 2 delay

   Bits 15-8 not used


 [BPLCON2](hardware/7-video-priorities-setting-the-priority-control-register.md)  - Bitplane Control

   Bit 6 - PF2PRI

```c
      1 = Playfield 2 has priority
      0 = Playfield 1 has priority
```
   Bits 0-5  Playfield sprite priority

   Bits 7-15  not used


 [DDFSTRT](hardware/3-basic-playfield-telling-the-system-how-to-fetch-and.md)  - Data-fetch Start
   (Beginning position for data fetch)

   Bits 15-8 - not used

   Bits 7-2 - pixel position H8-H3 (bit H3 only respected in Hires Mode.)

   Bits 1-0 - not used


 [DDFSTOP](hardware/3-basic-playfield-telling-the-system-how-to-fetch-and.md)  - Data-fetch Stop
   (Ending position for data fetch)

   Bits 15-8 - not used

   Bits 7-2 - pixel position H8-H3 (bit H3 only respected in Hires Mode.)

   Bits 1-0 - not used


 [BPLxPTH](hardware/3-allocating-memory-for-bitplanes-ntsc-example-of-bitplane.md)  - Bitplane Pointer
   (Bitplane pointer high word, where x is the bitplane number)


 [BPLxPTL](hardware/3-allocating-memory-for-bitplanes-ntsc-example-of-bitplane.md)  - Bitplane Pointer
   (Bitplane pointer low word, where x is the bitplane number)


 [DIWSTRT](hardware/3-size-display-window-setting-display-window-starting.md)  - Display Window Start
   (Starting vertical and horizontal coordinates)

   Bits 15-8 - VSTART (V7-V0)

   Bits 7-0 - HSTART (H7-H0)


 [DIWSTOP](hardware/3-size-display-window-setting-display-window-stopping.md)  - Display Window Stop
   (Ending vertical and horizontal coordinates)

   Bits 15-8 - VSTOP (V7-V0)

   Bits 7-0 - HSTOP (H7-H0)

 [BPL1MOD](hardware/3-basic-playfield-telling-the-system-how-to-fetch-and.md)  - Bitplane Modulo
   (Odd-numbered bitplanes, playfield 1)


 [BPL2MOD](hardware/3-basic-playfield-telling-the-system-how-to-fetch-and.md)  - Bitplane Modulo
   (Even-numbered bitplanes, playfield 2)

