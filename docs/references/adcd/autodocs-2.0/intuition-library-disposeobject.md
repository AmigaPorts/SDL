---
title: intuition.library/DisposeObject
manual: autodocs-2.0
chapter: autodocs-2.0
section: intuition-library-disposeobject
functions: [DisposeObject, GetAttr, MakeClass, NewObject]
libraries: [intuition.library]
---

# intuition.library/DisposeObject

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    DisposeObject -- Deletes a 'boopsi' object. (V36)
```
SYNOPSIS

```c
    DisposeObject( Object )
                   A0

    VOID DisposeObject( APTR );
```
FUNCTION

```c
    Deletes a boopsi object and all of it auxiliary data.
    These objects are all created by [NewObject()](autodocs-2.0/intuition-library-newobject.md).  Objects
    of certain classes "own" other objects, which will also
    be deleted when the object is passed to DisposeObject().
    Read the per-class documentation carefully to be aware
    of these instances.
```
INPUTS

```c
    Object = abstract pointer to a boopsi object returned by [NewObject()](autodocs-2.0/intuition-library-newobject.md)
```
NOTES

    This function invokes the OM_DISPOSE method.
RESULT

    None.
BUGS

SEE ALSO

```c
    [NewObject()](autodocs-2.0/intuition-library-newobject.md), SetAttrs(), [GetAttr()](autodocs-2.0/intuition-library-getattr.md), [MakeClass()](autodocs-2.0/intuition-library-makeclass.md),
    Document "Basic Object-Oriented Programming System for Intuition"
    and the "boopsi Class Reference" document.
```

---

## See Also

- [DisposeObject — intuition.library](../autodocs/intuition.library.md#disposeobject)
- [GetAttr — intuition.library](../autodocs/intuition.library.md#getattr)
- [MakeClass — intuition.library](../autodocs/intuition.library.md#makeclass)
- [NewObject — intuition.library](../autodocs/intuition.library.md#newobject)
