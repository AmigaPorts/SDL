---
title: amigaguide.library/UnlockAmigaGuideBasemigaguide.library/UnlockAmigaGuideBase
manual: autodocs-3.5
chapter: autodocs-3.5
section: amigaguide-library-unlockamigaguidebasemigaguide-library
functions: []
libraries: []
---

# amigaguide.library/UnlockAmigaGuideBasemigaguide.library/UnlockAmigaGuideBase

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

```c
    NAME
        UnlockAmigaGuideBase - Unlock an AmigaGuide client.     (V34)

    SYNOPSIS
        UnlockAmigaGuideBase (key);
                              d0

        VOID UnlockAmigaGuideBase (LONG);

    FUNCTION
        This function is used to release a lock obtained with
        [LockAmigaGuideBase()](autodocs-3.5/amigaguide-library-lockamigaguidebase.md).

    INPUTS
        key - Value returned by [LockAmigaGuideBase()](autodocs-3.5/amigaguide-library-lockamigaguidebase.md).

    SEE ALSO
        [LockAmigaGuideBase()](autodocs-3.5/amigaguide-library-lockamigaguidebase.md).
```
