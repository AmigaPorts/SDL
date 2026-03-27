---
title: 10 / Writing A Graphics Printer Driver / Printertag.asm
manual: devices
chapter: devices
section: 10-writing-a-graphics-printer-driver-printertag-asm
functions: []
libraries: []
---

# 10 / Writing A Graphics Printer Driver / Printertag.asm

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

For a graphic printer the printer-specific values that need to be filled
in in printertag.asm are as follows:

MaxXDots
   The maximum number of dots the printer can print across the page.

MaxYDots
   The maximum number of dots the printer can print down the page.
   Generally, if the printer supports roll or form feed paper, this
   value should be 0 indicating that there is no limit. If the printer
   has a definite y dots maximum (as a laser printer does), this number
   should be entered here.

XDotsInch
   The dot density in x (supplied by [SetDensity()](devices/10-writing-a-graphics-printer-driver-setdensity.md), if it exists).

YDotsInch
   The dot density in y (supplied by [SetDensity()](devices/10-writing-a-graphics-printer-driver-setdensity.md), if it exists).

PrinterClass
   The printer class of the printer.


```c
      PPC_BWALPHA     black&white alphanumeric, no graphics.
      PPC_BWGFX       black&white (only) graphics.
      PPC_COLORALPHA  color alphanumeric, no graphics.
      PPC_COLORGFX    color (and maybe black&white) graphics.
```
ColorClass
   The color class the printer falls into.


      PCC_BW         Black&White only
      PCC_YMC        Yellow Magenta Cyan only.
      PCC_YMC_BW     Yellow Magenta Cyan or Black&White, but not both
      PCC_YMCB       Yellow Magenta Cyan Black
      PCC_WB         White&Black only, 0 is BLACK
      PCC_BGR        Blue Green Red
      PCC_BGR_WB     Blue Green Red or Black&White
      PCC_BGRW       Blue Green Red White
NumRows
   The number of pixel rows printed by one pass of the print head. This
   number is used by the non-printer-specific code to determine when to
   make a render Case 2 call to you. You have to keep this number in
   mind when determining how big a buffer you'll need to store one print
   cycle's worth of data.

