---
title: intuition.library/InitRequester
manual: autodocs-3.5
chapter: autodocs-3.5
section: intuition-library-initrequester-2
functions: []
libraries: []
---

# intuition.library/InitRequester

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	InitRequester -- Initialize a [Requester](autodocs-3.5/include-intuition-intuition-h.md) structure.

    SYNOPSIS
	InitRequester( [Requester](autodocs-3.5/include-intuition-intuition-h.md) )
		       A0

	VOID InitRequester( struct [Requester](autodocs-3.5/include-intuition-intuition-h.md) * );

    FUNCTION
	Initializes a requester for general use.  After calling InitRequester,
	you need fill in only those [Requester](autodocs-3.5/include-intuition-intuition-h.md) values that fit your needs.
	The other values are set to NULL--or zero--states.

	Note that the example in the early versions of the Intuition
	Reference Manual is flawed because the [Requester](autodocs-3.5/include-intuition-intuition-h.md) structure is
	initialized BEFORE InitRequester is called.  Be sure to
	perform your initialization AFTER calling InitRequester.

    INPUTS
	[Requester](autodocs-3.5/include-intuition-intuition-h.md) = a pointer to a [Requester](autodocs-3.5/include-intuition-intuition-h.md) structure

    RESULT
	None

    BUGS
	Since the publication of the first Intuition Manual to this
	day, most people haven't used this function, and for
	compatibility reasons, we'll never be able to assume that
	they do.  Thus, this function is useless.


    SEE ALSO
