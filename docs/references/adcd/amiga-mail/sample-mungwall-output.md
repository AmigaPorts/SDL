---
title: Sample Mungwall Output
manual: amiga-mail
chapter: amiga-mail
section: sample-mungwall-output
functions: [AllocMem, FreeMem]
libraries: [exec.library]
---

# Sample Mungwall Output

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

When Mungwall reports a hit, it lists:

The function that triggered the hit (either AllocMem() or FreeMem()).
It includes the functions arguments.

The name of the offending program (``attempted by `<program name>' '').

The address of the offending program's Task structure (``at 0x<task
address>'').

The address from which AllocMem()/FreeMem() was called.  Mungwall
reports two addresses: one labelled ``A:'' and one labelled ``C:''.
The ``A:'' address is the address if AllocMem()/FreeMem() was called
directly (i.e., using assembler or #pragmas) by the offending program.
The ``C:'' address is the address if AllocMem()/FreeMem() was called
from an amiga.lib C stub by the offending program.  Since Mungwall
patches the memory allocation functions, it can only guess the caller's
address based on the return address it finds on the stack.

The stack pointer at the time of the Mungwall hit.  It is labelled
``SP:''.

Note that Mungwall ignores the layers.library's partial deallocations.
If any other debugging tools patch AllocMem() or FreeMem(), Mungwall's
``A:'' and ``C:'' addresses may be thrown off by additional information
pushed on the stack, and Mungwall will also be unable to screen out the
layers.library's partial deallocations (which will often show up as
Mungwall hits on your task, CON:, or input.device).

Here are some sample Mungwall hits that were produced by a program
called mungwalltest.  As a reminder, the arguments for memory functions
are AllocMem(size,type) and FreeMem(address,size).

AllocMem(0x0,10000) attempted by `mungwalltest' (at 0x339590)
  from A:0x35C03A C:0x35677E SP:0x35CFC0         Tried to allocate 0 bytes

                                                 of memory.
FreeMem(0x0,16) attempted by `mungwalltest' (at 0x339590)
  from A:0x35C068 C:0x3567C4 SP:0x35CFB8         Tried to free memory with

                                                 a NULL pointer.
FreeMem(0x33BD10,0) attempted by `mungwalltest' (at 0x339590)
  from A:0x35C068 C:0x3567D4 SP:0x35CFB0         Tried to free 0 bytes of

                                                 memory.
Mis-aligned FreeMem(0x33BD14,16) attempted by `mungwalltest' (at 0x339590)

```c
      from A:0x35C068 C:0x3567E2 SP:0x35CFA8     Deallocation address is
                                                 incorrect because it is
                                                 not aligned according to
                                                 AllocMem()'s lowest
                                                 memory chunk size.
```
Mismatched FreeMem size 14!
Original allocation: 16 bytes from A:0x35C03A C:0x3567A0 Task 0x339590
Testing with original size.                      Deallocation size does

                                                 not match the allocation
                                                 size.
19 byte(s) before allocation at 0x33BD10, size 16 were hit!
>$: BBBBBBBB BBBBBBBB BB536572 6765616E 74277320 50657070 65722000

                                                 Something wrote to the
                                                 bytes which precede the
                                                 allocation.
8 byte(s) after allocation at 0x33BD10, size 16 were hit!
>$: 75622042 616E6400 BBBBBBBB BBBBBBBB BBBBBBBB BBBBBBBB BBBBBBBBB

                                                 Something wrote to the
                                                 bytes which follow the
                                                 allocation.

---

## See Also

- [AllocMem — exec.library](../autodocs/exec.library.md#allocmem)
- [FreeMem — exec.library](../autodocs/exec.library.md#freemem)
