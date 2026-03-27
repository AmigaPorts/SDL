# input.device/PeekQualifier



   NAME
	PeekQualifier -- get the input device's current qualifiers (V36)

   SYNOPSIS
	qualifier = PeekQualifier()
	d0

	[UWORD](../Includes_and_Autodocs_3._guide/node0654.html#line43) PeekQualifier( VOID );

   FUNCTION
	This function takes a snapshot of what the input device thinks
	the current qualifiers are.

   RESULTS
	qualifier - a word with the following bits set according to
	    what the input device knows their state to be:
		IEQUALIFIER_LSHIFT, IEQUALIFIER_RSHIFT,
		IEQUALIFIER_CAPSLOCK, IEQUALIFIER_CONTROL,
		IEQUALIFIER_LALT, IEQUALIFIER_RALT,
		IEQUALIFIER_LCOMMAND, IEQUALIFIER_RCOMMAND,
		IEQUALIFIER_LEFTBUTTON, IEQUALIFIER_RBUTTON,
		IEQUALIFIER_MIDBUTTON

   NOTE
	This function is new for V36.

   SEE ALSO
	[devices/inputevent.h](../Includes_and_Autodocs_3._guide/node061A.html)

