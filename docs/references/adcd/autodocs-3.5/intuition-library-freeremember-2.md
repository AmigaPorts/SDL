---
title: intuition.library/FreeRemember
manual: autodocs-3.5
chapter: autodocs-3.5
section: intuition-library-freeremember-2
functions: [AllocRemember, FreeMem, FreeRemember]
libraries: [exec.library, intuition.library]
---

# intuition.library/FreeRemember

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	FreeRemember -- Free memory allocated by calls to [AllocRemember()](autodocs-3.5/intuition-library-allocremember-2.md).

    SYNOPSIS
	FreeRemember( RememberKey, ReallyForget )
		      A0           D0

	VOID FreeRemember( struct [Remember](autodocs-3.5/include-intuition-intuition-h.md) **, [BOOL](autodocs-3.5/include-exec-types-h.md) );

    FUNCTION
	This function frees up memory allocated by the [AllocRemember()](autodocs-3.5/intuition-library-allocremember-2.md) function.
	It will either free up just the [Remember](autodocs-3.5/include-intuition-intuition-h.md) structures, which supply the
	link nodes that tie your allocations together, or it will deallocate
	both the link nodes AND your memory buffers too.

	If you want to deallocate just the [Remember](autodocs-3.5/include-intuition-intuition-h.md) structure link nodes,
	you should set the ReallyForget argument to FALSE.  However, if you
	want FreeRemember to really deallocate all the memory, including
	both the [Remember](autodocs-3.5/include-intuition-intuition-h.md) structure link nodes and the buffers you requested
	via earlier calls to [AllocRemember()](autodocs-3.5/intuition-library-allocremember-2.md), then you should set the
	ReallyForget argument to TRUE.

	NOTE WELL: Once you call this function passing it FALSE, the
	linkages between all the memory chunks are lost, and you
	cannot subsequently use FreeRemember() to free them.

    INPUTS
	RememberKey = the address of a pointer to struct [Remember](autodocs-3.5/include-intuition-intuition-h.md).  This
```c
           pointer should either be NULL or set to some value (possibly
           NULL) by a call to [AllocRemember()](autodocs-3.5/intuition-library-allocremember-2.md).
```
	ReallyForget = a [BOOL](autodocs-3.5/include-exec-types-h.md) FALSE or TRUE describing, respectively,
```c
           whether you want to free up only the [Remember](autodocs-3.5/include-intuition-intuition-h.md) nodes or
           if you want this procedure to really forget about all of
           the memory, including both the nodes and the memory buffers
           referenced by the nodes.

    EXAMPLE
```
	struct [Remember](autodocs-3.5/include-intuition-intuition-h.md) *RememberKey;
	RememberKey = NULL;
	AllocRemember(&RememberKey, BUFSIZE, MEMF_CHIP);
	FreeRemember(&RememberKey, TRUE);

    RESULT
	None

    BUGS

    SEE ALSO
	[AllocRemember()](autodocs-3.5/intuition-library-allocremember-2.md), [exec.library/FreeMem()](autodocs-3.5/exec-library-freemem-2.md)

---

## See Also

- [AllocRemember — intuition.library](../autodocs/intuition.library.md#allocremember)
- [FreeMem — exec.library](../autodocs/exec.library.md#freemem)
- [FreeRemember — intuition.library](../autodocs/intuition.library.md#freeremember)
