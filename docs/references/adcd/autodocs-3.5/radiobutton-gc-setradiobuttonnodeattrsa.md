---
title: radiobutton_gc/SetRadioButtonNodeAttrsA
manual: autodocs-3.5
chapter: autodocs-3.5
section: radiobutton-gc-setradiobuttonnodeattrsa
functions: []
libraries: []
---

# radiobutton_gc/SetRadioButtonNodeAttrsA

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

```c
    NAME
        SetRadioButtonNodeAttrsA -- Set attributes of a RadioButton node. (V40)

    SYNOPSIS
        VOID SetRadioButtonNodeAttrs(struct [Node](autodocs-3.5/include-exec-nodes-h.md) *, [Tag](autodocs-3.5/include-utility-tagitem-h.md), ...)
        SetRadioButtonNodeAttrs(node, firsttag, ...)

        VOID SetRadioButtonNodeAttrsA(struct [Node](autodocs-3.5/include-exec-nodes-h.md) *, struct [TagItem](autodocs-3.5/include-utility-tagitem-h.md) *)
        SetRadioButtonNodeAttrsA(node, taglist)

    FUNCTION
        Changes attributes for a RadioButton node.  Since the RadioButton
        class uses a private node structure, this is the only way to change
        node attributes.

        You may NOT change node attributes when the node is in a list
        attached to a RadioButton gadget.  You must first detach the list
        with RADIOBUTTON_Labels, ~0 before you can change attributes, and
        then re-attach the list.

    TAGS
        RBNA_Label (STRPTR)

    INPUTS
        node - [Node](autodocs-3.5/include-exec-nodes-h.md) whose attributes you are changing.
        taglist - [Tag](autodocs-3.5/include-utility-tagitem-h.md) list of attributes to change.

    SEE ALSO
        [GetRadioButtonNodeAttrsA()](autodocs-3.5/radiobutton-gc-getradiobuttonnodeattrsa.md)
```
