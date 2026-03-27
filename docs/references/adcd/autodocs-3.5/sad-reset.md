---
title: SAD/RESET
manual: autodocs-3.5
chapter: autodocs-3.5
section: sad-reset
functions: []
libraries: []
---

# SAD/RESET

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

 RESET - Reset the computer...

 Command:	$AF $10
 Data:		$FF $FF $FF $FF

 This command will reset the computer.  the $FFFFFFFF value is there
 mainly to prevent false reset.  This command will only be ACK'ed as
 the computer will be reset afterwards...

 Command will be ACK'ed when received.
 Command ACK:	$00 $10

