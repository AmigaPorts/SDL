---
title: chooser_gc/AllocChooserNodeA
manual: autodocs-3.5
chapter: autodocs-3.5
section: chooser-gc-allocchoosernodea
functions: []
libraries: []
---

# chooser_gc/AllocChooserNodeA

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

```c
    NAME
        AllocChooserNodeA -- [Allocate](autodocs-3.5/exec-library-allocate-2.md) a Chooser node.

    SYNOPSIS
        struct [Node](autodocs-3.5/include-exec-nodes-h.md) * AllocChooserNode(Tag, ...)
        node = AllocChooserNode(columns, [Tag](autodocs-3.5/include-utility-tagitem-h.md), ...)

        struct [Node](autodocs-3.5/include-exec-nodes-h.md) * AllocChooserNodeA(struct [TagItem](autodocs-3.5/include-utility-tagitem-h.md) *)
        node = AllocChooserNodeA(taglist)

    FUNCTION
        Allocates a node that can be added to the Exec linked list of
        labels in the chooser.  This is the only way to allocate a
        node for this list, you cannot allocate nodes yourself because
        the Chooser class uses a private node structure.

    INPUTS
        taglist - Attributes for the node, passed onto [SetChooserNodeAttrsA()](autodocs-3.5/chooser-gc-setchoosernodeattrsa.md).

    RESULT
        node - A node that can be added into the Exec list of labels for
            a Chooser gadget.

    SEE ALSO
        [FreeChooserNode()](autodocs-3.5/chooser-gc-freechoosernode.md), [SetChooserNodeAttrsA()](autodocs-3.5/chooser-gc-setchoosernodeattrsa.md)
```
