---
title: amigaguide.library/GetAmigaGuideAttr
manual: autodocs-3.5
chapter: autodocs-3.5
section: amigaguide-library-getamigaguideattr
functions: []
libraries: []
---

# amigaguide.library/GetAmigaGuideAttr

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

```c
    NAME
        GetAmigaGuideAttr - Get an AmigaGuide attribute.        (V34)

    SYNOPSIS
        retval = GetAmigaGuideAttr (tag, handle, storage);
        d0                           d0    a0      a1

        [LONG](autodocs-3.5/include-exec-types-h.md) GetAmigaGuideAttr (Tag, [AMIGAGUIDECONTEXT](autodocs-3.5/include-libraries-amigaguide-h.md), ULONG *);

    FUNCTION
        This function is used to obtain attributes from AmigaGuide.

    INPUTS
        tag - Attribute to obtain.
        handle - Handle to an AmigaGuide system.
        storage - Pointer to appropriate storage for the answer.

    TAGS
        AGA_Path (BPTR) - Pointer to the current path used by
            AmigaGuide.

        AGA_XRefList (struct [List](autodocs-3.5/include-exec-lists-h.md) *) - Pointer to the current
            cross reference list.

    RETURNS

    SEE ALSO
        [SetAmigaGuideAttrsA()](autodocs-3.5/amigaguide-library-setamigaguideattrsa.md)
```
