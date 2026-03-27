---
title: scroller_gc/--datasheet--
manual: autodocs-3.5
chapter: autodocs-3.5
section: scroller-gc-datasheet
functions: [GetAttr]
libraries: [intuition.library]
---

# scroller_gc/--datasheet--

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

```c
    NAME
        scroller_gc -- create scroller BOOPSI objects

    SUPERCLASS
        gadgetclass

    REQUIRES
        bevel.image, glyph.image

    DESCRIPTION
        The scroller gadget is a propgclass wrapper class and is used
        to create proportional scroller or linear slider gadgets.
        To create a linear slider, SCROLLER_Visible must be set to 1, and
        SCROLLER_Top will range in value from 0 to SCROLLER_Total - 1.

        The IntuiMessage.Code field will contain the SCROLLER_Top
        attribute, cast to a WORD.

        Advantages that this class provides are:

         > Supports window relativity.

         > Supports OS 3.0 BOOPSI Notification/Update.

         > Special signaling ability.

         > Optional scroller arrow buttons.

         > Supports usage in window boarders.

    METHODS
        OM_NEW -- Create the scroller gadget. Also allocates an
            instance of the bevel and glyph image classes.
            Passed to superclass then calls OM_SET.

        OM_SET -- Set object attributes. Passed to superclass first.

        OM_DISPOSE -- Frees up the scroller gadget as well as the
            bevel and glyph image instances. Passed to superclass last.

        OM_UPDATE -- Set object notification attributes. Passed to
            superclass first.

        GM_RENDER -- Renders the gadget imagery. Overrides the superclass.

        GM_GOACTIVE -- Handles activation. Overrides the superclass.

        GM_HANDLEINPUT -- Handles input events once active. Overrides
            the superclass.

        GM_GOINACTIVE -- Overrides the superclass. Handles deactivation.

        GM_HELPTEST -- Test if mouse is within gadget hit area.

        GM_HITTEST -- Test if mouse is within gadget hit area.

        GM_DOMAIN -- Returns GDOMAIN_MINIMUM and GDOMAIN_MAXIMUM dimensions.

        All other methods are passed to the superclass.

    ATTRIBUTES
        SCROLLER_Top (LONG)
            Set the current top value of the scroller within the
            proportional range. (V40)

            Applicability is (OM_NEW, OM_SET, OM_UPDATE, OM_GET)

        SCROLLER_Visible (LONG)
            Set the visible portion of the proportional range. (V40)

            (OM_NEW, OM_SET, OM_UPDATE, OM_GET)

        SCROLLER_Total (LONG)
            Set the total range of the scroller. (V40)

            Applicability is (OM_NEW, OM_SET, OM_UPDATE, OM_GET)

        SCROLLER_Orientation
            Define orientation of the scroller.

            Accepted values as defined in [<gadgets/scroller.h>](autodocs-3.5/include-gadgets-scroller-h.md) are:

                SORIENT_VERT
                SORIENT_HORIZ

            Defines are found in [<gadgets/scroller.h>](autodocs-3.5/include-gadgets-scroller-h.md) and are synomyms for
            the propgclass FREEVERT and FREEHORIZ. (V40)

            Applicability is (OM_NEW, OM_GET)

        SCROLLER_Arrows (BOOL)
            [Enable](autodocs-3.5/exec-library-enable-2.md) rendering of optional scroller arrows. (V40)

            Applicability is (OM_NEW, OM_GET)

        SCROLLER_ArrowDelta (WORD) (V41)
            Allows you to change the amount that clicking an arrow causes
            the scroller to move by.

            Defaults to 1.

            Applicability is (OM_NEW, OM_SET, OM_UPDATE, OM_GET)

        SCROLLER_SignalTask (struct [Task](autodocs-3.5/include-exec-tasks-h.md) *)  (V42)
            [Signal](autodocs-3.5/exec-library-signal-2.md) the specified [Task](autodocs-3.5/include-exec-tasks-h.md) while scroller is active.  This is
            very useful to reduce the load on input.device because you can
            render from some other task (application, or anything else)
            that waits for this signal and then [GetAttr()](autodocs-3.5/intuition-library-getattr-2.md) SCROLLER_Top, etc.

            Defaults to NULL (no signaling).

            Applicability is (OM_NEW, OM_SET)

        SCROLLER_SignalTaskBit (ULONG)  (V42)
            [Signal](autodocs-3.5/exec-library-signal-2.md) with this Bit. See also; SCROLLER_SignalTask.

            Applicability is (OM_NEW, OM_SET)
```

---

## See Also

- [GetAttr — intuition.library](../autodocs/intuition.library.md#getattr)
