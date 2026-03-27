---
title: SAD/READ_BYTE
manual: autodocs-3.5
chapter: autodocs-3.5
section: sad-read-byte
functions: []
libraries: []
---

# SAD/READ_BYTE

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

 READ [BYTE](autodocs-3.5/include-exec-types-h.md) - [Read](autodocs-3.5/dos-library-read-2.md) a byte from the given address

 Command:	$AF $04
 Data:		$ww $xx $yy $zz

 [Read](autodocs-3.5/dos-library-read-2.md) a byte from address <$wwxxyyzz>  Returns <$qq> as result

 Command will be ACK'ed when received.
 Command ACK:	$00 $04
 Command DONE:	$1F $04 $qq

