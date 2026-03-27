---
title: SAD/READ_ARRAY
manual: autodocs-3.5
chapter: autodocs-3.5
section: sad-read-array
functions: []
libraries: []
---

# SAD/READ_ARRAY

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

 READ ARRAY - [Read](autodocs-3.5/dos-library-read-2.md) a range of bytes

 Command:	$AF $0F
 Data:		$ww $xx $yy $zz $qq $rr $ss $tt

 [Read](autodocs-3.5/dos-library-read-2.md) a range of bytes from address <$wwxxyyzz> for <$qqrrsstt> bytes
 Will return that number of bytes...

 Command will be ACK'ed when received.
 Command ACK:	$00 $0F
 Command DONE:	$1F $0F $uu [$uu ...]

