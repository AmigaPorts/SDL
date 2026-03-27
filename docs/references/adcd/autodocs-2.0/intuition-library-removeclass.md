---
title: intuition.library/RemoveClass
manual: autodocs-2.0
chapter: autodocs-2.0
section: intuition-library-removeclass
functions: [AddClass, FreeClass, MakeClass]
libraries: [intuition.library]
---

# intuition.library/RemoveClass

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    RemoveClass -- Make a public boopsi class unavailable. (V36)
```
SYNOPSIS

```c
    RemoveClass( classPtr )
                 A0

    VOID RemoveClass( struct IClass * );
```
FUNCTION

    Makes a public class unavailable for public consumption.
    It's OK to call this function for a class which is not
    yet in the internal public class list, or has been
    already removed.
INPUTS

```c
    ClassPtr = pointer to *public* class created by [MakeClass()](autodocs-2.0/intuition-library-makeclass.md),
            may be NULL.
```
RESULT

    None.
NOTES

BUGS

SEE ALSO

```c
    [MakeClass()](autodocs-2.0/intuition-library-makeclass.md), [FreeClass()](autodocs-2.0/intuition-library-freeclass.md), [AddClass()](autodocs-2.0/intuition-library-addclass.md)
    Document "Basic Object-Oriented Programming System for Intuition"
    and the "boopsi Class Reference" document.
```

---

## See Also

- [AddClass — intuition.library](../autodocs/intuition.library.md#addclass)
- [FreeClass — intuition.library](../autodocs/intuition.library.md#freeclass)
- [MakeClass — intuition.library](../autodocs/intuition.library.md#makeclass)
