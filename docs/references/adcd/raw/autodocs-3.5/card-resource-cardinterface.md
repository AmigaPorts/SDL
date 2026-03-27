# card.resource/CardInterface



   NAME
	CardInterface -- Determine the type of card interface.

   SYNOPSIS
	return = CardInterface()
	d0

	ULONG CardInterface( void );

   FUNCTION
	This function is used to determine the type of credit-card
	(hardware) interface available.  For the most part the
	card.resource hides the hardware details from devices within its
	function calls.  However should we need to provide a work-around
	because of differences, or limitations imposed by future interface
	hardware, this function must be used to identify which interface
	is available.

   RETURN
	A ULONG value as defined in card.h/i.

   NOTES
	In general only I/O devices (e.g., a device which interfaces
	with a modem card) would need to provide work-arounds,
	or alternative code.  An example would be a change in the way
	interrupt requests from the card are handled.  Specific details
	will be provided as need in the future.  I/O devices) should abort
	properly if this function returns a value which is unknown.

	Current implementations (see card.h/i) -

	CARD_INTERFACE_AMIGA_0
	-------------------------------------------------------------

	The card slot can be configured for use as an I/O interface
	by using the [CardMiscControl()](../Includes_and_Autodocs_3._guide/node0094.html) function.

	The card slot inhibits writes to cards which do not negate
	the WP status bit.  This can be overridden by using the
	[CardMiscControl()](../Includes_and_Autodocs_3._guide/node0094.html) function.

	Changes in the interrupt request line are latched by a gate-array,
	and have to be obtained via the status change mechanism provided
	when you call the [OwnCard()](../Includes_and_Autodocs_3._guide/node009D.html) function.  The interrupt is cleared
	when you return from the status change interrupt.  A level 2
	interrupt is generated.  Usually you will want to clear the
	interrupt on the card at this time, and [Signal()](../Includes_and_Autodocs_3._guide/node023D.html) a task.  The IRQ
	line is the same as the RDY/BSY line.

	Changes in BVD1, WP, and RDY/BSY are also latched by the gate-array,
	and are obtainable via the status change mechanism provided by
	the [OwnCard()](../Includes_and_Autodocs_3._guide/node009D.html) function.  A level 2 interrupt is generated.

	Changes in BVD2 (also used for digital audio) have to be
	monitored via polling.  Generally this will cause no problem.
	Monitoring changes in BVD1 & BVD2 to monitor for low battery
	condition can be handled by a low priority tool which periodically
	checks the condition of both lines using the [ReadCardStatus()](../Includes_and_Autodocs_3._guide/node009E.html)
	function.

	As of card.resource V39 (check VERSION in resource base), the
	[CardMiscControl()](../Includes_and_Autodocs_3._guide/node0094.html) function can be used to enable/disable
	status change interrupts for changes in BVD1, BVD2, and the
	RDY/BSY status line.  Status change interrupts for WR
	(Write-protect enable/disable) are always enabled.  The default
	state of enabled/disabled status change interrupts noted above
	are unchanged, and automatically reset to the defaults when
	a card is removed, or when even a task releases ownership
	of the card.

	Some PC oriented eight (8) bit cards may require you read
	odd-byte I/O address registers at the corresponding even-byte
	address plus 64K.  There is sufficient I/O address space
	provided that exceeding I/O address space should not be a problem.

	Your code should wait at least 1 millisecond for Vpp to stabilize
	after voltage change (see [CardProgramVoltage()](../Includes_and_Autodocs_3._guide/node0095.html)).

    SEE ALSO
	[CardMiscControl()](../Includes_and_Autodocs_3._guide/node0094.html), resources/card.i, [resources/card.h](../Includes_and_Autodocs_3._guide/node05E2.html)

