# card.resource/ReadCardStatus



   NAME
	ReadCardStatus -- [Read](../Includes_and_Autodocs_3._guide/node01A0.html) credit card status register

   SYNOPSIS
	status=ReadCardStatus()
	d0

	[UBYTE](../Includes_and_Autodocs_3._guide/node0654.html#line50) ReadCardStatus( void );

   FUNCTION
	Returns current state of the credit card status register.

	See card.h/i for bit definitions.

	Note that the meaning of the returned status bits may vary
	depending on the type of card inserted in the slot, and
	mode of operation.  Interpretation of the bits is left
	up to the application.

   RETURNS
	A [UBYTE](../Includes_and_Autodocs_3._guide/node0654.html#line50) value to be interpreted as status bits.

   NOTES
	This function may be called from within a task, or from any level
	interrupt.

   SEE ALSO
	[resources/card.h](../Includes_and_Autodocs_3._guide/node05E2.html), resources/card.i

