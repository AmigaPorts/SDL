# 28 / / The GELs System / Initializing the GEL System


To initialize the animation system, call the system function [InitGels()](../Includes_and_Autodocs_2._guide/node0451.html).
It takes the form:


```c
    struct VSprite  *vsHead;
    struct VSprite  *vsTail;
    struct GelsInfo *gInfo;

    InitGels(vsHead, vsTail, gInfo);
```
The vsHead argument is a pointer to the [VSprite](../Libraries_Manual_guide/node0381.html) structure to be used as
the GEL list head.  (You must allocate an actual VSprite structure for
vsHead to point to.)  The vsTail argument is a pointer to the VSprite
structure to be used as the GEL list tail.  (You must allocate an actual
VSprite structure for vsTail to point to.)  The gInfo argument is a
pointer to the [GelsInfo](../Libraries_Manual_guide/node0377.html#line6) structure to be initialized.

[InitGels()](../Includes_and_Autodocs_2._guide/node0451.html) forms these structures into a linked list of GELs that is empty
except for these two dummy elements (the head and tail).  It gives the
head [VSprite](../Libraries_Manual_guide/node0381.html) the maximum negative x and y positions and the tail VSprite
the maximum positive x and y positions.  This is to aid the system in
keeping the list sorted by x, y values, so GELs that are closer to the top
and left of the display are nearer the head of the list.  The memory space
that the VSprites and [GelsInfo](../Libraries_Manual_guide/node0377.html#line6) structures take up must already have been
allocated.  This can be done either by declaring them statically or
explicitly allocating memory for them.

Once the [GelsInfo](../Libraries_Manual_guide/node0377.html#line6) structure has been allocated and initialized, GELs can
be added to the system.  Refer to the [setupGelSys()](../Libraries_Manual_guide/node059C.html#line28) and [cleanupGelSys()](../Libraries_Manual_guide/node059C.html#line73)
functions in the [animtools.c](../Libraries_Manual_guide/node059C.html) lisitng at the end of the chapter for
examples of allocating, initializing and freeing a GelsInfo structure.

