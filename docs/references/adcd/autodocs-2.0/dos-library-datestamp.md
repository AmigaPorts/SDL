---
title: dos.library/DateStamp
manual: autodocs-2.0
chapter: autodocs-2.0
section: dos-library-datestamp
functions: [CompareDates, DateStamp, DateToStr, StrToDate]
libraries: [dos.library]
---

# dos.library/DateStamp

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    [DateStamp](autodocs-2.0/includes-dos-dos-h.md) -- Obtain the date and time in internal format
```
SYNOPSIS

```c
    ds = DateStamp( ds );
    D0              D1

    struct [DateStamp](autodocs-2.0/includes-dos-dos-h.md) *DateStamp(struct [DateStamp](autodocs-2.0/includes-dos-dos-h.md) *)
```
FUNCTION

```c
    DateStamp() takes a structure of three longwords that is set to the
    current time.  The first element in the vector is a count of the
    number of days.  The second element is the number of minutes elapsed
    in the day.  The third is the number of ticks elapsed in the current
    minute.  A tick happens 50 times a second.  DateStamp() ensures that
    the day and minute are consistent.  All three elements are zero if
    the date is unset. DateStamp() currently only returns even
    multiples of 50 ticks.  Therefore the time you get is always an even
    number of ticks.

    Time is measured from Jan 1, 1978.
```
INPUTS

```c
    ds - pointer a struct [DateStamp](autodocs-2.0/includes-dos-dos-h.md)
```
RESULTS

```c
    The array is filled as described and returned (for pre-V36
    compabability).
```
SEE ALSO

```c
    [DateToStr()](autodocs-2.0/dos-library-datetostr.md), [StrToDate()](autodocs-2.0/dos-library-strtodate.md), [SetFileDate()](autodocs-2.0/dos-library-setfiledate.md), [CompareDates()](autodocs-2.0/dos-library-comparedates.md)
```

---

## See Also

- [CompareDates — dos.library](../autodocs/dos.library.md#comparedates)
- [DateStamp — dos.library](../autodocs/dos.library.md#datestamp)
- [DateToStr — dos.library](../autodocs/dos.library.md#datetostr)
- [StrToDate — dos.library](../autodocs/dos.library.md#strtodate)
