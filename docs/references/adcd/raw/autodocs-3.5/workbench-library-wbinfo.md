# workbench.library/WBInfo



   NAME
	WBInfo - Bring up the Information requester                     (V39)

   SYNOPSIS
	worked = WBInfo(lock, name, screen)
	d0              a0    a1    a2

	ULONG WBInfo(BPTR, [STRPTR](../Includes_and_Autodocs_3._guide/node0654.html#line57), struct [Screen](../Includes_and_Autodocs_3._guide/node0602.html#line132) *);

   FUNCTION
	This is the LVO that Workbench calls to bring up the Icon Information
	requester.  External applications may also call this requester.
	In addition, if someone were to wish to replace this requester
	with another one, they could do so via a [SetFunction](../Includes_and_Autodocs_3._guide/node0238.html).

   INPUTS
	lock   - A lock on the parent directory
	name   - The name of the icon contained within above directory
	screen - A screen pointer on which the requester is to show up

   RESULTS
	worked - Returns TRUE if the requester came up, FALSE if it did not.

   NOTE
	Note that this LVO may be called many times by different tasks
	before other calls return.  Thus, the code must be 100% re-entrant.

   SEE ALSO
	icon.library

