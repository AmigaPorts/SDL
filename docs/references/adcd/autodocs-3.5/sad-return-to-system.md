---
title: SAD/RETURN_TO_SYSTEM
manual: autodocs-3.5
chapter: autodocs-3.5
section: sad-return-to-system
functions: []
libraries: []
---

# SAD/RETURN_TO_SYSTEM

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

 RETURN TO SYSTEM

 Command:	$AF $08
 Data:		$00 $00 $00 $00

 This command will return <exit> from SAD back to whatever started it.
 The 4 $00 are required as a "safty" to this command.  The command
 will be ACK'ed only as it will have lost control of the system.

 Command ACK:	$00 $08

