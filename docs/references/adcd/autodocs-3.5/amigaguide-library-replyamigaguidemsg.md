---
title: amigaguide.library/ReplyAmigaGuideMsg
manual: autodocs-3.5
chapter: autodocs-3.5
section: amigaguide-library-replyamigaguidemsg
functions: []
libraries: []
---

# amigaguide.library/ReplyAmigaGuideMsg

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME

```c
        ReplyAmigaGuideMsg - Reply to an AmigaGuide message.    (V34)
```
   SYNOPSIS

```c
        ReplyAmigaGuideMsg ( msg );
                             a0

        VOID ReplyAmigaGuideMsg (struct [AmigaGuideMsg](autodocs-3.5/include-libraries-amigaguide-h.md) *msg);
```
   FUNCTION

        This function is used to reply to an AmigaGuide SIPC message.
   INPUTS

```c
        msg - Pointer to a SIPC message returned by a previous call to
            [GetAmigaGuideMsg()](autodocs-3.5/amigaguide-library-getamigaguidemsg.md).
```
   SEE ALSO

```c
        [OpenAmigaGuideAsyncA()](autodocs-3.5/amigaguide-library-openamigaguideasyncamigaguide-library.md), [AmigaGuideSignal()](autodocs-3.5/amigaguide-library-amigaguidesignal.md), [GetAmigaGuideMsg()](autodocs-3.5/amigaguide-library-getamigaguidemsg.md)
```
