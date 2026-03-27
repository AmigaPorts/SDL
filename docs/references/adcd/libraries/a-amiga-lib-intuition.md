---
title: A / Amiga.lib / Intuition
manual: libraries
chapter: libraries
section: a-amiga-lib-intuition
functions: []
libraries: []
---

# A / Amiga.lib / Intuition

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

[CallHook()](autodocs-2.0/amiga-lib-callhook.md) and [CallHookA()](autodocs-2.0/amiga-lib-callhooka.md)

```c
    These functions invoke hooks.  CallHook() expects a parameter packet
    ("message") on the stack, while CallHookA() takes a pointer to the
    message.
```
[DoMethod()](autodocs-2.0/amiga-lib-domethod.md) and [DoMethodA()](autodocs-2.0/amiga-lib-domethoda.md)

```c
    Boopsi support functions that ask a specified Boopsi object to
    perform a specific message.  The message is passed in the function
    call for DoMethodA() and on the stack for DoMethod().  The message is
    invoked on the object's true class.
```
[DoSuperMethod()](autodocs-2.0/amiga-lib-dosupermethod.md) and [DoSuperMethodA()](autodocs-2.0/amiga-lib-dosupermethoda.md)

```c
    Boopsi support functions that ask a Boopsi object to perform a
    supplied message as if it was an instance of its superclass.  The
    message is passed in the function call for DoSuperMethodA() and on
    the stack for DoSuperMethod().
```
[CoerceMethod()](autodocs-2.0/amiga-lib-coercemethod.md) and [CoerceMethodA()](autodocs-2.0/amiga-lib-coercemethoda.md)

```c
    Boopsi support functions that ask a Boopsi object to perform a
    supplied message as if it was an instance of some other class. The
    message is passed in the function call for CoerceMethodA() and on the
    stack for CoerceMethod.
```
[SetSuperAttrs()](autodocs-2.0/amiga-lib-setsuperattrs.md)

```c
    Boopsi support function which invokes the OM_SET method on the
    superclass of the supplied class for the supplied object. Allows the
    ops_AttrList to be supplied on the stack (i.e. in a varargs way).
```
