---
title: Using Multiple RastPorts
manual: amiga-mail
chapter: amiga-mail
section: using-multiple-rastports
functions: [SetAPen, SetBPen, SetDrMd]
libraries: [graphics.library]
---

# Using Multiple RastPorts

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

A RastPort specifies attributes needed to perform many rendering
operations.  These include the RastPort's foreground, background, and
drawing mode.  The Graphics library functions SetAPen(), SetBPen(),
and SetDrMd() set each of these attributes, respectively.

Although these functions appear to have fairly simple purposes in
life, the SetAPen(), SetBPen(), and SetDrMd() are quite CPU intensive
routines.  These functions require recalculating values that the OS
caches in private parts of the RastPort.  If an application only
requires a few different combinations of foreground/background/draw
mode, it can improve its performance by using a different RastPort
structure for each combination.  An application sets the attributes
of several RastPorts only once which is generally more efficient that
setting the attributes of one RastPort every time the rendering
attributes change.

Assume an application has a window in which it renders all of its
data in pen 1, and clears any part of its display using color 0.
Such an application can improve its rendering performance by doing
the following:


```c
    struct RastPort dataRP;
    struct RastPort clrRP;

    dataRP = *window->RPort;
    SetAPen(&dataRP,1);
    SetBPen(&dataRP,0);

    clrRP = *window->RPort;
    SetAPen(&clrRP,0);

    /* renders to the window's RastPort in color 1 */
    Text(&dataRP,"hello",5);

    /* clears a section of the window's RastPort in color 0 */
    RectFill(&clrRPort,0,0,10,10);
```

---

## See Also

- [SetAPen — graphics.library](../autodocs/graphics.library.md#setapen)
- [SetBPen — graphics.library](../autodocs/graphics.library.md#setbpen)
- [SetDrMd — graphics.library](../autodocs/graphics.library.md#setdrmd)
