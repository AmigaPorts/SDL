---
title: utility.library/Date2Amiga
manual: autodocs-2.0
chapter: autodocs-2.0
section: utility-library-date2amiga
functions: [Amiga2Date, CheckDate]
libraries: [utility.library]
---

# utility.library/Date2Amiga

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    Date2Amiga -- Calculate seconds from 01-Jan-1978.  (V36)
```
SYNOPSIS

```c
    AmigaTime = Date2Amiga( Date )
    D0                      A0

    ULONG Date2Amiga( struct [ClockData](autodocs-2.0/includes-utility-date-h.md) * );
```
FUNCTION

```c
    Calculates the number of seconds from 01-Jan-1978 to the date
    specified in the [ClockData](autodocs-2.0/includes-utility-date-h.md) structure.
```
INPUTS

```c
    Date            - pointer to a [ClockData](autodocs-2.0/includes-utility-date-h.md) structure containing the
                      date of interest.
```
RESULTS

    AmigaTime       - the number of seconds from 01-Jan-1978 to the
                      date specified in Date.
NOTES

    This function does no sanity checking of the data in Date.
SEE ALSO

```c
    [Amiga2Date()](autodocs-2.0/utility-library-amiga2date.md), [CheckDate()](autodocs-2.0/utility-library-checkdate.md)
```
BUGS

---

## See Also

- [Amiga2Date — utility.library](../autodocs/utility.library.md#amiga2date)
- [CheckDate — utility.library](../autodocs/utility.library.md#checkdate)
