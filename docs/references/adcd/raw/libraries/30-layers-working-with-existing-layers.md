# 30 / Layers / Working With Existing Layers


A common operation performed by applications is to render text or graphics
into an existing layer such as an Intuition window.  To prevent Intuition
from changing the layer (for instance when the user resizes or moves the
window) during a series of graphic operations, the layers library provides
locking functions for obtaining exclusive access to a layer.

These locking functions are also useful for applications that create their
own layers if the application has more than one task operating on the
layers asynchronously.  These calls coordinate multiple access to layers.


  Table 30-1: Functions for Intertask Control of Layers (Layers Library)
   ____________________________________________________________________
  |                                                                    |
  |        [LockLayer()](../Libraries_Manual_guide/node03ED.html#line27)  Lock out rendering in a single layer.          |
  |      [UnlockLayer()](../Libraries_Manual_guide/node03ED.html#line40)  Release LockLayer() lock.                      |
  |       [LockLayers()](../Libraries_Manual_guide/node03ED.html#line49)  Lock out rendering in all layers of a display. |
  |     [UnlockLayers()](../Libraries_Manual_guide/node03ED.html#line49)  Release LockLayers() lock.                     |
  |    [LockLayerInfo()](../Libraries_Manual_guide/node03ED.html#line6)  Gain exclusive access to the display's layers. |
  |  [UnlockLayerInfo()](../Libraries_Manual_guide/node03ED.html#line19)  Release LockLayerInfo() lock.                  |
  |____________________________________________________________________|


The following routines from the graphics library also allow multitasking
access to layer structures:


 Table 30-2: Functions for Intertask Control of Layers (Graphics Library)
   ____________________________________________________________________
  |                                                                    |
  |         [LockLayerRom()](../Includes_and_Autodocs_2._guide/node045A.html)  Same as [LockLayer()](../Libraries_Manual_guide/node03ED.html#line27), from layers library.  |
  |       [UnlockLayerRom()](../Includes_and_Autodocs_2._guide/node0486.html)  Release LockLayerRom() lock.               |
  |  [AttemptLockLayerRom()](../Includes_and_Autodocs_2._guide/node041D.html)  Lock layer only if it is immediately       |
  |                         available.                                 |
  |____________________________________________________________________|


These functions are similar to the layers [LockLayer()](../Libraries_Manual_guide/node03ED.html#line27) and [UnlockLayer()](../Libraries_Manual_guide/node03ED.html#line40)
functions, but do not require the layers library to be open.  See the
Amiga ROM Kernel Reference Manual: Includes and Autodocs for details.

 [Intertask Operations](../Libraries_Manual_guide/node03ED.html)    [Determining Layer Position](../Libraries_Manual_guide/node03EE.html) 

