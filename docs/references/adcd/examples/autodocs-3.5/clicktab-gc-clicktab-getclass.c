/* Source: ADCD 2.1
 * Section: clicktab-gc-clicktab-getclass
 * Library: autodocs-3.5
 * ADCD reference: autodocs-3.5/clicktab-gc-clicktab-getclass.md
 */

    NAME
        CLICKTAB_GetClass  --  Gets the pointer to the clicktab class.

    SYNOPSIS
        clicktab_class = CLICKTAB_GetClass();
        D0

        Class * CLICKTAB_GetClass(VOID);

    FUNCTION
        Obtains the pointer to the ClickTab gadget class for use with
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
        clicktab_class - Pointer to the ClickTab gadget class.

    SEE ALSO
