---
title: speedbar_gc/SPEEDBAR_GetClass
manual: autodocs-3.5
chapter: autodocs-3.5
section: speedbar-gc-speedbar-getclass
functions: [NewObject]
libraries: [intuition.library]
---

# speedbar_gc/SPEEDBAR_GetClass

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

```c
    NAME
        SPEEDBAR_GetClass -- Gets the pointer to the speedbar class. (V40)

    SYNOPSIS
        speedbar_class = SPEEDBAR_GetClass();
        D0

        Class * SPEEDBAR_GetClass(VOID);

    FUNCTION
        Obtains the pointer to the SpeedBar gadget class for use with
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
        speedbar_class - Pointer to the SpeedBar gadget class.

    SEE ALSO
```

---

## See Also

- [NewObject — intuition.library](../autodocs/intuition.library.md#newobject)
