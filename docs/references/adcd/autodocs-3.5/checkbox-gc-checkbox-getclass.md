---
title: checkbox_gc/CHECKBOX_GetClass
manual: autodocs-3.5
chapter: autodocs-3.5
section: checkbox-gc-checkbox-getclass
functions: [NewObject]
libraries: [intuition.library]
---

# checkbox_gc/CHECKBOX_GetClass

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

```c
    NAME
        CHECKBOX_GetClass -- Gets the pointer to the checkbox class.

    SYNOPSIS
        checkbox_class = CHECKBOX_GetClass();
        D0

        Class * CHECKBOX_GetClass(VOID);

    FUNCTION
        This function is only available in runtime linked version of the
        class, checkbox.gadget and is not in the compiler linker library
        checkbox_gc.lib.

        Obtains the pointer to the CheckBox gadget class for use with
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
        checkbox_class - Pointer to the CheckBox gadget class.

    SEE ALSO
```

---

## See Also

- [NewObject — intuition.library](../autodocs/intuition.library.md#newobject)
