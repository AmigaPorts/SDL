---
title: amiga.lib/DoMethodA
manual: autodocs-2.0
chapter: autodocs-2.0
section: amiga-lib-domethoda
functions: []
libraries: []
---

# amiga.lib/DoMethodA

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    DoMethodA -- Perform method on object.  (V36)
```
SYNOPSIS

```c
    result = DoMethodA( obj, msg )

    ULONG DoMethodA( Object *, Msg * );
```
FUNCTION

    Boopsi support function that invokes the supplied message
    on the specified object.  The message is invoked on the
    object's true class.
INPUTS

    obj - pointer to boopsi object
    msg - pointer to method-specific message to send
RESULT

    result - specific to the message and the object's class.
NOTES

```c
    While this function requires V36 or higher intuition.library,
    it first appeared in V37 amiga.lib.
    Some early example code may refer to this function as DM().
```
SEE ALSO

```c
    [DoMethod()](autodocs-2.0/amiga-lib-domethod.md), [CoerceMethodA()](autodocs-2.0/amiga-lib-coercemethoda.md), [DoSuperMethodA()](autodocs-2.0/amiga-lib-dosupermethoda.md), [<intuition/classusr.h>](autodocs-2.0/includes-intuition-classusr-h.md)
    ROM Kernel Manual boopsi section
```
