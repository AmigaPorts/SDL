---
title: ddebug.lib/DMayGetChar
manual: autodocs-3.5
chapter: autodocs-3.5
section: ddebug-lib-dmaygetchar
functions: []
libraries: []
---

# ddebug.lib/DMayGetChar

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	DMayGetChar - return a char iff present, but don't block

   SYNOPSIS
	flagChar = DMayGetChar()
	D0

   FUNCTION
	return either a -1, saying that there is no char present, or
	the char that was waiting

