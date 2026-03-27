---
title: amigaguide.library/AmigaGuideSignal
manual: autodocs-3.5
chapter: autodocs-3.5
section: amigaguide-library-amigaguidesignal
functions: []
libraries: []
---

# amigaguide.library/AmigaGuideSignal

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME

```c
        AmigaGuideSignal - Obtain aysnc AmigaGuide signal.      (V34)
```
   SYNOPSIS

```c
        signal = AmigaGuideSignal ( handle );
        d0                           a0

        ULONG AmigaGuideSignal (AMIGAGUIDECONTEXT);
```
   FUNCTION

```c
        This function returns the signal bit to [Wait](autodocs-3.5/exec-library-wait-2.md) on for AmigaGuideMsg's
        for a particular AmigaGuide database.
```
   INPUTS

        handle -- Handle to a AmigaGuide system.
   EXAMPLE

```c
        ULONG sigw, sigh;
        [AMIGAGUIDECONTEXT](autodocs-3.5/include-libraries-amigaguide-h.md) handle;

        /* get the signal bit to wait on for a AmigaGuide message */
        sigh = AmigaGuideSignal(handle);

        /* add the signal bit into the total signals to wait on */
        sigw |= sigh;
```
   RETURNS

```c
        signal -- [Signal](autodocs-3.5/exec-library-signal-2.md) bit to [Wait](autodocs-3.5/exec-library-wait-2.md) on.
```
   SEE ALSO

```c
        [OpenAmigaGuideAsyncA()](autodocs-3.5/amigaguide-library-openamigaguideasyncamigaguide-library.md), [GetAmigaGuideMsg()](autodocs-3.5/amigaguide-library-getamigaguidemsg.md), [ReplyAmigaGuideMsg()](autodocs-3.5/amigaguide-library-replyamigaguidemsg.md)
```
