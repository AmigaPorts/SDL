---
title: realtime.library/SetConductorState
manual: autodocs-3.5
chapter: autodocs-3.5
section: realtime-library-setconductorstate
functions: []
libraries: []
---

# realtime.library/SetConductorState

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	SetConductorState -- change the play state of a player's
			     conductor. (V37)

   SYNOPSIS
	result = SetConductorState(player, state, time);
	D0			   A0	   D0     D1

	[LONG](autodocs-3.5/include-exec-types-h.md) SetConductorState(struct [Player](autodocs-3.5/include-libraries-realtime-h.md) *, ULONG, LONG);

   FUNCTION
	Changes the play state of the conductor referenced by the
	player. The states can be CONDSTATE_STOPPED, CONDSTATE_PAUSED,
	CONDSTATE_LOCATE, CONDSTATE_RUNNING, or the special value
	CONDSTATE_METRIC which asks the highest priority conducted node
	to do a CONDSTATE_LOCATE, or the special value CONDSTATE_SHUTTLE
	which informs the players that the clock value is changing, but the
	clock isn't actually running. Note that going from CONDSTATE_PAUSED
	to CONDSTATE_RUNNING does not reset the cdt_ClockTime of the
	conductor.

   INPUTS
	player - player referencing the conductor to change
	state - new play state of conductor
	time - start time offset in realtime.library heartbeat units

   RESULTS
	result - 0 if everything went OK, or a realtime.library error code
		 if an error occured. These currently include RTE_PLAYING
		 and RTE_NOCONDUCTOR.

