---
title: card.resource/OwnCard
manual: autodocs-3.5
chapter: autodocs-3.5
section: card-resource-owncard
functions: []
libraries: []
---

# card.resource/OwnCard

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	OwnCard -- Own credit card registers, and memory

   SYNOPSIS
	return = OwnCard( handle )
	d0		a1

	struct [CardHandle](autodocs-3.5/include-resources-card-h.md) *OwnCard( struct [CardHandle](autodocs-3.5/include-resources-card-h.md) * );

   FUNCTION
	This function is used to obtain immediate, or deferred
	ownership of a credit-card in the credit-card slot.

	Typically an EXEC STYLE DEVICE will be written to interface
	between an application, and a credit card in the slot.  While
	applications, and libraries can attempt to own a credit-card
	in the card slot, the rest of this documentation assumes a
	device interface will be used.

	Because credit-cards can be inserted, or removed by the user at
	any time (otherwise known as HOT-INSERTION, and HOT-REMOVAL),
	the card.resource provides devices with a protocol which
	lets many devices bid for ownership of a newly inserted card.

	In general, devices should support HOT-REMOVAL, however there
	are legitimate cases where HOT-REMOVAL is not practical.  For
	these cases this function allows you to own the resource using
	the CARDB_RESETREMOVE flag.  If the card is removed before your
	device calls [ReleaseCard()](autodocs-3.5/card-resource-releasecard.md), the machine will [RESET](autodocs-3.5/sad-reset.md).

   INPUTS
	handle - pointer to a [CardHandle](autodocs-3.5/include-resources-card-h.md) structure.

		struct [CardHandle](autodocs-3.5/include-resources-card-h.md) {
		struct [Node](autodocs-3.5/include-exec-nodes-h.md) 		 cah_CardNode;
		struct [Interrupt](autodocs-3.5/include-exec-interrupts-h.md)	*cah_CardRemoved;
		struct [Interrupt](autodocs-3.5/include-exec-interrupts-h.md)	*cah_CardInserted;
		struct [Interrupt](autodocs-3.5/include-exec-interrupts-h.md)	*cah_CardStatus;
		[UBYTE](autodocs-3.5/include-exec-types-h.md)			 cah_CardFlags;
		};

	The following fields in the structure must be filled
	in by the application before calling OwnCard() -

	cah_CardNode.ln_Pri -

		See table below.  The [Node](autodocs-3.5/include-exec-nodes-h.md) field is used by the resource to
		add your handle to a sorted list of [CardHandle](autodocs-3.5/include-resources-card-h.md) structures.
		This list is used by the resource to notify devices when the
		device owns the credit-card.

		Your device will only be notified (at most) one time
		per card insertion, and perhaps less often if some
		higher priority device on the notification list retains
		ownership of a card in the slot.

	Priority	Comments
	--------------------------------------------------
		>= 21	Reserved for future use

		10-20	To be used by third party devices (e.g.,
			I/O CARD manufacturers) which look for
			specific card tuples to identify credit-cards.

		01-19	Reserved for future use

		00	To be used by general purpose devices which
			have loose card specification requirements.

		<= -1	Reserved for future use


	cah_CardNode.ln_Type -

		Must be set to 0 for now.  This field may be used in the
		future to identify an extended [CardHandle](autodocs-3.5/include-resources-card-h.md) structure.

	cah_CardNode.ln_Name -

		Must be initialized to NULL, or name of device which owns
		this structure.

	cah_CardRemoved -

		Pointer to an initialized interrupt structure.  Only the
		is_Data, and is_Code fields need to be initialized.  This
		is the interrupt code which will be called when a credit-card
		which your device owns is removed.  Once you receive this
		interrupt, all credit-card interface control registers are
		reset (e.g., programming voltage, access speed, etc.), and
		you should stop accessing the card as soon as possible.

		Because your code is called on interrupt time, you
		should do the least amount possible, and use little
		stack space.

		This pointer can be NULL if you have asked for reset
		on card-removal, and you never turn reset off.

	cah_ CardInserted -

		Pointer to an initialized interrupt structure.  Only the
		is_Data, and is_Code fields need to be initialized.  This
		is the code which will be called when your [CardHandle](autodocs-3.5/include-resources-card-h.md) owns
		the credit-card in the slot.

		Note that your code may be called on the context of
		an interrupt, or a task in FORBID, therefore you should
		do the least amount possible, and use little stack space.

		Note that it is possible to receive a card removed
		interrupt immediately before you receive this interrupt if
		the card is removed while your CardInserted interrupt
		is being called.

		Your device owns the credit-card until the card is manually
		removed by the user, or you release the card by calling
		[ReleaseCard()](autodocs-3.5/card-resource-releasecard.md).

		Your device should examine the card in the slot (e.g., look
		for specific tuples), and decide if the card is of a type your
		device understands.

		If not, release ownership of the card by calling
		[ReleaseCard()](autodocs-3.5/card-resource-releasecard.md) so that other devices will be given a chance to
		examine the current card in the credit-card slot.

	cah_CardStatus -

		Pointer to an initialized interrupt structure.  Only the
		is_Data, and is_Code fields need to be initialized.

		Note that your code will be called on the context of
		an interrupt, therefore you should do the least
		amount possible, and use little stack space.

		Note that it is possible to receive a card removed
		interrupt immediately before you receive this interrupt
		if the card is removed during this interrupt.

		If this pointer is NULL, you will not receive card status
		change interrupts.

		Your interrupt code will be called with a mask value in
		register D0, and a pointer to your data in A1.

		The mask value in D0 can be interpreted using the same bit
		definitions returned by [ReadCardStatus()](autodocs-3.5/card-resource-readcardstatus.md).  Note that more
		than one bit may be set, and the mask only tells you what has
		changed, not the current state.

		Use [ReadCardStatus()](autodocs-3.5/card-resource-readcardstatus.md) if you need to determine the current
		state of the status bits.

		Not all status change interrupts will necessarily be
		enabled on all systems.  For example, on some systems
		BVD2/DA status change interrupts will not be enabled so
		that digital audio can occur without generating many
		interrupts.  Status change interrupts are typically meant
		to be used for monitoring BSY/IRQ, WR, and BVD1/SC.  Battery
		voltage low detection would best be done by a separate
		utility which periodically polls BVD1 & BVD2 by using the
		[ReadCardStatus()](autodocs-3.5/card-resource-readcardstatus.md) function.

		Typically the mask value in D0 MUST be returned unchanged
		on exit from your code.  The return value in D0 is then used
		to clear the source(s) of the interrupt.

		In the rare case that you need to keep a status change
		interrupt active, clear the appropriate bit(s) in D0 before
		returning via RTS.  Clear no bits other than those defined
		as valid bits for ReadCardStatus()!

		!!!NEW FOR V39!!!

		See definition of CARDB_POSTSTATUS below.

	cah_CardFlags -

		Optional flags (all other bits must be 0).

		- CARDB_RESETREMOVE means you want the machine to
		  reset if the credit-card in the slot is removed
		  while you own the credit-card.

		- CARDB_IFAVAILABLE means you only want ownership of
		  the credit-card in the slot if it is immediately
		  available.

		If it is available, your [CardHandle](autodocs-3.5/include-resources-card-h.md) structure will be added
		to a list so that you can be notified via an interrupt when
		the credit-card is removed by the user.

		If the credit-card is not immediately available (either
		because there is no credit-card in the slot, or because some
		other device owns the credit-card), your [CardHandle](autodocs-3.5/include-resources-card-h.md) structure
		will NOT be added to the notification list.

		- CARDB_DELAYOWNERSHIP means you never want a successful
		  return from OwnCard() even if the credit-card is
		  available.  Rather you will be notified of ownership
		  via your cah_CardInserted interrupt.  If you use this flag,
		  OwnCard() will always return -1.  This flag cannot be used
		  with the CARDB_IFAVAILABLE flag.

		- CARDB_POSTSTATUS is new for V39 card.resource (check
		  resource base VERSION before using).  It is meant to be
		  used by drivers which want to service the card hardware
		  AFTER the status change interrupt has been cleared on the
		  gate array.  Previously a PORTS interrupt server had
		  to be added to do this; this is somewhat more efficient, and
		  easier to use.  Your status change interrupt is first called
		  with status change bits in register D0.  You would examine
		  these bits, and set a flag(s) for the POST callback.  When
		  you return from the status change interrupt, the interrupt
		  on the gate array is cleared (based on what you return in
		  register D0), and your status change interrupt is immediately
		  called again, but this time with 0 in D0.  The value you
		  return in D0 for the POST callback case is ignored.


	ALL other fields are used by the resource, and no fields in the
	structure may be modified while the structure is in use by the
	resource.  If you need to make changes, you must remove your
	[CardHandle](autodocs-3.5/include-resources-card-h.md) (see [ReleaseCard()](autodocs-3.5/card-resource-releasecard.md)), make the changes, and then call
	OwnCard() again.

   RESULTS
	 0  - indicates success, your device owns the credit card.

	-1  - indicates that the card cannot be owned (most likely
	      because there is no card in the credit card slot).

	ptr - indicates failure.  Returns pointer to the [CardHandle](autodocs-3.5/include-resources-card-h.md)
	      structure which owns the credit card.

   NOTES
	This function should only be called from a task.

  	[CardHandle](autodocs-3.5/include-resources-card-h.md) interrupts are called with a pointer to your data
	in A1, and a pointer to your code in A5.  With the exception
	of status change interrupts, D0-D1, A0-A1, and A5-A6 may be
	treated as scratch registers.  Status change interrupts are
	also called with meaningful data in D0, and expect D0 be
	preserved upon RTS from your code.  No other registers are
	guaranteed to contain initialized data.  All other registers
	must be preserved.

    SEE ALSO
	[ReleaseCard()](autodocs-3.5/card-resource-releasecard.md), [ReadCardStatus()](autodocs-3.5/card-resource-readcardstatus.md), resources/card.i, [resources/card.h](autodocs-3.5/include-resources-card-h.md)

