---
title: any_sana2_protocol/CopyToBuff
manual: amiga-mail
chapter: amiga-mail
section: any-sana2-protocol-copytobuff
functions: [Forbid]
libraries: [exec.library]
---

# any_sana2_protocol/CopyToBuff

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    CopyToBuff -- Copy n bytes to an abstract data structure.
SYNOPSIS

```c
    success = CopyToBuff(to, from, n)
    d0                   a0  a1    d0

    BOOL CopyToBuff(VOID *, VOID *, ULONG);
```
FUNCTION

```c
    This function first does any initialization and/or allocation
    required to prepare the abstract data structure pointed at by 'to'
    to be filled with 'n' bytes of data from 'from'.  It then executes
    the copy operation.

    If, for example, there is not enough memory available to prepare
    the abstract data structure, the call is failed and FALSE is returned.

    The buffer management scheme should be such that any memory needed
    to fulfill CopyToBuff() calls is already allocated from the system
    before the call to CopyToBuff() is made.
```
INPUTS

    to              - pointer to abstract structure to copy to.
    from            - pointer to contiguous memory to copy from.
    n               - number of bytes to copy.
RESULT

    success         - TRUE if operation was successful, else FALSE.
EXAMPLE

NOTES

```c
    This function must be callable from interupts.  In particular, this
    means that this function may not directly or indirectly call any
    system memory functions (since those functions rely on Forbid() to
    protect themselves) and that you must not compile this function
    with stack checking enabled.  See the RKM:Libraries Exec:Interupts
    chapter for more details on what is legal in a routine called from
    an interupt handler.

    'C' programmers should not compile with stack checking (option '-v'
    in SAS) and should geta4() or __saveds.
```
BUGS

SEE ALSO

---

## See Also

- [Forbid — exec.library](../autodocs/exec.library.md#forbid)
