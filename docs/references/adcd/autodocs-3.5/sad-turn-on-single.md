---
title: SAD/TURN_ON_SINGLE
manual: autodocs-3.5
chapter: autodocs-3.5
section: sad-turn-on-single
functions: []
libraries: []
---

# SAD/TURN_ON_SINGLE

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

 TURN ON SINGLE STEPPING

 Command:	$AF $0C
 Data:		<none>

 This command will turn on SAD single stepping mode.  This means that SAD
 will single step (via 68000 trace mode) the system.  SAD will take over
 the TRACE exception vector during this time.  This command will return
 the contents of the vector such that you can return this value when
 you wish to turn off single stepping mode.  Note that turning on single
 stepping mode while in $BF prompting will cause the step to be taken
 and then SAD will execute in $3F mode (non-NMI)
 The command returns <$wwxxyyzz> which you must use when turning off
 the single-step mode.

 Command ACK:	$00 $0C
 Command DONE:	$1F $0C $ww $xx $yy $zz

