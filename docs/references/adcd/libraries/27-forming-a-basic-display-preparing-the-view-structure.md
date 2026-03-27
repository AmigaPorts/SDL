---
title: 27 / / Forming a Basic Display / Preparing the View Structure
manual: libraries
chapter: libraries
section: 27-forming-a-basic-display-preparing-the-view-structure
functions: [GfxAssociate, GfxNew]
libraries: [graphics.library]
---

# 27 / / Forming a Basic Display / Preparing the View Structure

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The following code prepares the [View](libraries/27-display-routines-and-structures-viewport-display-memory.md) structure for further use:


```c
    InitView(&view);      /* Initialize the View.          */
    view.Modes |= LACE;   /* Only interlaced, 1.3 displays */
                          /* require this                  */
```
For Release 2 applications, a [ViewExtra](libraries/27-display-routines-and-structures-forming-a-basic-display.md) structure must also be created
with [GfxNew()](libraries/27-display-routines-and-structures-forming-a-basic-display.md) and associated with this [View](libraries/27-display-routines-and-structures-viewport-display-memory.md) with [GfxAssociate()](libraries/27-display-routines-and-structures-forming-a-basic-display.md) as shown
in the example programs [RGBBoxes.c](libraries/lib-examples-rgbboxes-c.md) and [WBClone.c](libraries/lib-examples-wbclone-c.md).


```c
    /* Form the ModeID from values in <displayinfo.h> */
    modeID=DEFAULT_MONITOR_ID | HIRESLACE_KEY;

    /* Make the ViewExtra structure */
    if( vextra=GfxNew(VIEW_EXTRA_TYPE) )
        {
        /* Attach the ViewExtra to the View */
        GfxAssociate(&view , vextra);
        view.Modes |= EXTEND_VSTRUCT;

        /* Initialize the MonitorSpec field of the ViewExtra */
        if( monspec=OpenMonitor(NULL,modeID) )
            vextra->Monitor=monspec;
        else
            fail("Could not get MonitorSpec\n");
        }
     else fail("Could not get ViewExtra\n");
```

---

## See Also

- [GfxAssociate — graphics.library](../autodocs/graphics.library.md#gfxassociate)
- [GfxNew — graphics.library](../autodocs/graphics.library.md#gfxnew)
