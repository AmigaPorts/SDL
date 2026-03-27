# keymap.library/AskKeyMapDefault



   NAME
	AskKeyMapDefault -- Ask for a pointer to the current default
	                    keymap. (V36)

   SYNOPSIS
	keyMap = AskKeyMapDefault()

	struct [KeyMap](../Includes_and_Autodocs_3._guide/node0623.html#line20) *AskKeyMapDefault( VOID );

   FUNCTION
	Return a pointer to the keymap used by the keymap library for
	[MapRawKey](../Includes_and_Autodocs_3._guide/node0412.html) and [MapANSI](../Includes_and_Autodocs_3._guide/node0411.html) when a keymap is not specified.

   RESULTS
	keyMap - a pointer to a keyMap structure.  This key map is
	    guaranteed to be permanently allocated: it will remain in
	    memory till the machine is reset.

   BUGS
	The keymap.h include file should be in the libraries/ or perhaps
	resources/ directory, but is in the devices/ directory for
	compatibility reasons.

   SEE ALSO
	[devices/keymap.h](../Includes_and_Autodocs_3._guide/node0623.html), [keymap.library/SetKeyMapDefault()](../Includes_and_Autodocs_3._guide/node0413.html),
	console.device ...KEYMAP functions

