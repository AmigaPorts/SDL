---
title: expansion.library/AllocConfigDev
manual: autodocs-2.0
chapter: autodocs-2.0
section: expansion-library-allocconfigdev
functions: []
libraries: []
---

# expansion.library/AllocConfigDev

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    AllocConfigDev - allocate a [ConfigDev](autodocs-2.0/includes-libraries-configvars-h.md) structure
```
SYNOPSIS

```c
    configDev = AllocConfigDev()
    D0
```
FUNCTION

```c
    This routine returns the address of a [ConfigDev](autodocs-2.0/includes-libraries-configvars-h.md) structure.
    It is provided so new fields can be added to the structure
    without breaking old, existing code.  The structure is cleared
    when it is returned to the user.
```
INPUTS

RESULTS

```c
    configDev - either a valid [ConfigDev](autodocs-2.0/includes-libraries-configvars-h.md) structure or NULL.
```
EXCEPTIONS

SEE ALSO

```c
    [FreeConfigDev](autodocs-2.0/expansion-library-freeconfigdev.md)
```
BUGS

