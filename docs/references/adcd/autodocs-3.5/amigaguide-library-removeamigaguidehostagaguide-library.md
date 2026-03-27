---
title: amigaguide.library/RemoveAmigaGuideHostAgaguide.library/RemoveAmigaGuideHostA
manual: autodocs-3.5
chapter: autodocs-3.5
section: amigaguide-library-removeamigaguidehostagaguide-library
functions: []
libraries: []
---

# amigaguide.library/RemoveAmigaGuideHostAgaguide.library/RemoveAmigaGuideHostA

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

```c
    NAME
        RemoveAmigaGuideHostA - [Remove](autodocs-3.5/exec-library-remove-2.md) a dynamic node host.     (V34)

    SYNOPSIS
        use = RemoveAmigaGuideHostA (key, attrs)
        d0                            a0   a1

        [LONG](autodocs-3.5/include-exec-types-h.md) RemoveAmigaGuideHostA (AMIGAGUIDEHOST, struct [TagItem](autodocs-3.5/include-utility-tagitem-h.md) *);

        use = RemoveAmigaGuideHost (key, tag1, ...);

        [LONG](autodocs-3.5/include-exec-types-h.md) RemoveAmigaGuideHost (AMIGAGUIDEHOST, [Tag](autodocs-3.5/include-utility-tagitem-h.md), ...);

    FUNCTION
        This function removes a dynamic node host, that was added by
        AddAmigaGuideHost(), from the system.

    INPUTS
        key - Key that was returned by AddAmigaGuideHost().

        attrs - Additional attributes.  None are defined at this time.

    RETURNS
        use - Number of outstanding clients of this database.  You
            can not exit until use==0.

    SEE ALSO
        [AddAmigaGuideHostA()](autodocs-3.5/amigaguide-library-addamigaguidehosta.md)
```
