---
title: 27 / / Forming a Basic Display / Preparing the ViewPort Structure
manual: libraries
chapter: libraries
section: 27-forming-a-basic-display-preparing-the-viewport-structure
functions: [GfxNew, InitVPort, VideoControl]
libraries: [graphics.library]
---

# 27 / / Forming a Basic Display / Preparing the ViewPort Structure

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

To prepare the [ViewPort](libraries/27-display-routines-and-structures-viewport-display-memory.md) structure for further use, you call [InitVPort()](autodocs-2.0/graphics-library-initvport.md)
and initialize certain fields as follows:


```c
    InitVPort(&viewPort);        /* Initialize the ViewPort.             */
    viewPort.RasInfo = &rasInfo; /* The rasInfo must also be initialized */
    viewPort.DWidth  = WIDTH;
    viewPort.DHeight = HEIGHT;

    /* Under 1.3, you should set viewPort.Modes here to select a display
     * mode. Under Release 2, use VideoControl() with VTAG_NORMAL_DISP_SET
     * to select a display mode by attaching a DisplayInfo structure to
     *  the ViewPort.                                                    */
```
The [InitVPort()](autodocs-2.0/graphics-library-initvport.md) routine presets certain default values in the [ViewPort](libraries/27-display-routines-and-structures-viewport-display-memory.md)
structure.  The defaults include:

  * [Modes](libraries/27-display-routines-and-structures-viewport-display-modes.md) variable set to zero--this means you select a low-resolution

```c
    display.  (To alter this, use [VideoControl()](libraries/27-mode-specification-viewport-interface.md) with the
    [VTAG_NORMAL_DISP_SET](libraries/27-mode-specification-viewport-interface.md) tag as explained below.)
```
  * [Next](autodocs-2.0/includes-graphics-view-h.md) variable set to NULL--no other [ViewPort](libraries/27-display-routines-and-structures-viewport-display-memory.md) is linked to this one.

    If you want a display with multiple ViewPorts, you must fill in the
    link yourself.
If you want to create a [View](libraries/27-display-routines-and-structures-viewport-display-memory.md) with two or more [ViewPort](libraries/27-display-routines-and-structures-viewport-display-memory.md)s you must declare
and initialize the ViewPorts as above.  Then link them together using the
[ViewPort.Next](autodocs-2.0/includes-graphics-view-h.md) field with a NULL link for the ViewPort at the end of the
chain:



```c
    viewPortA.Next = &viewPortB; /* Tell 1st one the address of the 2nd. */
    viewPortB.Next = NULL;       /* There are no others after this one.  */
```
For Release 2 applications, once a [ViewPort](libraries/27-display-routines-and-structures-viewport-display-memory.md) has been prepared, a
[ViewPortExtra](libraries/27-display-routines-and-structures-forming-a-basic-display.md) structure must also be created with [GfxNew()](libraries/27-display-routines-and-structures-forming-a-basic-display.md), initialized,
and associated with the ViewPort via the [VideoControl()](libraries/27-mode-specification-viewport-interface.md) function.  In
addition, a [DisplayInfo](autodocs-2.0/includes-graphics-displayinfo-h.md) for this mode must be attached to the ViewPort.
The fragment below shows how to do this.  For complete examples, refer to
the program listings of [RGBBoxes.c](libraries/lib-examples-rgbboxes-c.md) and [WBClone.c](libraries/lib-examples-wbclone-c.md).


struct TagItem vcTags[] =              /* These tags will be passed to   */
{                                      /* the VideoControl() function to */
```c
    { VTAG_ATTACH_CM_SET, NULL },      /* set up the extended ViewPort   */
    { VTAG_VIEWPORTEXTRA_SET, NULL },  /* structures required in Release */
    { VTAG_NORMAL_DISP_SET, NULL },    /* 2. The NULL ti_Data field of   */
    { VTAG_END_CM, NULL }              /* these tags must be filled in   */
```
};                                     /* before making the call to      */

```c
                                       /* VideoControl().                */
```
struct DimensionInfo dimquery;  /* Release 2 structure for display size  */

                                /* data */
/* Make a ViewPortExtra and get ready to attach it */
if( vpextra = GfxNew(VIEWPORT_EXTRA_TYPE) )
```c
    {
    vcTags[1].ti_Data = (ULONG) vpextra;

    /* Initialize the DisplayClip field of the ViewPortExtra structure */
    if( GetDisplayInfoData( NULL , (UBYTE *) &dimquery ,
                           sizeof(struct dimquery) , DTAG_DIMS, modeID) )
        {
        vpextra->DisplayClip = dimquery.Nominal;

        /* Make a DisplayInfo and get ready to attach it */
        if( !(vcTags[2].ti_Data = (ULONG) FindDisplayInfo(modeID)) )
            fail("Could not get DisplayInfo\n");
        }
    else fail("Could not get DimensionInfo\n");
    }
```
else fail("Could not get ViewPortExtra\n");

/* This is for backwards compatibility with, for example,   */
/* a 1.3 screen saver utility that looks at the Modes field */
viewPort.Modes = (UWORD) (modeID & 0x0000ffff);

---

## See Also

- [GfxNew — graphics.library](../autodocs/graphics.library.md#gfxnew)
- [InitVPort — graphics.library](../autodocs/graphics.library.md#initvport)
- [VideoControl — graphics.library](../autodocs/graphics.library.md#videocontrol)
