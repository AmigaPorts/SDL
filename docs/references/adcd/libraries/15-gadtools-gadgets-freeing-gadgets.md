---
title: 15 / GadTools Gadgets / Freeing Gadgets
manual: libraries
chapter: libraries
section: 15-gadtools-gadgets-freeing-gadgets
functions: [FreeGadgets]
libraries: [gadtools.library]
---

# 15 / GadTools Gadgets / Freeing Gadgets

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

After closing the window, the gadgets allocated using [CreateGadget()](libraries/15-gadtools-gadgets-creating-gadgets.md) must
be released.  [FreeGadgets()](autodocs-2.0/gadtools-library-freegadgets.md) is a simple call that will free all the
GadTools gadgets that it finds, beginning with the gadget whose pointer is
passed as an argument.


```c
    void FreeGadgets( struct Gadget *gad );
```
The gad argument is a pointer to the first gadget to be freed.  It is safe
to call [FreeGadgets()](autodocs-2.0/gadtools-library-freegadgets.md) with a NULL gadget pointer, the function will then
return immediately.  Before calling FreeGadgets(), the application must
first either remove the gadgets or close the window.

When the gadget passed to [FreeGadgets()](autodocs-2.0/gadtools-library-freegadgets.md) is the first gadget in a linked
list, the function frees all the GadTools gadgets on the list without
patching pointers or trying to maintain the integrity of the list.  Any
non-GadTools gadgets found on the list will not be freed, hence the result
will not necessarily form a nice list since any intervening GadTools
gadgets will be gone.

See the section on "[Creating Gadget Lists](libraries/15-gadtools-gadgets-creating-gadget-lists.md)" for more information on using
linked lists of gadgets.

---

## See Also

- [FreeGadgets — gadtools.library](../autodocs/gadtools.library.md#freegadgets)
