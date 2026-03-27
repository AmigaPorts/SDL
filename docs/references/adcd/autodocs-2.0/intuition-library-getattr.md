---
title: intuition.library/GetAttr
manual: autodocs-2.0
chapter: autodocs-2.0
section: intuition-library-getattr
functions: [DisposeObject, MakeClass, NewObject]
libraries: [intuition.library]
---

# intuition.library/GetAttr

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    GetAttr -- Inquire the value of some attribute of an object. (V36)
```
SYNOPSIS

```c
    attr = GetAttr( AttrID, Object, StoragePtr )
    D0              D0      A0      A1

    ULONG GetAttr( ULONG, APTR, ULONG * );
```
FUNCTION

```c
    Inquires from the specified object the value of the specified
    attribute.

    You always pass the address of a long variable, which will
    receive the same value that would be passed to SetAttrs() in
    the ti_Data portion of a [TagItem](autodocs-2.0/includes-utility-tagitem-h.md) element.  See the documentation
    for the class for exceptions to this general rule.

    Not all attributes will respond to this function.  Those that
    will are documented on a class-by-class basis.
```
INPUTS

```c
    AttrID = the attribute tag ID understood by the object's class
    Object = abstract pointer to the boopsi object you are interested in
    StoragePtr = pointer to appropriate storage for the answer
```
RESULT

```c
    Returns FALSE (0) if the inquiries of attribute are not provided
    by the object's class.
```
NOTES

    This function invokes the OM_GET method of the object.
BUGS

SEE ALSO

```c
    [NewObject()](autodocs-2.0/intuition-library-newobject.md), [DisposeObject()](autodocs-2.0/intuition-library-disposeobject.md), SetAttrs(), [MakeClass()](autodocs-2.0/intuition-library-makeclass.md),
    Document "Basic Object-Oriented Programming System for Intuition"
    and the "boopsi Class Reference" document.
```

---

## See Also

- [DisposeObject — intuition.library](../autodocs/intuition.library.md#disposeobject)
- [MakeClass — intuition.library](../autodocs/intuition.library.md#makeclass)
- [NewObject — intuition.library](../autodocs/intuition.library.md#newobject)
