---
title: amigaguide.library/LockAmigaGuideBase
manual: autodocs-3.5
chapter: autodocs-3.5
section: amigaguide-library-lockamigaguidebase
functions: []
libraries: []
---

# amigaguide.library/LockAmigaGuideBase

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

```c
    NAME
        LockAmigaGuideBase - [Lock](autodocs-3.5/dos-library-lock-2.md) an AmigaGuide client.         (V34)

    SYNOPSIS
        key = LockAmigaGuideBase (AMIGAGUIDECONTEXT handle);
        d0                                            a0

        [LONG](autodocs-3.5/include-exec-types-h.md) LockAmigaGuideBase (AMIGAGUIDECONTEXT);

    FUNCTION
        This function is used to lock the AmigaGuide context handle
        while working with data obtained with the the
        [GetAmigaGuideAttr()](autodocs-3.5/amigaguide-library-getamigaguideattr.md) function.

    INPUTS
        handle - [AMIGAGUIDECONTEXT](autodocs-3.5/include-libraries-amigaguide-h.md) handle obtained with
            OpenAmigaGuideAsync().

    RETURNS
        Returns a key to pass to [UnlockAmigaGuideBase()](autodocs-3.5/amigaguide-library-unlockamigaguidebasemigaguide-library.md).

    SEE ALSO
        [UnlockAmigaGuideBase()](autodocs-3.5/amigaguide-library-unlockamigaguidebasemigaguide-library.md)
```
