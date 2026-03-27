---
title: graphics.library/GetVPModeID
manual: autodocs-2.0
chapter: autodocs-2.0
section: graphics-library-getvpmodeid
functions: [ModeNotAvailable]
libraries: [graphics.library]
---

# graphics.library/GetVPModeID

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    GetVPModeID -- get the 32 bit DisplayID from a [ViewPort](autodocs-2.0/includes-graphics-view-h.md). (V36)
```
SYNOPSIS

```c
    modeID =  GetVPModeID( vp )
    d0                     a0

    ULONG GetVPModeID( struct [ViewPort](autodocs-2.0/includes-graphics-view-h.md) *);
```
FUNCTION

```c
    returns the normal display modeID, if one is currently  associated
    with this [ViewPort](autodocs-2.0/includes-graphics-view-h.md).
```
INPUTS

```c
    vp -- pointer to a [ViewPort](autodocs-2.0/includes-graphics-view-h.md) structure.
```
RESULT


```c
    modeID -- a 32 bit DisplayInfoRecord identifier associated with
              this [ViewPort](autodocs-2.0/includes-graphics-view-h.md), or INVALID_ID.
```
NOTES

```c
    Test the return value of this function against INVALID_ID, not NULL.
    (INVALID_ID is defined in [graphics/displayinfo.h)](autodocs-2.0/includes-graphics-displayinfo-h.md).
```
BUGS

SEE ALSO

```c
    [graphics/displayinfo.h](autodocs-2.0/includes-graphics-displayinfo-h.md), [ModeNotAvailable()](autodocs-2.0/graphics-library-modenotavailable.md)
```

---

## See Also

- [ModeNotAvailable — graphics.library](../autodocs/graphics.library.md#modenotavailable)
