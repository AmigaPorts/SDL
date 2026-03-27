---
title: speedbar_gc/AllocSpeedButtonNodeA
manual: autodocs-3.5
chapter: autodocs-3.5
section: speedbar-gc-allocspeedbuttonnodea
functions: []
libraries: []
---

# speedbar_gc/AllocSpeedButtonNodeA

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

```c
    NAME
        AllocSpeedButtonNodeA -- [Allocate](autodocs-3.5/exec-library-allocate-2.md) a SpeedBar node. (V40)

    SYNOPSIS
        struct [Node](autodocs-3.5/include-exec-nodes-h.md) * AllocSpeedButtonNode(UWORD, [Tag](autodocs-3.5/include-utility-tagitem-h.md), ...)
        node = AllocSpeedButtonNode(number, [Tag](autodocs-3.5/include-utility-tagitem-h.md), ...)

        struct [Node](autodocs-3.5/include-exec-nodes-h.md) * AllocSpeedButtonNodeA(UWORD, struct [TagItem](autodocs-3.5/include-utility-tagitem-h.md) *)
        node = AllocSpeedButtonNodeA(number, taglist)

    FUNCTION
        Allocates a node that can be added to the Exec linked list of
        labels in the speedbar.  This is the only way to allocate a
        node for this list, you cannot allocate nodes yourself because
        the SpeedBar class uses a private node structure.

    INPUTS
        number - Places value in node->sbn_Node.ln_Pri, and is the
            numeric ID of the button within the bar. Note the current
            limitation, ln_Pri is a [BYTE](autodocs-3.5/include-exec-types-h.md). This will be addressed, and
            *posibly* made obsolete and overridden by SBNA_ButtonID.

        taglist - Attributes for the node, passed onto
            [SetSpeedButtonNodeAttrsA()](autodocs-3.5/speedbar-gc-setspeedbuttonnodeattrsa.md).

    RESULT
        node - A node that can be added into the Exec list of labels for
            a SpeedBar gadget.

    SEE ALSO
        [FreeSpeedButtonNode()](autodocs-3.5/speedbar-gc-freespeedbuttonnode.md), [SetSpeedButtonNodeAttrsA()](autodocs-3.5/speedbar-gc-setspeedbuttonnodeattrsa.md)
```
