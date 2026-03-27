---
title: chooser_gc/SetChooserNodeAttrsA
manual: autodocs-3.5
chapter: autodocs-3.5
section: chooser-gc-setchoosernodeattrsa
functions: []
libraries: []
---

# chooser_gc/SetChooserNodeAttrsA

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

```c
    NAME
        SetChooserNodeAttrsA -- Set attributes of a Chooser node.

    SYNOPSIS
        VOID SetChooserNodeAttrs(struct [Node](autodocs-3.5/include-exec-nodes-h.md) *, [Tag](autodocs-3.5/include-utility-tagitem-h.md), ...)
        SetChooserNodeAttrs(node, firsttag, ...)

        VOID SetChooserNodeAttrsA(struct [Node](autodocs-3.5/include-exec-nodes-h.md) *, struct [TagItem](autodocs-3.5/include-utility-tagitem-h.md) *)
        SetChooserNodeAttrsA(node, taglist)

    FUNCTION
        Changes attributes for a Chooser node.  Since the Chooser
        class uses a private node structure, this is the only way to change
        node attributes.

        You may NOT change node attributes when the node is in a list
        attached to a Chooser gadget.  You must first detach the list
        with CHOOSER_Labels, ~0 before you can change attributes, and
        then re-attach the list.

    TAGS
        CNA_Text (STRPTR)
        [Text](autodocs-3.5/graphics-library-text-2.md) string to appear as a line in the Chooser menu. This tag
        must be supplied for the node.

        CNA_Image (struct [Image](autodocs-3.5/include-intuition-intuition-h.md) *)
        [Image](autodocs-3.5/include-intuition-intuition-h.md) to be placed to the left of the CNA_Text in the Chooser menu.

        CNA_SelImage (struct [Image](autodocs-3.5/include-intuition-intuition-h.md) *)
        Selected state [Image](autodocs-3.5/include-intuition-intuition-h.md) to be placed to the left of the CNA_Text in
        the Chooser menu.

        CNA_ReadOnly (BOOL) (V41.4)
        Item will not be highlight rendered when selected.

        CNA_Disabled (BOOL) (V41.5)
        Item can not be selected. No GADGETUP message is generated.

        CNA_Separator (BOOL) (V41.7)
        Separator (~~~~) Bar Item can not be selected. Simular to the
        separator bars in Intuition menus. No GADGETUP message is generated.

    INPUTS
        node - [Node](autodocs-3.5/include-exec-nodes-h.md) whose attributes you are changing.
        taglist - [Tag](autodocs-3.5/include-utility-tagitem-h.md) list of attributes to change.

    SEE ALSO
        [GetChooserNodeAttrsA()](autodocs-3.5/chooser-gc-getchoosernodeattrsa.md)
```
