/* Source: ADCD 2.1
 * Section: amigaguide-library-setamigaguideattrsa
 * Library: autodocs-3.5
 * ADCD reference: autodocs-3.5/amigaguide-library-setamigaguideattrsa.md
 */

    NAME
        SetAmigaGuideAttrsA - Set an AmigaGuide attribute.      (V34)

    SYNOPSIS
        retval = SetAmigaGuideAttrsA (handle, attrs);
        d0                             a0      a1

        [LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) SetAmigaGuideAttrsA (AMIGAGUIDECONTEXT, struct [TagItem](../Includes_and_Autodocs_3._guide/node064C.html#line31) *);

        retval = SetAmigaGuideAttrs (handle, tag1, ...);

        [LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) SetAmigaGuideAttrs (AMIGAGUIDECONTEXT, [Tag](../Includes_and_Autodocs_3._guide/node064C.html#line29), ...);

    FUNCTION
        This function is used to set AmigaGuide attributes.

    INPUTS
        handle -- Pointer to an AmigaGuide handle.

        attrs -- Attribute pairs to set.

    TAGS
        AGA_Activate (BOOL) - AmigaGuide activates the window when
            it receives a LINK command.  This tag allows the
            application developer to turn that feature off and on.

    SEE ALSO
        [GetAmigaGuideAttr()](../Includes_and_Autodocs_3._guide/node000A.html)
