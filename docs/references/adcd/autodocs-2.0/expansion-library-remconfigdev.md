---
title: expansion.library/RemConfigDev
manual: autodocs-2.0
chapter: autodocs-2.0
section: expansion-library-remconfigdev
functions: []
libraries: []
---

# expansion.library/RemConfigDev

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    RemConfigDev - remove a [ConfigDev](autodocs-2.0/includes-libraries-configvars-h.md) structure from the system
```
SYNOPSIS

```c
    RemConfigDev( configDev )
                  A0
```
FUNCTION

```c
    (Not typically called by user code)

    This routine removes the specified [ConfigDev](autodocs-2.0/includes-libraries-configvars-h.md) structure from the
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
    [AddConfigDev](autodocs-2.0/expansion-library-addconfigdev.md)
```
BUGS

