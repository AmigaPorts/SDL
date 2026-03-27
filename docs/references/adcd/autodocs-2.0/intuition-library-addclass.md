---
title: intuition.library/AddClass
manual: autodocs-2.0
chapter: autodocs-2.0
section: intuition-library-addclass
functions: [FreeClass, MakeClass, RemoveClass]
libraries: [intuition.library]
---

# intuition.library/AddClass

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    AddClass -- Make a public class available (V36)
```
SYNOPSIS

```c
    AddClass( Class )
              A0

    VOID AddClass( struct IClass * );
```
FUNCTION

```c
    Adds a public boopsi class to the internal list of classes available
    for public consumption.

    You must call this function after you call [MakeClass()](autodocs-2.0/intuition-library-makeclass.md).
```
INPUTS

```c
    Class = pointer returned by [MakeClass()](autodocs-2.0/intuition-library-makeclass.md)
```
RESULT

    Nothing returned.
NOTES

BUGS

    Although there is some protection against creating classes
    with the same name as an existing class, this function
    does not do any checking or other dealings with like-named
    classes.  Until this is rectified, only officially registered
    names can be used for public classes, and there is no
    "class replacement" policy in effect.
SEE ALSO

```c
    [MakeClass()](autodocs-2.0/intuition-library-makeclass.md), [FreeClass()](autodocs-2.0/intuition-library-freeclass.md), [RemoveClass()](autodocs-2.0/intuition-library-removeclass.md)
    Document "Basic Object-Oriented Programming System for Intuition"
    and the "boopsi Class Reference" document.
```

---

## See Also

- [FreeClass — intuition.library](../autodocs/intuition.library.md#freeclass)
- [MakeClass — intuition.library](../autodocs/intuition.library.md#makeclass)
- [RemoveClass — intuition.library](../autodocs/intuition.library.md#removeclass)
