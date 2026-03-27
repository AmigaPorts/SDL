---
title: dos.library/Relabel
manual: autodocs-3.5
chapter: autodocs-3.5
section: dos-library-relabel-2
functions: []
libraries: []
---

# dos.library/Relabel

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	Relabel -- Change the volume name of a volume (V36)

   SYNOPSIS
	success = Relabel(volumename,name)
	D0                    D1      D2

	[BOOL](autodocs-3.5/include-exec-types-h.md) Relabel(STRPTR,STRPTR)

   FUNCTION
	Changes the volumename of a volume, if supported by the filesystem.

   INPUTS
	volumename - Full name of device to rename (with ':')
	newname    - New name to apply to device (without ':')

   RESULT
	success    - Success/failure indicator

   SEE ALSO

