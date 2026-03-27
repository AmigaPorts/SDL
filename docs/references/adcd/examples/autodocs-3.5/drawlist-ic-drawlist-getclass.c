/* Source: ADCD 2.1
 * Section: drawlist-ic-drawlist-getclass
 * Library: autodocs-3.5
 * ADCD reference: autodocs-3.5/drawlist-ic-drawlist-getclass.md
 */

    NAME
        DRAWLIST_GetClass -- Gets the pointer to the drawlist class.

    SYNOPSIS
        drawlist_class = DRAWLIST_GetClass();
        D0

        Class * DRAWLIST_GetClass(VOID);

    FUNCTION
        Obtains the pointer to the [DrawList](../Includes_and_Autodocs_3._guide/node0603.html#line67) image class for use with
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
        drawlist_class - Pointer to the [DrawList](../Includes_and_Autodocs_3._guide/node0603.html#line67) image class.

    SEE ALSO
