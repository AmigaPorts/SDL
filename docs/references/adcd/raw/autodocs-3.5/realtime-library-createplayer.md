# realtime.library/CreatePlayer



   NAME
	CreatePlayerA -- create a player and link it to a conductor. (V37)
	CreatePlayer -- varargs stub for CreatePlayerA(). (V37)

   SYNOPSIS
	player = CreatePlayerA(tagList);
	D0                     A0

	struct [Player](../Includes_and_Autodocs_3._guide/node05F0.html#line105) *CreatePlayerA(struct [TagItem](../Includes_and_Autodocs_3._guide/node064C.html#line31) *);

	player = CreatePlayer(firstTag, ...);

	struct [Player](../Includes_and_Autodocs_3._guide/node05F0.html#line105) *CreatePlayer(Tag, ...);

   FUNCTION
	Creates a player structure with the desired attributes.

   INPUTS
	tagList - pointer to an array of tags providing optional extra
		  parameters, or NULL

   TAGS
	PLAYER_Name (STRPTR) - name of the player (generally the
			application's name). Default is no name. (V37)

	PLAYER_Hook (struct [Hook](../Includes_and_Autodocs_3._guide/node0617.html#line27) *) - function to call when time changes
			occur. Default is no function. The [Hook](../Includes_and_Autodocs_3._guide/node0617.html#line27) is called
			with:

				A0 - address of [Hook](../Includes_and_Autodocs_3._guide/node0617.html#line27) structure
				A1 - message, currently [pmTime](../Includes_and_Autodocs_3._guide/node05F0.html#line166) or [pmState](../Includes_and_Autodocs_3._guide/node05F0.html#line173)
		                A2 - address of [Player](../Includes_and_Autodocs_3._guide/node05F0.html#line105) structure

			Note that your hook function is not necessarily called
			TICK_FREQ times per second. This is the maximum number
			of times it can be called. (V37)

	PLAYER_Priority (BYTE) - priority for the player, from -128 to +127.
			Default is 0. (V37)

	PLAYER_Conductor (STRPTR) - name of the conductor to link with. If
			this conductor doesn't exist, it is created
			automatically. If ~0 is passed, creates a private
			conductor. (V37)

	PLAYER_Ready (BOOL) - set/clear the "ready" flag. Default is FALSE.
			(V37)

	PLAYER_AlarmTime (LONG) - sets this player's alarm time, and the
			PLAYERF_ALARMSET flag. (V37)

	PLAYER_Alarm (BOOL) - if TRUE sets the PLAYERF_ALARMSET flag, FALSE
			clears the flag. Default is FALSE. (V37)

	PLAYER_AlarmSigTask (struct [Task](../Includes_and_Autodocs_3._guide/node064B.html#line23) *) - task to signal on notify or
			alarm. Default is no task. Having no task automatically
			forces the PLAYERF_ALARMSET flag off. (V37)

	PLAYER_AlarmSigBit (BYTE) - signal bit to use on alarm or -1 to
			disable. Default is -1. Having a signal bit of -1
			automatically forces the PLAYERF_ALARMSET flag
			off. (V37)

	PLAYER_Quiet (BOOL) - when TRUE, this player is ignored. Mainly
			used by external sync applications. Default is FALSE.
			(V37)

	PLAYER_UserData (VOID *) - sets the player's UserData value.
			Default is NULL. (V37)

	PLAYER_ID (UWORD) - sets the player's ID value. Default is 0. (V37)

	PLAYER_Conducted (BOOL) - if TRUE sets the PLAYERF_CONDUCTED flag,
			FALSE clears the flag. Default is FALSE. (V37)

	PLAYER_ExtSync (BOOL) - if TRUE, attempts to become external sync
			source. (V37)

	PLAYER_ErrorCode (LONG *) - optional pointer to a longword which
			will receive an error code whenever this function
			fails. Possible error values currently include:
			  RTE_NOMEMORY - memory allocation failed
			  RTE_NOTIMER  - timer (CIA) allocation failed

   RESULTS
	player - a pointer to a [Player](../Includes_and_Autodocs_3._guide/node05F0.html#line105) structure on success or NULL on
		 failure. When NULL is returned, an error code can be returned
		 in the longword variable pointed to by the optional
		 PLAYER_ErrorCode tag.

   SEE ALSO
	[DeletePlayer()](../Includes_and_Autodocs_3._guide/node0534.html), GetPlayerAttrs(), [SetPlayerAttrs()](../Includes_and_Autodocs_3._guide/node053B.html)

