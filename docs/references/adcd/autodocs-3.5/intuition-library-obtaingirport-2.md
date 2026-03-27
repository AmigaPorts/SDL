---
title: intuition.library/ObtainGIRPort
manual: autodocs-3.5
chapter: autodocs-3.5
section: intuition-library-obtaingirport-2
functions: [ObtainGIRPort, ReleaseGIRPort]
libraries: [intuition.library]
---

# intuition.library/ObtainGIRPort

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	ObtainGIRPort -- Set up a [RastPort](autodocs-3.5/include-graphics-rastport-h.md) for a custom gadget. (V36)

    SYNOPSIS
	RPort = ObtainGIRPort( GInfo )
	D0		       A0

	struct [RastPort](autodocs-3.5/include-graphics-rastport-h.md) *ObtainGIRPort( struct [GadgetInfo](autodocs-3.5/include-intuition-cghooks-h.md) * );

    FUNCTION
	Sets up a [RastPort](autodocs-3.5/include-graphics-rastport-h.md) for use (only) by custom gadget hook routines.
	This function must be called EACH time a hook routine needing
	to perform gadget rendering is called, and must be accompanied
	by a corresponding call to [ReleaseGIRPort()](autodocs-3.5/intuition-library-releasegirport-2.md).

	Note that if a hook function passes you a [RastPort](autodocs-3.5/include-graphics-rastport-h.md) pointer,
	e.g., GM_RENDER, you needn't call ObtainGIRPort() in that case.

    INPUTS
	A pointer to a [GadgetInfo](autodocs-3.5/include-intuition-cghooks-h.md) structure, as passed to each custom
	gadget hook function.

    RESULT
	A pointer to a [RastPort](autodocs-3.5/include-graphics-rastport-h.md) that may be used for gadget rendering.
	This pointer may be NULL, in which case you should do no rendering.
	You may (optionally) pass a null return value to [ReleaseGIRPort()](autodocs-3.5/intuition-library-releasegirport-2.md).

    BUGS

    SEE ALSO
	[ReleaseGIRPort()](autodocs-3.5/intuition-library-releasegirport-2.md), [Custom](autodocs-3.5/include-hardware-custom-h.md) [Gadget](autodocs-3.5/include-intuition-intuition-h.md) documentation

---

## See Also

- [ObtainGIRPort — intuition.library](../autodocs/intuition.library.md#obtaingirport)
- [ReleaseGIRPort — intuition.library](../autodocs/intuition.library.md#releasegirport)
