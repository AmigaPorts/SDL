---
title: 5 / Boolean Gadget Type / BoolInfo Structure
manual: libraries
chapter: libraries
section: 5-boolean-gadget-type-boolinfo-structure
functions: []
libraries: []
---

# 5 / Boolean Gadget Type / BoolInfo Structure

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

This is the special data structure required for a masked [boolean](libraries/5-intuition-gadgets-boolean-gadget-type.md) gadget. A
pointer to this structure must be placed in the gadget's [SpecialInfo](libraries/5-intuition-gadgets-gadget-structure.md) field
for a masked boolean gadget.


```c
    struct [BoolInfo](autodocs-2.0/includes-intuition-intuition-h.md)
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
