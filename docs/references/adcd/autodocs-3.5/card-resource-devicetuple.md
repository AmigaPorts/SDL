---
title: card.resource/DeviceTuple
manual: autodocs-3.5
chapter: autodocs-3.5
section: card-resource-devicetuple
functions: []
libraries: []
---

# card.resource/DeviceTuple

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	DeviceTuple -- Decode a device tuple

   SYNOPSIS
	return=DeviceTuple( tuple_data, storage)
		   	    a0		a1

	ULONG DeviceTuple( [UBYTE](autodocs-3.5/include-exec-types-h.md) *, struct [DeviceTData](autodocs-3.5/include-resources-card-h.md) *);

   FUNCTION
	Extracts SIZE, TYPE, and SPEED from a device tuple (generally
	obtained with [CopyTuple()](autodocs-3.5/card-resource-copytuple.md)).

   INPUTS
	tuple_data - Pointer to a CISTPL_DEVICE tuple (generally obtained
	with [CopyTuple()](autodocs-3.5/card-resource-copytuple.md)).

	storage - Pointer to a [DeviceTData](autodocs-3.5/include-resources-card-h.md) structure in which results
	are to be stored.

	struct	[DeviceTData](autodocs-3.5/include-resources-card-h.md) {
		ULONG	dtd_DTsize;		/* Size of card (bytes)	*/
		ULONG	dtd_DTspeed;		/* Speed in nanoseconds	*/
		[UBYTE](autodocs-3.5/include-exec-types-h.md)	dtd_DTtype;		/* Type of card		*/
		[UBYTE](autodocs-3.5/include-exec-types-h.md)	dtd_DTflags;		/* Other flags		*/
	};


   RETURN
	SIZE (same as dtd_DTsize) if the [Device](autodocs-3.5/include-exec-devices-h.md) Tuple could be decoded.
	FALSE (0) if the tuple is believed to be invalid.  The tuple is
	considered to be invalid if:

		The tuple link value is 0.

		The device type/speed byte is $00, or $FF.

		The device type is DTYPE_EXTEND, which is undefined
		as of this writing.

		The extended speed byte is a value which is
		undefined as of this writing.

		The extended speed byte is extended again which is
		undefined as of this writing.

		The device Size byte is $FF.

   NOTES
	Some cards may not have a size specified in the device
	tuple.  An example would be an I/O card.  The size would be
	returned as one (1) in this case.

	You should not call this function with a partial CISTPL_DEVICE
	tuple, or the return values may be junk.

   SEE ALSO
	[CopyTuple()](autodocs-3.5/card-resource-copytuple.md), [resources/card.h](autodocs-3.5/include-resources-card-h.md), resources/card.i

