---
title: 27 Graphics Primitives / Function Reference
manual: libraries
chapter: libraries
section: 27-graphics-primitives-function-reference
functions: [AllocRaster, AreaCircle, AreaDraw, AreaEllipse, AreaEnd, AreaMove, BitMapScale, BltBitMap, BltBitMapRastPort, BltClear, BltMaskBitMapRastPort, BltPattern, BltTemplate, CBump, CEND, CINIT, CMOVE, CWAIT, ClipBlit, CloseMonitor, DisownBlitter, Draw, DrawEllipse, FindDisplayInfo, Flood, FreeColorMap, FreeCprList, FreeRaster, FreeVPortCopLists, GetColorMap, GetDisplayInfoData, GetVPModeID, GfxAssociate, GfxFree, GfxNew, InitArea, InitBitMap, InitRastPort, InitVPort, InitView, LoadRGB4, LoadView, MakeVPort, ModeNotAvailable, Move, MrgCop, OpenMonitor, OwnBlitter, PolyDraw, QBSBlit, QBlit, ReadPixel, RectFill, ScrollRaster, SetAPen, SetBPen, SetOPen, SetRGB4CM, SetRast, VideoControl, WaitBlit, WritePixel]
libraries: [graphics.library]
---

# 27 Graphics Primitives / Function Reference

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The following are brief descriptions of the Amiga's graphics primitives.
See the Amiga ROM Kernel Reference Manual: Includes and Autodocs for
details on each function call.


                Table 27-9: Graphics Primitives Functions
  ________________________________________________________________________
 |                                                                        |
 |         Display                                                        |
 |     Set-up Functions              Description                          |
 |========================================================================|
 |           [InitView()](autodocs-2.0/graphics-library-initview.md)  Initializes the [View](libraries/27-display-routines-and-structures-viewport-display-memory.md) structure.                  |
 |         [InitBitMap()](autodocs-2.0/graphics-library-initbitmap.md)  Initializes the [BitMap](libraries/27-display-routines-and-structures-viewport-display-memory.md) structure.                |
 |            [RASSIZE()](autodocs-2.0/includes-graphics-gfx-h.md)  Calculates the size of a [ViewPort](libraries/27-display-routines-and-structures-viewport-display-memory.md)'s BitMap.      |
 |        [AllocRaster()](autodocs-2.0/graphics-library-allocraster.md)  Allocates the bitplanes needed for a BitMap.     |
 |         [FreeRaster()](autodocs-2.0/graphics-library-freeraster.md)  Frees the bitplanes created with AllocRaster().  |
 |          [InitVPort()](autodocs-2.0/graphics-library-initvport.md)  Initializes the ViewPort structure.              |
 |        [GetColorMap()](autodocs-2.0/graphics-library-getcolormap.md)  Returns the [ColorMap](libraries/3-intuition-screens-intuition-screens-and-the-graphics.md) structure used by           |
 |                       ViewPorts.                                       |
 |       [FreeColorMap()](autodocs-2.0/graphics-library-freecolormap.md)  Frees the ColorMap created by GetColorMap().     |
 |           [LoadRGB4()](autodocs-2.0/graphics-library-loadrgb4.md)  Loads the color registers for a given [ViewPort](libraries/27-display-routines-and-structures-viewport-display-memory.md).  |
 |          [SetRGB4CM()](autodocs-2.0/graphics-library-setrgb4cm.md)  Loads an individual color register for a given   |
 |                       ViewPort.                                        |
 |          [MakeVPort()](autodocs-2.0/graphics-library-makevport.md)  Creates the intermediate Copper list program for |
 |                       a ViewPort.                                      |
 |             [MrgCop()](autodocs-2.0/graphics-library-mrgcop.md)  Merges the intermediate Copper lists.            |
 |           [LoadView()](autodocs-2.0/graphics-library-loadview.md)  Displays a given [View](libraries/27-display-routines-and-structures-viewport-display-memory.md).                           |
 |        [FreeCprList()](autodocs-2.0/graphics-library-freecprlist.md)  Frees the Copper list created with MrgCop()      |
 |  [FreeVPortCopLists()](autodocs-2.0/graphics-library-freevportcoplists.md)  Frees the intermediate Copper lists created with |
 |                       MakeVPort().                                     |
 |        [OFF_DISPLAY()](autodocs-2.0/includes-graphics-gfxmacros-h.md)  Turns the video display DMA off                  |
 |         [ON_DISPLAY()](autodocs-2.0/includes-graphics-gfxmacros-h.md)  Turns the video display DMA back on again.       |
 |________________________________________________________________________|

  ________________________________________________________________________
 |                                                                        |
 |    Release 2 Display                                                   |
 |    Set-up Functions               Description                          |
 |========================================================================|
 |     [FindDisplayInfo()](autodocs-2.0/graphics-library-finddisplayinfo.md)  Returns the display database handle for a given |
 |                        ModeID (V36).                                   |
 |  [GetDisplayInfoData()](autodocs-2.0/graphics-library-getdisplayinfodata.md)  Looks up a display attribute in the display     |
 |                        database (V36).                                 |
 |        [VideoControl()](autodocs-2.0/graphics-library-videocontrol.md)  Sets, clears and gets the attributes of an      |
 |                        existing display (V36).                         |
 |              [GfxNew()](autodocs-2.0/graphics-library-gfxnew.md)  Creates [ViewExtra](libraries/27-display-routines-and-structures-forming-a-basic-display.md) or [ViewPortExtra](libraries/27-display-routines-and-structures-forming-a-basic-display.md) used in      |
 |                        Release 2 displays (V36).                       |
 |        [GfxAssociate()](autodocs-2.0/graphics-library-gfxassociate.md)  Attaches a ViewExtra to a [View](libraries/27-display-routines-and-structures-viewport-display-memory.md) (V36).           |
 |             [GfxFree()](autodocs-2.0/graphics-library-gfxfree.md)  Frees the ViewExtra or ViewPortExtra created by |
 |                        GfxNew() (V36).                                 |
 |         [OpenMonitor()](autodocs-2.0/graphics-library-openmonitor.md)  Returns the [MonitorSpec](autodocs-2.0/includes-graphics-monitor-h.md) structure used in       |
 |                        Release 2 Views (V36).                          |
 |        [CloseMonitor()](autodocs-2.0/graphics-library-closemonitor.md)  Frees the MonitorSpec structure created by      |
 |                        OpenMonitor() (V36).                            |
 |         [GetVPModeID()](autodocs-2.0/graphics-library-getvpmodeid.md)  Returns the Release 2 ModeID of an existing     |
 |                        [ViewPort](libraries/27-display-routines-and-structures-viewport-display-memory.md) (V36).                                 |
 |    [ModeNotAvailable()](autodocs-2.0/graphics-library-modenotavailable.md)  Determines if a display mode is available from  |
 |                        a given ModeID (V36).                           |
 |________________________________________________________________________|

  ________________________________________________________________________
 |                                                                        |
 |      Drawing                                                           |
 |     Functions                     Description                          |
 |========================================================================|
 |  [InitRastPort()](autodocs-2.0/graphics-library-initrastport.md)  Initialize a [RastPort](libraries/27-drawing-routines-the-rastport-structure.md) structure.                      |
 |      [InitArea()](autodocs-2.0/graphics-library-initarea.md)  Initialize the [AreaInfo](libraries/27-the-rastport-structure-rastport-area-fill-information.md) structure used with a         |
 |                  RastPort.                                             |
 |     [SetWrMask()](autodocs-2.0/includes-graphics-gfxmacros-h.md)  Set the [RastPort.Mask](libraries/27-the-rastport-structure-rastport-write-mask.md).                                |
 |       [SetAPen()](autodocs-2.0/graphics-library-setapen.md)  Set the [RastPort.FgPen](libraries/27-the-rastport-structure-rastport-drawing-pens.md) foreground pen color.          |
 |       SetBPen()  Set the [RastPort.BgPen](libraries/27-the-rastport-structure-rastport-drawing-pens.md) background pen color.          |
 |       [SetOPen()](autodocs-2.0/graphics-library-setopen.md)  Set the [RastPort.AOlPen](libraries/27-the-rastport-structure-rastport-drawing-pens.md) area fill outline pen color.  |
 |     [SetDrMode()](autodocs-2.0/includes-graphics-gfxmacros-h.md)  Set the [RastPort.DrawMode](libraries/27-the-rastport-structure-rastport-drawing-modes.md) drawing mode.               |
 |       SetDrPt()  Set the RastPort.LinePtrn line drawing pattern.       |
 |       [SetAfPt()](autodocs-2.0/includes-graphics-gfxmacros-h.md)  Set the RastPort area fill pattern and size.          |
 |------------------------------------------------------------------------|
 |    [WritePixel()](autodocs-2.0/graphics-library-writepixel.md)  Draw a single pixel in the foreground color at a      |
 |                  given coordinate.                                     |
 |     [ReadPixel()](autodocs-2.0/graphics-library-readpixel.md)  Find the color of the pixel at a given coordinate.    |
 |    [DrawCircle()](autodocs-2.0/includes-graphics-gfxmacros-h.md)  Draw a circle with a given radius and center point.   |
 |   [DrawEllipse()](autodocs-2.0/graphics-library-drawellipse.md)  Draw an ellipse with the given radii and center       |
 |                  point.                                                |
 |          [Move()](autodocs-2.0/graphics-library-move.md)  Move the [RastPort](libraries/27-drawing-routines-the-rastport-structure.md) drawing pen to a given coordinate.  |
 |          [Draw()](autodocs-2.0/graphics-library-draw.md)  Draw a line from the current pen location to a given  |
 |                  coordinate.                                           |
 |------------------------------------------------------------------------|
 |      [PolyDraw()](autodocs-2.0/graphics-library-polydraw.md)  Draw a polygon with a given set of vertices.          |
 |      [AreaMove()](autodocs-2.0/graphics-library-areamove.md)  Set the anchor point for a filled polygon.            |
 |      [AreaDraw()](autodocs-2.0/graphics-library-areadraw.md)  Add a new vertice to an area-fill polygon.            |
 |       [AreaEnd()](autodocs-2.0/graphics-library-areaend.md)  Close and area-fill polygon, draw it and fill it.     |
 |      [BNDRYOFF()](autodocs-2.0/includes-graphics-gfxmacros-h.md)  Turn off area-outline pen usage activated with        |
 |                  SetOPen().                                            |
 |    [AreaCircle()](autodocs-2.0/graphics-library-areacircle.md)  Draw a filled circle with a given radius and center   |
 |                  point.                                                |
 |   [AreaEllipse()](autodocs-2.0/graphics-library-areaellipse.md)  Draw a filled ellipse with the given radii and center |
 |                  point.                                                |
 |         [Flood()](autodocs-2.0/graphics-library-flood.md)  Flood fill a region starting at a given coordinate.   |
 |      [RectFill()](autodocs-2.0/graphics-library-rectfill.md)  Flood fill a rectangular area at a given location and |
 |                  size.                                                 |
 |________________________________________________________________________|

  ________________________________________________________________________
 |                                                                        |
 |         Data Movement                                                  |
 |           Functions               Description                          |
 |========================================================================|
 |               [BltClear()](autodocs-2.0/graphics-library-bltclear.md)  Use the hardware blitter to clear a block of |
 |                           memory.                                      |
 |                [SetRast()](autodocs-2.0/graphics-library-setrast.md)  Fill the RastPort.BitMap with a given color. |
 |           [ScrollRaster()](autodocs-2.0/graphics-library-scrollraster.md)  Move a portion of a RastPort.BitMap.         |
 |             [BltPattern()](autodocs-2.0/graphics-library-bltpattern.md)  Draw a rectangular pattern of pixels into a  |
 |                           RastPort.BitMap.  The x-dimension of the     |
 |                           rectangle must be word-aligned and           |
 |                           word-sized.                                  |
 |            [BltTemplate()](autodocs-2.0/graphics-library-blttemplate.md)  Draw a rectangular pattern of pixels into a  |
 |                           RastPort.BitMap.  The x-dimension of the     |
 |                           rectangle can be arbitrarily bit-aligned and |
 |                           sized.                                       |
 |              [BltBitMap()](autodocs-2.0/graphics-library-bltbitmap.md)  Copy a rectangular area from one [BitMap](libraries/27-display-routines-and-structures-viewport-display-memory.md) to a |
 |                           given coordinate in another BitMap.          |
 |      [BltBitMapRastPort()](autodocs-2.0/graphics-library-bltbitmaprastport.md)  Copy a rectangular area from a BitMap to a   |
 |                           given coordinate in a RastPort.BitMap.       |
 |  [BltMaskBitMapRastPort()](autodocs-2.0/graphics-library-bltmaskbitmaprastport.md)  Copy a rectangular area from a BitMap to a   |
 |                           RastPort.BitMap through a mask bitplane.     |
 |               [ClipBlit()](autodocs-2.0/graphics-library-clipblit.md)  Copy a rectangular area from one [RastPort](libraries/27-drawing-routines-the-rastport-structure.md) to |
 |                           another with respect to their [Layer](libraries/30-layers-the-layer-structure.md)s.        |
 |            [BitMapScale()](autodocs-2.0/graphics-library-bitmapscale.md)  Scale a rectangular area within a BitMap to  |
 |                           new dimensions (V36).                        |
 |________________________________________________________________________|

  ________________________________________________________________________
 |                                                                        |
 |  Hardware Programming                                                  |
 |       Functions                   Description                          |
 |========================================================================|
 |     [OwnBlitter()](autodocs-2.0/graphics-library-ownblitter.md)  Obtain exclusive access to the Amiga's hardware      |
 |                   blitter.                                             |
 |  [DisownBlitter()](autodocs-2.0/graphics-library-disownblitter.md)  Relinquish exclusive access to the blitter.          |
 |       [WaitBlit()](autodocs-2.0/graphics-library-waitblit.md)  Suspend until the current blitter operation has      |
 |                   completed.                                           |
 |          [QBlit()](autodocs-2.0/graphics-library-qblit.md)  Place a bltnode-style asynchronous blitter request   |
 |                   in the system queue                                  |
 |        [QBSBlit()](autodocs-2.0/graphics-library-qbsblit.md)  Place a bltnode-style asynchronous blitter request   |
 |                   in the beam synchronized queue.                      |
 |------------------------------------------------------------------------|
 |          [CINIT()](autodocs-2.0/graphics-library-cinit.md)  Initialize the user Copper list buffer.              |
 |          [CWAIT()](autodocs-2.0/graphics-library-cwait.md)  Instructs the Copper to wait for the video beam to   |
 |                   reach a given position.                              |
 |          [CMOVE()](autodocs-2.0/graphics-library-cmove.md)  Instructs the Copper to place a value into a given   |
 |                   hardware register.                                   |
 |          [CBump()](autodocs-2.0/graphics-library-cbump.md)  Instructs the Copper to increment its Copper list    |
 |                   pointer.                                             |
 |           [CEND()](autodocs-2.0/graphics-library-cend.md)  Terminate the user Copper list.                      |
 |________________________________________________________________________|

---

## See Also

- [AllocRaster — graphics.library](../autodocs/graphics.library.md#allocraster)
- [AreaCircle — graphics.library](../autodocs/graphics.library.md#areacircle)
- [AreaDraw — graphics.library](../autodocs/graphics.library.md#areadraw)
- [AreaEllipse — graphics.library](../autodocs/graphics.library.md#areaellipse)
- [AreaEnd — graphics.library](../autodocs/graphics.library.md#areaend)
- [AreaMove — graphics.library](../autodocs/graphics.library.md#areamove)
- [BitMapScale — graphics.library](../autodocs/graphics.library.md#bitmapscale)
- [BltBitMap — graphics.library](../autodocs/graphics.library.md#bltbitmap)
- [BltBitMapRastPort — graphics.library](../autodocs/graphics.library.md#bltbitmaprastport)
- [BltClear — graphics.library](../autodocs/graphics.library.md#bltclear)
- [BltMaskBitMapRastPort — graphics.library](../autodocs/graphics.library.md#bltmaskbitmaprastport)
- [BltPattern — graphics.library](../autodocs/graphics.library.md#bltpattern)
- [BltTemplate — graphics.library](../autodocs/graphics.library.md#blttemplate)
- [CBump — graphics.library](../autodocs/graphics.library.md#cbump)
- [CEND — graphics.library](../autodocs/graphics.library.md#cend)
- [CINIT — graphics.library](../autodocs/graphics.library.md#cinit)
- [CMOVE — graphics.library](../autodocs/graphics.library.md#cmove)
- [CWAIT — graphics.library](../autodocs/graphics.library.md#cwait)
- [ClipBlit — graphics.library](../autodocs/graphics.library.md#clipblit)
- [CloseMonitor — graphics.library](../autodocs/graphics.library.md#closemonitor)
- [DisownBlitter — graphics.library](../autodocs/graphics.library.md#disownblitter)
- [Draw — graphics.library](../autodocs/graphics.library.md#draw)
- [DrawEllipse — graphics.library](../autodocs/graphics.library.md#drawellipse)
- [FindDisplayInfo — graphics.library](../autodocs/graphics.library.md#finddisplayinfo)
- [Flood — graphics.library](../autodocs/graphics.library.md#flood)
- [FreeColorMap — graphics.library](../autodocs/graphics.library.md#freecolormap)
- [FreeCprList — graphics.library](../autodocs/graphics.library.md#freecprlist)
- [FreeRaster — graphics.library](../autodocs/graphics.library.md#freeraster)
- [FreeVPortCopLists — graphics.library](../autodocs/graphics.library.md#freevportcoplists)
- [GetColorMap — graphics.library](../autodocs/graphics.library.md#getcolormap)
- [GetDisplayInfoData — graphics.library](../autodocs/graphics.library.md#getdisplayinfodata)
- [GetVPModeID — graphics.library](../autodocs/graphics.library.md#getvpmodeid)
- [GfxAssociate — graphics.library](../autodocs/graphics.library.md#gfxassociate)
- [GfxFree — graphics.library](../autodocs/graphics.library.md#gfxfree)
- [GfxNew — graphics.library](../autodocs/graphics.library.md#gfxnew)
- [InitArea — graphics.library](../autodocs/graphics.library.md#initarea)
- [InitBitMap — graphics.library](../autodocs/graphics.library.md#initbitmap)
- [InitRastPort — graphics.library](../autodocs/graphics.library.md#initrastport)
- [InitVPort — graphics.library](../autodocs/graphics.library.md#initvport)
- [InitView — graphics.library](../autodocs/graphics.library.md#initview)
- [LoadRGB4 — graphics.library](../autodocs/graphics.library.md#loadrgb4)
- [LoadView — graphics.library](../autodocs/graphics.library.md#loadview)
- [MakeVPort — graphics.library](../autodocs/graphics.library.md#makevport)
- [ModeNotAvailable — graphics.library](../autodocs/graphics.library.md#modenotavailable)
- [Move — graphics.library](../autodocs/graphics.library.md#move)
- [MrgCop — graphics.library](../autodocs/graphics.library.md#mrgcop)
- [OpenMonitor — graphics.library](../autodocs/graphics.library.md#openmonitor)
- [OwnBlitter — graphics.library](../autodocs/graphics.library.md#ownblitter)
- [PolyDraw — graphics.library](../autodocs/graphics.library.md#polydraw)
- [QBSBlit — graphics.library](../autodocs/graphics.library.md#qbsblit)
- [QBlit — graphics.library](../autodocs/graphics.library.md#qblit)
- [ReadPixel — graphics.library](../autodocs/graphics.library.md#readpixel)
- [RectFill — graphics.library](../autodocs/graphics.library.md#rectfill)
- [ScrollRaster — graphics.library](../autodocs/graphics.library.md#scrollraster)
- [SetAPen — graphics.library](../autodocs/graphics.library.md#setapen)
- [SetBPen — graphics.library](../autodocs/graphics.library.md#setbpen)
- [SetOPen — graphics.library](../autodocs/graphics.library.md#setopen)
- [SetRGB4CM — graphics.library](../autodocs/graphics.library.md#setrgb4cm)
- [SetRast — graphics.library](../autodocs/graphics.library.md#setrast)
- [VideoControl — graphics.library](../autodocs/graphics.library.md#videocontrol)
- [WaitBlit — graphics.library](../autodocs/graphics.library.md#waitblit)
- [WritePixel — graphics.library](../autodocs/graphics.library.md#writepixel)
