# The Global Drawing Attribute Chunks / FILL


FILL (0x46494C4C)   	/* Object-oriented fill pattern */

The FILL chunk defines a fill pattern.  This chunk is only valid inside
nested DR2D FORMs.  The GRUP object chunk section of this article contans
an example of the FILL chunk.


```c
    struct FILLstruct {
        ULONG       ID;
        ULONG       Size;
        USHORT      FillID;                 /* ID of the fill */
    };
```
FillID is the number by which the ATTR object attribute chunk references
fill patterns.  The FILL chunk must be the first chunk inside a nested
DR2D FORM.  A FILL is followed by one DR2D object plus any of the object
attribute chunks (ATTR, BBOX) associated with the object.

 [Figure 2 - Fill Patterns](../Devices_Manual_guide/node02E2.html) 

DR2D makes a ``tile'' out of the fill pattern, giving it a virtual
bounding box based on the extreme X and Y values of the FILL's object
(Fig. A).  The bounding box shown in Fig. A surrounding the pattern (the
two ellipses) is invisible to the user.  In concept, this rectangle is
pasted on the page left to right, top to bottom like floor tiles (Fig. B).
Again, the bounding boxes are not visible.  The only portion of this tiled
pattern that is visible is the part that overlaps the object (Fig. C)
being filled.  The object's path is called a clipping path, as it
``clips'' its shape from the tiled pattern (Fig. D).  Note that the fill
is only masked on top of underlying objects, so any ``holes'' in the
pattern will act as a window, leaving visible underlying objects.

