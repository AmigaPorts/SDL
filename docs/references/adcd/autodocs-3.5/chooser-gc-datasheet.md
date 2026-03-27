---
title: chooser_gc/--datasheet--
manual: autodocs-3.5
chapter: autodocs-3.5
section: chooser-gc-datasheet
functions: []
libraries: []
---

# chooser_gc/--datasheet--

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

```c
     NAME
        chooser_gc -- A popup/dropdown small list selection gadget.

     SUPERCLASS
        gadgetclass

    REQUIRES
        bevel.image, glyph.image

     DESCRIPTION
        A chooser is a small-list selection object.  In its inactive mode it
        looks much like a button or cycle gadget.  When the button is pressed
        using the mouse, a menu displaying the items in the list is displayed.

        The chooser operates in either of two modes, pop-up and drop-down.
        Even though the may operate similarly internally, they are for two
        different functions.  Consult the chooser style guide for
        information on how to use these two modes.

        Advantages that this class provides:

         > Supports window relativity.

         > Supports OS 3.0 BOOPSI [Gadget](autodocs-3.5/include-intuition-intuition-h.md) HelpTest.

         > Cycle2Menu style activation.

         > Supports tab-cycle activation and keyboard control.

     METHODS
        OM_NEW -- Create the chooser gadget.  Passed to superclass.

        OM_SET -- Set object attributes.  Passed to superclass first.

        OM_DISPOSE -- Cancels the chooser menu before being passed to
            superclass.

        OM_UPDATE -- Set object notification attributes & render.
            Passed to superclass first.

        OM_NOTIFY -- Notify object attributes. Passed to superclass last.

        GM_RENDER -- Renders the gadget imagry.  Overrides the superclass.

        GM_HITTEST -- Determines if mouse is within the gadget rectangle.
            Overrrides the superclass.

        GM_GOACTIVE -- Handles activation, pops up the chooser menu.
            Overrides the superclass.

        GM_HANDLEINPUT -- Handles input events once active.  Overrides the
            superclass.

        GM_GOINACTIVE -- Closes the chooser menu.  Overrides the superclass.

        GM_DOMAIN -- Calculates mix/max sizes. Overrides the superclass.

        GM_KEYACTIVE -- Activates gadget via keyboard, advances popup
            selection to the next item, if SHIFT is pressed, it selects
            the previous item. Invoked by window.class only.

        GM_KEYINACTIVE -- Deactivates gadget. Invoked by window.class only.

        All other methods are passed to the superclass.

     ATTRIBUTES

        GA_ID (WORD)
            Applicability is (OM_NEW, OM_SET, OM_UPDATE, OM_GET, OM_NOTIFY)

        GA_ReadOnly (BOOL)
            Set to TRUE to make the gadget non-selectable, but without
            a ghost pattern.

            Defaults to FALSE.

            Applicability is (OM_NEW, OM_SET, OM_UPDATE, OM_GET)

        GA_Disabled (BOOL)
            Set to TRUE to disable gadget, FALSE otherwise

            Defaults to FALSE.

            Applicability is (OM_NEW, OM_SET, OM_UPDATE, OM_GET)

        GA_TextAttr (struct [TextAttr](autodocs-3.5/include-graphics-text-h.md) *)
            Font to use for the gadget text.

            Defaults to the screen's font.

            Applicability is (OM_NEW, OM_GET)

        CHOOSER_PopUp (BOOL)
            Sets the chooser to work in popup mode.
            Generally this mode is used for selecting an application mode or
            a state from a list of possible values.  This item is mutually
            exclusive to CHOOSER_DropDown, one of the two MUST be TRUE.

            Defaults to FALSE.

            Applicability is (OM_NEW, OM_SET, OM_UPDATE, OM_GET)

        CHOOSER_DropDown (BOOL)
            Sets the chooser to work in dropdown mode.  Generally for
            selecting an action to perform from a list of possible actions.
            This item is mutually exclusive to CHOOSER_PopUp, one of the
            two MUST be TRUE.

            Defaults to FALSE.

            Applicability is (OM_NEW, OM_SET, OM_UPDATE, OM_GET)

        CHOOSER_Title (STRPTR)
            Title to appear within the select box when in dropdown mode

            Defaults to NULL.

            Applicability is (OM_NEW, OM_SET, OM_UPDATE, OM_GET)

        CHOOSER_Labels (struct [List](autodocs-3.5/include-exec-lists-h.md) *)
            Exec [List](autodocs-3.5/include-exec-lists-h.md) of labels.  Each node must be allocated with the
            [AllocChooserNodeA()](autodocs-3.5/chooser-gc-allocchoosernodea.md) function.

            Applicability is (OM_NEW, OM_SET, OM_UPDATE, OM_GET)

        CHOOSER_MaxLabels (WORD)
            Set the maximum number of labels that will be displayed in the
            chooser, regardless of the size of the list.

            Defaults to 12.

            Applicability is (OM_NEW, OM_SET, OM_UPDATE, OM_GET)

        CHOOSER_Active (WORD) /* Obsolete */
        CHOOSER_Selected (WORD)
            Index of selected label in the list.

            Applicability is (OM_NEW, OM_SET, OM_UPDATE, OM_GET, OM_NOTIFY)

        CHOOSER_Width (WORD)
            The width of the chooser menu.

            Defaults to the width of the gadget select box.

            Applicability is (OM_NEW, OM_SET, OM_UPDATE, OM_GET)

        CHOOSER_AutoFit (BOOL)
            Set the width of the chooser menu so that it fits the widest
            label in the list.

            Defaults to FALSE.

            Applicability is (OM_NEW, OM_SET, OM_UPDATE, OM_GET)
```
