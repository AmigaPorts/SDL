---
title: label_ic/LABEL_GetClass
manual: autodocs-3.5
chapter: autodocs-3.5
section: label-ic-label-getclass
functions: [NewObject]
libraries: [intuition.library]
---

# label_ic/LABEL_GetClass

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

```c
    NAME
        LABEL_GetClass -- Gets the pointer to the label image class.

    SYNOPSIS
        label_class = LABEL_GetClass();
        D0

        Class * LABEL_GetClass(VOID);

    FUNCTION
        Obtains the pointer to the Label gadget class for use with
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
        label_class - Pointer to the Label gadget class.

    SEE ALSO
```

---

## See Also

- [NewObject — intuition.library](../autodocs/intuition.library.md#newobject)
