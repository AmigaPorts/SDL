---
title: realtime.library/ExternalSync
manual: autodocs-3.5
chapter: autodocs-3.5
section: realtime-library-externalsync
functions: []
libraries: []
---

# realtime.library/ExternalSync

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	ExternalSync -- provide external source clock for a player's
			conductor. (V37)

   SYNOPSIS
	result = ExternalSync(player, minTime, maxTime);
	D0		      A0      D0       D1

	[BOOL](autodocs-3.5/include-exec-types-h.md) ExternalSync(struct [Player](autodocs-3.5/include-libraries-realtime-h.md) *, [LONG](autodocs-3.5/include-exec-types-h.md), LONG);

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

