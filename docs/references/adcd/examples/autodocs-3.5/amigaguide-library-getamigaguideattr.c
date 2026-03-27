/* Source: ADCD 2.1
 * Section: amigaguide-library-getamigaguideattr
 * Library: autodocs-3.5
 * ADCD reference: autodocs-3.5/amigaguide-library-getamigaguideattr.md
 */

    NAME
        GetAmigaGuideAttr - Get an AmigaGuide attribute.        (V34)

    SYNOPSIS
        retval = GetAmigaGuideAttr (tag, handle, storage);
        d0                           d0    a0      a1

        [LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) GetAmigaGuideAttr (Tag, [AMIGAGUIDECONTEXT](../Includes_and_Autodocs_3._guide/node05D2.html#line86), ULONG *);

    FUNCTION
        This function is used to obtain attributes from AmigaGuide.

    INPUTS
        tag - Attribute to obtain.
        handle - Handle to an AmigaGuide system.
        storage - Pointer to appropriate storage for the answer.

    TAGS
        AGA_Path (BPTR) - Pointer to the current path used by
            AmigaGuide.

        AGA_XRefList (struct [List](../Includes_and_Autodocs_3._guide/node0628.html#line19) *) - Pointer to the current
            cross reference list.

    RETURNS

    SEE ALSO
        [SetAmigaGuideAttrsA()](../Includes_and_Autodocs_3._guide/node0014.html)
