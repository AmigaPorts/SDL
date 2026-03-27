---
title: any_sana2_protocol/CopyFromBuff
manual: amiga-mail
chapter: amiga-mail
section: any-sana2-protocol-copyfrombuff
functions: [Forbid]
libraries: [exec.library]
---

# any_sana2_protocol/CopyFromBuff

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    CopyFromBuff -- Copy n bytes from an abstract data structure.
SYNOPSIS

```c
    success = CopyFromBuff(to, from, n)
    d0                     a0  a1    d0

    BOOL CopyToBuff(VOID *, VOID *, ULONG);
```
FUNCTION

    This function copies 'n' bytes of data in the abstract data structure
    pointed to by 'from' into the contigous memory pointed to by 'to'.
    'to' must contain at least 'n' bytes of usable memory or innocent
    memory will be overwritten.
INPUTS

    to              - pointer to contiguous memory to copy to.
    from            - pointer to abstract structure to copy from.
    n               - number of bytes to copy.
RESULT

    success         - TRUE if operation was successful, else FALSE.
EXAMPLE

NOTES

```c
    This function must be callable from interupts.  In particular, this
    means that this function may not directly or indirectly call any
    system memory functions (since those functions rely on Forbid() to
    protect themselves) and that  you must not compile this function
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
