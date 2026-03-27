---
title: intuition.library/NextObject
manual: autodocs-2.0
chapter: autodocs-2.0
section: intuition-library-nextobject
functions: [DisposeObject, GetAttr, MakeClass, NextObject]
libraries: [intuition.library]
---

# intuition.library/NextObject

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    NextObject -- iterate through the object on an Exec list. (V36)
```
SYNOPSIS

```c
    object = NextObject( objectPtrPtr )
    D0                   A0

    APTR NextObject( APTR );
```
FUNCTION

```c
    This function is for boopsi class implementors only.

    When you collect a set of boopsi objects on an Exec [List](autodocs-2.0/includes-exec-lists-h.md)
    structure by invoking their OM_ADDMEMBER method, you
    can (only) retrieve them by iterations of this function.

    Works even if you remove and dispose the returned list
    members in turn.
```
INPUTS

```c
    Initially, you set a pointer variable to equal the
    lh_Head field of the list (or mlh_Head field of a MinList).
    You pass the *address* of that pointer repeatedly
    to NextObject() until it returns NULL.
```
EXAMPLE


```c
    /* here is the OM_DISPOSE case of some class's dispatcher */
    case OM_DISPOSE:
        /* dispose members  */
        object_state = mydata->md_CollectionList.lh_Head;
        while ( member_object = NextObject( &object_state ) )
        {
            DoMethod( member_object, OM_REMOVE ); /* remove from list */
            DM( member, msg );      /* and pass along dispose       */
        }
```
RESULT

    Returns pointers to each object in the list in turn, and NULL
    when there are no more.
NOTES

BUGS

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
- [NextObject — intuition.library](../autodocs/intuition.library.md#nextobject)
