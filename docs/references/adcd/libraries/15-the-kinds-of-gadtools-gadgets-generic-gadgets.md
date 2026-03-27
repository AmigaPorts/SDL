---
title: 15 / / The Kinds of GadTools Gadgets / Generic Gadgets
manual: libraries
chapter: libraries
section: 15-the-kinds-of-gadtools-gadgets-generic-gadgets
functions: [FreeGadgets]
libraries: [gadtools.library]
---

# 15 / / The Kinds of GadTools Gadgets / Generic Gadgets

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

If the application requires a specialized gadget which does not fit into
any of the defined GadTools kinds but would still like to use the GadTools
gadget creation and deletion functions, it may create a GadTools generic
gadget and use it any way it sees fit.  In fact, all of the kinds of
GadTools gadgets are created out of GadTools GENERIC_KIND gadgets.

The gadget that gets created will heed almost all the information
contained in the [NewGadget](libraries/15-gadtools-gadgets-the-newgadget-structure.md) structure supplied.

If [ng_GadgetText](libraries/15-gadtools-gadgets-the-newgadget-structure.md) is supplied, the [Gadget](libraries/5-intuition-gadgets-gadget-structure.md)'s [GadgetText](libraries/5-intuition-gadgets-gadget-structure.md) will point to an
[IntuiText](libraries/8-creating-text-intuitext-structure.md) structure with the provided string and font.  However, do not
specify any of the PLACETEXT [ng_Flags](libraries/15-gadtools-gadgets-the-newgadget-structure.md), as they are currently ignored by
GENERIC_KIND gadgets.  PLACETEXT flags may be supported by generic
GadTools gadgets in the future.

It is up to the program to set the [Flags](libraries/5-intuition-gadgets-gadget-structure.md), [Activation](libraries/5-intuition-gadgets-gadget-structure.md), [GadgetRender](libraries/5-intuition-gadgets-gadget-structure.md),
[SelectRender](libraries/5-intuition-gadgets-gadget-structure.md), [MutualExclude](libraries/5-intuition-gadgets-gadget-structure.md) and [SpecialInfo](libraries/5-intuition-gadgets-gadget-structure.md) fields of the [Gadget](libraries/5-intuition-gadgets-gadget-structure.md) structure.

The application must also set the [GadgetType](libraries/5-intuition-gadgets-gadget-structure.md) field, but be certain to
preserve the bits set by [CreateGadget()](libraries/15-gadtools-gadgets-creating-gadgets.md). For instance, to make a gadget
boolean, use:


```c
    gad->GadgetType |= GTYP_BOOLGADGET;
```
and not


```c
    gad->GadgetType = GTYP_BOOLGADGET;
```
Using direct assignment, (the = operator), clears all other flags in the
[GadgetType](libraries/5-intuition-gadgets-gadget-structure.md) field and the gadget may not be properly freed by [FreeGadgets()](libraries/15-gadtools-gadgets-freeing-gadgets.md).

---

## See Also

- [FreeGadgets — gadtools.library](../autodocs/gadtools.library.md#freegadgets)
