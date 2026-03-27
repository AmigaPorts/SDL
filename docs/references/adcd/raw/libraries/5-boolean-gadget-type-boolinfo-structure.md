# 5 / Boolean Gadget Type / BoolInfo Structure


This is the special data structure required for a masked [boolean](../Libraries_Manual_guide/node014C.html) gadget. A
pointer to this structure must be placed in the gadget's [SpecialInfo](../Libraries_Manual_guide/node0149.html#line125) field
for a masked boolean gadget.


```c
    struct [BoolInfo](../Includes_and_Autodocs_2._guide/node00D4.html#line427)
        {
        UWORD  Flags;
        UWORD  *Mask;
        ULONG  Reserved;
        };
```
Flags

    Flags must be given the value BOOLMASK.
Mask

    This is a bit mask for highlighting and picking the gadget.
    Construct the mask as a single plane of image data.  The image's
    width and height are determined by the width and height  of the
    gadget's select box.  The mask data must be in Chip memory.
Reserved

    Set this field to NULL.
