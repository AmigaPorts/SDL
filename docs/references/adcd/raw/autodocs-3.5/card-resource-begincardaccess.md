# card.resource/BeginCardAccess



   NAME
	BeginCardAccess -- Called before you begin credit-card memory access

   SYNOPSIS
	result=BeginCardAccess( handle )
	d0			a1

	[BOOL](../Includes_and_Autodocs_3._guide/node0654.html#line73) BeginCardAccess( struct [CardHandle](../Includes_and_Autodocs_3._guide/node05E2.html#line29) * );

   FUNCTION
	This function should be called before you begin access
	to credit-card memory.

	Its effect will depend on the type of Amiga machine your
	code happens to be running on.  On some machines it
	will cause an access light to be turned ON.

   INPUTS
	handle - Same handle as that used when [OwnCard()](../Includes_and_Autodocs_3._guide/node009D.html) was called.

   RETURNS
	TRUE if you are still the owner of the credit-card, and
	memory access is permitted.  FALSE if you are no longer
	the owner of the credit-card (usually indicating that
	the card was removed).

   NOTES
	This function may be called from within a task, or from a level 1
	or level 2 interrupt.

	It is highly recommended that you call this function
	before accessing credit-card memory, as well as checking
	the return value.  If it is a return value of FALSE, you
	should stop accessing credit-card memory.

   SEE ALSO
	[OwnCard()](../Includes_and_Autodocs_3._guide/node009D.html), [EndCardAccess()](../Includes_and_Autodocs_3._guide/node009A.html)

