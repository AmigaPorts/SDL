---
title: integer_gc/INTEGER_GetClass
manual: autodocs-3.5
chapter: autodocs-3.5
section: integer-gc-integer-getclass
functions: [NewObject]
libraries: [intuition.library]
---

# integer_gc/INTEGER_GetClass

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

```c
    NAME
        INTEGER_GetClass -- Gets the pointer to the integer class.

    SYNOPSIS
        integer_class = INTEGER_GetClass();
        D0

        Class * INTEGER_GetClass(VOID);

    FUNCTION
        Obtains the pointer to the Integer gadget class for use with
        [NewObject()](autodocs-3.5/intuition-library-newobject-2.md).  This function always returns a valid pointer so
        you do not need to check it.  The reason is that if the library
        opens fine, then the pointer returned is already setup.  (Of course
        this implies that if opening the library fails, you shouldn't be
        calling this.)

        Note that this function does not create the class, that is done
        when the class library is opened.

    INPUTS
        Nothing.

    RESULT
        integer_class - Pointer to the Integer gadget class.

    SEE ALSO
```

---

## See Also

- [NewObject — intuition.library](../autodocs/intuition.library.md#newobject)
