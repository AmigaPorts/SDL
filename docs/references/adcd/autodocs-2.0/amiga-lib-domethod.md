---
title: amiga.lib/DoMethod
manual: autodocs-2.0
chapter: autodocs-2.0
section: amiga-lib-domethod
functions: []
libraries: []
---

# amiga.lib/DoMethod

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    DoMethod -- Perform method on object.  (V36)
```
SYNOPSIS

```c
    result = DoMethod( obj, MethodID, ... )

    ULONG DoMethod( Object *, ULONG, ... );
```
FUNCTION

```c
    Boopsi support function that invokes the supplied message
    on the specified object.  The message is invoked on the
    object's true class.  Equivalent to [DoMethodA()](autodocs-2.0/amiga-lib-domethoda.md), but allows
    you to build the message on the stack.
```
INPUTS

```c
    obj - pointer to boopsi object
    MethodID - which method to send (see [<intuition/classusr.h>](autodocs-2.0/includes-intuition-classusr-h.md))
    ... - method-specific message built on the stack
```
RESULT

    result - specific to the message and the object's class.
NOTES

    While this function requires V36 or higher intuition.library,
    it first appeared in V37 amiga.lib.
SEE ALSO

```c
    [DoMethodA()](autodocs-2.0/amiga-lib-domethoda.md), [CoerceMethodA()](autodocs-2.0/amiga-lib-coercemethoda.md), [DoSuperMethodA()](autodocs-2.0/amiga-lib-dosupermethoda.md), [<intuition/classusr.h>](autodocs-2.0/includes-intuition-classusr-h.md)
    ROM Kernel Manual boopsi section
```
