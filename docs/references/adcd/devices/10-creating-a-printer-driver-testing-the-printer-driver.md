---
title: 10 / Creating a Printer Driver / Testing The Printer Driver
manual: devices
chapter: devices
section: 10-creating-a-printer-driver-testing-the-printer-driver
functions: []
libraries: []
---

# 10 / Creating a Printer Driver / Testing The Printer Driver

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

A printer driver should be thoroughly tested before it is released. Though
labor intensive, the alphanumeric part of a driver can be easily tested.
The graphics part is more difficult.  Following are some recommendations
on how to test this part.

Start with a black and white (threshold 8), grey scale and color dump of
the same picture. The color dump should be in color, of course. The grey
scale dump should be like the color dump, except it will consist of
patterns of black dots. The black and white dump will have solid black and
solid white areas.

Next, do a dump with the DestX and DestY dots set to an even multiple of
the XDotsInch and YDotsInch for the printer. For example, if the printer
has a resolution of 120 x 144 dpi, a 480 x 432 dump could be done. This
should produce a printed picture which covers 4 x 3 inches on paper. If
the width of the picture is off, then the wrong value for XDotsInch has
been put in [printertag.asm](devices/10-writing-a-graphics-printer-driver-printertag-asm.md). If the height of the picture is off, the wrong
value for YDotsInch is in printertag.asm.

Do a color dump as wide as the printer can handle with the density set to
7.

Make sure that the printer doesn't force graphic dumps to be done within
the text margins. This can easily be tested by setting the text margins to
30 and 50, the pitch to 10 cpi and then doing a graphic dump wider than 2
inches. The dump should be left justified and as wide as you instructed.
If the dump starts at character position 30 and is cut off at position 50,
the driver will have to be changed. These changes involve clearing the
margins before the dump (Case 0) and restoring the margins after the dump
(Case 4). An example of this is present in render.c source example listed
at the end of this chapter.

   The Invisible Setup.
   --------------------
   Before the graphic dump, some text must be sent to the printer to
   have the printer device initialize the printer. The "text" sent
   does not have to contain any printable characters (i.e., you can send
   a carriage return or other control characters).

As a final test, construct an image with a white background that has
objects in it surrounded by white space. Dump this as black and white,
grey scale and color. This will test the white-space stripping or RLE, and
the ability of the driver to handle null lines. The white data areas
should be separated by at least as many lines of white space as the
NumRows value in the [printertag.asm](devices/10-writing-a-graphics-printer-driver-printertag-asm.md) file.

