---
title: An Example Debugger
manual: amiga-mail
chapter: amiga-mail
section: an-example-debugger
functions: [Forbid, SetFunction]
libraries: [exec.library]
---

# An Example Debugger

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The usage of SetFunction() is shown by the example debugging program at
the end of this article, [ISpy](amiga-mail/iii-1-ispy-c.md).  ISpy uses a semaphore to gain access to
its jump table.  This jump table contains pointers to the wedge routines.
When executed, each wedge routine puts a shared lock on the semaphore to
indicate that the code is being executed.  To get an idea of who is
calling the debugger entries, ISpy uses a little [assembler stub](amiga-mail/iii-1-ispy-stubs-asm.md) to load a4
with the address of the stack of the caller and calls a C routine where
the actual (simple) argument checking is done.  When ISpy is signalled to
exit, it tries to get an exclusive lock on the semaphore in a Forbid()en
state.  If this succeeds, it can safely assume its code is not being
executed at the moment and can therefore place the original function
vectors in the jump table and exit, leaving the semaphore behind.  This
semaphore is also used to check whether ISpy is already installed.  If so,
the new instance will exit immediately. Because of the use of shared
semaphore locks, this program will only run with V37.  By using a global
counter (which is incremented each time a function is entered and
decremented when it is exited) ISpy can be adapted to V33.  Because of the
way ISpy is set up, it is very easy to add argument checking front ends
for functions, and have multiple versions of ISpy for different libraries.

Memoration and Scratcher by Bill Hawes.  IO_Torture by Bryce Nesbitt.
Wedge and DevMon by Carolyn Scheppner.  MungWall by Ewout Walraven
(inspired by Memwall by Randell Jesup and MemMung by Bryce Nesbitt).

---

## See Also

- [Forbid — exec.library](../autodocs/exec.library.md#forbid)
- [SetFunction — exec.library](../autodocs/exec.library.md#setfunction)
