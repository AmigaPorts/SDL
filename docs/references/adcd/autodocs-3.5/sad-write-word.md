---
title: SAD/WRITE_WORD
manual: autodocs-3.5
chapter: autodocs-3.5
section: sad-write-word
functions: []
libraries: []
---

# SAD/WRITE_WORD

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

 WRITE WORD - [Write](autodocs-3.5/dos-library-write-2.md) the given data to the address given

 Command:	$AF $02
 Data:		$ww $xx $yy $zz $qq $rr

 [Write](autodocs-3.5/dos-library-write-2.md) the word <$qqrr> to address <$wwxxyyzz>

 Command will be ACK'ed when received.
 Command ACK:	$00 $02
 Command DONE:	$1F $02

