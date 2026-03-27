---
title: SAD/CALL_ADDRESS
manual: autodocs-3.5
chapter: autodocs-3.5
section: sad-call-address
functions: []
libraries: []
---

# SAD/CALL_ADDRESS

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

 CALL ADDRESS - JSR to the given address.

 Command:	$AF $07
 Data:		$ww $xx $yy $zz

 Call the following address as a subroutine.  No registers will be
 set up but the context frame will exist.  Standard calling
 conventions apply (d0/d1/a0/a1 are available, rest must be saved)
 The command will be ACK'ed when received.
 Command ACK:	$00 $07
 Command DONE:	$1F $07

