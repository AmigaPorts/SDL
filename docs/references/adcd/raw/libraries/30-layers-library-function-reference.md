# 30 Layers Library / Function Reference


The following are brief descriptions of the layers library functions and
related routines from the graphics library.  See the Amiga ROM Kernel
Reference Manual: Includes and Autodocs for details on each function call.


                  Table 30-5: Layers Library Functions
  ______________________________________________________________________
 |                                                                      |
 |              Function                   Description                  |
 |======================================================================|
 |              [NewLayerInfo()](../Includes_and_Autodocs_2._guide/node03A1.html)  Allocating a [Layer_Info](../Includes_and_Autodocs_2._guide/node00C4.html#line33) structure.      |
 |          [DisposeLayerInfo()](../Includes_and_Autodocs_2._guide/node0395.html)  Deallocating a Layer_Info structure.    |
 |----------------------------------------------------------------------|
 |        [CreateUpfrontLayer()](../Includes_and_Autodocs_2._guide/node0393.html)  Make a new layer in front of others.    |
 |         [CreateBehindLayer()](../Includes_and_Autodocs_2._guide/node0391.html)  Make a new layer behind others.         |
 |               [DeleteLayer()](../Includes_and_Autodocs_2._guide/node0394.html)  Remove and delete an existing layer.    |
 |----------------------------------------------------------------------|
 |                 [MoveLayer()](../Includes_and_Autodocs_2._guide/node039E.html)  Change the position (not depth) of a    |
 |                              layer.                                  |
 |                 [SizeLayer()](../Includes_and_Autodocs_2._guide/node03A3.html)  Change the size of a layer.             |
 |               [ScrollLayer()](../Includes_and_Autodocs_2._guide/node03A2.html)  Change the internal coordinates of a    |
 |                              layer.                                  |
 |----------------------------------------------------------------------|
 |               [BehindLayer()](../Includes_and_Autodocs_2._guide/node038F.html)  Depth arrange a layer behind others.    |
 |              [UpfrontLayer()](../Includes_and_Autodocs_2._guide/node03A9.html)  Depth arrange a layer in front of       |
 |                              others.                                 |
 |        [MoveLayerInFrontOf()](../Includes_and_Autodocs_2._guide/node039F.html)  Depth arrange a layer to a specific     |
 |                              position.                               |
 |----------------------------------------------------------------------|
 |                [WhichLayer()](../Includes_and_Autodocs_2._guide/node03AA.html)  Find the frontmost layer at a position. |
 |----------------------------------------------------------------------|
 |  [SwapBitsRastPortClipRect()](../Includes_and_Autodocs_2._guide/node03A4.html)  Fast, non-layered and non-damaging      |
 |                              display operation.                      |
 |----------------------------------------------------------------------|
 |               [BeginUpdate()](../Includes_and_Autodocs_2._guide/node038E.html)  Synchronize optimized refreshing for    |
 |                              layer.                                  |
 |                 [EndUpdate()](../Includes_and_Autodocs_2._guide/node0396.html)  End optimized layer refresh.            |
 |----------------------------------------------------------------------|
 |                 [LockLayer()](../Includes_and_Autodocs_2._guide/node039B.html)  Lock out rendering in a single layer.   |
 |               [UnlockLayer()](../Includes_and_Autodocs_2._guide/node03A6.html)  Release LockLayer() lock.               |
 |                [LockLayers()](../Includes_and_Autodocs_2._guide/node039D.html)  Lock out rendering in all layers of a   |
 |                              display.                                |
 |              [UnlockLayers()](../Includes_and_Autodocs_2._guide/node03A8.html)  Release LockLayers() lock.              |
 |             [LockLayerInfo()](../Includes_and_Autodocs_2._guide/node039C.html)  Gain exclusive access to the display's  |
 |                              layers.                                 |
 |           [UnlockLayerInfo()](../Includes_and_Autodocs_2._guide/node03A7.html)  Release LockLayerInfo() lock.           |
 |----------------------------------------------------------------------|
 |         [InstallClipRegion()](../Includes_and_Autodocs_2._guide/node0399.html)  Add a clipping region to a layer.       |
 |______________________________________________________________________|


The following routines from graphics library are also required for certain
layers library functions:

  ______________________________________________________________________
 |                                                                      |
 |            Routine                        Description                |
 |======================================================================|
 |         [LockLayerRom()](../Includes_and_Autodocs_2._guide/node045A.html)  Same as LockLayer(), from layers library.    |
 |       [UnlockLayerRom()](../Includes_and_Autodocs_2._guide/node0486.html)  Release LockLayerRom() lock.                 |
 |  [AttemptLockLayerRom()](../Includes_and_Autodocs_2._guide/node041D.html)  Lock layer only if it is immediately         |
 |                         available.                                   |
 |----------------------------------------------------------------------|
 |            [NewRegion()](../Includes_and_Autodocs_2._guide/node0460.html)  Create a new, empty region.                  |
 |        [DisposeRegion()](../Includes_and_Autodocs_2._guide/node0434.html)  Dispose of an existing region and its        |
 |                         rectangles.                                  |
 |----------------------------------------------------------------------|
 |        [AndRectRegion()](../Includes_and_Autodocs_2._guide/node0413.html)  AND a rectangle into a region.               |
 |         [OrRectRegion()](../Includes_and_Autodocs_2._guide/node0464.html)  OR a rectangle into a region.                |
 |        [XorRectRegion()](../Includes_and_Autodocs_2._guide/node0490.html)  Exclusive-OR a rectangle into a region.      |
 |      [ClearRectRegion()](../Includes_and_Autodocs_2._guide/node042A.html)  Clear a region.                              |
 |      [AndRegionRegion()](../Includes_and_Autodocs_2._guide/node0414.html)  AND two regions together.                    |
 |       [OrRegionRegion()](../Includes_and_Autodocs_2._guide/node0465.html)  OR two regions together.                     |
 |      [XorRegionRegion()](../Includes_and_Autodocs_2._guide/node0491.html)  Exclusive-OR two regions together.           |
 |          [ClearRegion()](../Includes_and_Autodocs_2._guide/node042B.html)  Clear a region.                              |
 |______________________________________________________________________|

