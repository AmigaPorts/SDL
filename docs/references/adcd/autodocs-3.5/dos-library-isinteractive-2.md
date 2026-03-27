---
title: dos.library/IsInteractive
manual: autodocs-3.5
chapter: autodocs-3.5
section: dos-library-isinteractive-2
functions: []
libraries: []
---

# dos.library/IsInteractive

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	IsInteractive -- Discover whether a file is "interactive"

    SYNOPSIS
	status = IsInteractive( file )
	D0			D1

	[BOOL](autodocs-3.5/include-exec-types-h.md) IsInteractive(BPTR)

    FUNCTION
	The return value 'status' indicates whether the file associated
	with the file handle 'file' is connected to a virtual terminal.

    INPUTS
	file - BCPL pointer to a file handle

    RESULTS
	status - boolean


    SEE ALSO
