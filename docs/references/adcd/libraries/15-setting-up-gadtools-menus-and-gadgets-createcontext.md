---
title: 15 / / Setting Up GadTools Menus and Gadgets / CreateContext()
manual: libraries
chapter: libraries
section: 15-setting-up-gadtools-menus-and-gadgets-createcontext
functions: [CreateContext]
libraries: [gadtools.library]
---

# 15 / / Setting Up GadTools Menus and Gadgets / CreateContext()

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Use of GadTools gadgets requires some per-window context information.
[CreateContext()](autodocs-2.0/gadtools-library-createcontext.md) establishes a place for that information to go. This
function must be called before any GadTools gadgets are created.


```c
    struct Gadget *CreateContext( struct Gadget **glistptr );
```
The glistptr argument is a double-pointer to a [Gadget](libraries/5-intuition-gadgets-gadget-structure.md) structure.  More
specifically, this is a pointer to a NULL-initialized pointer to a Gadget
structure.

The return value of [CreateContext()](autodocs-2.0/gadtools-library-createcontext.md) is a pointer to this gadget, which
should be fed to the program's first call to [CreateGadget()](libraries/15-gadtools-gadgets-creating-gadgets.md).  This pointer
to the [Gadget](libraries/5-intuition-gadgets-gadget-structure.md) structure returned by CreateContext(), may then serve as a
handle to the list of gadgets as they are created.  The [code fragment](libraries/15-gadtools-gadgets-creating-gadget-lists.md)
listed in the next section shows how to use CreateContext() together with
CreateGadget() to make a linked list of GadTools gadgets.

---

## See Also

- [CreateContext — gadtools.library](../autodocs/gadtools.library.md#createcontext)
