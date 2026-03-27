---
title: clicktab_gc/SetClickTabNodeAttrsA
manual: autodocs-3.5
chapter: autodocs-3.5
section: clicktab-gc-setclicktabnodeattrsa
functions: []
libraries: []
---

# clicktab_gc/SetClickTabNodeAttrsA

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

```c
    NAME
        SetClickTabNodeAttrsA -- Set attributes of a ClickTab node.

    SYNOPSIS
        VOID SetClickTabNodeAttrs(struct [Node](autodocs-3.5/include-exec-nodes-h.md) *, [Tag](autodocs-3.5/include-utility-tagitem-h.md), ...)
        SetClickTabNodeAttrs(node, firsttag, ...)

        VOID SetClickTabNodeAttrsA(struct [Node](autodocs-3.5/include-exec-nodes-h.md) *, struct [TagItem](autodocs-3.5/include-utility-tagitem-h.md) *)
        SetClickTabNodeAttrsA(node, taglist)

    FUNCTION
        Changes attributes for a ClickTab node.  Since the ClickTab
        class uses a private node structure, this is the only way to change
        node attributes.

        You may NOT change node attributes when the node is in a list
        attached to a ClickTab gadget.  You must first detach the list
        with CLICKTAB_Labels, ~0 before you can change attributes, and
        then re-attach the list, and re-render the gadget to reflect
        any changes. This should include re-domaining the gadget.
        If used in a layout group, turn off domain caching for the
        clicktab object if you intend to dynamically alter the tabs
        and refresh the layout group with [RethinkLayout()](autodocs-3.5/layout-gc-rethinklayout.md).

    TAGS
        TNA_Text (STRPTR)

            [Text](autodocs-3.5/graphics-library-text-2.md) string to appear as a line in the ClickTab menu node.

        TNA_Number (WORD)

            ID Number assigned to a ClickTab menu node

        TNA_TextPen (WORD)

            Specifies pen number to use for the label.

            Defaults to pens[TEXTPEN].

    INPUTS
        node - [Node](autodocs-3.5/include-exec-nodes-h.md) whose attributes you are changing.
        taglist - [Tag](autodocs-3.5/include-utility-tagitem-h.md) list of attributes to change.

    SEE ALSO
        [GetClickTabNodeAttrsA()](autodocs-3.5/clicktab-gc-getclicktabnodeattrsa.md)
```
