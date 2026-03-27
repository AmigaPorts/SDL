---
title: SAD/FREE_MEMORY
manual: autodocs-3.5
chapter: autodocs-3.5
section: sad-free-memory
functions: [FreeVec]
libraries: [exec.library]
---

# SAD/FREE_MEMORY

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

 FREE MEMORY

 Command:	$AF $0B
 Data:		$ww $xx $yy $zz

 Free the memory allocated with the ALLOCATE MEMORY command.  This command
 has the same restrictions as ALLOCATE MEMORY.  Memory is released by
 calling [FreeVec()](autodocs-3.5/exec-library-freevec-2.md) on the address <$wwxxyyzz>

 Command ACK:	$00 $0B
 Command DONE:	$1F $0B

---

## See Also

- [FreeVec — exec.library](../autodocs/exec.library.md#freevec)
