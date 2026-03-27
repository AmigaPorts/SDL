---
title: clicktab_gc/--datasheet--
manual: autodocs-3.5
chapter: autodocs-3.5
section: clicktab-gc-datasheet
functions: []
libraries: []
---

# clicktab_gc/--datasheet--

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

```c
    NAME
        clicktab.gadget--File folder tabs gadget.

    SUPERCLASS
        gadgetclass

    REQUIRES
        None.

    DESCRIPTION
        The tabs gadget class provides a custom control that has imagry
        similar in style to the tabs seen in a drawer full of file folders.
        The action of the gadget is the same as a conventional
        mutual-exclusion control in that only one tab can be active at a
        time and a tab is selected by clicking upon it.

        The purpose of the tabs gadget class is to provide functionality like
        the page selection cycle gadget on the top-right side of the AmigaOS
        2.1 PrinterPS preferences editor, but allowing all the choices to be
        visible at the same time. The tab "bar" allows strumming across the
        selections. The current selection is slightly raised and its text
        label displayed in bold.

    METHODS
        OM_NEW -- Create the button gadget.  Passed to superclass, then OM_SET.

        OM_GET -- Get an object attribute.  Passed to superclass for unknown
            attributes.

        OM_SET -- Set object attributes.  Passed to superclass first.

        OM_UPDATE -- Set object notification attributes.  Passed to superclass
            first.

        OM_NOTIFY -- Sets  taglist for notification and pass to superclass.

        GM_DOMAIN -- Calculate imagery & positioning, and return
            minimum/maximum domain size.

        GM_RENDER -- Renders the gadget imagry.  Overrides the superclass.

        GM_HITTEST -- Determines if mouse is within the gadget rectangle.
            Overrides the superclass.

        GM_GOACTIVE -- Handles activation, toggle-select and button-select.
            Overrides the superclass.

        GM_GOINACTIVE -- Deactivates object.  Overrides the superclass.

        GM_HANDLEINPUT -- Handles selection input, RMB undo/abort, etc.

        GM_KEYACTIVE -- Activates gadget via keyboard, selects appropriate
            tab based on input key.  Invoked by window.class only.

        GM_KEYINACTIVE -- Deactivates gadget.  Invoked by window.class only.

        All other methods are passed to the superclass, including OM_DISPOSE.

    ATTRIBUTES

        GA_ID (WORD)
            Applicability is (OM_NEW, OM_SET, OM_UPDATE, OM_NOTIFY)

        GA_Top (LONG)
            The top of the gadget.  Typically win->BorderTop + 2 for proper
            placement along the inner top of a window unless used within a
            layout gadget group, then placement is automatic.

        GA_Left (LONG)
            The left edge of the gadget.

        GA_Height (LONG)
            Height of the gadget.  Typically font height plus eight.

        GA_RelHeight (LONG)
            Like all other ReAction gadgets, this attribute is supported.
            However, due to the nature of the classes intended visuals
            it is stylistically a bad thing to do.

        GA_Disabled (BOOL) -- Determines whether the gadget is disabled or
            not.  Changing disable state will invoke GM_RENDER.  A disabled
            gadget's border and label are all rendered in SHADOWPEN and then
            dusted in a ghosting pattern that is rendered in SHADOWPEN.

            Defaults to FALSE.

        GA_TextAttr (struct [TextAttr](autodocs-3.5/include-graphics-text-h.md) *)
            Optional text attribute for the font to use for the labels.

            Defaults to NULL.

        CLICKTAB_Labels (struct [List](autodocs-3.5/include-exec-lists-h.md) *)
            A list of clicktab node structures used to indicate the labels
            for each of the tabs.

            Defaults to NULL.

            Applicability is (OM_NEW)

        CLICKTAB_Current (LONG)
            Currently selected tab.

            Defaults to 0.

            Applicability is (OM_NEW, OM_SET, OM_UPDATE, OM_NOTIFY)

    NOTES

        This class is best suited for use in a ReAction layout group
        and requires receiving GM_DOMAIN prior to the first GM_RENDER
        in order to size & position its imagery correctly.
```
