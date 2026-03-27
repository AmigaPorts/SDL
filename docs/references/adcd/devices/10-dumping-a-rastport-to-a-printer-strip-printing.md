---
title: 10 / Dumping a Rastport to a Printer / Strip Printing
manual: devices
chapter: devices
section: 10-dumping-a-rastport-to-a-printer-strip-printing
functions: []
libraries: []
---

# 10 / Dumping a Rastport to a Printer / Strip Printing

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Strip printing is a method which allows you to print a picture that
normally requires a large print buffer when there is not much memory
available. This would allow, for example, a [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) to be printed at a
higher resolution than it was drawn in. Strip printing is done by creating
a temporary RastPort as wide as the source RastPort, but not as high. The
source RastPort is then rendered, a strip at a time, into the temporary
RastPort which is dumped to the printer.

The height of the strip to dump must be an integer multiple of the
printer's NumRows if a non-aspect-ratio-corrected image is to be printed.

For an aspect-ratio-corrected image, the [SPECIAL_NOPRINT](devices/10-dumping-a-rastport-to-a-printer-printer-special-flags.md) flag will have
to be used to find an io_DestRows that is an integer multiple of NumRows.
This can be done by varying the source height and asking for a
SPECIAL_NOPRINT dump until io_DestRows holds a number that is an integer
multiple of the printer's NumRows.

If smoothing is to work with strip printing, a raster line above and below
the actual area should be added. The line above should be the last line
from the previous strip, the line below should be the first line of the
next strip. Of course, the first strip should not have a line added above
and the last strip should not have a line added below.

The following is a strip printing procedure for a [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) which is 200
lines high.

First strip

   * copy source line 0 through 50 (51 lines) to strip [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) lines 0
```c
     through 50 (51 lines).
```
   * io_SrcY = 0, io_Height = 50.
   * the printer device can see there is no line above the first line to

```c
     dump (since SrcY = 0) and that there is a line below the last line to
     dump (since there is a 51 line RastPort and only 50 lines are dumped).
```
Second strip

   * copy source line 49 through 100 (52 lines) to strip [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) lines 0
```c
     through 51 (52 lines).
```
   * io_SrcY = 1, io_Height = 50.
   * the printer device can see there is a line above the first line to

```c
     dump (since SrcY = 1) and that there is a line below the last line to
     dump (since there is a 52 line [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) and only 50 lines are dumped).
```
Third strip

   * copy source line 99 through 150 (52 lines) to strip [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) lines 0
```c
     through 51 (52 lines).
```
   * io_SrcY = 1, io_Height = 50.
   * the printer device can see there is a line above the first line to

```c
     dump (since SrcY = 1) and that there is a line below the last line to
     dump (since there is a 52 line [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) and only 50 lines are dumped).
```
Fourth strip

   * copy source line 149 through 199 (51 lines) to strip [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) lines 0
```c
     through 50 (51 lines).
```
   * io_SrcY = 1, io_Height = 50.
   * the printer device can see there is a line above the first line to

```c
     dump (since SrcY = 1) and that there is no line below the last line to
     dump (since there is a 51 line [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) and only 50 lines are dumped).
```
