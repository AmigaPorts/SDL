---
title: utility.library/Amiga2Date
manual: autodocs-2.0
chapter: autodocs-2.0
section: utility-library-amiga2date
functions: [CheckDate, Date2Amiga]
libraries: [utility.library]
---

# utility.library/Amiga2Date

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    Amiga2Date -- Calculate the date from a timestamp.  (V36)
```
SYNOPSIS

```c
    Amiga2Date( AmigaTime, Date )
                D0         A0

    void Amiga2Date( ULONG, struct [ClockData](autodocs-2.0/includes-utility-date-h.md) * );
```
FUNCTION

```c
    Fills in a [ClockData](autodocs-2.0/includes-utility-date-h.md) structure with the date and time calculated
    from a ULONG containing the number of seconds from 01-Jan-1978
    to the date.
```
INPUTS

    AmigaTime       - the number of seconds from 01-Jan-1978.
RESULTS

    Date            - filled in with the date/time specified by
                      AmigaTime.
NOTES

SEE ALSO

```c
    [CheckDate()](autodocs-2.0/utility-library-checkdate.md), [Date2Amiga()](autodocs-2.0/utility-library-date2amiga.md)
```
BUGS

---

## See Also

- [CheckDate — utility.library](../autodocs/utility.library.md#checkdate)
- [Date2Amiga — utility.library](../autodocs/utility.library.md#date2amiga)
