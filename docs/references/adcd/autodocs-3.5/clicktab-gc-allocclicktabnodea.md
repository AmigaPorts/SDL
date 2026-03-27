---
title: clicktab_gc/AllocClickTabNodeA
manual: autodocs-3.5
chapter: autodocs-3.5
section: clicktab-gc-allocclicktabnodea
functions: []
libraries: []
---

# clicktab_gc/AllocClickTabNodeA

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

```c
    NAME
        AllocClickTabNodeA -- [Allocate](autodocs-3.5/exec-library-allocate-2.md) a ClickTab node.

    SYNOPSIS
        struct [Node](autodocs-3.5/include-exec-nodes-h.md) * AllocClickTabNode(Tag, ...)
        node = AllocClickTabNode(Tag, ...)

        struct [Node](autodocs-3.5/include-exec-nodes-h.md) * AllocClickTabNodeA(struct [TagItem](autodocs-3.5/include-utility-tagitem-h.md) *)
        node = AllocClickTabNodeA(taglist)

    FUNCTION
        Allocates a node that can be added to the Exec linked list of
        labels in the clicktab.  This is the only way to allocate a
        node for this list, you cannot allocate nodes yourself because
        the ClickTab class uses a private node structure.

    INPUTS
        columns - How many columns your ClickTab has.
        taglist - Attributes for the node, passed onto [SetClickTabNodeAttrsA()](autodocs-3.5/clicktab-gc-setclicktabnodeattrsa.md).

    RESULT
        node - A node that can be added into the Exec list of labels for
            a ClickTab gadget.

    SEE ALSO
        [FreeClickTabNode()](autodocs-3.5/clicktab-gc-freeclicktabnode.md), [SetClickTabNodeAttrsA()](autodocs-3.5/clicktab-gc-setclicktabnodeattrsa.md)
```
