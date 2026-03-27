---
title: amigaguide.library/SetAmigaGuideAttrsA
manual: autodocs-3.5
chapter: autodocs-3.5
section: amigaguide-library-setamigaguideattrsa
functions: []
libraries: []
---

# amigaguide.library/SetAmigaGuideAttrsA

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

```c
    NAME
        SetAmigaGuideAttrsA - Set an AmigaGuide attribute.      (V34)

    SYNOPSIS
        retval = SetAmigaGuideAttrsA (handle, attrs);
        d0                             a0      a1

        [LONG](autodocs-3.5/include-exec-types-h.md) SetAmigaGuideAttrsA (AMIGAGUIDECONTEXT, struct [TagItem](autodocs-3.5/include-utility-tagitem-h.md) *);

        retval = SetAmigaGuideAttrs (handle, tag1, ...);

        [LONG](autodocs-3.5/include-exec-types-h.md) SetAmigaGuideAttrs (AMIGAGUIDECONTEXT, [Tag](autodocs-3.5/include-utility-tagitem-h.md), ...);

    FUNCTION
        This function is used to set AmigaGuide attributes.

    INPUTS
        handle -- Pointer to an AmigaGuide handle.

        attrs -- Attribute pairs to set.

    TAGS
        AGA_Activate (BOOL) - AmigaGuide activates the window when
            it receives a LINK command.  This tag allows the
            application developer to turn that feature off and on.

    SEE ALSO
        [GetAmigaGuideAttr()](autodocs-3.5/amigaguide-library-getamigaguideattr.md)
```
