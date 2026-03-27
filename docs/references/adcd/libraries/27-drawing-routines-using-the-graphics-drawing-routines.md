---
title: 27 / Drawing Routines / Using the Graphics Drawing Routines
manual: libraries
chapter: libraries
section: 27-drawing-routines-using-the-graphics-drawing-routines
functions: [WaitBlit]
libraries: [graphics.library]
---

# 27 / Drawing Routines / Using the Graphics Drawing Routines

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

This section shows you how to use the Amiga drawing routines. All of these
routines work either on their own or along with the windowing system and
layers library.  For details about using the layers and windows, see the
chapters on "[Layers Library](libraries/30-layers-library.md)" and "[Intuition](libraries/4-intuition-windows.md) Windows".


```c
    Use WaitBlit().
    ---------------
    The graphics library rendering and data movement routines generally
    wait to get access to the blitter, start their blit, and then exit.
    Therefore, you must [WaitBlit()](libraries/27-performing-data-move-operations-when-to-wait-for-the.md) after a graphics rendering or data
    movement call if you intend to immediately deallocate, examine, or
    perform order-dependent processor operations on the memory used in
    the call.
```
As you read this section, keep in mind that to use the drawing routines,
you need to pass them a pointer to a [RastPort](libraries/27-drawing-routines-the-rastport-structure.md).  You can define the
RastPort directly, as shown in the sample program segments in preceding
sections, or you can get a RastPort from your [Window](libraries/4-intuition-windows-the-window-structure.md) structure using code
like the following:


```c
    struct Window *window;
    struct RastPort *rastPort;

    window = OpenWindow(&newWindow);  /*  You could use OpenWindowTags() */
    if (window)
        rastPort = window->RPort;
```
You can also get the [RastPort](libraries/27-drawing-routines-the-rastport-structure.md) from the [Layer](libraries/30-layers-the-layer-structure.md) structure, if you are not
using Intuition.

 [Drawing Individual Pixels](libraries/27-using-the-graphics-drawing-routines-drawing-individual.md) 
 [Reading Individual Pixels](libraries/27-using-the-graphics-drawing-routines-reading-individual.md) 
 [Drawing Ellipses and Circles](libraries/27-using-graphics-drawing-routines-drawing-ellipses-and.md) 
 [Drawing Lines](libraries/27-using-the-graphics-drawing-routines-drawing-lines.md) 
 [Drawing Patterned Lines](libraries/27-using-the-graphics-drawing-routines-drawing-patterned.md) 
 [Drawing Multiple Lines with a Single Command](libraries/27-drawing-multiple-lines-with-a-single-command.md) 
 [Area-fill Operations](libraries/27-using-the-graphics-drawing-routines-area-fill-operations.md) 
 [Ellipse and Circle-fill Operations](libraries/27-using-drawing-routines-ellipse-and-circle-fill-operations.md) 
 [Flood-fill Operations](libraries/27-using-the-graphics-drawing-routines-flood-fill-operations.md) 
 [Rectangle-fill Operations](libraries/27-using-the-graphics-drawing-routines-rectangle-fill.md) 

---

## See Also

- [WaitBlit — graphics.library](../autodocs/graphics.library.md#waitblit)
