---
title: intuition.library/NewObject
manual: autodocs-2.0
chapter: autodocs-2.0
section: intuition-library-newobject
functions: [DisposeObject, GetAttr, MakeClass]
libraries: [intuition.library]
---

# intuition.library/NewObject

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    NewObjectA -- Create an object from a class. (V36)
    NewObject -- Varargs stub for NewObjectA(). (V36)
```
SYNOPSIS

```c
    object = NewObjectA( class, classID, tagList )
    D0                   A0     A1       A2

    APTR NewObjectA( struct IClass *, UBYTE *, struct [TagItem](autodocs-2.0/includes-utility-tagitem-h.md) * );

    object = NewObject( class, classID, Tag1, ... )

    APTR NewObject( struct IClass *, UBYTE *, ULONG, ... );
```
FUNCTION

```c
    This is the general method of creating objects from 'boopsi' classes.
    ('Boopsi' stands for "basic object-oriented programming system for
    Intuition".)

    You specify a class either as a pointer (for a private class) or
    by its ID string (for public classes).  If the class pointer
    is NULL, then the classID is used.

    You further specify initial "create-time" attributes for the
    object via a [TagItem](autodocs-2.0/includes-utility-tagitem-h.md) list, and they are applied to the resulting
    generic data object that is returned.  The attributes, their meanings,
    attributes applied only at create-time, and required attributes
    are all defined and documented on a class-by-class basis.
```
INPUTS

```c
    class = abstract pointer to a boopsi class gotten via [MakeClass()](autodocs-2.0/intuition-library-makeclass.md).
    classID = the name/ID string of a public class.  This parameter is
            only used if 'class' is NULL.
    tagList = pointer to array of TagItems containing attribute/value
            pairs to be applied to the object being created
```
RESULT

```c
    A boopsi object, which may be used in different contexts such
    as a gadget or image, and may be manipulated by generic functions.
    You eventually free the object using [DisposeObject()](autodocs-2.0/intuition-library-disposeobject.md).
```
NOTES

    This function invokes the OM_NEW "method" for the class specified.
BUGS

```c
    Typedef's for 'Object' and 'Class' are defined in the include
    files but not used consistently.  The generic type APTR is
    probably best used for object and class "handles", with the
    type (UBYTE *) used for classID strings.
```
SEE ALSO

```c
    [DisposeObject()](autodocs-2.0/intuition-library-disposeobject.md), SetAttrs(), [GetAttr()](autodocs-2.0/intuition-library-getattr.md), [MakeClass()](autodocs-2.0/intuition-library-makeclass.md),
    Document "Basic Object-Oriented Programming System for Intuition"
    and the "boopsi Class Reference" document.
```

---

## See Also

- [DisposeObject — intuition.library](../autodocs/intuition.library.md#disposeobject)
- [GetAttr — intuition.library](../autodocs/intuition.library.md#getattr)
- [MakeClass — intuition.library](../autodocs/intuition.library.md#makeclass)
