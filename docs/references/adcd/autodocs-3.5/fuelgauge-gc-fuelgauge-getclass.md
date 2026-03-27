---
title: fuelgauge_gc/FUELGAUGE_GetClass
manual: autodocs-3.5
chapter: autodocs-3.5
section: fuelgauge-gc-fuelgauge-getclass
functions: [NewObject]
libraries: [intuition.library]
---

# fuelgauge_gc/FUELGAUGE_GetClass

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

```c
    NAME
        FUELGAUGE_GetClass -- Gets the pointer to the fuelgauge class.

    SYNOPSIS
        fuelgauge_class = FUELGAUGE_GetClass();
        D0

        Class * FUELGAUGE_GetClass(VOID);

    FUNCTION
        Obtains the pointer to the FuelGauge gadget class for use with
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
        fuelgauge_class - Pointer to the FuelGauge gadget class.

    SEE ALSO
```

---

## See Also

- [NewObject — intuition.library](../autodocs/intuition.library.md#newobject)
