---
title: SAD/WRITE_BYTE
manual: autodocs-3.5
chapter: autodocs-3.5
section: sad-write-byte
functions: []
libraries: []
---

# SAD/WRITE_BYTE

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

 WRITE [BYTE](autodocs-3.5/include-exec-types-h.md) - [Write](autodocs-3.5/dos-library-write-2.md) the given data to the address given	(V40 SAD)

 Command:	$AF $01
 Data:		$ww $xx $yy $zz $qq

 [Write](autodocs-3.5/dos-library-write-2.md) the byte <$qq> to address <$wwxxyyzz>

 Command will be ACK'ed when received.
 Command ACK:	$00 $01
 Command DONE:	$1F $01

 BUGS
	This command does not exists in pre-V40 EXEC.
	This command can be emulated with the [WRITE_ARRAY](autodocs-3.5/sad-write-array.md) command with
	a length of 1.

