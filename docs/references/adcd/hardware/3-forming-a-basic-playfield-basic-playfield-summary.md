---
title: 3 / Forming a Basic Playfield / Basic Playfield Summary
manual: hardware
chapter: hardware
section: 3-forming-a-basic-playfield-basic-playfield-summary
functions: []
libraries: []
---

# 3 / Forming a Basic Playfield / Basic Playfield Summary

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The steps for defining a basic playfield are summarized below:

1. Define Playfield Characteristics
   --------------------------------
   a.  [Specify color](hardware/3-forming-a-basic-playfield-bitplanes-and-color.md)  for each pixel:

```c
      * Load desired colors in color table registers.

      * Define color of each pixel in terms of the binary value
        that points at the desired color register.

      * Build bitplanes and set bitplane registers:

           Bits 12-14 in  [BPLCON0](hardware/3-playfield-hardware-summary-of-playfield-registers.md)  - number of bitplanes ( [BPU2 - BPU0](hardware/3-bitplanes-and-color-selecting-the-number-of-bitplanes.md) ).
            [BPLxPTH](hardware/3-allocating-memory-for-bitplanes-ntsc-example-of-bitplane.md)  - pointer to bitplane starting position in memory
```
	               (written as a long word).

   b.  [Specify resolution](hardware/3-basic-playfield-selecting-horizontal-and-vertical.md) :


```c
      * Low resolution:

          320 pixels in each horizontal line.
          Clear bit 15 in register  [BPLCON0](hardware/3-playfield-hardware-summary-of-playfield-registers.md)  ( [HIRES](hardware/3-basic-playfield-selecting-horizontal-and-vertical.md) ).

      * High resolution:

          640 pixels in each horizontal line.
          Set bit 15 in register  [BPLCON0](hardware/3-playfield-hardware-summary-of-playfield-registers.md)  ( [HIRES](hardware/3-basic-playfield-selecting-horizontal-and-vertical.md) ).
```
   c.  [Specify interlaced or non-interlaced mode](hardware/3-basic-playfield-selecting-horizontal-and-vertical.md) :


```c
      * Interlaced mode:

          400 vertical lines for NTSC, 512 for PAL.
          Set bit 2 in register  [BPLCON0](hardware/3-playfield-hardware-summary-of-playfield-registers.md)  ( [LACE](hardware/3-basic-playfield-selecting-horizontal-and-vertical.md) ).

      * Non-interlaced mode:

          200 vertical lines for NTSC, 256 for PAL.
          Clear bit 2 in  [BPLCON0](hardware/3-playfield-hardware-summary-of-playfield-registers.md)  ( [LACE](hardware/3-basic-playfield-selecting-horizontal-and-vertical.md) ).
```
2.  [Allocate Memory](hardware/3-forming-a-basic-playfield-allocating-memory-for-bitplanes.md) . To calculate data-bytes in the total bitplanes,
   -----------------  use the following formula:


          Bytes per line * lines in playfield * number of bitplanes
3.  [Define Size of Display Window](hardware/3-forming-basic-playfield-defining-the-size-of-the-display.md) .
   -------------------------------
   * Write start position of display window in  [DIWSTRT](hardware/3-size-display-window-setting-display-window-starting.md) :


```c
      Horizontal position in bits 0 through 7 (low order bits).
      Vertical position in bits 8 through 15 (high order bits).
```
   * Write stop position of display window in  [DIWSTOP](hardware/3-size-display-window-setting-display-window-stopping.md) :


      Horizontal position in bits 0 through 7.
      Vertical position in bits 8 through 15.
4.  [Define Data Fetch](hardware/3-basic-playfield-telling-the-system-how-to-fetch-and.md) . Set registers  [DDFSTRT](hardware/3-basic-playfield-telling-the-system-how-to-fetch-and.md)  and  [DDFSTOP](hardware/3-basic-playfield-telling-the-system-how-to-fetch-and.md) :
   -------------------
   * For  [DDFSTRT](hardware/3-basic-playfield-telling-the-system-how-to-fetch-and.md) , use the horizontal position as shown in

```c
      [Setting the Display Window Starting Position](hardware/3-size-display-window-setting-display-window-starting.md) .
```
   * For  [DDFSTOP](hardware/3-basic-playfield-telling-the-system-how-to-fetch-and.md) , use the horizontal position as shown in

```c
      [Setting the Display Window Stopping Position](hardware/3-size-display-window-setting-display-window-stopping.md) .
```
5.  [Define Modulo](hardware/3-basic-playfield-telling-the-system-how-to-fetch-and.md) . Set registers  [BPL1MOD and BPL2MOD](hardware/3-basic-playfield-telling-the-system-how-to-fetch-and.md) .  Set modulo to 0
   ---------------  for non-interlaced, 40 for interlaced.

6. Write Copper Instructions To Handle  [Redisplay](hardware/3-basic-playfield-displaying-and-redisplaying-the-playfield.md) .
   -----------------------------------------------

7.  [Enable Color Display](hardware/3-forming-a-basic-playfield-enabling-the-color-display.md) .For the A1000: set bit 9 in  [BPLCON0](hardware/3-playfield-hardware-summary-of-playfield-registers.md)  to enable the
   ---------------------- the color display on a composite video monitor.

                          RGB video is not affected.  Only the A1000 has
                          color composite video output, other Amiga models
                          cannot enable this feature using standard
                          hardware.
