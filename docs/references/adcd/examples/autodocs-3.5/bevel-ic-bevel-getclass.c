/* Source: ADCD 2.1
 * Section: bevel-ic-bevel-getclass
 * Library: autodocs-3.5
 * ADCD reference: autodocs-3.5/bevel-ic-bevel-getclass.md
 */

    NAME
        BEVEL_GetClass -- Gets the pointer to the bevel class.

    SYNOPSIS
        bevel_class = BEVEL_GetClass();
        D0

        Class * BEVEL_GetClass(VOID);

    FUNCTION
        Obtains the pointer to the Bevel image class for use with
        [NewObject()](../Includes_and_Autodocs_3._guide/node03CB.html).  This function always returns a valid pointer so
        you do not need to check it.  The reason is that if the library
        opens fine, then the pointer returned is already setup.  (Of course
        this implies that if opening the library fails, you shouldn't be
        calling this.)

        Note that this function does not create the class, that is done
        when the class library is opened.

    INPUTS
        Nothing.

    RESULT
        bevel_class - Pointer to the Bevel image class.

    SEE ALSO
