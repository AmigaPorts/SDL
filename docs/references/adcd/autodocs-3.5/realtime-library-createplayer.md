---
title: realtime.library/CreatePlayer
manual: autodocs-3.5
chapter: autodocs-3.5
section: realtime-library-createplayer
functions: []
libraries: []
---

# realtime.library/CreatePlayer

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	CreatePlayerA -- create a player and link it to a conductor. (V37)
	CreatePlayer -- varargs stub for CreatePlayerA(). (V37)

   SYNOPSIS
	player = CreatePlayerA(tagList);
	D0                     A0

	struct [Player](autodocs-3.5/include-libraries-realtime-h.md) *CreatePlayerA(struct [TagItem](autodocs-3.5/include-utility-tagitem-h.md) *);

	player = CreatePlayer(firstTag, ...);

	struct [Player](autodocs-3.5/include-libraries-realtime-h.md) *CreatePlayer(Tag, ...);

   FUNCTION
	Creates a player structure with the desired attributes.

   INPUTS
	tagList - pointer to an array of tags providing optional extra
		  parameters, or NULL

   TAGS
	PLAYER_Name (STRPTR) - name of the player (generally the
			application's name). Default is no name. (V37)

	PLAYER_Hook (struct [Hook](autodocs-3.5/include-utility-hooks-h.md) *) - function to call when time changes
			occur. Default is no function. The [Hook](autodocs-3.5/include-utility-hooks-h.md) is called
			with:

				A0 - address of [Hook](autodocs-3.5/include-utility-hooks-h.md) structure
				A1 - message, currently [pmTime](autodocs-3.5/include-libraries-realtime-h.md) or [pmState](autodocs-3.5/include-libraries-realtime-h.md)
		                A2 - address of [Player](autodocs-3.5/include-libraries-realtime-h.md) structure

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

	PLAYER_AlarmSigTask (struct [Task](autodocs-3.5/include-exec-tasks-h.md) *) - task to signal on notify or
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
	player - a pointer to a [Player](autodocs-3.5/include-libraries-realtime-h.md) structure on success or NULL on
		 failure. When NULL is returned, an error code can be returned
		 in the longword variable pointed to by the optional
		 PLAYER_ErrorCode tag.

   SEE ALSO
	[DeletePlayer()](autodocs-3.5/realtime-library-deleteplayer.md), GetPlayerAttrs(), [SetPlayerAttrs()](autodocs-3.5/realtime-library-setplayerattrs.md)

