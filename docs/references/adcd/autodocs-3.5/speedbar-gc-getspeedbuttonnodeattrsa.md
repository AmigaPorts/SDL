---
title: speedbar_gc/GetSpeedButtonNodeAttrsA
manual: autodocs-3.5
chapter: autodocs-3.5
section: speedbar-gc-getspeedbuttonnodeattrsa
functions: []
libraries: []
---

# speedbar_gc/GetSpeedButtonNodeAttrsA

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

```c
    NAME
        GetSpeedButtonNodeAttrsA -- Get attributes about a SpeedBar node. (V40)

    SYNOPSIS
        VOID GetSpeedButtonNodeAttrs(struct [Node](autodocs-3.5/include-exec-nodes-h.md) *, [Tag](autodocs-3.5/include-utility-tagitem-h.md), ...)
        GetSpeedButtonNodeAttrs(node, firsttag, ...)

        VOID GetSpeedButtonNodeAttrsA(struct [Node](autodocs-3.5/include-exec-nodes-h.md) *, struct [TagItem](autodocs-3.5/include-utility-tagitem-h.md) *)
        GetSpeedButtonNodeAttrsA(node, taglist)

    FUNCTION
        The SpeedBar uses a private node structure and all attributes
        are hidden, and must therefore be accessed with this function.

    INPUTS
        node - The SpeedBar node to get the information on.
        taglist - A tag list of attributes to get.  ti_Tag is the attribute
            to get and ti_Data is a pointer to a location to copy the result
            to.

    SEE ALSO
        [SetSpeedButtonNodeAttrsA()](autodocs-3.5/speedbar-gc-setspeedbuttonnodeattrsa.md)
```
