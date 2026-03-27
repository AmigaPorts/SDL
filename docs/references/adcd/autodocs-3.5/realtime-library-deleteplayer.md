---
title: realtime.library/DeletePlayer
manual: autodocs-3.5
chapter: autodocs-3.5
section: realtime-library-deleteplayer
functions: []
libraries: []
---

# realtime.library/DeletePlayer

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	DeletePlayer -- delete a player. (V37)

   SYNOPSIS
	DeletePlayer(player);
	             A0

	VOID DeletePlayer(struct [Player](autodocs-3.5/include-libraries-realtime-h.md) *);

   FUNCTION
	Deletes the specified player.

	Flushes the conductor that the player was connected to if this
	is the last player connected to that conductor.

   INPUTS
	player - [Player](autodocs-3.5/include-libraries-realtime-h.md) structure to delete, as allocated by
		 [CreatePlayer()](autodocs-3.5/realtime-library-createplayer.md). May be NULL, in which case this function
		 does nothing.

   SEE ALSO
	[CreatePlayer()](autodocs-3.5/realtime-library-createplayer.md)

