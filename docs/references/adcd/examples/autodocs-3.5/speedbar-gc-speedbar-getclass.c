/* Source: ADCD 2.1
 * Section: speedbar-gc-speedbar-getclass
 * Library: autodocs-3.5
 * ADCD reference: autodocs-3.5/speedbar-gc-speedbar-getclass.md
 */

    NAME
        SPEEDBAR_GetClass -- Gets the pointer to the speedbar class. (V40)

    SYNOPSIS
        speedbar_class = SPEEDBAR_GetClass();
        D0

        Class * SPEEDBAR_GetClass(VOID);

    FUNCTION
        Obtains the pointer to the SpeedBar gadget class for use with
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
        speedbar_class - Pointer to the SpeedBar gadget class.

    SEE ALSO
