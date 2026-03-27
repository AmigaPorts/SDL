---
title: utility.library/CheckDate
manual: autodocs-2.0
chapter: autodocs-2.0
section: utility-library-checkdate
functions: [Amiga2Date, Date2Amiga]
libraries: [utility.library]
---

# utility.library/CheckDate

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    CheckDate -- Checks [ClockData](autodocs-2.0/includes-utility-date-h.md) struct for legal date. (V36)
```
SYNOPSIS

```c
    AmigaTime = CheckDate( Date )
    D0                     A0

    ULONG CheckDate( struct [ClockData](autodocs-2.0/includes-utility-date-h.md) * );
```
FUNCTION

    Determines if the Date is a legal date and returns the number
    of seconds to Date from 01-Jan-1978 if it is.
INPUTS

```c
    Date            - pointer to a [ClockData](autodocs-2.0/includes-utility-date-h.md) structure.
```
RESULTS

```c
    AmigaTime       - 0 if Date invalid; otherwise, the number of
                      seconds to Date from 01-Jan-1978.
```
NOTES

BUGS

```c
    The wday field of the [ClockData](autodocs-2.0/includes-utility-date-h.md) structure is not checked.
```
SEE ALSO

```c
    [Amiga2Date()](autodocs-2.0/utility-library-amiga2date.md), [Date2Amiga()](autodocs-2.0/utility-library-date2amiga.md)
```

---

## See Also

- [Amiga2Date — utility.library](../autodocs/utility.library.md#amiga2date)
- [Date2Amiga — utility.library](../autodocs/utility.library.md#date2amiga)
