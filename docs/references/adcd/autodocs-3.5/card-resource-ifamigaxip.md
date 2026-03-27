---
title: card.resource/IfAmigaXIP
manual: autodocs-3.5
chapter: autodocs-3.5
section: card-resource-ifamigaxip
functions: [InitResident]
libraries: [exec.library]
---

# card.resource/IfAmigaXIP

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	IfAmigaXIP -- Check if a card is an Amiga execute-in-place card.

   SYNOPSIS
	result=IfAmigaXIP( handle )
	d0		       a2

	struct [Resident](autodocs-3.5/include-exec-resident-h.md) *IfAmigaXIP( struct [CardHandle](autodocs-3.5/include-resources-card-h.md) * );

   FUNCTION
	Check to see if a card in the slot is an Amiga execute-in-place
	card.  The Card Information Structure must have a valid
	CISTPL_AMIGAXIP tuple.

	Tuples can be treated like structures.  The format of a
	CISTPL_AMIGAXIP tuple is -


 	struct [TP_AmigaXIP](autodocs-3.5/include-resources-card-h.md) {
		[UBYTE](autodocs-3.5/include-exec-types-h.md)	TPL_CODE;
		[UBYTE](autodocs-3.5/include-exec-types-h.md)	TPL_LINK;
		[UBYTE](autodocs-3.5/include-exec-types-h.md)	TP_XIPLOC[4];
		[UBYTE](autodocs-3.5/include-exec-types-h.md)	TP_XIPFLAGS;
		[UBYTE](autodocs-3.5/include-exec-types-h.md)	TP_XIPRESRV;
	};


	The TPL_CODE field must be equal to CISTPL_AMIGAXIP (0x91).

	The TPL_LINK field must be equal to the length of the body
	of a CISTPL_AMIGAXIP tuple (0x06).

	The TP_XIPLOC array is the memory location of your ROM-TAG
	stored in little-endian order.  This value is stored as an
	"offset" into common memory as is the standard for storing 32 bit
	bit pointers in tuples.

	For example, a pointer to a ROM-TAG stored at an offset of
	0x00000200 would be stored as four bytes like so:

		0x00, 0x02, 0x00, 0x00

	Currently credit-card common memory is mapped starting at
	memory location 0x600000.  Because a ROM-TAG is used,
	it is implied that execute-in-place code can be compiled/linked
	to use absolute references.  It is believed that most developers
	will not want to have to write pc-relative code only.

	The TP_XIPFLAGS field is treated as a set of flag bits.
	See card.i/h for defined bits.  All undefined bits MUST be
	0.

	The TP_XIPRESRV field must be 0 for now.


	The system polls for cards which have a CISTPL_AMIGAXIP tuple
	at the same time that it searches for devices to boot off.
	When a card with a valid CISTPL_AMIGAXIP tuple is found, the
	system will call your ROM-TAG via Exec's [InitResident()](autodocs-3.5/exec-library-initresident-2.md) function.

	The system examines the return code from [InitResident()](autodocs-3.5/exec-library-initresident-2.md).  A
	NULL return in D0 means you are done with the card, and it can
	be removed by the user.  A successful return indicates you are
	still using the card.  Some programs (e.g., some games) may
	never return.  The only requirement is that if you do return,
	you must leave the system in a "good" state (including returning
	most of, or all the memory you allocated).  The standard
	convention for preserving registers apply.

	Note that your execute-in-place code will not be called
	a second time, unless you have returned a non-successful
	result.  In this case your execute-in-place code MUST
	assume the user can remove, and insert your card again.
	There are a variety of ways to check for re-insertion
	(e.g., search for a message port, device, library, task,
	etc., that you created).

	Note that your execute-in-place code runs in an environment
	similar to boot block games; before DOS has been initialized!

	Your execute-in-place code should NOT try to initialize DOS
	because DOS requires a suitable disk-like device be at
	the head of the expansion base mountlist to boot off.

	If you need DOS, it is possible to boot off a credit-card using
	carddisk.device.  Such cards will require a valid
	CISTPL_DEVICE tuple, and CISTPL_FORMAT tuple.  A portion
	of the card can be used for a minimal number of data blocks
	like the method described above.

	However this method is not recommended, though it is anticipated
	that some developers will have thought of, and used this
	method anyway.  If you must do this, at least use the
	[CardHandle](autodocs-3.5/include-resources-card-h.md) returned by [OwnCard()](autodocs-3.5/card-resource-owncard.md) to set hardware reset
	on removal else the machine will likely crash anyway if
	the card is removed while your execute-in-place code is running.

   RETURNS
	Pointer to a ROM-TAG on the card, or NULL indicating that:

	o The card does not meet the above requirements, or
	o The card has been removed, or
	o You are not the owner of the credit-card.

   NOTES
	This function is being made public so developers can test
	test that their execute-in-place credit-cards meet the
	requirements for an Amiga execute-in-place card.  In general
	there is no reason for devices, or applications to use this
	function.

	Amiga execute-in-place software is identified via a tuple code
	reserved for manufacturer specific use, therefore the manufacturer
	of the card may freely use the CISTPL_VERS_1, or CISTPL_VERS_2
	tuples to place identification information on the credit-card.

	No attempt has been made to make use of the MS-DOS execute-in-place
	method; it is believed that most manufacturers of Amiga
	execute-in-place software will prefer a simple, and small
	scheme for running their execute-in-place code.

   SEE ALSO
	[OwnCard()](autodocs-3.5/card-resource-owncard.md), [resources/card.h](autodocs-3.5/include-resources-card-h.md), resources/card.i

---

## See Also

- [InitResident — exec.library](../autodocs/exec.library.md#initresident)
