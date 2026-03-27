---
title: 10 / Dumping a Rastport to a Printer / Printer Special Flags
manual: devices
chapter: devices
section: 10-dumping-a-rastport-to-a-printer-printer-special-flags
functions: []
libraries: []
---

# 10 / Dumping a Rastport to a Printer / Printer Special Flags

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The printer special flags (io_Flags) of the [IODRPReq](devices/10-printer-device-device-interface.md) provide a high degree
of control over the printing of a [RastPort](autodocs-2.0/includes-graphics-rastport-h.md).

   SPECIAL_ASPECT       Allows one of the dimensions to be

                        reduced/expanded to preserve the correct
                        aspect ratio of the printout.
   SPECIAL_CENTER       Centers the image between the left and right

                        edge of the paper.
   SPECIAL_NOFORMFEED   Prevents the page from being ejected after

```c
                        a graphics dump.  Usually used to mix graphics and
                        text or multiple graphics dump on a page oriented
                        printer (normally a laser printer).
```
   SPECIAL_NOPRINT      The print size will be computed, and set

                        in io_DestCols and io_DestRows, but won't print.
                        This way the application can see what the actual
                        printsize in printerpixels would be.
   SPECIAL_TRUSTME      Instructs the printer not to send a reset

```c
                        before and after the dump.  This flag is obsolete
                        for V1.3 (and higher) drivers.
```
   SPECIAL_DENSITY1-7   This flag bit is set by the user in Preferences.

```c
                        Refer to "Reading and Changing the Printer
                        [Preferences Settings](devices/10-printer-device-reading-and-changing-printer-preferences.md)" if you want to change to
                        density of the printout. (Or any other setting for
                        that matter.)
```
   SPECIAL_FULLCOLS     The width is set to the maximum possible,

                        as determined by the printer or the configuration
                        limits.
   SPECIAL_FULLROWS     The height is set to the maximum possible, as

                        determined by the printer or the configuration
                        limits.
   SPECIAL_FRACCOLS     Informs the printer device that the value in

```c
                        io_DestCols is to be taken as a longword binary
                        fraction of the maximum for the dimension.  For
                        example, if io_DestCols is 0x8000, the width
                        would be 1/2 (0x8000 / 0xffff) of the width of
                        the paper.
```
   SPECIAL_FRACROWS     Informs the printer device that the value in

                        io_DestRows is to be taken as a longword binary
                        fraction for the dimension.
   SPECIAL_MILCOLS      Informs the printer device that the value in

                        io_DestCols is specified in thousandths of an inch.
                        For example, if io_DestCols is 8000, the width of
                        the printout would be 8.000 inches.
   SPECIAL_MILROWS      Informs the printer device that the value in

                        io_DestRows is specified in thousandths of an inch.
The flags are defined in the include file devices/[printer.h](autodocs-2.0/includes-devices-printer-h.md).

