# 15 / / Other GadTools Functions / DrawBevelBox()


A key visual signature shared by most GadTools gadgets is the raised or
recessed bevelled box imagery.  Since the program may wish to create its
own boxes to match, GadTools provides the [DrawBevelBox()](../Includes_and_Autodocs_2._guide/node03EA.html) and
[DrawBevelBoxA()](../Includes_and_Autodocs_2._guide/node03EA.html) functions.


```c
    void DrawBevelBoxA( struct RastPort *rport, long left, long top,
                        long width, long height, struct TagItem *taglist );
    void DrawBevelBox ( struct RastPort *rport, long left, long top,
                        long width, long height, Tag tag1, ... );
```
The rport argument is a pointer to the [RastPort](../Libraries_Manual_guide/node034A.html) into which the box is to
be rendered.  The left, top, width and height arguments specify the
dimensions of the desired box.

The tag arguments, tag1 or taglist, may be set as follows:

GT_VisualInfo (APTR)

```c
    The [VisualInfo](../Libraries_Manual_guide/node026C.html#line12) handle as returned by a prior call to [GetVisualInfo()](../Libraries_Manual_guide/node026C.html).
    This value is required.
```
GTBB_Recessed (BOOL)

    A bevelled box may either appear to be raised to signify an area of
    the window that is selectable or recessed to signify an area of the
    window in which clicking will have no effect.  Set this boolean tag
    to TRUE to get a recessed box.  Omit this tag entirely to get a
    raised box.
[DrawBevelBox()](../Includes_and_Autodocs_2._guide/node03EA.html) is a rendering operation, not a gadget. This means that the
program must refresh any bevelled boxes rendered through this function if
the window gets damaged.

