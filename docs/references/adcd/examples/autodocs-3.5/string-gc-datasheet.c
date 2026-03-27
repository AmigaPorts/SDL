/* Source: ADCD 2.1
 * Section: string-gc-datasheet
 * Library: autodocs-3.5
 * ADCD reference: autodocs-3.5/string-gc-datasheet.md
 */

        string_gc -- create string BOOPSI objects

    SUPERCLASS
        gadgetclass

    REQUIRES
        bevel.image

    DESCRIPTION
        The string gadget class is used to create single line
        editable strings. This class also supports window relativity.
        This class is a subclass of rom strgclass which automatically
        creates a field bevel and supports GM_DOMAIN for layout groups.

     METHODS
        OM_NEW -- Passed to superclass, strgclass allocated, then OM_SET.

        OM_SET -- Passed to superclass, and strgclass is set.

        OM_UPDATE -- Passed to superclass, and strgclass is set then
            rendered.

        OM_DISPOSE -- Disposes strgclass object, then passed to superclass.

        GM_RENDER -- Passed to superclass, then strgclass object

        GM_HITTEST -- Overrides supperclass, returns GMR_HITTEST.

        GM_GOACTIVE -- Passed to superclass, strgclass, string activated

        GM_HANDLEINPUT -- Routes input to strgclass object.

        GM_GOINACTIVE -- Passed to superclass, strgclass, string deactivated.

        GM_DOMAIN -- Returns GDOMAIN_MINIMUM, GDOMAIN_NOMINAL and
            GDOMAIN_MAXIMUM dimensions.

     ATTRIBUTES
        GA_Disabled (BOOL)
            Determines whether the string is disabled or not.
            Changing disable state will invoke GM_RENDER.  A disabled
            string is dusted in a ghosting pattern that is rendered
            in SHADOWPEN.

            Defaults to FALSE.

            Applicability is (OM_NEW, OM_SET, OM_UPDATE)

        GA_TextAttr (struct [TextAttr](../Includes_and_Autodocs_3._guide/node05EC.html#line64) *)
            [Text](../Includes_and_Autodocs_3._guide/node0332.html) attribute for the font to use for the string.

            Defaults to RPort->Font, which is often the screen or
            window font.

            Applicability is (OM_NEW)

        GA_ReadOnly (BOOL)
            Read-only gadgets ignore activation attempts.

            Defaults to FALSE.

            Applicability is (OM_NEW, OM_SET, OM_UPDATE)

        STRINGA_MinVisible (WORD) (V41)
            Set the minimum number of characters that should be
            visible for a 'GDOMAIN_MIMIMUM' domain size. Nominal
            domain sizes to twice this minimum. This is a handy
            addition (also present in V40.35) to ensure a mimimum
            number characters will be visible in a string gadget.

            Defaults to 4.

            Applicability is (OM_NEW, OM_SET, OM_UPDATE)


     NOTES

        The string class passes all tags to its strgclass child,
        please see strgclass tags & autodocs, and look in
        [<intuition/gadgetclass.h>](../Includes_and_Autodocs_3._guide/node0615.html) for the STRINGA_ tags.

        WARNING: string.gadget is ROM strgclass wrapper, depending on
        string.gadget version. Passing GA_Text can crash strgclass,
        please use STRING_TextVal as its intended. STRINGA_Font and
        STRINGA_LongVal are not directly supported, for numeric
        strings use our more powerful integer.gadget class. To specify
        the font for the gadget, use GA_TextAttr which is consistant
        with all other ReAction gadget attributes.
