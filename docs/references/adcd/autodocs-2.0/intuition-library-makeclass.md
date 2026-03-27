---
title: intuition.library/MakeClass
manual: autodocs-2.0
chapter: autodocs-2.0
section: intuition-library-makeclass
functions: [AddClass, FreeClass, MakeClass, NewObject, RemoveClass]
libraries: [intuition.library]
---

# intuition.library/MakeClass

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    MakeClass -- Create and initialize a boopsi class. (V36)
```
SYNOPSIS

```c
    iclass = MakeClass( ClassID, SuperClassID, SuperClassPtr,
    D0                  A0       A1            A2
            InstanceSize, Flags )
            D0            D1

    struct IClass *MakeClass( UBYTE *, UBYTE *, struct IClass *,
            UWORD, ULONG );
```
FUNCTION

```c
    For class implementors only.

    This function creates a new public or private boopsi class.
    The superclass should be defined to be another boopsi class:
    all classes are descendants of the class "rootclass".

    Superclasses can be public or private.  You provide a name/ID
    for your class if it is to be a public class (but you must
    have registered your class name and your attribute ID's with
    Commodore before you do this!).  For a public class, you would
    also call [AddClass()](autodocs-2.0/intuition-library-addclass.md) to make it available after you have
    finished your initialization.

    Returns pointer to an IClass data structure for your
    class.  You then initialize the [Hook](autodocs-2.0/includes-utility-hooks-h.md) cl_Dispatcher for
    your class methods code.  You can also set up special data
    shared by all objects in your class, and point cl_UserData at it.
    The last step for public classes is to call [AddClass()](autodocs-2.0/intuition-library-addclass.md).

    You dispose of a class created by this function by calling
    [FreeClass()](autodocs-2.0/intuition-library-freeclass.md).
```
INPUTS

```c
    ClassID = NULL for private classes, the name/ID string for public
            classes
    SuperClassID = name/ID of your new class's superclass.  NULL if
            superclass is a private class
    SuperClassPtr = pointer to private superclass.  Only used if
            SuperClassID is NULL.  You are required never to provide
            a NULL superclass.
    InstanceSize = the size of the instance data that your class's
            objects will require, beyond that data defined for
            your superclass's objects.
    Flags = for future enhancement, including possible additional
            parameters.  Provide zero for now.
```
RESULT

    Pointer to the resulting class, or NULL if not possible:
    - no memory for class data structure
    - public superclass not found
    - public class of same name/ID as this one already exists
NOTES

EXAMPLE

    Creating a private subclass of a public class:
/* per-object instance data defined by my class     */
struct MyInstanceData {
```c
    ULONG   mid_SomeData;
```
};

/* some useful table I'll share use for all objects */
UWORD myTable[] = {
    5, 4, 3, 2, 1, 0
};

struct IClass       *
initMyClass()
{
```c
    ULONG __saveds  myDispatcher();
    ULONG   hookEntry();    /* asm-to-C interface glue       */
    struct IClass   *cl;
    struct IClass   *MakeClass();

    if ( cl =  MakeClass( NULL,
                SUPERCLASSID, NULL,  /* superclass is public */
                sizeof (struct MyInstanceData),
                0 ))
    {
        /* initialize the cl_Dispatcher [Hook](autodocs-2.0/includes-utility-hooks-h.md)       */
        cl->cl_Dispatcher.h_Entry = hookEntry;
        cl->cl_Dispatcher.h_SubEntry = myDispatcher;
        cl->cl_Dispatcher.h_Data = (VOID *) 0xFACE; /* unused */

        cl-cl_UserData = (ULONG) myTable;
    }
    return ( cl );
```
}

BUGS

    The typedef 'Class' isn't consistently used.  Class pointers
    used blindly should be APTR, or struct IClass for class implementors.
SEE ALSO

```c
    [FreeClass()](autodocs-2.0/intuition-library-freeclass.md), [AddClass()](autodocs-2.0/intuition-library-addclass.md), [RemoveClass()](autodocs-2.0/intuition-library-removeclass.md), [NewObject()](autodocs-2.0/intuition-library-newobject.md),
    Document "Basic Object-Oriented Programming System for Intuition"
    and the "boopsi Class Reference" document.
```

---

## See Also

- [AddClass — intuition.library](../autodocs/intuition.library.md#addclass)
- [FreeClass — intuition.library](../autodocs/intuition.library.md#freeclass)
- [MakeClass — intuition.library](../autodocs/intuition.library.md#makeclass)
- [NewObject — intuition.library](../autodocs/intuition.library.md#newobject)
- [RemoveClass — intuition.library](../autodocs/intuition.library.md#removeclass)
