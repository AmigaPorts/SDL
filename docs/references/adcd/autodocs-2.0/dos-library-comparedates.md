---
title: dos.library/CompareDates
manual: autodocs-2.0
chapter: autodocs-2.0
section: dos-library-comparedates
functions: [DateStamp, DateToStr, StrToDate]
libraries: [dos.library]
---

# dos.library/CompareDates

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    CompareDates -- Compares two datestamps (V36)
```
SYNOPSIS

```c
    result = CompareDates(date1,date2)
    D0                     D1     D2

    LONG CompareDates(struct [DateStamp](autodocs-2.0/includes-dos-dos-h.md) *,struct [DateStamp](autodocs-2.0/includes-dos-dos-h.md) *)
```
FUNCTION

    Compares two times for relative magnitide.  <0 is returned if date1 is
    later than date2, 0 if they are equal, or >0 if date2 is later than
    date1.  NOTE: this is NOT the same ordering as strcmp!
INPUTS

    date1, date2 - DateStamps to compare
RESULT

    result -  <0, 0, or >0 based on comparison of two date stamps
SEE ALSO

```c
    [DateStamp()](autodocs-2.0/dos-library-datestamp.md), [DateToStr()](autodocs-2.0/dos-library-datetostr.md), [StrToDate()](autodocs-2.0/dos-library-strtodate.md)
```

---

## See Also

- [DateStamp — dos.library](../autodocs/dos.library.md#datestamp)
- [DateToStr — dos.library](../autodocs/dos.library.md#datetostr)
- [StrToDate — dos.library](../autodocs/dos.library.md#strtodate)
