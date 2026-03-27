---
title: chooser_gc/GetChooserNodeAttrsA
manual: autodocs-3.5
chapter: autodocs-3.5
section: chooser-gc-getchoosernodeattrsa
functions: []
libraries: []
---

# chooser_gc/GetChooserNodeAttrsA

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

```c
    NAME
        GetChooserNodeAttrsA -- Get attributes about a Chooser node.

    SYNOPSIS
        VOID GetChooserNodeAttrs(struct [Node](autodocs-3.5/include-exec-nodes-h.md) *, [Tag](autodocs-3.5/include-utility-tagitem-h.md), ...)
        GetChooserNodeAttrs(node, firsttag, ...)

        VOID GetChooserNodeAttrsA(struct [Node](autodocs-3.5/include-exec-nodes-h.md) *, struct [TagItem](autodocs-3.5/include-utility-tagitem-h.md) *)
        GetChooserNodeAttrsA(node, taglist)

    FUNCTION
        The Chooser uses a private node structure and all attributes
        are hidden, and must therefore be accessed with this function.

    INPUTS
        node - The Chooser node to get the information on.
        taglist - A tag list of attributes to get.  ti_Tag is the attribute
            to get and ti_Data is a pointer to a location to copy the result
            to.  The exception is LBNA_Column, which is used to specify a
            column to get attributes on.

    SEE ALSO
        [SetChooserNodeAttrsA()](autodocs-3.5/chooser-gc-setchoosernodeattrsa.md)
```
