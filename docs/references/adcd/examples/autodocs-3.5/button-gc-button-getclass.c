/* Source: ADCD 2.1
 * Section: button-gc-button-getclass
 * Library: autodocs-3.5
 * ADCD reference: autodocs-3.5/button-gc-button-getclass.md
 */

    NAME
        BUTTON_GetClass -- Gets the pointer to the button class.

    SYNOPSIS
        button_class = BUTTON_GetClass();
        D0

        Class * BUTTON_GetClass(VOID);

    FUNCTION
        This function is only available in runtime linked version of the
        class, and is not in the compiler linker library button_gc.lib.

        Obtains the pointer to the Button gadget class for use with
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
        button_class - Pointer to the Button gadget class.

    SEE ALSO
