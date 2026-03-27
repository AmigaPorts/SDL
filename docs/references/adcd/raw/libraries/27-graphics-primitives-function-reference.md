# 27 Graphics Primitives / Function Reference


The following are brief descriptions of the Amiga's graphics primitives.
See the Amiga ROM Kernel Reference Manual: Includes and Autodocs for
details on each function call.


                Table 27-9: Graphics Primitives Functions
  ________________________________________________________________________
 |                                                                        |
 |         Display                                                        |
 |     Set-up Functions              Description                          |
 |========================================================================|
 |           [InitView()](../Includes_and_Autodocs_2._guide/node0456.html)  Initializes the [View](../Libraries_Manual_guide/node032B.html#line51) structure.                  |
 |         [InitBitMap()](../Includes_and_Autodocs_2._guide/node0450.html)  Initializes the [BitMap](../Libraries_Manual_guide/node032B.html#line74) structure.                |
 |            [RASSIZE()](../Includes_and_Autodocs_2._guide/node00A6.html#line57)  Calculates the size of a [ViewPort](../Libraries_Manual_guide/node032B.html#line59)'s BitMap.      |
 |        [AllocRaster()](../Includes_and_Autodocs_2._guide/node0412.html)  Allocates the bitplanes needed for a BitMap.     |
 |         [FreeRaster()](../Includes_and_Autodocs_2._guide/node0442.html)  Frees the bitplanes created with AllocRaster().  |
 |          [InitVPort()](../Includes_and_Autodocs_2._guide/node0457.html)  Initializes the ViewPort structure.              |
 |        [GetColorMap()](../Includes_and_Autodocs_2._guide/node0445.html)  Returns the [ColorMap](../Libraries_Manual_guide/node00F1.html#line4) structure used by           |
 |                       ViewPorts.                                       |
 |       [FreeColorMap()](../Includes_and_Autodocs_2._guide/node043E.html)  Frees the ColorMap created by GetColorMap().     |
 |           [LoadRGB4()](../Includes_and_Autodocs_2._guide/node0458.html)  Loads the color registers for a given [ViewPort](../Libraries_Manual_guide/node032B.html#line59).  |
 |          [SetRGB4CM()](../Includes_and_Autodocs_2._guide/node047D.html)  Loads an individual color register for a given   |
 |                       ViewPort.                                        |
 |          [MakeVPort()](../Includes_and_Autodocs_2._guide/node045B.html)  Creates the intermediate Copper list program for |
 |                       a ViewPort.                                      |
 |             [MrgCop()](../Includes_and_Autodocs_2._guide/node045F.html)  Merges the intermediate Copper lists.            |
 |           [LoadView()](../Includes_and_Autodocs_2._guide/node0459.html)  Displays a given [View](../Libraries_Manual_guide/node032B.html#line51).                           |
 |        [FreeCprList()](../Includes_and_Autodocs_2._guide/node0440.html)  Frees the Copper list created with MrgCop()      |
 |  [FreeVPortCopLists()](../Includes_and_Autodocs_2._guide/node0444.html)  Frees the intermediate Copper lists created with |
 |                       MakeVPort().                                     |
 |        [OFF_DISPLAY()](../Includes_and_Autodocs_2._guide/node00B6.html#line22)  Turns the video display DMA off                  |
 |         [ON_DISPLAY()](../Includes_and_Autodocs_2._guide/node00B6.html#line22)  Turns the video display DMA back on again.       |
 |________________________________________________________________________|

  ________________________________________________________________________
 |                                                                        |
 |    Release 2 Display                                                   |
 |    Set-up Functions               Description                          |
 |========================================================================|
 |     [FindDisplayInfo()](../Includes_and_Autodocs_2._guide/node043B.html)  Returns the display database handle for a given |
 |                        ModeID (V36).                                   |
 |  [GetDisplayInfoData()](../Includes_and_Autodocs_2._guide/node0446.html)  Looks up a display attribute in the display     |
 |                        database (V36).                                 |
 |        [VideoControl()](../Includes_and_Autodocs_2._guide/node0488.html)  Sets, clears and gets the attributes of an      |
 |                        existing display (V36).                         |
 |              [GfxNew()](../Includes_and_Autodocs_2._guide/node044E.html)  Creates [ViewExtra](../Libraries_Manual_guide/node032C.html#line16) or [ViewPortExtra](../Libraries_Manual_guide/node032C.html#line16) used in      |
 |                        Release 2 displays (V36).                       |
 |        [GfxAssociate()](../Includes_and_Autodocs_2._guide/node044B.html)  Attaches a ViewExtra to a [View](../Libraries_Manual_guide/node032B.html#line51) (V36).           |
 |             [GfxFree()](../Includes_and_Autodocs_2._guide/node044C.html)  Frees the ViewExtra or ViewPortExtra created by |
 |                        GfxNew() (V36).                                 |
 |         [OpenMonitor()](../Includes_and_Autodocs_2._guide/node0463.html)  Returns the [MonitorSpec](../Includes_and_Autodocs_2._guide/node00A7.html#line26) structure used in       |
 |                        Release 2 Views (V36).                          |
 |        [CloseMonitor()](../Includes_and_Autodocs_2._guide/node042F.html)  Frees the MonitorSpec structure created by      |
 |                        OpenMonitor() (V36).                            |
 |         [GetVPModeID()](../Includes_and_Autodocs_2._guide/node044A.html)  Returns the Release 2 ModeID of an existing     |
 |                        [ViewPort](../Libraries_Manual_guide/node032B.html#line59) (V36).                                 |
 |    [ModeNotAvailable()](../Includes_and_Autodocs_2._guide/node045C.html)  Determines if a display mode is available from  |
 |                        a given ModeID (V36).                           |
 |________________________________________________________________________|

  ________________________________________________________________________
 |                                                                        |
 |      Drawing                                                           |
 |     Functions                     Description                          |
 |========================================================================|
 |  [InitRastPort()](../Includes_and_Autodocs_2._guide/node0454.html)  Initialize a [RastPort](../Libraries_Manual_guide/node034A.html) structure.                      |
 |      [InitArea()](../Includes_and_Autodocs_2._guide/node044F.html)  Initialize the [AreaInfo](../Libraries_Manual_guide/node034D.html) structure used with a         |
 |                  RastPort.                                             |
 |     [SetWrMask()](../Includes_and_Autodocs_2._guide/node00B6.html#line30)  Set the [RastPort.Mask](../Libraries_Manual_guide/node034F.html).                                |
 |       [SetAPen()](../Includes_and_Autodocs_2._guide/node0475.html)  Set the [RastPort.FgPen](../Libraries_Manual_guide/node0350.html#line3) foreground pen color.          |
 |       SetBPen()  Set the [RastPort.BgPen](../Libraries_Manual_guide/node0350.html#line6) background pen color.          |
 |       [SetOPen()](../Includes_and_Autodocs_2._guide/node047A.html)  Set the [RastPort.AOlPen](../Libraries_Manual_guide/node0350.html#line9) area fill outline pen color.  |
 |     [SetDrMode()](../Includes_and_Autodocs_2._guide/node00B6.html#line30)  Set the [RastPort.DrawMode](../Libraries_Manual_guide/node0351.html) drawing mode.               |
 |       SetDrPt()  Set the RastPort.LinePtrn line drawing pattern.       |
 |       [SetAfPt()](../Includes_and_Autodocs_2._guide/node00B6.html#line30)  Set the RastPort area fill pattern and size.          |
 |------------------------------------------------------------------------|
 |    [WritePixel()](../Includes_and_Autodocs_2._guide/node048D.html)  Draw a single pixel in the foreground color at a      |
 |                  given coordinate.                                     |
 |     [ReadPixel()](../Includes_and_Autodocs_2._guide/node046A.html)  Find the color of the pixel at a given coordinate.    |
 |    [DrawCircle()](../Includes_and_Autodocs_2._guide/node00B6.html#line42)  Draw a circle with a given radius and center point.   |
 |   [DrawEllipse()](../Includes_and_Autodocs_2._guide/node0437.html)  Draw an ellipse with the given radii and center       |
 |                  point.                                                |
 |          [Move()](../Includes_and_Autodocs_2._guide/node045D.html)  Move the [RastPort](../Libraries_Manual_guide/node034A.html) drawing pen to a given coordinate.  |
 |          [Draw()](../Includes_and_Autodocs_2._guide/node0436.html)  Draw a line from the current pen location to a given  |
 |                  coordinate.                                           |
 |------------------------------------------------------------------------|
 |      [PolyDraw()](../Includes_and_Autodocs_2._guide/node0467.html)  Draw a polygon with a given set of vertices.          |
 |      [AreaMove()](../Includes_and_Autodocs_2._guide/node041A.html)  Set the anchor point for a filled polygon.            |
 |      [AreaDraw()](../Includes_and_Autodocs_2._guide/node0417.html)  Add a new vertice to an area-fill polygon.            |
 |       [AreaEnd()](../Includes_and_Autodocs_2._guide/node0419.html)  Close and area-fill polygon, draw it and fill it.     |
 |      [BNDRYOFF()](../Includes_and_Autodocs_2._guide/node00B6.html#line35)  Turn off area-outline pen usage activated with        |
 |                  SetOPen().                                            |
 |    [AreaCircle()](../Includes_and_Autodocs_2._guide/node0416.html)  Draw a filled circle with a given radius and center   |
 |                  point.                                                |
 |   [AreaEllipse()](../Includes_and_Autodocs_2._guide/node0418.html)  Draw a filled ellipse with the given radii and center |
 |                  point.                                                |
 |         [Flood()](../Includes_and_Autodocs_2._guide/node043C.html)  Flood fill a region starting at a given coordinate.   |
 |      [RectFill()](../Includes_and_Autodocs_2._guide/node046D.html)  Flood fill a rectangular area at a given location and |
 |                  size.                                                 |
 |________________________________________________________________________|

  ________________________________________________________________________
 |                                                                        |
 |         Data Movement                                                  |
 |           Functions               Description                          |
 |========================================================================|
 |               [BltClear()](../Includes_and_Autodocs_2._guide/node0421.html)  Use the hardware blitter to clear a block of |
 |                           memory.                                      |
 |                [SetRast()](../Includes_and_Autodocs_2._guide/node047B.html)  Fill the RastPort.BitMap with a given color. |
 |           [ScrollRaster()](../Includes_and_Autodocs_2._guide/node0473.html)  Move a portion of a RastPort.BitMap.         |
 |             [BltPattern()](../Includes_and_Autodocs_2._guide/node0423.html)  Draw a rectangular pattern of pixels into a  |
 |                           RastPort.BitMap.  The x-dimension of the     |
 |                           rectangle must be word-aligned and           |
 |                           word-sized.                                  |
 |            [BltTemplate()](../Includes_and_Autodocs_2._guide/node0424.html)  Draw a rectangular pattern of pixels into a  |
 |                           RastPort.BitMap.  The x-dimension of the     |
 |                           rectangle can be arbitrarily bit-aligned and |
 |                           sized.                                       |
 |              [BltBitMap()](../Includes_and_Autodocs_2._guide/node041F.html)  Copy a rectangular area from one [BitMap](../Libraries_Manual_guide/node032B.html#line74) to a |
 |                           given coordinate in another BitMap.          |
 |      [BltBitMapRastPort()](../Includes_and_Autodocs_2._guide/node0420.html)  Copy a rectangular area from a BitMap to a   |
 |                           given coordinate in a RastPort.BitMap.       |
 |  [BltMaskBitMapRastPort()](../Includes_and_Autodocs_2._guide/node0422.html)  Copy a rectangular area from a BitMap to a   |
 |                           RastPort.BitMap through a mask bitplane.     |
 |               [ClipBlit()](../Includes_and_Autodocs_2._guide/node042D.html)  Copy a rectangular area from one [RastPort](../Libraries_Manual_guide/node034A.html) to |
 |                           another with respect to their [Layer](../Libraries_Manual_guide/node03E4.html)s.        |
 |            [BitMapScale()](../Includes_and_Autodocs_2._guide/node041E.html)  Scale a rectangular area within a BitMap to  |
 |                           new dimensions (V36).                        |
 |________________________________________________________________________|

  ________________________________________________________________________
 |                                                                        |
 |  Hardware Programming                                                  |
 |       Functions                   Description                          |
 |========================================================================|
 |     [OwnBlitter()](../Includes_and_Autodocs_2._guide/node0466.html)  Obtain exclusive access to the Amiga's hardware      |
 |                   blitter.                                             |
 |  [DisownBlitter()](../Includes_and_Autodocs_2._guide/node0433.html)  Relinquish exclusive access to the blitter.          |
 |       [WaitBlit()](../Includes_and_Autodocs_2._guide/node0489.html)  Suspend until the current blitter operation has      |
 |                   completed.                                           |
 |          [QBlit()](../Includes_and_Autodocs_2._guide/node0468.html)  Place a bltnode-style asynchronous blitter request   |
 |                   in the system queue                                  |
 |        [QBSBlit()](../Includes_and_Autodocs_2._guide/node0469.html)  Place a bltnode-style asynchronous blitter request   |
 |                   in the beam synchronized queue.                      |
 |------------------------------------------------------------------------|
 |          [CINIT()](../Includes_and_Autodocs_2._guide/node0428.html)  Initialize the user Copper list buffer.              |
 |          [CWAIT()](../Includes_and_Autodocs_2._guide/node0432.html)  Instructs the Copper to wait for the video beam to   |
 |                   reach a given position.                              |
 |          [CMOVE()](../Includes_and_Autodocs_2._guide/node0430.html)  Instructs the Copper to place a value into a given   |
 |                   hardware register.                                   |
 |          [CBump()](../Includes_and_Autodocs_2._guide/node0425.html)  Instructs the Copper to increment its Copper list    |
 |                   pointer.                                             |
 |           [CEND()](../Includes_and_Autodocs_2._guide/node0426.html)  Terminate the user Copper list.                      |
 |________________________________________________________________________|

