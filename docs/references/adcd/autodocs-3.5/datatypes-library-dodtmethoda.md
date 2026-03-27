---
title: datatypes.library/DoDTMethodA
manual: autodocs-3.5
chapter: autodocs-3.5
section: datatypes-library-dodtmethoda
functions: []
libraries: []
---

# datatypes.library/DoDTMethodA

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	DoDTMethodA - Do a datatypes method.                    (V39)

    SYNOPSIS
	retval = DoDTMethodA (o, win, req, msg);
	d0		      a0 a1   a2   a3

	ULONG DoDTMethodA (Object *, struct [Window](autodocs-3.5/include-intuition-intuition-h.md) *,
			   struct [Requester](autodocs-3.5/include-intuition-intuition-h.md) *, Msg);

	retval = DoDTMethod (o, win, req, data, ...);

	ULONG DoDTMethod (Object *, struct [Window](autodocs-3.5/include-intuition-intuition-h.md) *,
			  struct [Requester](autodocs-3.5/include-intuition-intuition-h.md) *, ULONG, ...);

    FUNCTION
	This function is used to perform a datatypes method.

    INPUTS
	o - Pointer to an object as returned by [NewDTObjectA()](autodocs-3.5/datatypes-library-newdtobjecta.md).

	win - [Window](autodocs-3.5/include-intuition-intuition-h.md) that the object is attached to.

	req - [Requester](autodocs-3.5/include-intuition-intuition-h.md) that the object is attached to.

	msg - The message to send to the object.

    RETURNS
	Returns the value returned by the method.

    SEE ALSO
	intuition.library/DoGadgetMethod()

