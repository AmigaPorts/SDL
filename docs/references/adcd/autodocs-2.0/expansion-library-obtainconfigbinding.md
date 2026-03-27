---
title: expansion.library/ObtainConfigBinding
manual: autodocs-2.0
chapter: autodocs-2.0
section: expansion-library-obtainconfigbinding
functions: []
libraries: []
---

# expansion.library/ObtainConfigBinding

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    ObtainConfigBinding - try to get permission to bind drivers
SYNOPSIS


```c
    ObtainConfigBinding()
```
FUNCTION

```c
    ObtainConfigBinding gives permission to bind drivers to
    [ConfigDev](autodocs-2.0/includes-libraries-configvars-h.md) structures.  It exists so two drivers at once
    do not try and own the same [ConfigDev](autodocs-2.0/includes-libraries-configvars-h.md) structure.  This
    call will block until it is safe proceed.

    It is crucially important that people lock out others
    before loading new drivers.  Much of the data that is used
    to configure things is statically kept, and others need
    to be kept from using it.

    This call is built directly on Exec [SignalSemaphore](autodocs-2.0/includes-exec-semaphores-h.md) code
    (e.g. ObtainSemaphore).
```
INPUTS

RESULTS

EXCEPTIONS

SEE ALSO

```c
    [ReleaseConfigBinding()](autodocs-2.0/expansion-library-releaseconfigbinding.md)
```
BUGS

