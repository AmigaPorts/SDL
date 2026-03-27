/* Source: ADCD 2.1
 * Section: chooser-gc-chooser-getclass
 * Library: autodocs-3.5
 * ADCD reference: autodocs-3.5/chooser-gc-chooser-getclass.md
 */

    NAME
        CHOOSER_GetClass -- Gets the pointer to the chooser class.

    SYNOPSIS
        chooser_class = CHOOSER_GetClass();
        D0

        Class * CHOOSER_GetClass(VOID);

    FUNCTION
        This function is only available in runtime linked version of the
        class, and is not in the compiler linker library chooser_gc.lib.

        Obtains the pointer to the Chooser gadget class for use with
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
        chooser_class - Pointer to the Chooser gadget class.

    SEE ALSO
