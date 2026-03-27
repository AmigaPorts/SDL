/* Source: ADCD 2.1
 * Section: string-gc-string-getclass
 * Library: autodocs-3.5
 * ADCD reference: autodocs-3.5/string-gc-string-getclass.md
 */

    NAME
        STRING_GetClass -- Gets the pointer to the string class.

    SYNOPSIS
        string_class = STRING_GetClass();
        D0

        Class * STRING_GetClass(VOID);

    FUNCTION
        Obtains the pointer to the String gadget class for use with
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
        string_class - Pointer to the String gadget class.

    SEE ALSO
