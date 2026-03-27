---
title: palette_gc/PALETTE_GetClass
manual: autodocs-3.5
chapter: autodocs-3.5
section: palette-gc-palette-getclass
functions: [NewObject]
libraries: [intuition.library]
---

# palette_gc/PALETTE_GetClass

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

```c
    NAME
        PALETTE_GetClass -- Gets the pointer to the palette class.

    SYNOPSIS
        palette_class = PALETTE_GetClass();
        D0

        Class * PALETTE_GetClass(VOID);

    FUNCTION
        Obtains the pointer to the Palette gadget class for use with
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
        palette_class - Pointer to the Palette gadget class.

    SEE ALSO
```

---

## See Also

- [NewObject — intuition.library](../autodocs/intuition.library.md#newobject)
