---
title: SAD/WRITE_ARRAY
manual: autodocs-3.5
chapter: autodocs-3.5
section: sad-write-array
functions: []
libraries: []
---

# SAD/WRITE_ARRAY

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

 WRITE ARRAY - [Write](autodocs-3.5/dos-library-write-2.md) a range of bytes

 Command:	$AF $0E
 Data:		$ww $xx $yy $zz $qq $rr $ss $tt

 [Write](autodocs-3.5/dos-library-write-2.md) a range of bytes to address <$wwxxyyzz> for <$qqrrsstt> bytes
 After the computer sends the ACK, you must then send the byte stream...

 Command will be ACK'ed when received.
 Command ACK:	$00 $0E
 Command DONE:	$1F $0E

