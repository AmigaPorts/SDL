---
title: amigaguide.library/SendAmigaGuideContextAguide.library/SendAmigaGuideContextA
manual: autodocs-3.5
chapter: autodocs-3.5
section: amigaguide-library-sendamigaguidecontextaguide-library
functions: []
libraries: []
---

# amigaguide.library/SendAmigaGuideContextAguide.library/SendAmigaGuideContextA

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
        SendAmigaGuideContextA - Align an AmigaGuide system on the context ID
.
```c
                                                               (V34)
```
   SYNOPSIS

```c
        success = SendAmigaGuideContextA (handle, attrs);
        d0                                 a0      d0

        [BOOL](autodocs-3.5/include-exec-types-h.md) SendAmigaGuideContextA (AMIGAGUIDECONTEXT, struct [TagItem](autodocs-3.5/include-utility-tagitem-h.md) *);

        success = SendAmigaGuideContext (handle, tag1, ...);

        [BOOL](autodocs-3.5/include-exec-types-h.md) SendAmigaGuideContext (AMIGAGUIDECONTEXT, [Tag](autodocs-3.5/include-utility-tagitem-h.md), ...);
```
   FUNCTION

```c
        This function is used to send a message to an AmigaGuide system to
        align it on the current context ID.

        This function effectively does a:

            SendAmigaGuideCmd(handle 'LINK ContextArray[contextID]', NULL);
```
   INPUTS

        handle - Handle to an AmigaGuide system.
        future - Future expansion, must be set to NULL for now.
   EXAMPLE


```c
        struct [IntuiMessage](autodocs-3.5/include-intuition-intuition-h.md) *imsg;

        ...

        case RAWKEY:
            switch (imsg->Code)
            {
                case 95:
                    /* bring up help on a particular subject */
                    SendAmigaGuideContext(handle, NULL);
                    break;
                ...
            }
            break;

        ...
```
   RETURNS

        success -- Returns TRUE if the message was sent, otherwise returns
            FALSE.
   SEE ALSO

```c
        [SetAmigaGuideContextA()](autodocs-3.5/amigaguide-library-setamigaguidecontextagaguide-library.md), [SendAmigaGuideCmdA()](autodocs-3.5/amigaguide-library-sendamigaguidecmda.md)
```
