---
title: radiobutton_gc/AllocRadioButtonNodeA
manual: autodocs-3.5
chapter: autodocs-3.5
section: radiobutton-gc-allocradiobuttonnodea
functions: []
libraries: []
---

# radiobutton_gc/AllocRadioButtonNodeA

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

```c
    NAME
        AllocRadioButtonNodeA -- [Allocate](autodocs-3.5/exec-library-allocate-2.md) a RadioButton node. (V40)

    SYNOPSIS
        struct [Node](autodocs-3.5/include-exec-nodes-h.md) * AllocRadioButtonNode(UWORD, [Tag](autodocs-3.5/include-utility-tagitem-h.md), ...)
        node = AllocRadioButtonNode(columns, [Tag](autodocs-3.5/include-utility-tagitem-h.md), ...)

        struct [Node](autodocs-3.5/include-exec-nodes-h.md) * AllocRadioButtonNodeA(UWORD, struct [TagItem](autodocs-3.5/include-utility-tagitem-h.md) *)
        node = AllocRadioButtonNodeA(taglist)

    FUNCTION
        Allocates a node that can be added to the Exec linked list of
        labels in the radiobutton.  This is the only way to allocate a
        node for this list, you cannot allocate nodes yourself because
        the RadioButton class uses a private node structure.

    INPUTS
        taglist - Attributes for the node, passed onto
            [SetRadioButtonNodeAttrsA()](autodocs-3.5/radiobutton-gc-setradiobuttonnodeattrsa.md).

    RESULT
        node - A node that can be added into the Exec list of labels for
            a RadioButton gadget.

    SEE ALSO
        [FreeRadioButtonNode()](autodocs-3.5/radiobutton-gc-freeradiobuttonnode.md), [SetRadioButtonNodeAttrsA()](autodocs-3.5/radiobutton-gc-setradiobuttonnodeattrsa.md)
```
