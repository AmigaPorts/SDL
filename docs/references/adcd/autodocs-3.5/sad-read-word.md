---
title: SAD/READ_WORD
manual: autodocs-3.5
chapter: autodocs-3.5
section: sad-read-word
functions: []
libraries: []
---

# SAD/READ_WORD

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

 READ WORD - [Read](autodocs-3.5/dos-library-read-2.md) a word from the given address		(V40 SAD)

 Command:	$AF $05
 Data:		$ww $xx $yy $zz

 [Read](autodocs-3.5/dos-library-read-2.md) a word from address <$wwxxyyzz>  Returns <$qqrr> as result

 Command will be ACK'ed when received.
 Command ACK:	$00 $05
 Command DONE:	$1F $05 $qq $rr

 BUGS
	This command does not return correct values in pre-V40 EXEC.

