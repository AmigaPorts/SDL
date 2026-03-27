# realtime.library/ExternalSync



   NAME
	ExternalSync -- provide external source clock for a player's
			conductor. (V37)

   SYNOPSIS
	result = ExternalSync(player, minTime, maxTime);
	D0		      A0      D0       D1

	[BOOL](../Includes_and_Autodocs_3._guide/node0654.html#line73) ExternalSync(struct [Player](../Includes_and_Autodocs_3._guide/node05F0.html#line105) *, [LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39), LONG);

   FUNCTION
	Allows external applications to constrain conductor time between
	minTime and maxTime, with the restraint that time can never run
	backwards. Does nothing if the given player is not the
	current External Sync source.

   INPUTS
	player - player referencing the conductor to change
	minTime, maxTime - time constraints

   RESULTS
	result - TRUE if everything went OK, FALSE if the player is not the
		 current sync source or there is no conductor for the player.

