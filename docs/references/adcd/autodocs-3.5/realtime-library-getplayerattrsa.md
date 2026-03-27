---
title: realtime.library/GetPlayerAttrsA
manual: autodocs-3.5
chapter: autodocs-3.5
section: realtime-library-getplayerattrsa
functions: []
libraries: []
---

# realtime.library/GetPlayerAttrsA

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	GetPlayerAttrsA -- get the attributes of a player. (V37)
	GetPlayerAttrs -- varargs stub for GetPlayerAttrsA(). (V37)

   SYNOPSIS
	numProcessed = GetPlayerAttrsA(player, tagList);
	D0                             A0      A1

	ULONG GetPlayerAttrsA(struct [Player](autodocs-3.5/include-libraries-realtime-h.md) *, struct [TagItem](autodocs-3.5/include-utility-tagitem-h.md) *);

	numProcessed = GetPlayerAttrs(player, firstTag, ...);

	ULONG GetPlayerAttrs(struct [Player](autodocs-3.5/include-libraries-realtime-h.md) *, [Tag](autodocs-3.5/include-utility-tagitem-h.md), ...);

   FUNCTION
	Retrieves the attributes of the specified player, according to the
	attributes chosen in the tag list. For each entry in the tag list,
	ti_Tag identifies the attribute, and ti_Data is a pointer to
	the longword variable where you wish the result to be stored.

   INPUTS
	player - pointer to the player in question. May be NULL, in which case
	         this function returns 0
	tagList - pointer to [TagItem](autodocs-3.5/include-utility-tagitem-h.md) list.

   TAGS
	PLAYER_Name (STRPTR) - return the name of the player, or NULL
			if this is an unnamed player. (V37)

	PLAYER_Hook (struct [Hook](autodocs-3.5/include-utility-hooks-h.md) *) - returns a pointer to the current
			function called when time changes occur, or NULL
			if no function is currently installed. (V37)

	PLAYER_Priority (BYTE) - returns the priority for the player. (V37)

	PLAYER_Conductor (STRPTR) - returns the name of the conductor this
			player is currently linked with, or NULL if the
			player is not linked to a conductor. (V37)

	PLAYER_Ready (BOOL) - gets the state of the "ready" flag. (V37)

	PLAYER_AlarmTime (LONG) - gets the current alarm time for this
			player. (V37)

	PLAYER_Alarm (BOOL) - returns TRUE if this player's alarm is
			currently on. (V37)

	PLAYER_AlarmSigTask (struct [Task](autodocs-3.5/include-exec-tasks-h.md) *) - returns a pointer to the task to
			signal on notify or alarm, or NULL if there is no
			task to signal. (V37)

	PLAYER_AlarmSigBit (BYTE) - returns the signal bit to use on alarm or
			-1 if no signal. (V37)

	PLAYER_Quiet (BOOL) - returns TRUE if this player is currently being
			ignored. FALSE if not. (V37)

	PLAYER_UserData (VOID *) - returns the current value of this player's
			UserData. (V37)

	PLAYER_ID (UWORD) - gets the value of this player's ID. (V37)

	PLAYER_Conducted (BOOL) - returns TRUE if this player is currently
			being conducted. (V37)

	PLAYER_ExtSync (BOOL) - returns TRUE if this player is the current
			external sync source. (V37)

   RESULTS
	numProcessed - the number of attributes successfully filled in.

   SEE ALSO
	[CreatePlayer()](autodocs-3.5/realtime-library-createplayer.md), [SetPlayerAttrs()](autodocs-3.5/realtime-library-setplayerattrs.md)

