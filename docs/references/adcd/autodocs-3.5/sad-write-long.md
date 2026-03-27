---
title: SAD/WRITE_LONG
manual: autodocs-3.5
chapter: autodocs-3.5
section: sad-write-long
functions: []
libraries: []
---

# SAD/WRITE_LONG

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

 WRITE [LONG](autodocs-3.5/include-exec-types-h.md) - [Write](autodocs-3.5/dos-library-write-2.md) the given data to the address given

 Command:	$AF $03
 Data:		$ww $xx $yy $zz $qq $rr $ss $tt

 [Write](autodocs-3.5/dos-library-write-2.md) the long <$qqrrsstt> to address <$wwxxyyzz>

 Command will be ACK'ed when received.
 Command ACK:	$00 $03
 Command DONE:	$1F $03

