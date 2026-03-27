---
title: SAD/READ_LONG
manual: autodocs-3.5
chapter: autodocs-3.5
section: sad-read-long
functions: []
libraries: []
---

# SAD/READ_LONG

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

 READ [LONG](autodocs-3.5/include-exec-types-h.md) - [Read](autodocs-3.5/dos-library-read-2.md) a long from the given address

 Command:	$AF $06
 Data:		$ww $xx $yy $zz

 [Read](autodocs-3.5/dos-library-read-2.md) a long from address <$wwxxyyzz>  Returns <$qqrrsstt> as result

 Command will be ACK'ed when received.
 Command ACK:	$00 $06
 Command DONE:	$1F $06 $qq $rr $ss $tt

