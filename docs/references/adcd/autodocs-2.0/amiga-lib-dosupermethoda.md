---
title: amiga.lib/DoSuperMethodA
manual: autodocs-2.0
chapter: autodocs-2.0
section: amiga-lib-dosupermethoda
functions: []
libraries: []
---

# amiga.lib/DoSuperMethodA

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    DoSuperMethodA -- Perform method on object coerced to superclass. (V36)
```
SYNOPSIS

```c
    result = DoSuperMethodA( cl, obj, msg )

    ULONG DoSuperMethodA( struct IClass *, Object *, Msg * );
```
FUNCTION

    Boopsi support function that invokes the supplied message
    on the specified object, as though it were the superclass
    of the specified class.
INPUTS

    cl - pointer to boopsi class whose superclass is to
        receive the message
    obj - pointer to boopsi object
    msg - pointer to method-specific message to send
RESULT

    result - class and message-specific result.
NOTES

```c
    While this function requires V36 or higher intuition.library,
    it first appeared in V37 amiga.lib.
    Some early example code may refer to this function as DSM().
```
SEE ALSO

```c
    [CoerceMethodA()](autodocs-2.0/amiga-lib-coercemethoda.md), [DoMethodA()](autodocs-2.0/amiga-lib-domethoda.md), [DoSuperMethod()](autodocs-2.0/amiga-lib-dosupermethod.md), [<intuition/classusr.h>](autodocs-2.0/includes-intuition-classusr-h.md)
    ROM Kernel Manual boopsi section
```
