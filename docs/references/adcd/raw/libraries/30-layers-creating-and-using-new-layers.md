# 30 / Layers / Creating and Using New Layers


The functions described in this section are generally not safe to use with
Intuition.  To create new layers for Intuition you use Intuition window
calls (see the "[Intuition Windows](../Libraries_Manual_guide/node0102.html)" chapter earlier in this book).

Only applications that create and mange their own [View](../Libraries_Manual_guide/node00F1.html#line4) will be able to
call the layer creation and updating functions discussed here.


         Table 30-3: Functions for Creating and Updating Layers
   ___________________________________________________________________
  |                                                                   |
  |              [NewLayerInfo()](../Libraries_Manual_guide/node03F2.html)  Allocating a [Layer_Info](../Includes_and_Autodocs_2._guide/node00C4.html#line33) structure.   |
  |          [DisposeLayerInfo()](../Libraries_Manual_guide/node03F2.html#line5)  Deallocating a Layer_Info structure. |
  |-------------------------------------------------------------------|
  |        [CreateUpfrontLayer()](../Libraries_Manual_guide/node03F3.html)  Make a new layer in front of others. |
  |         [CreateBehindLayer()](../Libraries_Manual_guide/node03F3.html#line9)  Make a new layer behind others.      |
  |               [DeleteLayer()](../Libraries_Manual_guide/node03F3.html#line28)  Remove and delete an existing layer. |
  |-------------------------------------------------------------------|
  |                 [MoveLayer()](../Libraries_Manual_guide/node03F4.html)  Change the position (not depth) of a |
  |                              layer.                               |
  |                 [SizeLayer()](../Libraries_Manual_guide/node03F4.html)  Change the size of a layer.          |
  |               [ScrollLayer()](../Libraries_Manual_guide/node03F5.html)  Change the internal coordinates of a |
  |                              layer.                               |
  |-------------------------------------------------------------------|
  |               [BehindLayer()](../Libraries_Manual_guide/node03F6.html)  Depth arrange a layer behind others. |
  |              [UpfrontLayer()](../Libraries_Manual_guide/node03F6.html)  Depth arrange a layer in front of    |
  |                              others.                              |
  |        [MoveLayerInFrontOf()](../Libraries_Manual_guide/node03F6.html)  Depth arrange a layer to a specific  |
  |                              position.                            |
  |-------------------------------------------------------------------|
  |  [SwapBitsRastPortClipRect()](../Libraries_Manual_guide/node03F7.html)  Fast, non-layered and non-damaging   |
  |                              display operation.                   |
  |-------------------------------------------------------------------|
  |               [BeginUpdate()](../Libraries_Manual_guide/node03F6.html#line13)  Synchronize optimized refreshing for |
  |                              layer.                               |
  |                 [EndUpdate()](../Libraries_Manual_guide/node03F6.html#line13)  End optimized layer refresh.         |
  |___________________________________________________________________|


 [Creating a Viewing Workspace](../Libraries_Manual_guide/node03F0.html) 
 [Creating the Layers](../Libraries_Manual_guide/node03F1.html) 
 [Allocating and Deallocating Layer_Info](../Libraries_Manual_guide/node03F2.html) 
 [Allocating and Deallocating Layers](../Libraries_Manual_guide/node03F3.html) 
 [Moving and Sizing Layers](../Libraries_Manual_guide/node03F4.html) 
 [Changing a Viewpoint](../Libraries_Manual_guide/node03F5.html) 
 [Reordering Layers](../Libraries_Manual_guide/node03F6.html) 
 [Sub-Layer Rectangle Operations](../Libraries_Manual_guide/node03F7.html) 

