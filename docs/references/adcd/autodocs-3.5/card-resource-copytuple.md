---
title: card.resource/CopyTuple
manual: autodocs-3.5
chapter: autodocs-3.5
section: card-resource-copytuple
functions: []
libraries: []
---

# card.resource/CopyTuple

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	CopyTuple -- Find/copy a credit card tuple.

   SYNOPSIS
	success = CopyTuple( [CardHandle](autodocs-3.5/include-resources-card-h.md), buffer, tuplecode, size );
	d0			a1	 a0	 d1	    d0

	[BOOL](autodocs-3.5/include-exec-types-h.md) CopyTuple( struct [CardHandle](autodocs-3.5/include-resources-card-h.md) *, [UBYTE](autodocs-3.5/include-exec-types-h.md) *, ULONG, ULONG );

   FUNCTION
	This function scans credit-card memory for a tuple, and
	if found, copies it into a supplied buffer.  The entire
	tuple (including the tuple code, and link) are copied to
	the supplied buffer.  The number of bytes copied to the
	buffer will be 2 bytes, plus the argument "size", or the
	value in the tuple LINK field (whichever is SMALLER).

	The software calling this function is responsible for
	examining the copy of the tuple (e.g., recognition of
	fields, recognition of stop bytes, etc. within the tuple).

	This function does the best job it can to find a tuple
	in attribute, or common memory.  It follows tuple chains,
	and skips odd bytes in attribute memory.

	This function monitors for credit-card removal while reading data.
	If the credit-card is removed while a byte is being read, it will
	stop searching, and return FALSE.

	This function does not protect against another task writing
	to credit-card memory while data is being read.  The device
	is responsible for single-threading reads/writes to the
	credit card as needed.

	This function can be used to find multiple tuple codes; this
	is a very rare case, so the mechanism provided for doing so is
	unusual.  See INPUTS below for more information.

	This function does not read bytes within the body of any tuples
	except for the tuple you want copied, and the basic compatibility
	tuples this function understands (see list below).

	On some machines this function may slow down memory access
	speed while reading the tuple chain.  This is done to prevent
	potential problems on slow cards.  By examining the CISTPL_DEVICE,
	and CISTPL_DEVICE_A tuples, you can determine the best possible
	memory access speed for the type of card inserted.  Because memory
	access speed may be slowed down, calls to this function should
	be single-threaded.

	The Card Information Structure must start with a CISTPL_DEVICE
	tuple stored as the first tuple in attribute memory.  If not,
	this function will search for a CISTPL_LINKTARGET tuple
	stored at byte 0 of common memory.  Therefore it is possible
	to store a CIS on cards which do not have any writeable
	attribute memory, though this may cause problems for other
	software implemented on other machines.  For example, some
	SRAM cards do not come with writeable attribute memory, and/or
	some may have OPTIONAL EEPROM memory which may not have been
	initialized by the card manufacturer.  While it could be
	argued that such cards do not conform to the PCMCIA PC Card
	Standard, such cards are cheaper, and therefore likely to be
	used.

   INPUTS
	[CardHandle](autodocs-3.5/include-resources-card-h.md) - Same handle as that used when [OwnCard()](autodocs-3.5/card-resource-owncard.md) was
	called.

	buffer - Pointer to a buffer where the tuple will be copied.

	The buffer should be at least as large as "size" + 8 (see
	use of "size" argument below).  Therefore the minimum buffer
	size is 8 bytes.  See NOTES below.

	tuplecode - The tuple code you want to search for.  This is
	a ULONG value.  The upper 16 bits should be 0, or a number between
	1-32K where a value of 0 means you want to find the first tuple
	match, a value of 1 the second, etc.  For example -

	0x41 means find the FIRST tuple equal to $41.

	((1<<16)|(0x41)) means find the SECOND tuple equal to $41.

	((2<<16)|(0x41)) means find the THIRD tuple equal to $41.

	size - The maximum number of bytes you want copied (not
	       including the tuple code, and link).  The actual number
	       of bytes copied may be less than "size" if the tuple
	       link field is less than "size".

	       A size of 0 will result in only the tuple code, and
	       link being copied to your buffer if the tuple is found.

	       If you do not care how many bytes are copied, any unsigned
	       value of 255 or greater will do.  In this case a maximum
	       of 257 bytes might be copied to your buffer (if the
	       tuple link field is the maximum of 255).

	       Other sizes are useful if you know the size of the tuple
	       you want copied, or you know there are active registers
	       stored within the tuple, and only want to copy a portion
	       of a tuple.

   RETURNS

	TRUE if the tuple was found, and copied, else FALSE.
	This function may also return false if the CIS is believed
	to be corrupt, or if the card is removed while reading the
	tuples.

   NOTES

	This function can be called multiple times (adjusting the "size"
	argument) to read a tuple of variable length, or unknown size.

	Your supplied buffered is used by this function for working
	storage - the contents of it will be modified even if this
	function fails to find the tuple you want a copy of.

	This function should NOT be used to find/copy tuples of type :

	- CISTPL_LONGLINK_A
	- CISTPL_LONGLINK_C
	- CISTPL_NO_LINK
	- CISTPL_LINKTARGET
	- CISTPL_NULL
	- CISTPL_END

	These tuples are automatically handled for you by this function.

   SEE ALSO
	[OwnCard()](autodocs-3.5/card-resource-owncard.md)

