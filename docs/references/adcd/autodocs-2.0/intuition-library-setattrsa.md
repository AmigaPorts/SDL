---
title: intuition.library/SetAttrsA
manual: autodocs-2.0
chapter: autodocs-2.0
section: intuition-library-setattrsa
functions: [DisposeObject, GetAttr, MakeClass, NewObject, SetAttrsA]
libraries: [intuition.library]
---

# intuition.library/SetAttrsA

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    SetAttrsA -- Specify attribute values for an object. (V36)
    SetAttrs -- Varargs stub for SetAttrsA(). (V36)
```
SYNOPSIS

```c
    result = SetAttrsA( Object, TagList )
    D0                  A0      A1

    ULONG SetAttrsA( APTR, struct [TagItem](autodocs-2.0/includes-utility-tagitem-h.md) * );

    result = SetAttrs( Object, Tag1, ... )

    ULONG SetAttrs( APTR, ULONG, ... );
```
FUNCTION

```c
    Specifies a set of attribute/value pairs with meaning as
    defined by a 'boopsi' object's class.

    This function does not provide enough context information or
    arbitration for boopsi gadgets which are attached to windows
    or requesters.  For those objects, use SetGadgetAttrs().
```
INPUTS

```c
    Object = abstract pointer to a boopsi object.
    TagList = array of [TagItem](autodocs-2.0/includes-utility-tagitem-h.md) structures with attribute/value pairs.
```
RESULT

    The object does whatever it wants with the attributes you provide.
    The return value tends to be non-zero if the changes would require
    refreshing gadget imagery, if the object is a gadget.
NOTES

```c
    This function invokes the OM_SET method with a NULL [GadgetInfo](autodocs-2.0/includes-intuition-cghooks-h.md)
    parameter.
```
BUGS

SEE ALSO

```c
    [NewObject()](autodocs-2.0/intuition-library-newobject.md), [DisposeObject()](autodocs-2.0/intuition-library-disposeobject.md), [GetAttr()](autodocs-2.0/intuition-library-getattr.md), [MakeClass()](autodocs-2.0/intuition-library-makeclass.md),
    Document "Basic Object-Oriented Programming System for Intuition"
    and the "boopsi Class Reference" document.
```

---

## See Also

- [DisposeObject — intuition.library](../autodocs/intuition.library.md#disposeobject)
- [GetAttr — intuition.library](../autodocs/intuition.library.md#getattr)
- [MakeClass — intuition.library](../autodocs/intuition.library.md#makeclass)
- [NewObject — intuition.library](../autodocs/intuition.library.md#newobject)
- [SetAttrsA — intuition.library](../autodocs/intuition.library.md#setattrsa)
