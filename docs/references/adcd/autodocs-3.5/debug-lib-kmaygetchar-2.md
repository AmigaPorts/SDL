---
title: debug.lib/KMayGetChar
manual: autodocs-3.5
chapter: autodocs-3.5
section: debug-lib-kmaygetchar-2
functions: []
libraries: []
---

# debug.lib/KMayGetChar

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	KMayGetChar - return a character if present, but don't wait
		      (defaults to the serial port at 9600 baud)

   SYNOPSIS
	flagChar = KMayGetChar()
	D0

   FUNCTION
	return either a -1, saying that there is no character present, or
	whatever character was waiting.  KMayGetChar is the assembly
	interface,  _KMayGetChar is the C interface.

