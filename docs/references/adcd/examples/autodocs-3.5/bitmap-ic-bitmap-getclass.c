/* Source: ADCD 2.1
 * Section: bitmap-ic-bitmap-getclass
 * Library: autodocs-3.5
 * ADCD reference: autodocs-3.5/bitmap-ic-bitmap-getclass.md
 */

    NAME
        BITMAP_GetClass -- Gets the pointer to the bitmap class.

    SYNOPSIS
        bitmap_class = BITMAP_GetClass();
        D0

        Class * BITMAP_GetClass(VOID);

    FUNCTION
        Obtains the pointer to the [BitMap](../Includes_and_Autodocs_3._guide/node05DC.html#line45) image class for use with
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
        bitmap_class - Pointer to the [BitMap](../Includes_and_Autodocs_3._guide/node05DC.html#line45) image class.

    SEE ALSO
