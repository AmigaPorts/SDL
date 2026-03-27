---
title: datatypes.library/DoAsyncLayout
manual: autodocs-3.5
chapter: autodocs-3.5
section: datatypes-library-doasynclayout
functions: []
libraries: []
---

# datatypes.library/DoAsyncLayout

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	DoAsyncLayout - Call the DTM_ASYNCLAYOUT method on a separate process.
```c
                                                               (V39)

    SYNOPSIS
```
	retval = DoAsyncLayout (object, gpl);
	d0			a0	a1

	ULONG DoAsyncLayout (Object *, struct [gpLayout](autodocs-3.5/include-intuition-gadgetclass-h.md) *);

    FUNCTION
	This function is used to asyncronously perform the object's
	DTM_ASYNCLAYOUT method.  This is used to offload the layout method
	from input.device.

	The DTM_ASYNCLAYOUT method must exit when SIGBREAKF_CTRL_C signal
	is set.   This indicates that the data has become obsolete and
	the DTM_ASYNCLAYOUT method will be called again.

    INPUTS
	object - Pointer to the data types object.
	gpl - Pointer to a [gpLayout](autodocs-3.5/include-intuition-gadgetclass-h.md) message.


    RETURNS

    SEE ALSO
