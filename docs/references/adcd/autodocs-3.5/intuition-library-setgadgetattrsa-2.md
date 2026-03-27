---
title: intuition.library/SetGadgetAttrsA
manual: autodocs-3.5
chapter: autodocs-3.5
section: intuition-library-setgadgetattrsa-2
functions: [AddGList, AddGadget, DisposeObject, GetAttr, MakeClass, NewObject, SetGadgetAttrsA]
libraries: [intuition.library]
---

# intuition.library/SetGadgetAttrsA

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	SetGadgetAttrsA -- Specify attribute values for a boopsi gadget. (V36)
	SetGadgetAttrs -- Varargs stub for SetGadgetAttrsA(). (V36)

    SYNOPSIS
	result = SetGadgetAttrsA( [Gadget](autodocs-3.5/include-intuition-intuition-h.md), [Window](autodocs-3.5/include-intuition-intuition-h.md), [Requester](autodocs-3.5/include-intuition-intuition-h.md), TagList )
	D0		          A0      A1      A2         A3

	ULONG SetGadgetAttrsA( struct [Gadget](autodocs-3.5/include-intuition-intuition-h.md) *, struct [Window](autodocs-3.5/include-intuition-intuition-h.md) *,
		struct [Requester](autodocs-3.5/include-intuition-intuition-h.md) *, struct [TagItem](autodocs-3.5/include-utility-tagitem-h.md) * );

	result = SetGadgetAttrs( [Gadget](autodocs-3.5/include-intuition-intuition-h.md), [Window](autodocs-3.5/include-intuition-intuition-h.md), [Requester](autodocs-3.5/include-intuition-intuition-h.md), Tag1, ...)

	ULONG SetGadgetAttrs( struct [Gadget](autodocs-3.5/include-intuition-intuition-h.md) *, struct [Window](autodocs-3.5/include-intuition-intuition-h.md) *,
		struct [Requester](autodocs-3.5/include-intuition-intuition-h.md) *, ULONG, ... );

    FUNCTION
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

    INPUTS
	[Gadget](autodocs-3.5/include-intuition-intuition-h.md) = abstract pointer to a boopsi gadget
	[Window](autodocs-3.5/include-intuition-intuition-h.md) = window gadget has been added to using [AddGList()](autodocs-3.5/intuition-library-addglist-2.md) or [AddGadget()](autodocs-3.5/intuition-library-addgadget-2.md)
	[Requester](autodocs-3.5/include-intuition-intuition-h.md) = for REQGADGETs, requester containing the gadget
	TagList = array of [TagItem](autodocs-3.5/include-utility-tagitem-h.md) structures with attribute/value pairs.

    RESULT
	The object does whatever it wants with the attributes you provide,
	which might include updating its gadget visuals.

	The return value tends to be non-zero if the changes would require
	refreshing gadget imagery, if the object is a gadget.

    NOTES
	This function invokes the OM_SET method with a [GadgetInfo](autodocs-3.5/include-intuition-cghooks-h.md)
	derived from the 'Window' and 'Requester' pointers.

    BUGS
	Prior to V39, this function ran with inadequate locking against
	the calls that Intuition's input task makes to the gadgets.
	To run properly prior to V39, this function, input processing,
	and and the gadget's dispatcher must be mutually re-entrant.

    SEE ALSO
	[NewObject()](autodocs-3.5/intuition-library-newobject-2.md), [DisposeObject()](autodocs-3.5/intuition-library-disposeobject-2.md), [GetAttr()](autodocs-3.5/intuition-library-getattr-2.md), [MakeClass()](autodocs-3.5/intuition-library-makeclass-2.md),
	Document "Basic Object-Oriented Programming System for Intuition"
	and the "boopsi Class Reference" document.

---

## See Also

- [AddGList — intuition.library](../autodocs/intuition.library.md#addglist)
- [AddGadget — intuition.library](../autodocs/intuition.library.md#addgadget)
- [DisposeObject — intuition.library](../autodocs/intuition.library.md#disposeobject)
- [GetAttr — intuition.library](../autodocs/intuition.library.md#getattr)
- [MakeClass — intuition.library](../autodocs/intuition.library.md#makeclass)
- [NewObject — intuition.library](../autodocs/intuition.library.md#newobject)
- [SetGadgetAttrsA — intuition.library](../autodocs/intuition.library.md#setgadgetattrsa)
