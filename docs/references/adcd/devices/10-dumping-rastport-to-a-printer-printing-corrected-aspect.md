---
title: 10 / Dumping Rastport to a Printer / Printing Corrected Aspect Ratio
manual: devices
chapter: devices
section: 10-dumping-rastport-to-a-printer-printing-corrected-aspect
functions: []
libraries: []
---

# 10 / Dumping Rastport to a Printer / Printing Corrected Aspect Ratio

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Using the special flags it is fairly easy to ensure a graphic dump will
have the correct aspect ratio on paper. There are some considerations
though when printing a non-displayed [RastPort](autodocs-2.0/includes-graphics-rastport-h.md).  One way to get a corrected
aspect ratio dump is to calculate the printer's ratio from XDotsInch and
YDotsInch (taking into account that the printer may not have square
pixels) and then adjust the width and height parameters accordingly. You
then ask for a non-aspect-ratio-corrected dump since you already corrected
it yourself.

Another possibility is having the printer device do it for you. To get a
correct calculation you could build your [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) dimensions in two ways:


   1. Using an integer multiple of one of the standard (NTSC) display

```c
      resolutions and setting the io_Modes argument accordingly. For
      example if your [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) dimensions were 1280 x 800 (an even multiple
      of 640 x 400) you would set io_Modes to LACE | HIRES. Setting the
      [SPECIAL_ASPECT](devices/10-dumping-a-rastport-to-a-printer-printer-special-flags.md) flag would enable the printer device to properly
      calculate the aspect ratio of the image.
```
   2. When using an arbitrary sized [RastPort](autodocs-2.0/includes-graphics-rastport-h.md), you can supply the ModeID of

```c
      a display mode which has the aspect ratio you would like for your
      RastPort. The aspect ratio of the various display modes are defined
      as ticks-per-pixel in the Resolution field of the [DisplayInfo](autodocs-2.0/includes-graphics-displayinfo-h.md)
      structure.  You can obtain this value from the graphics database.
      For example, the resolution of Productivity Mode is 22:22, in other
      words, 1:1, perfect for a RastPort sized to the limits of the output
      device.  See the "[Graphics Library](libraries/graphics-libraries.md)" chapters of the  Amiga ROM
      Kernel Reference Manual: Libraries for general information on the
      graphics system.
```
The following example will dump a [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) to the printer and wait for
either the printer to finish or the user to cancel the dump and act
accordingly.


```c
     [Demo_Dump.c](devices/devices-dev-examples-demo-dump-c.md) 
```
