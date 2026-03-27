---
title: amiga.lib/CoerceMethod
manual: autodocs-2.0
chapter: autodocs-2.0
section: amiga-lib-coercemethod
functions: []
libraries: []
---

# amiga.lib/CoerceMethod

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    CoerceMethod -- Perform method on coerced object.  (V36)
```
SYNOPSIS

```c
    result = CoerceMethod( cl, obj, MethodID, ... )

    ULONG CoerceMethod( struct IClass *, Object *, ULONG, ... );
```
FUNCTION

```c
    Boopsi support function that invokes the supplied message
    on the specified object, as though it were the specified
    class.  Equivalent to [CoerceMethodA()](autodocs-2.0/amiga-lib-coercemethoda.md), but allows you to
    build the message on the stack.
```
INPUTS

    cl - pointer to boopsi class to receive the message
    obj - pointer to boopsi object
    ... - method-specific message built on the stack
RESULT

    result - class and message-specific result.
NOTES

    While this function requires V36 or higher intuition.library,
    it first appeared in V37 amiga.lib.
SEE ALSO

```c
    [CoerceMethodA()](autodocs-2.0/amiga-lib-coercemethoda.md), [DoMethodA()](autodocs-2.0/amiga-lib-domethoda.md), [DoSuperMethodA()](autodocs-2.0/amiga-lib-dosupermethoda.md), [<intuition/classusr.h>](autodocs-2.0/includes-intuition-classusr-h.md)
    ROM Kernel Manual boopsi section
```
