# card.resource/ReleaseCard



   NAME
	ReleaseCard -- Release ownership of credit card

   SYNOPSIS
	ReleaseCard( handle, flags )
		     a1	     d0

	void ReleaseCard( struct [CardHandle](../Includes_and_Autodocs_3._guide/node05E2.html#line29) *, ULONG );

   FUNCTION
	This function releases ownership of the credit card in the
	slot.

	The access light (if any) is automatically turned off
	(if it was turned on) when you release ownership of
	a card you owned, and all credit-card control registers
	are reset to their default state.

	You must call this function if -

	You own the credit-card, and want to release it so that
	other devices on the notification list will have a chance
	to examine the credit-card in the card slot.

	You took a Card Removed interrupt while you owned the
	credit-card.  If so, you MUST call this function, else
	no other task will be notified of newly inserted cards.  On
	some machines the credit-card interface hardware may also
	be left disabled until you respond to the card removed interrupt
	by calling this function.

	You want to remove yourself from the notification list (see
	optional flags below).

   INPUTS
	handle - Same handle as that used when [OwnCard()](../Includes_and_Autodocs_3._guide/node009D.html) was called.

	flags - Optional flags.

		- CARDB_REMOVEHANDLE means you want remove your
		[CardHandle](../Includes_and_Autodocs_3._guide/node05E2.html#line29) structure from the notification list
		whether or not you currently own the credit-card
		in the card slot.  The node structure in your
		[CardHandle](../Includes_and_Autodocs_3._guide/node05E2.html#line29) will be removed from the notification
		list, and ownership will be released if you were
		the owner of the card.

   NOTES
	This function should only be called from a task.

    SEE ALSO
	[OwnCard()](../Includes_and_Autodocs_3._guide/node009D.html), resources/card.i, [resources/card.h](../Includes_and_Autodocs_3._guide/node05E2.html)

