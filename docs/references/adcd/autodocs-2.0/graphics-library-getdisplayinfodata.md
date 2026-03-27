---
title: graphics.library/GetDisplayInfoData
manual: autodocs-2.0
chapter: autodocs-2.0
section: graphics-library-getdisplayinfodata
functions: [FindDisplayInfo, GetDisplayInfoData, NextDisplayInfo]
libraries: [graphics.library]
---

# graphics.library/GetDisplayInfoData

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    GetDisplayInfoData -- query [DisplayInfo](autodocs-2.0/includes-graphics-displayinfo-h.md) Record parameters (V36)
```
SYNOPSIS

```c
    result = GetDisplayInfoData(handle, buf, size, tagID, [ID])
    D0                          A0      A1   D0    D1     [D2]

    ULONG GetDisplayInfoData(DisplayInfoHandle, UBYTE *, ULONG,
                                       ULONG, ULONG);
```
FUNCTION

```c
    GetDisplayInfoData() fills a buffer with data meaningful to the
    DisplayInfoRecord pointed at by your valid handle. The data type
    that you are interested in is indicated by a tagID for that chunk.
    The types of tagged information that may be available include:

    DTAG_DISP: (DisplayInfo)   - properties and availability information.
    DTAG_DIMS: (DimensionInfo) - default dimensions and overscan info.
    DTAG_MNTR: (MonitorInfo)   - type, position, scanrate, and
                                 compatibility
    DTAG_NAME: (NameInfo)      - a user friendly way to refer to this mode.
```
INPUTS

    handle - displayinfo handle
    buf    - pointer to destination buffer
    size   - buffer size in bytes
    tagID  - data chunk type
    ID     - displayinfo identifier, optionally used if handle is NULL
RESULT

    result - if positive, number of bytes actually transferred
             if zero, no information for ID was available
BUGS

SEE ALSO

```c
    [FindDisplayInfo()](autodocs-2.0/graphics-library-finddisplayinfo.md), [NextDisplayInfo()](autodocs-2.0/graphics-library-nextdisplayinfo.md)
    [graphics/displayinfo.h](autodocs-2.0/includes-graphics-displayinfo-h.md)
```

---

## See Also

- [FindDisplayInfo — graphics.library](../autodocs/graphics.library.md#finddisplayinfo)
- [GetDisplayInfoData — graphics.library](../autodocs/graphics.library.md#getdisplayinfodata)
- [NextDisplayInfo — graphics.library](../autodocs/graphics.library.md#nextdisplayinfo)
