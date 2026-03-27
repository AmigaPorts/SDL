---
title: SAD/TURN_OFF_SINGLE
manual: autodocs-3.5
chapter: autodocs-3.5
section: sad-turn-off-single
functions: []
libraries: []
---

# SAD/TURN_OFF_SINGLE

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

 TURN OFF SINGLE STEPPING

 Command:	$AF $0D
 Data:		$ww $xx $yy $zz

 This command will turn off SAD single stepping mode.  You need to pass
 to it the address returned from the call to turn on single stepping mode.

 Command ACK:	$00 $0D
 Command DONE:	$1F $0D

