---
title: graphics.library/NextDisplayInfo
manual: autodocs-2.0
chapter: autodocs-2.0
section: graphics-library-nextdisplayinfo
functions: [FindDisplayInfo, GetDisplayInfoData]
libraries: [graphics.library]
---

# graphics.library/NextDisplayInfo

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    NextDisplayInfo -- iterate current displayinfo identifiers (V36)
```
SYNOPSIS

```c
    next_ID = NextDisplayInfo(last_ID)
    D0                        D0

    ULONG NextDisplayInfo(ULONG);
```
FUNCTION

```c
    The basic iteration function with which to find all records in the
    graphics database.  Using each ID in succession, you can then call
    [FindDisplayInfo()](autodocs-2.0/graphics-library-finddisplayinfo.md) to obtain the handle associated with each ID.
    Each ID is a 32-bit Key which uniquely identifies one record.
    The INVALID_ID is special, and indicates the end-of-list.
```
INPUTS

    last_ID - previous displayinfo identifier
              or INVALID_ID if beginning iteration.
RESULT

    next_ID - subsequent displayinfo identifier
              or INVALID_ID if no more records.
BUGS

SEE ALSO

```c
    [FindDisplayInfo()](autodocs-2.0/graphics-library-finddisplayinfo.md), [GetDisplayInfoData()](autodocs-2.0/graphics-library-getdisplayinfodata.md)
    [graphics/displayinfo.h](autodocs-2.0/includes-graphics-displayinfo-h.md)
```

---

## See Also

- [FindDisplayInfo — graphics.library](../autodocs/graphics.library.md#finddisplayinfo)
- [GetDisplayInfoData — graphics.library](../autodocs/graphics.library.md#getdisplayinfodata)
