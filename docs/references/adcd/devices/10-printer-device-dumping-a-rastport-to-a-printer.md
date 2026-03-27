---
title: 10 Printer Device / Dumping a Rastport to a Printer
manual: devices
chapter: devices
section: 10-printer-device-dumping-a-rastport-to-a-printer
functions: [DoIO, GetVPModeID, SendIO]
libraries: [exec.library, graphics.library]
---

# 10 Printer Device / Dumping a Rastport to a Printer

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

You dump a [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) (drawing area) to a graphics capable printer by
passing an [IODRPReq](autodocs-2.0/includes-devices-printer-h.md) to the device with [PRD_DUMPRPORT](autodocs-2.0/printer-device-prd-dumprport.md) set in io_Command
along with several parameters that define how the dump is to be rendered.


```c
    union printerIO *PrintIO
    struct RastPort *rastPort;
    struct ColorMap *colorMap;
    ULONG modeid;
    UWORD sx, sy, sw, sh;
    LONG dc, dr;
    UWORD s;

    PrintIO->iodrp.io_RastPort = rastPort; /* pointer to RastPort */
    PrintIO->iodrp.io_ColorMap = colorMap; /* pointer to color map */
    PrintIO->iodrp.io_Modes = modeid;      /* ModeID of ViewPort */
    PrintIO->iodrp.io_SrcX = sx;           /* RastPort X offset */
    PrintIO->iodrp.io_SrcY = sy;           /* RastPort Y offset */
    PrintIO->iodrp.io_SrcWidth = sw;       /* print width from X offset */
    PrintIO->iodrp.io_SrcHeight = sh;      /* print height from Y offset */
    PrintIO->iodrp.io_DestCols = dc;       /* pixel width */
    PrintIO->iodrp.io_DestRows = dr;       /* pixel height */
    PrintIO->iodrp.io_Special = s;         /* flags */
    PrintIO->iodrp.io_Command = PRD_DUMPRPORT;
    SendIO((struct IORequest *)request);
```
The asynchronous [SendIO()](autodocs-2.0/exec-library-sendio.md) routine is used in this example instead of the
synchronous [DoIO()](autodocs-2.0/exec-library-doio.md).  A call to DoIO() does not return until the I/O
request is finished. A call to SendIO() returns immediately.  This allows
your task to do other processing such as checking if the user wants to
abort the I/O request.  It should also be used when writing a lot of text
or raw data with [CMD_WRITE](autodocs-2.0/printer-device-cmd-write.md) and [PRD_RAWWRITE](autodocs-2.0/printer-device-prd-rawwrite.md).

Here is an overview of the possible arguments for the [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) dump.

   io_RastPort     A pointer to a [RastPort](autodocs-2.0/includes-graphics-rastport-h.md). The RastPort's [bitmap](autodocs-2.0/includes-graphics-gfx-h.md) could be

                   in Fast memory.
   io_ColorMap     A pointer to a [ColorMap](autodocs-2.0/includes-graphics-view-h.md). This could be a custom one.
   io_Modes        The viewmode flags or the ModeID returned from

```c
                   GetVPModeID() (V36).
```
   io_SrcX         X offset in the RastPort to start printing from.
   io_SrcY         Y offset in the RastPort to start printing from.
   io_SrcWidth     Width of the RastPort to print from io_SrcX.
   io_SrcHeight    Height of the RastPort to print from io_SrcY.
   io_DestCols     Width of the dump in printer pixels.
   io_DestRows     Height of the dump in printer pixels.
   io_Special      Flag bits (described below).

Looking at these arguments you can see the enormous flexibility the
printer device offers for dumping a [RastPort](autodocs-2.0/includes-graphics-rastport-h.md). The RastPort pointed to
could be totally custom defined. This flexibility means it is possible to
build a [BitMap](autodocs-2.0/includes-graphics-gfx-h.md) with the resolution of the printer. This would result in
having one pixel of the BitMap correspond to one pixel of the printer. In
other words, only the resolution of the output device would limit the
final result. With 12 bit planes and a custom [ColorMap](autodocs-2.0/includes-graphics-view-h.md), you could dump
4096 colors - without the HAM limitation - to a suitable printer. The
offset, width and height parameters allow dumps of any desired part of the
picture. Finally the [ViewPort](autodocs-2.0/includes-graphics-view-h.md) mode, io_DestCols, io_DestRows parameters,
together with the io_Special flags define how the dump will appear on
paper and aid in getting the correct aspect ratio.

 [Printer Special Flags](devices/10-dumping-a-rastport-to-a-printer-printer-special-flags.md) 
 [Printing With Corrected Aspect Ratio](devices/10-dumping-rastport-to-a-printer-printing-corrected-aspect.md) 
 [Strip Printing](devices/10-dumping-a-rastport-to-a-printer-strip-printing.md) 
 [Additional Notes About Graphic Dumps](devices/10-dumping-rastport-to-a-printer-additional-notes-on.md) 

---

## See Also

- [DoIO — exec.library](../autodocs/exec.library.md#doio)
- [GetVPModeID — graphics.library](../autodocs/graphics.library.md#getvpmodeid)
- [SendIO — exec.library](../autodocs/exec.library.md#sendio)
