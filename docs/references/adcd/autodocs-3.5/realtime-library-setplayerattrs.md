---
title: realtime.library/SetPlayerAttrs
manual: autodocs-3.5
chapter: autodocs-3.5
section: realtime-library-setplayerattrs
functions: []
libraries: []
---

# realtime.library/SetPlayerAttrs

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	SetPlayerAttrsA -- set the attributes of a player. (V37)
	SetPlayerAttrs -- varargs stub for SetPlayerAttrsA(). (V37)

   SYNOPSIS
	result = SetPlayerAttrsA(player, tagList);
	D0                       A0      A1

	[BOOL](autodocs-3.5/include-exec-types-h.md) SetPlayerAttrsA(struct [Player](autodocs-3.5/include-libraries-realtime-h.md) *, struct [TagItem](autodocs-3.5/include-utility-tagitem-h.md) *);

	result = SetPlayerAttrs(player,firstTag, ...);

	[BOOL](autodocs-3.5/include-exec-types-h.md) SetPlayerAttrs(struct [Player](autodocs-3.5/include-libraries-realtime-h.md) *, [Tag](autodocs-3.5/include-utility-tagitem-h.md), ...);

   FUNCTION
	Changes the attributes of the specified player, according to the
	attributes chosen in the tag list. If an attribute is not provided
	in the tag list, its value remains unchanged.

   INPUTS
	player - player to set the attributes of.
	tagList - pointer to an array of tags specifying the attributes
		  to change, or NULL.

   TAGS
	PLAYER_Name (STRPTR) - name of the player (generally the
			application's name). (V37)

	PLAYER_Hook (struct [Hook](autodocs-3.5/include-utility-hooks-h.md) *) - function to call when time changes
			occur. The [Hook](autodocs-3.5/include-utility-hooks-h.md) is called
			with:

				A0 - address of [Hook](autodocs-3.5/include-utility-hooks-h.md) structure
				A1 - message, currently [pmTime](autodocs-3.5/include-libraries-realtime-h.md) or [pmState](autodocs-3.5/include-libraries-realtime-h.md)
		                A2 - address of [Player](autodocs-3.5/include-libraries-realtime-h.md) structure

			Note that your hook function is not necessarily called
			TICK_FREQ times per second. This is the maximum number
			of times it can be called. (V37)

	PLAYER_Priority (BYTE) - priority for the player, from -128 to +127.
			(V37)

	PLAYER_Conductor (STRPTR) - name of the conductor to link with. If
			NULL, delink from conductor. (V37)

	PLAYER_Ready (BOOL) - set/clear the "ready" flag. (V37)

	PLAYER_AlarmTime (LONG) - sets this player's alarm time, and the
			PLAYERF_ALARMSET flag. (V37)

	PLAYER_Alarm (BOOL) - if TRUE sets the PLAYERF_ALARMSET flag, FALSE
			clears the flag. (V37)

	PLAYER_AlarmSigTask (struct [Task](autodocs-3.5/include-exec-tasks-h.md) *) - task to signal on notify or
			alarm. Setting this to NULL automatically clears the
			PLAYERF_ALARMSET flag. (V37)

	PLAYER_AlarmSigBit (BYTE) - signal bit to use on alarm or -1 to
			disable. Setting this to -1 automatically clears the
			PLAYERF_ALARMSET. (V37)

	PLAYER_Quiet (BOOL) - when TRUE, this player is ignored. Mainly
			used by external sync applications. (V37)

	PLAYER_UserData (VOID *) - sets this player's UserData value. (V37)

	PLAYER_ID (UWORD) - sets this player's ID value. (V37)

	PLAYER_Conducted (BOOL) - if TRUE sets the PLAYERF_CONDUCTED flag,
			FALSE clears the flag. (V37)

	PLAYER_ExtSync (BOOL) - if TRUE, attempt to become external sync
			source. If FALSE, release external sync. (V37)

	PLAYER_ErrorCode (LONG *) - optional pointer to a longword which
			will receive an error code whenever this function
			fails. Possible error values currently include:
			  RTE_NOMEM   - memory allocation failed
			  RTE_NOTIMER - timer (CIA) allocation failed

   RESULTS
	result - TRUE if all went well, FALSE if there was an error.
		 When an error occurs, an error code can be returned
		 in the longword variable pointed to by the optional
		 PLAYER_ErrorCode tag.

   SEE ALSO
	[CreatePlayer()](autodocs-3.5/realtime-library-createplayer.md), [DeletePlayer()](autodocs-3.5/realtime-library-deleteplayer.md), GetPlayerAttrs()

