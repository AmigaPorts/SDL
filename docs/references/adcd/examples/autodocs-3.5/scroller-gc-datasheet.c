/* Source: ADCD 2.1
 * Section: scroller-gc-datasheet
 * Library: autodocs-3.5
 * ADCD reference: autodocs-3.5/scroller-gc-datasheet.md
 */

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

            Accepted values as defined in [<gadgets/scroller.h>](../Includes_and_Autodocs_3._guide/node0667.html) are:

                SORIENT_VERT
                SORIENT_HORIZ

            Defines are found in [<gadgets/scroller.h>](../Includes_and_Autodocs_3._guide/node0667.html) and are synomyms for
            the propgclass FREEVERT and FREEHORIZ. (V40)

            Applicability is (OM_NEW, OM_GET)

        SCROLLER_Arrows (BOOL)
            [Enable](../Includes_and_Autodocs_3._guide/node0205.html) rendering of optional scroller arrows. (V40)

            Applicability is (OM_NEW, OM_GET)

        SCROLLER_ArrowDelta (WORD) (V41)
            Allows you to change the amount that clicking an arrow causes
            the scroller to move by.

            Defaults to 1.

            Applicability is (OM_NEW, OM_SET, OM_UPDATE, OM_GET)

        SCROLLER_SignalTask (struct [Task](../Includes_and_Autodocs_3._guide/node064B.html#line23) *)  (V42)
            [Signal](../Includes_and_Autodocs_3._guide/node023D.html) the specified [Task](../Includes_and_Autodocs_3._guide/node064B.html#line23) while scroller is active.  This is
            very useful to reduce the load on input.device because you can
            render from some other task (application, or anything else)
            that waits for this signal and then [GetAttr()](../Includes_and_Autodocs_3._guide/node03B5.html) SCROLLER_Top, etc.

            Defaults to NULL (no signaling).

            Applicability is (OM_NEW, OM_SET)

        SCROLLER_SignalTaskBit (ULONG)  (V42)
            [Signal](../Includes_and_Autodocs_3._guide/node023D.html) with this Bit. See also; SCROLLER_SignalTask.

            Applicability is (OM_NEW, OM_SET)
