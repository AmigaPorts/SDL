# keymap.library/SetKeyMapDefault



   NAME
	SetKeyMapDefault -- Set the current default keymap. (V36)

   SYNOPSIS
	SetKeyMapDefault(keyMap)

	void SetKeyMapDefault( struct [KeyMap](../Includes_and_Autodocs_3._guide/node0623.html#line20) * );

   FUNCTION
	A pointer to key map specified is cached by the keymap library
	for use by [MapRawKey](../Includes_and_Autodocs_3._guide/node0412.html) and [MapANSI](../Includes_and_Autodocs_3._guide/node0411.html) when a keymap is not specified.

   INPUTS
	keyMap - a pointer to a keyMap structure.  This key map must be
	    permanently allocated: it must remain in memory till the
	    machine is reset.  It is appropriate that this keyMap be a
	    node on the keymap.resource list.

   BUGS
	The keymap.h include file should be in the libraries/ or perhaps
	resources/ directory, but is in the devices/ directory for
	compatability reasons.

   SEE ALSO
	[devices/keymap.h](../Includes_and_Autodocs_3._guide/node0623.html), [keymap.library/AskKeyMapDefault()](../Includes_and_Autodocs_3._guide/node0410.html),
	console.device ...KEYMAP functions

