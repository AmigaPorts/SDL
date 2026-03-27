/* Source: ADCD 2.1
 * Section: scroller-gc-scroller-getclass
 * Library: autodocs-3.5
 * ADCD reference: autodocs-3.5/scroller-gc-scroller-getclass.md
 */

    NAME
        SCROLLER_GetClass -- Gets the pointer to the scroller class.

    SYNOPSIS
        scroller_class = SCROLLER_GetClass();
        D0

        Class * SCROLLER_GetClass(VOID);

    FUNCTION
        Obtains the pointer to the Scroller gadget class for use with
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
        scroller_class - Pointer to the Scroller gadget class.

    SEE ALSO
