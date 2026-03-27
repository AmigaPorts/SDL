/* Source: ADCD 2.1
 * Section: checkbox-gc-datasheet
 * Library: autodocs-3.5
 * ADCD reference: autodocs-3.5/checkbox-gc-datasheet.md
 */

    NAME
        checkbox_gc -- create checkbox BOOPSI objects

    SUPERCLASS
        gadgetclass

    REQUIRES
        bevel.image, glyph.image

    DESCRIPTION
        The checkbox gadget class is used to create toggling check buttons.
        Selection of an associated option is denoted by the gadget being
        "checked", or in other words, containing a checkmark with in the
        checkbox. Unlike GadTools, GA_Height and GA_Width DO NOT specify
        the checkbox size, but rather the entire hit box area which
        includes the text label. The checkbox will maintain its aspect
        ratio when possible.

        Advantages that this class provides over the standard gadtools
        checkbox are:

         > Supports window relativity.

         > Ability to change background pen, text pen, and filltext pen.

         > Larger selection area, includes text label area.

         > Supports OS 3.0 BOOPSI [Gadget](../Includes_and_Autodocs_3._guide/node05E0.html#line213) HelpTest.

         > Aspect adaptive checkbox for any resolution and font.

    METHODS
        OM_NEW -- Passed to superclass first, defaults set, then OM_SET.

        OM_SET -- Passed to superclass first, then custom tags set & render.

        OM_GET -- Returns requested setting or passed to superclass

        OM_UPDATE -- Passed to superclass first, then custom tags set & render.

        OM_NOTIFY -- [Tag](../Includes_and_Autodocs_3._guide/node064C.html#line29) set then passed to superclass.

        OM_DISPOSE -- Passed to superclass.

        GM_DOMAIN -- Returns aspect ratio corrected minimum and maximum
            sizes.

        GM_GOACTIVE -- Passed to superclass first, then check activated

        GM_GOINACTIVE -- Passed to superclass first, then check deactivated

        GM_HANDLEINPUT -- Overrides superclass.

        GM_HITTEST -- Overrides superclass, returns GMR_HITTEST.

        GM_RENDER -- Renders or erases checkmark glyph.

        GM_DOMAIN -- Returns GDOMAIN_MINIMUM, GDOMAIN_NOMINAL and
            GDOMAIN_MAXIMUM dimensions.

        GM_KEYACTIVE -- Private method for keyboard control.

        GM_KEYINACTIVE -- Private method for keyboard control.

    ATTRIBUTES

        GA_ID (WORD)
            Applicability is (OM_NEW, OM_SET, OM_UPDATE, OM_NOTIFY)

        GA_Text (STRPTR)
            Used to set the text label for the checkbox

            Defaults to NULL.

            Applicability is (OM_NEW, OM_SET, OM_UPDATE)

        GA_TextAttr (struct [TextAttr](../Includes_and_Autodocs_3._guide/node05EC.html#line64) *)
            Used to set the text font to render the checkbox label.

            Defaults to RPort->Font, which is often the screen or
            window font.

            Applicability is (OM_NEW, OM_SET)

        GA_Selected (BOOL)
            Used to set the checkmark state via application control.

            Defaults to FALSE.

            Applicability is (OM_NEW, OM_SET, OM_UPDATE, OM_NOTIFY)

        GA_Disabled (BOOL)
            Used to disable the gadget, and render a disable ghost
            pattern of the checkbox.

            Defaults to FALSE.

            Applicability is (OM_NEW, OM_SET, OM_UPDATE)

        CHECKBOX_TextPen (WORD)
            Pen number used to render the text label.

            Defaults to TEXTPEN.

            Applicability is (OM_NEW, OM_SET, OM_UPDATE)

        CHECKBOX_BackGroundPen (WORD)
            Pen number used to render the gadget background.

            Defaults to BACKGROUNDPEN.

            Applicability is (OM_NEW, OM_SET, OM_UPDATE)

        CHECKBOX_TextPlace (WORD)
            Location of checkbox text label. Supports:

                PLACETEXT_RIGHT
                PLACETEXT_LEFT

            Defaults to PLACETEXT_RIGHT.

            Applicability is (OM_NEW)
