/* Source: ADCD 2.1
 * Section: amigaguide-library-lockamigaguidebase
 * Library: autodocs-3.5
 * ADCD reference: autodocs-3.5/amigaguide-library-lockamigaguidebase.md
 */

    NAME
        LockAmigaGuideBase - [Lock](../Includes_and_Autodocs_3._guide/node0186.html) an AmigaGuide client.         (V34)

    SYNOPSIS
        key = LockAmigaGuideBase (AMIGAGUIDECONTEXT handle);
        d0                                            a0

        [LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) LockAmigaGuideBase (AMIGAGUIDECONTEXT);

    FUNCTION
        This function is used to lock the AmigaGuide context handle
        while working with data obtained with the the
        [GetAmigaGuideAttr()](../Includes_and_Autodocs_3._guide/node000A.html) function.

    INPUTS
        handle - [AMIGAGUIDECONTEXT](../Includes_and_Autodocs_3._guide/node05D2.html#line86) handle obtained with
            OpenAmigaGuideAsync().

    RETURNS
        Returns a key to pass to [UnlockAmigaGuideBase()](../Includes_and_Autodocs_3._guide/node0016.html).

    SEE ALSO
        [UnlockAmigaGuideBase()](../Includes_and_Autodocs_3._guide/node0016.html)
