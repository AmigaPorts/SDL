---
title: amigaguide.library/GetAmigaGuideString
manual: autodocs-3.5
chapter: autodocs-3.5
section: amigaguide-library-getamigaguidestring
functions: []
libraries: []
---

# amigaguide.library/GetAmigaGuideString

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
```c
        GetAmigaGuideString - Get an AmigaGuide string.
                                                               (V34)
```
   SYNOPSIS

```c
        txt = GetAmigaGuideString (id);
        d0                         d0

        [STRPTR](autodocs-3.5/include-exec-types-h.md) GetAmigaGuideString (ULONG);
```
   FUNCTION

        This function is used to obtain a localized string given the
        ID.
   INPUTS

        ID -- Valid AmigaGuide string id.
   RETURNS

        A pointer to the string.   NULL for an invalid string.
   SEE ALSO

