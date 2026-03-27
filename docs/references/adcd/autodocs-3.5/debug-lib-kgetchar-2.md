---
title: debug.lib/KGetChar
manual: autodocs-3.5
chapter: autodocs-3.5
section: debug-lib-kgetchar-2
functions: []
libraries: []
---

# debug.lib/KGetChar

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	KGetChar - get a character from the console
		   (defaults to the serial port at 9600 baud)

   SYNOPSIS
	char = KGetChar()
	D0

   FUNCTION
	busy wait until a character arrives from the console.
	KGetChar is the assembly interface, _KGetChar and _kgetc
	are the C interfaces.

