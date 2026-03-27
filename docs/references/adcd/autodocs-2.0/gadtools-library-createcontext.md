---
title: gadtools.library/CreateContext
manual: autodocs-2.0
chapter: autodocs-2.0
section: gadtools-library-createcontext
functions: [AddGList, FreeGadgets, RefreshGList]
libraries: [gadtools.library, intuition.library]
---

# gadtools.library/CreateContext

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    CreateContext -- Create a place for GadTools context data. (V36)
```
SYNOPSIS

```c
    gad = CreateContext(glistpointer);
    D0                  A0

    struct [Gadget](autodocs-2.0/includes-intuition-intuition-h.md) *CreateContext(struct [Gadget](autodocs-2.0/includes-intuition-intuition-h.md) **);
```
FUNCTION

    Creates a place for GadTools to store any context data it might
    need for your window.  In reality, an unselectable invisible
    gadget is created, with room for the context data.
    This function also establishes the linkage from a glist type
    pointer to the individual gadget pointers.  Call this function
    before any of the other gadget creation calls.
INPUTS

```c
    glistptr - Address of a pointer to a [Gadget](autodocs-2.0/includes-intuition-intuition-h.md), which was previously
        set to NULL.  When all the gadget creation is done, you may
        use that pointer as your NewWindow.FirstGadget, or
        in [intuition.library/AddGList()](autodocs-2.0/intuition-library-addglist.md), [intuition.library/RefreshGList()](autodocs-2.0/intuition-library-refreshglist.md),
        [FreeGadgets()](autodocs-2.0/gadtools-library-freegadgets.md), etc.
```
RESULT

    gad - Pointer to context gadget, or NULL if failure.
EXAMPLE


```c
    struct [Gadget](autodocs-2.0/includes-intuition-intuition-h.md) *gad;
    struct [Gadget](autodocs-2.0/includes-intuition-intuition-h.md) *glist = NULL;
    gad = CreateContext(&glist);
    /*  Other creation calls go here */
    if (gad)
    {
        myNewWindow.FirstGadget = glist;
        if ( myWindow = OpenWindow(&myNewWindow) )
        {
            GT_RefreshWindow(win);
            /* other stuff */
            CloseWindow(myWindow);
        }
    }
    FreeGadgets(glist);
```
NOTES

BUGS

SEE ALSO

---

## See Also

- [AddGList — intuition.library](../autodocs/intuition.library.md#addglist)
- [FreeGadgets — gadtools.library](../autodocs/gadtools.library.md#freegadgets)
- [RefreshGList — intuition.library](../autodocs/intuition.library.md#refreshglist)
