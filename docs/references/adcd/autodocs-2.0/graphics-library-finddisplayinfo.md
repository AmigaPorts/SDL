---
title: graphics.library/FindDisplayInfo
manual: autodocs-2.0
chapter: autodocs-2.0
section: graphics-library-finddisplayinfo
functions: []
libraries: []
---

# graphics.library/FindDisplayInfo

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    FindDisplayInfo -- search for a record identified by a specific key
                       (V36)
```
SYNOPSIS

```c
    handle = FindDisplayInfo(ID)
    D0                       D0

    DisplayInfoHandle FindDisplayInfo(ULONG);
```
FUNCTION

    Given a 32-bit Mode Key, return a handle to a valid DisplayInfoRecord
    found in the graphics database.  Using this handle, you can obtain
    information about this Mode, including its default dimensions,
    properties, and whether it is currently available for use.
INPUTS

    ID     - unsigned long identifier
RESULT

    handle - handle to a displayinfo Record with that key
             or NULL if no match.
BUGS

SEE ALSO

```c
    [graphics/displayinfo.h](autodocs-2.0/includes-graphics-displayinfo-h.md)
```
