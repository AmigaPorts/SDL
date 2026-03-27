---
title: expansion.library/SetCurrentBinding
manual: autodocs-2.0
chapter: autodocs-2.0
section: expansion-library-setcurrentbinding
functions: []
libraries: []
---

# expansion.library/SetCurrentBinding

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    SetCurrentBinding - sets static board configuration area
SYNOPSIS

```c
    SetCurrentBinding( currentBinding, size )
                       A0              D0:16
```
FUNCTION

```c
    This function records the contents of the "currentBinding"
    structure in a private place.  It may be read via
    [GetCurrentBinding()](autodocs-2.0/expansion-library-getcurrentbinding.md).  This is really a kludge, but it is
    the only way to pass extra arguments to a newly configured
    device.

    A [CurrentBinding](autodocs-2.0/includes-libraries-configvars-h.md) structure has the name of the currently
    loaded file, the product string that was associated with
    this driver, and a pointer to the head of a singly linked
    list of [ConfigDev](autodocs-2.0/includes-libraries-configvars-h.md) structures (linked through the cd_NextCD
    field).

    Many devices may not need this information; they have hard
    coded into themselves their manufacture number.  It is
    recommended that you at least check that you can deal with
    the product code in the linked [ConfigDev](autodocs-2.0/includes-libraries-configvars-h.md) structures.
```
INPUTS

```c
    currentBinding - a pointer to a [CurrentBinding](autodocs-2.0/includes-libraries-configvars-h.md) structure

    size - The size of the user's binddriver structure.  No
        more than this much data will be copied.  If size is
        less than the library's idea a [CurrentBinding](autodocs-2.0/includes-libraries-configvars-h.md) size,
        then the library's structure will be null padded.
```
SEE ALSO

```c
    [GetCurrentBinding](autodocs-2.0/expansion-library-getcurrentbinding.md)
```
