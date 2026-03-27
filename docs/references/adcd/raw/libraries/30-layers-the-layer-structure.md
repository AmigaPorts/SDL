# 30 / Layers / The Layer Structure


The internal representation of layers is essentially a set of clipping
rectangles.  Each layer is represented by an instance of the Layer
structure.  All the layers in a display are linked together through the
[Layer_Info](../Includes_and_Autodocs_2._guide/node00C4.html#line33) structure.  Any display shared by multiple layers (such as an
Intuition screen) requires one Layer_Info data structure to handle
interactions between the various layers. Here is a partial listing of the
Layer structure from <graphics/[clip.h](../Includes_and_Autodocs_2._guide/node00A1.html#line33)>.  (For a complete listing refer to
the Amiga ROM Kernel Reference Manual: Includes and Autodocs.)


```c
    struct Layer
    {
        struct  Layer *front,*back;
        struct  ClipRect   *ClipRect; /* read ROMs to find 1st cliprect */
        struct  RastPort   *rp;
        struct  Rectangle  bounds;
          ...

        UWORD   Flags;                /* obscured ?, Virtual BitMap? */
        struct  BitMap  *SuperBitMap;
          ...

        struct  Region  *DamageList;  /* list of rectangles to refresh */
                                      /* through */
    };


    The Layer Structure is Read-Only.
    ---------------------------------
    Applications should never directly modify any of the elements of the
    Layer structure. In addition, applications should only read the
    front, back, rp, bounds, Flags, SuperBitMap and DamageList elements
    of the Layer structure. (Some of these elements are subject to
    dynamic change by the system so proper layer locking procedures must
    be followed when relying on what the application has read.)
```
