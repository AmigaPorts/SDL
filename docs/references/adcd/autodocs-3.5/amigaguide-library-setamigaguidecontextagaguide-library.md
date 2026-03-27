---
title: amigaguide.library/SetAmigaGuideContextAgaguide.library/SetAmigaGuideContextA
manual: autodocs-3.5
chapter: autodocs-3.5
section: amigaguide-library-setamigaguidecontextagaguide-library
functions: []
libraries: []
---

# amigaguide.library/SetAmigaGuideContextAgaguide.library/SetAmigaGuideContextA

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
```c
        SetAmigaGuideContextA - Set the context ID for an AmigaGuide system.
                                                               (V34)
```
   SYNOPSIS

```c
        success = SetAmigaGuideContextA ( handle, context, attrs );
        d0                                 a0       d0      d1

        [BOOL](autodocs-3.5/include-exec-types-h.md) SetAmigaGuideContextA (AMIGAGUIDECONTEXT, ULONG,
                                    struct [TagItem](autodocs-3.5/include-utility-tagitem-h.md) *);

        success = SetAmigaGuideContext (handle, context, tag1, ...);

        [BOOL](autodocs-3.5/include-exec-types-h.md) SetAmigaGuideContext (AMIGAGUIDECONTEXT, ULONG, [Tag](autodocs-3.5/include-utility-tagitem-h.md), ...);
```
   FUNCTION

```c
        This function, and the SendAmigaGuideContext() function, are used to
        provide a simple way to display a node based on a numeric value,
        instead of having to build up a slightly more complex command
        string.
```
   INPUTS

        handle -- Handle to an AmigaGuide system.

        context -- Index value of the desired node to display.

        future -- Future expansion, must be set to NULL for now.
   EXAMPLE


```c
        /* sample context table */
        [STRPTR](autodocs-3.5/include-exec-types-h.md) ContextArray[] =
        {
            "MAIN",
            "FILEREQ",
            "PRINT",
            "ABOUT",
            NULL
        };

        /* quickie defines */
        #define HELP_MAIN      0
        #define HELP_FILEREQ   1
        #define HELP_PRINT     2
        #define HELP_ABOUT     3

        ...

        struct [NewAmigaGuide](autodocs-3.5/include-libraries-amigaguide-h.md) nag = {NULL};

        /* initialize the context table */
        nag.nag_Context = ContextArray;

        ...

        /* bring up help on a particular subject */
        SetAmigaGuideContext(handle, HELP_ABOUT, NULL);
```
   RETURNS

        success - Returns TRUE if a valid context ID was passed,
            otherwise returns FALSE.
   SEE ALSO

```c
        [SendAmigaGuideContextA()](autodocs-3.5/amigaguide-library-sendamigaguidecontextaguide-library.md), [SendAmigaGuideCmdA()](autodocs-3.5/amigaguide-library-sendamigaguidecmda.md)
```
