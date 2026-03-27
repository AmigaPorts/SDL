---
title: clicktab_gc/GetClickTabNodeAttrsA
manual: autodocs-3.5
chapter: autodocs-3.5
section: clicktab-gc-getclicktabnodeattrsa
functions: []
libraries: []
---

# clicktab_gc/GetClickTabNodeAttrsA

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

```c
    NAME
        GetClickTabNodeAttrsA -- Get attributes about a ClickTab node.

    SYNOPSIS
        VOID GetClickTabNodeAttrs(struct [Node](autodocs-3.5/include-exec-nodes-h.md) *, [Tag](autodocs-3.5/include-utility-tagitem-h.md), ...)
        GetClickTabNodeAttrs(node, firsttag, ...)

        VOID GetClickTabNodeAttrsA(struct [Node](autodocs-3.5/include-exec-nodes-h.md) *, struct [TagItem](autodocs-3.5/include-utility-tagitem-h.md) *)
        GetClickTabNodeAttrsA(node, taglist)

    FUNCTION
        The ClickTab uses a private node structure and all attributes
        are hidden, and must therefore be accessed with this function.

    INPUTS
        node - The ClickTab node to get the information on.
        taglist - A tag list of attributes to get.  ti_Tag is the attribute
            to get and ti_Data is a pointer to a location to copy the result
            to.  The exception is LBNA_Column, which is used to specify a
            column to get attributes on.

    SEE ALSO
        [SetClickTabNodeAttrsA()](autodocs-3.5/clicktab-gc-setclicktabnodeattrsa.md)
```
