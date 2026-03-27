---
title: dos.library/StrToDate
manual: autodocs-2.0
chapter: autodocs-2.0
section: dos-library-strtodate
functions: [DateStamp, DateToStr]
libraries: [dos.library]
---

# dos.library/StrToDate

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    StrToDate -- Converts a string to a [DateStamp](autodocs-2.0/includes-dos-dos-h.md) (V36)
```
SYNOPSIS

```c
    success = StrToDate( datetime )
    D0                      D1

    BOOL StrToDate( struct [DateTime](autodocs-2.0/includes-dos-datetime-h.md) * )
```
FUNCTION

```c
    Converts a human readable ASCII string into an AmigaDOS
    [DateStamp](autodocs-2.0/includes-dos-dos-h.md).
```
INPUTS

```c
    [DateTime](autodocs-2.0/includes-dos-datetime-h.md) - a pointer to an initialized [DateTime](autodocs-2.0/includes-dos-datetime-h.md) structure.

    The [DateTime](autodocs-2.0/includes-dos-datetime-h.md) structure should   be initialized as follows:

    dat_Stamp  - ignored on input.

    dat_Format - a format   byte which specifies the format of the
            dat_StrDat.  This can   be any of the following (note:
            If value used   is something other than those below,
            the default of FORMAT_DOS is used):

            FORMAT_DOS:       AmigaDOS format (dd-mmm-yy).

            FORMAT_INT:       International format (yy-mmm-dd).

            FORMAT_USA:       American format (mm-dd-yy).

            FORMAT_CDN:       Canadian format (dd-mm-yy).

            FORMAT_DEF:       default format for locale.

    dat_Flags - a flags byte.  The only flag which affects this
              function is:

            DTF_SUBST:      ignored by this function
            DTF_FUTURE:       If set, indicates that strings such
                              as (stored in dat_StrDate) "Monday"
                              refer to "next" monday. Otherwise,
                              if clear, strings like "Monday"
                              refer to "last" monday.

    dat_StrDay - ignored bythis function.

    dat_StrDate -   pointer to valid string representing the date.
              This can be a "DTF_SUBST" style string such as
              "Today" "Tomorrow" "Monday", or it may be a string
              as specified by the dat_Format byte.  This will be
              converted to the ds_Days portion of the [DateStamp](autodocs-2.0/includes-dos-dos-h.md).
              If this pointer is NULL, DateStamp->ds_Days will not
              be affected.

    dat_StrTime -   Pointer to a buffer which contains the time in
              the ASCII format hh:mm:ss.  This will be converted
              to the ds_Minutes and ds_Ticks portions of the
              [DateStamp](autodocs-2.0/includes-dos-dos-h.md).  If this pointer is NULL, ds_Minutes and
              ds_Ticks will be unchanged.
```
RESULT

    success - a zero return indicates that a conversion could
            not be performed. A non-zero return indicates that the
            DateTime.dat_Stamp variable contains the converted
            values.
SEE ALSO

```c
    [DateStamp()](autodocs-2.0/dos-library-datestamp.md), [DateToStr()](autodocs-2.0/dos-library-datetostr.md), [<dos/datetime.h>](autodocs-2.0/includes-dos-datetime-h.md)
```

---

## See Also

- [DateStamp — dos.library](../autodocs/dos.library.md#datestamp)
- [DateToStr — dos.library](../autodocs/dos.library.md#datetostr)
