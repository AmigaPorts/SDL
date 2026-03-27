---
title: intuition.library/ReleaseGIRPort
manual: autodocs-3.5
chapter: autodocs-3.5
section: intuition-library-releasegirport-2
functions: [ObtainGIRPort]
libraries: [intuition.library]
---

# intuition.library/ReleaseGIRPort

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	ReleaseGIRPort -- Release a custom gadget [RastPort](autodocs-3.5/include-graphics-rastport-h.md). (V36)

    SYNOPSIS
	ReleaseGIRPort( RPort )
			A0

	VOID ReleaseGIRPort( struct [RastPort](autodocs-3.5/include-graphics-rastport-h.md) * );

    FUNCTION
	The corresponding function to [ObtainGIRPort()](autodocs-3.5/intuition-library-obtaingirport-2.md), it releases
	arbitration used by Intuition for gadget RastPorts.

    INPUTS
	Pointer to the [RastPort](autodocs-3.5/include-graphics-rastport-h.md) returned by [ObtainGIRPort()](autodocs-3.5/intuition-library-obtaingirport-2.md).
	This pointer can be NULL, in which case nothing happens.

    RESULT
	None

    BUGS

    SEE ALSO
	[ObtainGIRPort()](autodocs-3.5/intuition-library-obtaingirport-2.md), [Custom](autodocs-3.5/include-hardware-custom-h.md) [Gadget](autodocs-3.5/include-intuition-intuition-h.md) documentation

---

## See Also

- [ObtainGIRPort — intuition.library](../autodocs/intuition.library.md#obtaingirport)
