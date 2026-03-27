---
title: amigaguide.class/GetAGString
manual: autodocs-3.5
chapter: autodocs-3.5
section: amigaguide-class-getagstring
functions: []
libraries: []
---

# amigaguide.class/GetAGString

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

```c
    NAME
        GetAGString - Obtain localized AmigaGuide text  (V34)

    SYNOPSIS
        string = GetAGString (id);
        d0                      d0

        [STRPTR](autodocs-3.5/include-exec-types-h.md) GetAGString (LONG);

    FUNCTION
        This function is used to obtain a pointer to the string
        associated with the given ID.

    INPUTS
        id        - [Catalog](autodocs-3.5/include-libraries-locale-h.md) entry to obtain.

    RETURNS
        Returns a pointer to the NULL terminated string. NULL on
        failure.

    SEE ALSO
```
