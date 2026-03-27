# penmap_ic/PENMAP_GetClass




```c
    NAME
        PENMAP_GetClass -- Gets the pointer to the penmap class.

    SYNOPSIS
        penmap_class = PENMAP_GetClass();
        D0

        Class * PENMAP_GetClass(VOID);

    FUNCTION
        Obtains the pointer to the PenMap image class for use with
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
        penmap_class - Pointer to the PenMap image class.

    SEE ALSO
```
