# 10 Printer Device / Dumping a Rastport to a Printer


You dump a [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) (drawing area) to a graphics capable printer by
passing an [IODRPReq](../Includes_and_Autodocs_2._guide/node0052.html#line155) to the device with [PRD_DUMPRPORT](../Includes_and_Autodocs_2._guide/node0519.html) set in io_Command
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
The asynchronous [SendIO()](../Includes_and_Autodocs_2._guide/node037A.html) routine is used in this example instead of the
synchronous [DoIO()](../Includes_and_Autodocs_2._guide/node034B.html).  A call to DoIO() does not return until the I/O
request is finished. A call to SendIO() returns immediately.  This allows
your task to do other processing such as checking if the user wants to
abort the I/O request.  It should also be used when writing a lot of text
or raw data with [CMD_WRITE](../Includes_and_Autodocs_2._guide/node0518.html) and [PRD_RAWWRITE](../Includes_and_Autodocs_2._guide/node051C.html).

Here is an overview of the possible arguments for the [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) dump.

   io_RastPort     A pointer to a [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55). The RastPort's [bitmap](../Includes_and_Autodocs_2._guide/node00A6.html#line47) could be

                   in Fast memory.
   io_ColorMap     A pointer to a [ColorMap](../Includes_and_Autodocs_2._guide/node00B8.html#line113). This could be a custom one.
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
printer device offers for dumping a [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55). The RastPort pointed to
could be totally custom defined. This flexibility means it is possible to
build a [BitMap](../Includes_and_Autodocs_2._guide/node00A6.html#line47) with the resolution of the printer. This would result in
having one pixel of the BitMap correspond to one pixel of the printer. In
other words, only the resolution of the output device would limit the
final result. With 12 bit planes and a custom [ColorMap](../Includes_and_Autodocs_2._guide/node00B8.html#line113), you could dump
4096 colors - without the HAM limitation - to a suitable printer. The
offset, width and height parameters allow dumps of any desired part of the
picture. Finally the [ViewPort](../Includes_and_Autodocs_2._guide/node00B8.html#line40) mode, io_DestCols, io_DestRows parameters,
together with the io_Special flags define how the dump will appear on
paper and aid in getting the correct aspect ratio.

 [Printer Special Flags](../Devices_Manual_guide/node0050.html) 
 [Printing With Corrected Aspect Ratio](../Devices_Manual_guide/node0051.html) 
 [Strip Printing](../Devices_Manual_guide/node0052.html) 
 [Additional Notes About Graphic Dumps](../Devices_Manual_guide/node0053.html) 

