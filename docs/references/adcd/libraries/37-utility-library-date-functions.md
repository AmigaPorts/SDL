---
title: 37 Utility Library / Date Functions
manual: libraries
chapter: libraries
section: 37-utility-library-date-functions
functions: [Amiga2Date, CheckDate, Date2Amiga]
libraries: [utility.library]
---

# 37 Utility Library / Date Functions

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

To ease date-related calculations, the utility library has some functions
to convert a date, specified in a ClockData structure, in the number of
seconds since 00:00:00 01-Jan-78 and vice versa. To indicate the date, the
ClockData structure (in <utility/[date.h](autodocs-2.0/includes-utility-date-h.md)>) is used.


```c
    struct ClockData
    {
        UWORD sec;     /* seconds (0 - 59)*/
        UWORD min;     /* minutes (0 - 59) */
        UWORD hour;    /* hour (0 - 23) */
        UWORD mday;    /* day of the month (1 - 31) */
        UWORD month;   /* month of the year (1 - 12)
        UWORD year;    /* 1978 - */
        UWORD wday;    /* day of the week (0 - 6, where 0 is Sunday) */
    };
```
The following functions are available to operate on ClockData:

  ________________________________________________________________
 |                                                                |
 | [Amiga2Date()](autodocs-2.0/utility-library-amiga2date.md)  Calculate the date from the specified timestamp  |
 |               (in seconds).                                    |
 |  [CheckDate()](autodocs-2.0/utility-library-checkdate.md)  Check the legality of a date.                    |
 | [Date2Amiga()](autodocs-2.0/utility-library-date2amiga.md)  Calculate the timestamp from the specified date. |
 |________________________________________________________________|



            Table 37-5: Utility Library Date Functins
[Amiga2Date()](autodocs-2.0/utility-library-amiga2date.md) takes a number of seconds from 01-Jan-78 as argument and
fills in the supplied ClockData structure with the date and time.

[CheckDate()](autodocs-2.0/utility-library-checkdate.md) checks if the supplied ClockData structure is valid, and
returns the number of seconds from 01-Jan-78 if it is. Note that this
function currently does not take the supplied day of the week in account.

[Date2Amiga()](autodocs-2.0/utility-library-date2amiga.md) takes a ClockData structure as argument and returns the
number of seconds since 01-Jan-78. The supplied ClockData structure MUST
be valid, since no checking is done.

The following example shows various uses of the utility library date
functions.


```c
     [a2d.c](libraries/lib-examples-a2d-c.md) 
```

---

## See Also

- [Amiga2Date — utility.library](../autodocs/utility.library.md#amiga2date)
- [CheckDate — utility.library](../autodocs/utility.library.md#checkdate)
- [Date2Amiga — utility.library](../autodocs/utility.library.md#date2amiga)
