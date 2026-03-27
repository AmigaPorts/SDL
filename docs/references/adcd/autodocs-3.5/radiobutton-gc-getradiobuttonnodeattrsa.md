---
title: radiobutton_gc/GetRadioButtonNodeAttrsA
manual: autodocs-3.5
chapter: autodocs-3.5
section: radiobutton-gc-getradiobuttonnodeattrsa
functions: []
libraries: []
---

# radiobutton_gc/GetRadioButtonNodeAttrsA

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

```c
    NAME
        GetRadioButtonNodeAttrsA -- Get attributes about a RadioButton node. (V40)

    SYNOPSIS
        VOID GetRadioButtonNodeAttrs(struct [Node](autodocs-3.5/include-exec-nodes-h.md) *, [Tag](autodocs-3.5/include-utility-tagitem-h.md), ...)
        GetRadioButtonNodeAttrs(node, firsttag, ...)

        VOID GetRadioButtonNodeAttrsA(struct [Node](autodocs-3.5/include-exec-nodes-h.md) *, struct [TagItem](autodocs-3.5/include-utility-tagitem-h.md) *)
        GetRadioButtonNodeAttrsA(node, taglist)

    FUNCTION
        The RadioButton uses a private node structure and all attributes
        are hidden, and must therefore be accessed with this function.

    INPUTS
        node - The RadioButton node to get the information on.
        taglist - A tag list of attributes to get.  ti_Tag is the attribute
        to get and ti_Data is a pointer to a location to copy the result
        to.

    SEE ALSO
        [SetRadioButtonNodeAttrsA()](autodocs-3.5/radiobutton-gc-setradiobuttonnodeattrsa.md)
```
