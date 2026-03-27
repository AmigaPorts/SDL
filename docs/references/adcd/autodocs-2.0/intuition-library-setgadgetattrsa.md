---
title: intuition.library/SetGadgetAttrsA
manual: autodocs-2.0
chapter: autodocs-2.0
section: intuition-library-setgadgetattrsa
functions: [AddGList, AddGadget, DisposeObject, GetAttr, MakeClass, NewObject, SetGadgetAttrsA]
libraries: [intuition.library]
---

# intuition.library/SetGadgetAttrsA

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    SetGadgetAttrsA -- Specify attribute values for a boopsi gadget. (V36)
    SetGadgetAttrs -- Varargs stub for SetGadgetAttrsA(). (V36)
```
SYNOPSIS

```c
    result = SetGadgetAttrsA( [Gadget](autodocs-2.0/includes-intuition-intuition-h.md), [Window](autodocs-2.0/includes-intuition-intuition-h.md), [Requester](autodocs-2.0/includes-intuition-intuition-h.md), TagList )
    D0                        A0      A1      A2         A3

    ULONG SetGadgetAttrsA( struct [Gadget](autodocs-2.0/includes-intuition-intuition-h.md) *, struct [Window](autodocs-2.0/includes-intuition-intuition-h.md) *,
            struct [Requester](autodocs-2.0/includes-intuition-intuition-h.md) *, struct [TagItem](autodocs-2.0/includes-utility-tagitem-h.md) * );

    result = SetGadgetAttrs( [Gadget](autodocs-2.0/includes-intuition-intuition-h.md), [Window](autodocs-2.0/includes-intuition-intuition-h.md), [Requester](autodocs-2.0/includes-intuition-intuition-h.md), Tag1, ...)

    ULONG SetGadgetAttrs( struct [Gadget](autodocs-2.0/includes-intuition-intuition-h.md) *, struct [Window](autodocs-2.0/includes-intuition-intuition-h.md) *,
            struct [Requester](autodocs-2.0/includes-intuition-intuition-h.md) *, ULONG, ... );
```
FUNCTION

```c
    Same as SetAttrs(), but provides context information and
    arbitration for classes which implement custom Intuition gadgets.

    You should use this function for boopsi gadget objects which have
    already been added to a requester or a window, or for "models" which
    propagate information to gadget already added.

    Typically, the gadgets will refresh their visuals to reflect
    changes to visible attributes, such as the value of a slider,
    the text in a string-type gadget, the selected state of a button.

    You can use this as a replacement for SetAttrs(), too, if you
    specify NULL for the 'Window' and 'Requester' parameters.
```
INPUTS

```c
    [Gadget](autodocs-2.0/includes-intuition-intuition-h.md) = abstract pointer to a boopsi gadget
    [Window](autodocs-2.0/includes-intuition-intuition-h.md) = window gadget has been added to using [AddGList()](autodocs-2.0/intuition-library-addglist.md) or
             [AddGadget()](autodocs-2.0/intuition-library-addgadget.md)
    [Requester](autodocs-2.0/includes-intuition-intuition-h.md) = for REQGADGETs, requester containing the gadget
    TagList = array of [TagItem](autodocs-2.0/includes-utility-tagitem-h.md) structures with attribute/value pairs.
```
RESULT

    The object does whatever it wants with the attributes you provide,
    which might include updating its gadget visuals.

    The return value tends to be non-zero if the changes would require
    refreshing gadget imagery, if the object is a gadget.
NOTES

```c
    This function invokes the OM_SET method with a [GadgetInfo](autodocs-2.0/includes-intuition-cghooks-h.md)
    derived from the 'Window' and 'Requester' pointers.
```
BUGS

    There should be more arbitration between this function and
    the calls that Intuition's input task will make to the
    gadgets.  In the meantime, this function, input processing,
    and refreshing must be mutually re-entrant.
SEE ALSO

```c
    [NewObject()](autodocs-2.0/intuition-library-newobject.md), [DisposeObject()](autodocs-2.0/intuition-library-disposeobject.md), [GetAttr()](autodocs-2.0/intuition-library-getattr.md), [MakeClass()](autodocs-2.0/intuition-library-makeclass.md),
    Document "Basic Object-Oriented Programming System for Intuition"
    and the "boopsi Class Reference" document.
```

---

## See Also

- [AddGList — intuition.library](../autodocs/intuition.library.md#addglist)
- [AddGadget — intuition.library](../autodocs/intuition.library.md#addgadget)
- [DisposeObject — intuition.library](../autodocs/intuition.library.md#disposeobject)
- [GetAttr — intuition.library](../autodocs/intuition.library.md#getattr)
- [MakeClass — intuition.library](../autodocs/intuition.library.md#makeclass)
- [NewObject — intuition.library](../autodocs/intuition.library.md#newobject)
- [SetGadgetAttrsA — intuition.library](../autodocs/intuition.library.md#setgadgetattrsa)
