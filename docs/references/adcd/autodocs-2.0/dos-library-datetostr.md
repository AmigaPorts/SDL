---
title: dos.library/DateToStr
manual: autodocs-2.0
chapter: autodocs-2.0
section: dos-library-datetostr
functions: [DateStamp]
libraries: [dos.library]
---

# dos.library/DateToStr

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    DateToStr -- Converts a [DateStamp](autodocs-2.0/includes-dos-dos-h.md) to a string (V36)
```
SYNOPSIS

```c
    success = DateToStr( datetime )
    D0                      D1

    BOOL DateToStr(struct [DateTime](autodocs-2.0/includes-dos-datetime-h.md) *)
```
FUNCTION

```c
    StamptoStr converts an AmigaDOS [DateStamp](autodocs-2.0/includes-dos-dos-h.md) to a human
    readable ASCII string as requested by your settings in the
    [DateTime](autodocs-2.0/includes-dos-datetime-h.md) structure.
```
INPUTS

```c
    [DateTime](autodocs-2.0/includes-dos-datetime-h.md) - a pointer to an initialized [DateTime](autodocs-2.0/includes-dos-datetime-h.md) structure.

    The [DateTime](autodocs-2.0/includes-dos-datetime-h.md) structure should be initialized as follows:

    dat_Stamp - a copy of the datestamp you wish to convert to
              ascii.

    dat_Format - a format   byte which specifies the format of the
              dat_StrDate.  This can be any of the following
              (note: If value used is something other than those
              below, the default of FORMAT_DOS is used):

              FORMAT_DOS:     AmigaDOS format (dd-mmm-yy).

              FORMAT_INT:     International format (yy-mmm-dd).

              FORMAT_USA:     American format (mm-dd-yy).

              FORMAT_CDN:     Canadian format (dd-mm-yy).

              FORMAT_DEF:     default format for locale.

    dat_Flags - a   flags byte.  The only flag which affects this
              function is:

              DTF_SUBST:      If set, a string such as Today,
                              Monday, etc., will be used instead
                              of the dat_Format specification if
                              possible.
              DTF_FUTURE:     Ignored by this function.

    dat_StrDay - pointer to a buffer to receive the day of the
              week string.  (Monday, Tuesday, etc.). If null, this
              string will not be generated.

    dat_StrDate -   pointer to a buffer to receive the date
              string, in the format requested by dat_Format,
              subject to possible modifications by DTF_SUBST.  If
              null, this string will not be generated.

    dat_StrTime -   pointer to a buffer to receive the time of day
              string. If NULL, this will not be generated.
```
RESULT

```c
    success - a zero return indicates that the [DateStamp](autodocs-2.0/includes-dos-dos-h.md) was
              invalid, and could not be converted.  Non-zero
              indicates that the call succeeded.
```
SEE ALSO

```c
    [DateStamp()](autodocs-2.0/dos-library-datestamp.md), StrtoDate(), [<dos/datetime.h>](autodocs-2.0/includes-dos-datetime-h.md)
```

---

## See Also

- [DateStamp — dos.library](../autodocs/dos.library.md#datestamp)
