---
title: SAD/ALLOCATE_MEMORY
manual: autodocs-3.5
chapter: autodocs-3.5
section: sad-allocate-memory
functions: [AllocVec]
libraries: [exec.library]
---

# SAD/ALLOCATE_MEMORY

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

 ALLOCATE MEMORY

 Command:	$AF $0A
 Data:		$qq $rr $ss $tt $hh $ii $jj $kk

 [Allocate](autodocs-3.5/exec-library-allocate-2.md) a chunk of memory that is <$qqrrsstt> bytes in size.  Note
 that this call is only safe when SAD is in $3F prompting mode (called
 from [Debug()](autodocs-3.5/exec-library-debug-2.md)) and even then may be unsafe if the system is in bad shape.
 (You are debugging after all)  The returned address will be available to
 you until you release it.  (It is obtained via a call to [AllocVec()](autodocs-3.5/exec-library-allocvec-2.md))  The
 type of memory allocated is <$hhiijjkk>.  Note that the allocation may
 fail. In that case, the address returned will be $00000000.

 Command ACK:	$00 $0A
 Command DONE:	$1F $0A $ww $xx $yy $zz

---

## See Also

- [AllocVec — exec.library](../autodocs/exec.library.md#allocvec)
