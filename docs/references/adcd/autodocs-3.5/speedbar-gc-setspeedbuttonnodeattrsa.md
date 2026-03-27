---
title: speedbar_gc/SetSpeedButtonNodeAttrsA
manual: autodocs-3.5
chapter: autodocs-3.5
section: speedbar-gc-setspeedbuttonnodeattrsa
functions: []
libraries: []
---

# speedbar_gc/SetSpeedButtonNodeAttrsA

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

```c
    NAME
        SetSpeedButtonNodeAttrsA -- Set attributes of a SpeedBar node. (V40)

    SYNOPSIS
        VOID SetSpeedButtonNodeAttrs(struct [Node](autodocs-3.5/include-exec-nodes-h.md) *, [Tag](autodocs-3.5/include-utility-tagitem-h.md), ...)
        SetSpeedButtonNodeAttrs(node, firsttag, ...)

        VOID SetSpeedButtonNodeAttrsA(struct [Node](autodocs-3.5/include-exec-nodes-h.md) *, struct [TagItem](autodocs-3.5/include-utility-tagitem-h.md) *)
        SetSpeedButtonNodeAttrsA(node, taglist)

    FUNCTION
        Changes attributes for a SpeedBar node.  Since the SpeedBar
        class uses a private node structure, this is the only way to change
        node attributes.

        You may NOT change node attributes when the node is in a list
        attached to a SpeedBar gadget.  You must first detach the list
        with SPEEDBAR_Labels, ~0 before you can change attributes, and
        then re-attach the list.

    TAGS
        SBNA_Left (WORD)
        Left spacing offset of button from left of bar, set automatically.

        SBNA_Top (WORD)
        Top spacing offset of button from top of bar, set automatically.

        SBNA_Width (WORD)
        Width Of Button - these are set automatically.

        SBNA_Height (WORD)
        Height Of Button - these are set automatically.

        SBNA_Image (struct [Image](autodocs-3.5/include-intuition-intuition-h.md) *)
        Standard [Image](autodocs-3.5/include-intuition-intuition-h.md) or BOOPSI [Image](autodocs-3.5/include-intuition-intuition-h.md) to be displayed in this button.

        SBNA_SelImage (struct [Image](autodocs-3.5/include-intuition-intuition-h.md) *)
        Standard [Image](autodocs-3.5/include-intuition-intuition-h.md) or BOOPSI [Image](autodocs-3.5/include-intuition-intuition-h.md) to be displayed in this button
        when selected.

        SBNA_Spacing (WORD)
        Spacing between this button and the last button.

        SBNA_Highlight (WORD)
        Button selecting highlight mode, ant one of the following
        is supported:

                SBH_NONE        - Do not highlight.
                SBH_BACKFILL    - BackFill will FILLPEN
                SBH_RECESS      - Shift image right and down when selected.
                SBH_IMAGE       - Display alternate image (SBNA_SelImage)

        SBNA_Enabled (BOOL)
        Enabled (hidden/shown) state of a speed button.

        SBNA_Help (STRPTR)
        String Pointer to optional help text place in window titlebar
        when this speed button is active/selected.

        SBNA_UserData (APTR)
        User Data, use as desired.

        SBNA_Disabled (BOOL) (V41)
        Marks this button as disabled, it will render with a ghost pattern
        and will not allow it to be selected.

        SBNA_Toggle (BOOL) (V41)
        Designates the button as a boolean toggle button. Defaults FALSE.

        SBNA_Selected (BOOL) (V41)
        The current selection state of a Toggle/MX button. Defaults FALSE.

        SBNA_MXGroup (BOOL) (V41)
        Set the MXGroup a button belongs in. This setting implies the
        SBNA_Toggle setting as TRUE also. The default is ~0, or not
        in any MXGroup. Note, a single speedbar can contain several
        MX groupings and mixtures of toggles and normal selections!

    INPUTS
        node - [Node](autodocs-3.5/include-exec-nodes-h.md) whose attributes you are changing.
        taglist - [Tag](autodocs-3.5/include-utility-tagitem-h.md) list of attributes to change.

    SEE ALSO
        [GetSpeedButtonNodeAttrsA()](autodocs-3.5/speedbar-gc-getspeedbuttonnodeattrsa.md)
```
