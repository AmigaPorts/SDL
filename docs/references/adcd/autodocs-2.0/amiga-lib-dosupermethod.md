---
title: amiga.lib/DoSuperMethod
manual: autodocs-2.0
chapter: autodocs-2.0
section: amiga-lib-dosupermethod
functions: []
libraries: []
---

# amiga.lib/DoSuperMethod

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    DoSuperMethod -- Perform method on object coerced to superclass. (V36)
```
SYNOPSIS

```c
    result = DoSuperMethod( cl, obj, MethodID, ... )

    ULONG DoSuperMethod( struct IClass *, Object *, ULONG, ... );
```
FUNCTION

```c
    Boopsi support function that invokes the supplied message
    on the specified object, as though it were the superclass
    of the specified class.  Equivalent to [DoSuperMethodA()](autodocs-2.0/amiga-lib-dosupermethoda.md),
    but allows you to build the message on the stack.
```
INPUTS

    cl - pointer to boopsi class whose superclass is to
        receive the message
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
