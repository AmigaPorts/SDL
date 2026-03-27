# card.resource/EndCardAccess



   NAME
	EndCardAccess -- Called at the end of credit-card memory access

   SYNOPSIS
	result=EndCardAccess( handle )
	d0			a1

	ULONG EndCardAccess( struct [CardHandle](../Includes_and_Autodocs_3._guide/node05E2.html#line29) * );

   FUNCTION
	This function should be called when you are done accessing
	credit-card memory.

	Its effect will depend on the type of Amiga machine your
	code happens to be running on.  On some machines it
	will cause an access light to be turned OFF in approximately
	1/2 second.

	On machines which support an access light, the light will
	automatically be turned off when you call [ReleaseCard()](../Includes_and_Autodocs_3._guide/node009F.html).

   INPUTS
	handle - Same handle as that used when [OwnCard()](../Includes_and_Autodocs_3._guide/node009D.html) was called.

   RETURNS
	TRUE if you are still the owner of the credit-card.  FALSE
	if you are no longer the owner of the credit-card (usually
	indicating the card was removed).

   NOTES
	This function may be called from within a task, or from a level 1
	or level 2 interrupt.

	It is highly recommended that you call this function
	after accessing credit-card memory, as well as checking
	the return value.  If it is a return value of FALSE, you
	should stop accessing credit-card memory, and conclude
	that the card was removed before this function was called.

	On some machines it is possible that the credit-card will be
	removed before you receive the removed interrupt.

   SEE ALSO
	[OwnCard()](../Includes_and_Autodocs_3._guide/node009D.html), [ReleaseCard()](../Includes_and_Autodocs_3._guide/node009F.html), [BeginCardAccess()](../Includes_and_Autodocs_3._guide/node008F.html)

