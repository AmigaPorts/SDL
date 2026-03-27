---
title: amiga.lib/SetSuperAttrs
manual: autodocs-2.0
chapter: autodocs-2.0
section: amiga-lib-setsuperattrs
functions: []
libraries: []
---

# amiga.lib/SetSuperAttrs

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    SetSuperAttrs -- Invoke OM_SET method on superclass with varargs. (V36)
```
SYNOPSIS

```c
    result = SetSuperAttrs( cl, obj, tag, ... )

    ULONG SetSuperAttrs( struct IClass *, Object *, ULONG, ... );
```
FUNCTION

```c
    Boopsi support function which invokes the OM_SET method on the
    superclass of the supplied class for the supplied object.  Allows
    the ops_AttrList to be supplied on the stack (i.e. in a varargs
    way).  The equivalent non-varargs function would simply be

        DoSuperMethod( cl, obj, OM_SET, taglist, NULL );
```
INPUTS

    cl - pointer to boopsi class whose superclass is to
        receive the OM_SET message
    obj - pointer to boopsi object
    tag - list of tag-attribute pairs, ending in TAG_DONE
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
