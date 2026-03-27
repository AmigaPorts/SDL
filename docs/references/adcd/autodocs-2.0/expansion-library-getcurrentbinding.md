---
title: expansion.library/GetCurrentBinding
manual: autodocs-2.0
chapter: autodocs-2.0
section: expansion-library-getcurrentbinding
functions: []
libraries: []
---

# expansion.library/GetCurrentBinding

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    GetCurrentBinding - sets static board configuration area
SYNOPSIS

```c
    actual = GetCurrentBinding( currentBinding, size )
                                A0              D0:16
```
FUNCTION

```c
    This function writes the contents of the "currentBinding"
    structure out of a private place.  It may be set via
    [SetCurrentBinding()](autodocs-2.0/expansion-library-setcurrentbinding.md).  This is really a kludge, but it is
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

    size - The size of the user's binddriver structure.
        Do not pass in less than sizeof(struct CurrentBinding).
```
RESULTS

```c
    actual - the true size of a [CurrentBinding](autodocs-2.0/includes-libraries-configvars-h.md) structure is returned.
```
SEE ALSO

    GetCurrentBinding
