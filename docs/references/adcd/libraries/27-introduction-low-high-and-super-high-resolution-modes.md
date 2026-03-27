---
title: 27 / Introduction / Low, High and Super-High Resolution Modes
manual: libraries
chapter: libraries
section: 27-introduction-low-high-and-super-high-resolution-modes
functions: []
libraries: []
---

# 27 / Introduction / Low, High and Super-High Resolution Modes

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The Amiga also has three horizontal display modes: low-resolution (or
Lores), high-resolution (Hires) and super-high-resolution (SuperHires).

Normally, these three horizontal display modes have a width of 320 for
Lores, 640 for Hires or 1280 for SuperHires on both PAL and NTSC machines.
However, by taking full advantage of the overscan region, it is possible
to create dispays up to 362 pixels wide in Lores mode, 724 pixels wide in
Hires or 1448 pixels wide in SuperHires.  Usually, however, you should use
the standard values (320, 640 or 1280) for most applications.

In general, the number of colors available in each display mode decreases
as the resolution increases.  The Amiga has two special display modes that
can be used to increase the number of colors available.  HAM is
Hold-And-Modify mode, EHB is Extra-Half-Brite mode.

Hold-And-Modify (HAM) allows you to display the entire palette of 4,096
colors on-screen at once with certain restrictions, explained later.

Extra-Half-Brite allows for 64 colors on-screen at once; 32 colors plus 32
additional colors that are half the intensity of the first 32.  For
example, if color 1 is defined as 0xFFF (white), then color 33 is 0x777
(grey).

 [Display Modes, Colors, and Requirements](libraries/27-resolution-modes-display-modes-colors-and-requirements.md) 

