# 4 / / Setting Up A SuperBitMap Window / Graphics and Layers Functions


The portion of the bitmap showing within a SuperBitMap window is
controlled by the application.  Initially, the window shows the bitmap
starting from its origin (0,0) and clipped to fit within the window layer.
The visible portion of the bitmap can be scrolled around within the window
using the layers library [ScrollLayer()](../Libraries_Manual_guide/node03EF.html#line17) function:


```c
    void ScrollLayer(LONG unused, struct Layer *layer, LONG dx, LONG dy)
```
Pass this function a pointer to the window's layer in layer and the scroll
offsets in dx and dy.  (A pointer to the window's layer can be obtained
from [Window.RPort](../Libraries_Manual_guide/node0121.html#line66)->Layer.)

When rendering operations are performed in a SuperBitMap window, any
rendering that falls outside window boundaries is done in the
application's bitmap.  Rendering that falls within window bounds is done
in the screen's bitmap.  Before performing an operation such as a save on
the application bitmap, the graphics library function [SyncSBitMap()](../Includes_and_Autodocs_2._guide/node0481.html) should
be called:


```c
    void SyncSBitMap(struct Layer *layer)
```
Pass this function a pointer to the window's layer.  [SyncSBitMap()](../Includes_and_Autodocs_2._guide/node0481.html) copies
the window contents to the corresponding part of the application bitmap,
bringing it up to date.  (If no rendering operations have been performed
this call is not necessary.)

Similarly, after making any changes to the application bitmap such as
loading a new one, the window's layer should be locked and the
[CopySBitMap()](../Includes_and_Autodocs_2._guide/node0431.html) function should be called.


```c
    void CopySBitMap(struct Layer *)
```
This function copies the new information in the appropriate area of the
underlying bitmap to the window's layer.

For more information about bitmaps and layers, see the
"[Graphics Primitives](../Libraries_Manual_guide/node0363.html)" and "[Layers Library](../Libraries_Manual_guide/node03EF.html)" chapters of this manual.  Also
see the <graphics/[clip.h](../Includes_and_Autodocs_2._guide/node00A1.html)>, <graphics/[gfx.h](../Includes_and_Autodocs_2._guide/node00A6.html)>, <graphics/[layers.h](../Includes_and_Autodocs_2._guide/node00C4.html)>,
[graphics library](../Includes_and_Autodocs_2._guide/node040D.html) and [layers library](../Includes_and_Autodocs_2._guide/node038D.html) sections of the Amiga ROM Kernel
Reference Manual: Includes and Autodocs.

