# realtime.library/DeletePlayer



   NAME
	DeletePlayer -- delete a player. (V37)

   SYNOPSIS
	DeletePlayer(player);
	             A0

	VOID DeletePlayer(struct [Player](../Includes_and_Autodocs_3._guide/node05F0.html#line105) *);

   FUNCTION
	Deletes the specified player.

	Flushes the conductor that the player was connected to if this
	is the last player connected to that conductor.

   INPUTS
	player - [Player](../Includes_and_Autodocs_3._guide/node05F0.html#line105) structure to delete, as allocated by
		 [CreatePlayer()](../Includes_and_Autodocs_3._guide/node0533.html). May be NULL, in which case this function
		 does nothing.

   SEE ALSO
	[CreatePlayer()](../Includes_and_Autodocs_3._guide/node0533.html)

