---
title: 11 Intuition Special Functions / Current Time Values
manual: libraries
chapter: libraries
section: 11-intuition-special-functions-current-time-values
functions: [CompareDates, CurrentTime, DateToStr, StrToDate]
libraries: [dos.library, intuition.library]
---

# 11 Intuition Special Functions / Current Time Values

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The function [CurrentTime()](autodocs-2.0/intuition-library-currenttime.md) gets the current time values.  To use this
function, first declare the variables Seconds and Micros.  Then, when the
application call the function, the current time is copied into the
argument pointers.


```c
    void CurrentTime( ULONG *seconds, ULONG *micros );
```
See the DOS library Autodocs in the AmigaDOS Manual (Bantam Books) for
more information on functions dealing with the date and time.  The DOS
library includes such functions as [DateToStr()](autodocs-2.0/dos-library-datetostr.md), [StrToDate()](autodocs-2.0/dos-library-strtodate.md), [SetFileDate()](autodocs-2.0/dos-library-setfiledate.md)
and [CompareDates()](autodocs-2.0/dos-library-comparedates.md).

---

## See Also

- [CompareDates — dos.library](../autodocs/dos.library.md#comparedates)
- [CurrentTime — intuition.library](../autodocs/intuition.library.md#currenttime)
- [DateToStr — dos.library](../autodocs/dos.library.md#datetostr)
- [StrToDate — dos.library](../autodocs/dos.library.md#strtodate)
