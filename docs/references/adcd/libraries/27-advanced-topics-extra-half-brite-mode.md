---
title: 27 / Advanced Topics / Extra-Half-Brite Mode
manual: libraries
chapter: libraries
section: 27-advanced-topics-extra-half-brite-mode
functions: []
libraries: []
---

# 27 / Advanced Topics / Extra-Half-Brite Mode

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

In the Extra-Half-Brite mode you can create a single-playfield,
low-resolution display with up to 64 colors, double the normal maximum of
32.  This requires your [ViewPort](libraries/27-display-routines-and-structures-viewport-display-memory.md) to be defined with six bitplanes.  Under
1.3, you specify EHB mode by setting the [EXTRA_HALFBRITE](libraries/27-display-routines-and-structures-viewport-display-modes.md) bit in the
[ViewPort.Modes](libraries/27-display-routines-and-structures-viewport-display-modes.md) field.  Under Release 2, you specify EHB by selecting any
ModeID which includes EXTRAHALFBRITE in its name as defined in the include
file <graphics/[displayinfo.h](autodocs-2.0/includes-graphics-displayinfo-h.md)>.

When setting up the color palette for an EHB display, you only specify
values for registers 0 to 31.  If you draw using color numbers 0 through
31, the pixel you draw will be the color specified in that particular
system color register.  If you draw using a color number from 32 to 63,
then the color displayed will be half the intensity value of the
corresponding color register from 0 to 31.  For example, if color register
0 is set to 0xFFF (white), then color number 32 would be half this value
or 0x777 (grey).

EHB mode uses all six bitplanes.  The color register (0 through 31) is
obtained from the bit combinations from planes 5 to 1, in that order of
significance.  Plane 6 is used to determine whether the full intensity
(bit value 0) color or half-intensity (bit value 1) color is to be
displayed.

