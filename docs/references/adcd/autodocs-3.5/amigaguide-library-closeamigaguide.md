---
title: amigaguide.library/CloseAmigaGuide
manual: autodocs-3.5
chapter: autodocs-3.5
section: amigaguide-library-closeamigaguide
functions: []
libraries: []
---

# amigaguide.library/CloseAmigaGuide

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

```c
    NAME
        CloseAmigaGuide - [Close](autodocs-3.5/dos-library-close-2.md) a AmigaGuide client.            (V34)

    SYNOPSIS
        CloseAmigaGuide (handle);
                          a0

        VOID CloseAmigaGuide (AMIGAGUIDECONTEXT);

    FUNCTION
        Closes a synchronous, or asynchronous, AmigaGuide client.

        This function will also close all windows that were opened for
        the client.

    INPUTS
        handle - Handle to an AmigaGuide client.

    SEE ALSO
        [OpenAmigaGuideA()](autodocs-3.5/amigaguide-library-openamigaguidea.md), [OpenAmigaGuideAsyncA()](autodocs-3.5/amigaguide-library-openamigaguideasyncamigaguide-library.md)
```
