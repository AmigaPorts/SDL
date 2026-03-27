---
title: amiga.lib/CoerceMethodA
manual: autodocs-2.0
chapter: autodocs-2.0
section: amiga-lib-coercemethoda
functions: []
libraries: []
---

# amiga.lib/CoerceMethodA

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    CoerceMethodA -- Perform method on coerced object.  (V36)
```
SYNOPSIS

```c
    result = CoerceMethodA( cl, obj, msg )

    ULONG CoerceMethodA( struct IClass *, Object *, Msg * );
```
FUNCTION

    Boopsi support function that invokes the supplied message
    on the specified object, as though it were the specified
    class.
INPUTS

    cl - pointer to boopsi class to receive the message
    obj - pointer to boopsi object
    msg - pointer to method-specific message to send
RESULT

    result - class and message-specific result.
NOTES

```c
    While this function requires V36 or higher intuition.library,
    it first appeared in V37 amiga.lib.
    Some early example code may refer to this function as CM().
```
SEE ALSO

```c
    [CoerceMethod()](autodocs-2.0/amiga-lib-coercemethod.md), [DoMethodA()](autodocs-2.0/amiga-lib-domethoda.md), [DoSuperMethodA()](autodocs-2.0/amiga-lib-dosupermethoda.md), [<intuition/classusr.h>](autodocs-2.0/includes-intuition-classusr-h.md)
    ROM Kernel Manual boopsi section
```
