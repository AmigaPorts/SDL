/* Source: ADCD 2.1
 * Section: amigaguide-library-unlockamigaguidebasemigaguide-library
 * Library: autodocs-3.5
 * ADCD reference: autodocs-3.5/amigaguide-library-unlockamigaguidebasemigaguide-library.md
 */

    NAME
        UnlockAmigaGuideBase - Unlock an AmigaGuide client.     (V34)

    SYNOPSIS
        UnlockAmigaGuideBase (key);
                              d0

        VOID UnlockAmigaGuideBase (LONG);

    FUNCTION
        This function is used to release a lock obtained with
        [LockAmigaGuideBase()](../Includes_and_Autodocs_3._guide/node000D.html).

    INPUTS
        key - Value returned by [LockAmigaGuideBase()](../Includes_and_Autodocs_3._guide/node000D.html).

    SEE ALSO
        [LockAmigaGuideBase()](../Includes_and_Autodocs_3._guide/node000D.html).
