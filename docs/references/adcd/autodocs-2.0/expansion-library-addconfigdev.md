---
title: expansion.library/AddConfigDev
manual: autodocs-2.0
chapter: autodocs-2.0
section: expansion-library-addconfigdev
functions: []
libraries: []
---

# expansion.library/AddConfigDev

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    AddConfigDev - add a new [ConfigDev](autodocs-2.0/includes-libraries-configvars-h.md) structure to the system
```
SYNOPSIS

```c
    AddConfigDev( configDev )
                  A0
```
FUNCTION

```c
    (Not typically called by user code)

    This routine adds the specified [ConfigDev](autodocs-2.0/includes-libraries-configvars-h.md) structure to the
    list of Configuration Devices in the system.
```
INPUTS

```c
    configDev - a valid [ConfigDev](autodocs-2.0/includes-libraries-configvars-h.md) structure.
```
RESULTS

EXCEPTIONS

SEE ALSO

```c
    [RemConfigDev](autodocs-2.0/expansion-library-remconfigdev.md)
```
BUGS

