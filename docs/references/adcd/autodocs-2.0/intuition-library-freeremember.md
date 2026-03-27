---
title: intuition.library/FreeRemember
manual: autodocs-2.0
chapter: autodocs-2.0
section: intuition-library-freeremember
functions: [AllocRemember, FreeMem, FreeRemember]
libraries: [exec.library, intuition.library]
---

# intuition.library/FreeRemember

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    FreeRemember -- Free memory allocated by calls to [AllocRemember()](autodocs-2.0/intuition-library-allocremember.md).
```
SYNOPSIS

```c
    FreeRemember( RememberKey, ReallyForget )
                  A0           D0

    VOID FreeRemember( struct [Remember](autodocs-2.0/includes-intuition-intuition-h.md) **, BOOL );
```
FUNCTION

```c
    This function frees up memory allocated by the [AllocRemember()](autodocs-2.0/intuition-library-allocremember.md)
    function.  It will either free up just the [Remember](autodocs-2.0/includes-intuition-intuition-h.md) structures, which
    supply the link nodes that tie your allocations together, or it will
    deallocate both the link nodes AND your memory buffers too.

    If you want to deallocate just the [Remember](autodocs-2.0/includes-intuition-intuition-h.md) structure link nodes,
    you should set the ReallyForget argument to FALSE.  However, if you
    want FreeRemember to really deallocate all the memory, including
    both the [Remember](autodocs-2.0/includes-intuition-intuition-h.md) structure link nodes and the buffers you requested
    via earlier calls to [AllocRemember()](autodocs-2.0/intuition-library-allocremember.md), then you should set the
    ReallyForget argument to TRUE.

    NOTE WELL: Once you call this function passing it FALSE, the
    linkages between all the memory chunks are lost, and you
    cannot subsequently use FreeRemember() to free them.
```
INPUTS

```c
    RememberKey = the address of a pointer to struct [Remember](autodocs-2.0/includes-intuition-intuition-h.md).  This
       pointer should either be NULL or set to some value (possibly
       NULL) by a call to [AllocRemember()](autodocs-2.0/intuition-library-allocremember.md).
    ReallyForget = a BOOL FALSE or TRUE describing, respectively,
       whether you want to free up only the [Remember](autodocs-2.0/includes-intuition-intuition-h.md) nodes or
       if you want this procedure to really forget about all of
       the memory, including both the nodes and the memory buffers
       referenced by the nodes.
```
EXAMPLE

```c
    struct [Remember](autodocs-2.0/includes-intuition-intuition-h.md) *RememberKey;
    RememberKey = NULL;
    AllocRemember(&RememberKey, BUFSIZE, MEMF_CHIP);
    FreeRemember(&RememberKey, TRUE);
```
RESULT

    None
BUGS

SEE ALSO

```c
    [AllocRemember()](autodocs-2.0/intuition-library-allocremember.md), [exec.library/FreeMem()](autodocs-2.0/exec-library-freemem.md)
```

---

## See Also

- [AllocRemember — intuition.library](../autodocs/intuition.library.md#allocremember)
- [FreeMem — exec.library](../autodocs/exec.library.md#freemem)
- [FreeRemember — intuition.library](../autodocs/intuition.library.md#freeremember)
