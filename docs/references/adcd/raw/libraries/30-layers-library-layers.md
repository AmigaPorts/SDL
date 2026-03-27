# 30 Layers Library / Layers


The concept of a layer is closely tied to Intuition windows.  A layer is a
rectangular drawing area.  A layer can overlap other layers and has a
display priority that determines whether it will appear in front or behind
other layers.  Every Intuition window has an associated [Layer](../Libraries_Manual_guide/node03E4.html) structure.
Layers allow Intuition and application programs to :


```c
    * Share a display's [BitMap](../Libraries_Manual_guide/node00F1.html#line4) among various tasks in an orderly way
      by creating layers, separate drawing rectangles, within the
      BitMap.

    * Move, size or depth-arrange a layer while automatically keeping
      track of which portions of other layers are hidden or revealed
      by the operation.

    * Manage the remapping of coordinates, so the application need not
      track the layer's offset into the [BitMap](../Libraries_Manual_guide/node00F1.html#line4).

    * Maintain each layer as a separate entity, which may optionally
      have its own [BitMap](../Libraries_Manual_guide/node00F1.html#line4).

    * Automatically update same newly visible portions.
```
The layers library takes care of housekeeping: the low level, repetitive
tasks which are required to keep track of where to place bits.  The layers
library also provides a locking mechanism which coordinates display
updating when multiple tasks are drawing graphics to layers.  The
windowing environment provided by the Intuition library is largely based
on layers.


```c
    WARNING:
    --------
    Layers may not be created or used directly with Intuition screens.
    Intuition windows are the only supported method of adding layers to
    Intuition screens.  Only the layer locking and unlocking functions
    are safe to use with Intuition.  An application must create and
    manage its own [View](../Libraries_Manual_guide/node00F1.html#line4) if it will be creating layers directly on the
    display.
```
 [The Layer Structure](../Libraries_Manual_guide/node03E4.html)           [Working With Existing Layers](../Libraries_Manual_guide/node03EC.html) 
 [The Layer's RastPort](../Libraries_Manual_guide/node03E5.html)          [Creating and Using New Layers](../Libraries_Manual_guide/node03EF.html) 
 [Types of Layers](../Libraries_Manual_guide/node03E6.html)               [Layers Example](../Libraries_Manual_guide/node05C8.html) 
 [Opening the Layers Library](../Libraries_Manual_guide/node03EB.html) 

