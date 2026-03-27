---
title: card.resource/GetCardMap
manual: autodocs-3.5
chapter: autodocs-3.5
section: card-resource-getcardmap
functions: []
libraries: []
---

# card.resource/GetCardMap

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	GetCardMap -- Obtain pointer to [CardMemoryMap](autodocs-3.5/include-resources-card-h.md) structure

   SYNOPSIS
	pointer=GetCardMap()
	d0

	struct [CardMemoryMap](autodocs-3.5/include-resources-card-h.md) *GetCardMap( void );

   FUNCTION
	Obtain pointer to a [CardMemoryMap](autodocs-3.5/include-resources-card-h.md) structure.  The structure
	is READ only.

	Devices should never assume credit-card memory appears
	at any particular place in memory.  By using this function
	to obtain pointers to the base memory locations of the various
	credit-card memory types, your device will continue to work
	properly should credit cards appear in different memory
	locations in future hardware.

   RETURNS
	Pointer to [CardMemoryMap](autodocs-3.5/include-resources-card-h.md) structure -

		struct [CardMemoryMap](autodocs-3.5/include-resources-card-h.md) {
		[UBYTE](autodocs-3.5/include-exec-types-h.md)	*cmm_CommonMemory;
		[UBYTE](autodocs-3.5/include-exec-types-h.md)	*cmm_AttributeMemory;
		[UBYTE](autodocs-3.5/include-exec-types-h.md)	*cmm_IOMemory;
		};

	As of card.resource V39, this structure has been extended to
	include the size of these memory regions.  See card.h/card.i
	for the new fields.  If card.resource V39, use the constants
	in the [CardMemoryMap](autodocs-3.5/include-resources-card-h.md) structure rather than hard coded constants
	for memory region size.

   NOTES
	If any pointer in the structure is NULL, it means this type
	of credit-card memory is not being made available.

   SEE ALSO
	[resources/card.h](autodocs-3.5/include-resources-card-h.md), resources/card.i

