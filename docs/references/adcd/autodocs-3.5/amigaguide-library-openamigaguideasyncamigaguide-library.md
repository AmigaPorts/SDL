---
title: amigaguide.library/OpenAmigaGuideAsyncAmigaguide.library/OpenAmigaGuideAsyncA
manual: autodocs-3.5
chapter: autodocs-3.5
section: amigaguide-library-openamigaguideasyncamigaguide-library
functions: []
libraries: []
---

# amigaguide.library/OpenAmigaGuideAsyncAmigaguide.library/OpenAmigaGuideAsyncA

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME

```c
        OpenAmigaGuideAsyncA - [Open](autodocs-3.5/dos-library-open-2.md) an AmigaGuide database async (V34)
```
   SYNOPSIS

```c
        handle = OpenAmigaGuideAsyncA (nag, attrs);
        d0                              a0   d0

        [AMIGAGUIDECONTEXT](autodocs-3.5/include-libraries-amigaguide-h.md) OpenAmigaGuideAsyncA (struct [NewAmigaGuide](autodocs-3.5/include-libraries-amigaguide-h.md) *,
                                                struct [TagItem](autodocs-3.5/include-utility-tagitem-h.md) *);

        handle = OpenAmigaGuideAsync (nag, tag1, ...);

        [AMIGAGUIDECONTEXT](autodocs-3.5/include-libraries-amigaguide-h.md) OpenAmigaGuideAsyncA (struct [NewAmigaGuide](autodocs-3.5/include-libraries-amigaguide-h.md) *,
                                                [Tag](autodocs-3.5/include-utility-tagitem-h.md) tag1, ...);
```
   FUNCTION

```c
        Opens an AmigaGuide database for ansynchronous use.

        The [NewAmigaGuide](autodocs-3.5/include-libraries-amigaguide-h.md) structure, and its pointers, must stay valid until
        an ActiveToolID or ToolStatusID message is received by the calling
        process.

        This function actually spawns OpenAmigaGuide() as another process,
        so, for further documentation, refer to the OpenAmigaGuide()
        function.
```
   INPUTS

```c
        nag -- Pointer to a valid [NewAmigaGuide](autodocs-3.5/include-libraries-amigaguide-h.md) structure.
            (see OpenAmigaGuide() for documentation on its useage).

        attrs -- Additional attributes.  See [OpenAmigaGuideA()](autodocs-3.5/amigaguide-library-openamigaguidea.md).
```
   RETURNS

        handle -- Handle to an AmigaGuide system.
   SEE ALSO

```c
        [OpenAmigaGuideA()](autodocs-3.5/amigaguide-library-openamigaguidea.md), [CloseAmigaGuide()](autodocs-3.5/amigaguide-library-closeamigaguide.md)
```
