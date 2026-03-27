# card.resource/CardForceChange



   NAME
	CardForceChange -- Force a card change.

   SYNOPSIS
	success = CardForceChange( VOID )
	d0

	[BOOL](../Includes_and_Autodocs_3._guide/node0654.html#line73) CardForceChange( VOID );

   FUNCTION
	This function is not intended for general use.  Its
	purpose is to force a credit-card change as if
	the user had removed, or inserted a card.

	This function is intended to be used by a utility program
	which needs to force the current card owner to release
	ownership of the card, thereby allowing the utility an
	opportunity to own the credit-card.

   RESULT
	TRUE if the function succeeded, FALSE if card change is
	not allowed.  This function will generally succeed, unless
	someone is using the card in reset remove mode at the time
	this function is called.

   NOTES
	This function should only be called from a task.

   SEE ALSO

