---
title: Caveats
manual: amiga-mail
chapter: amiga-mail
section: caveats
functions: [Disable, Enable, Forbid, FreeMem, Permit, SetFunction, SumLibrary]
libraries: [exec.library]
---

# Caveats

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

There are some things to keep in mind when using SetFunction().  The
scheme described above can force a second task to hang around forever if
it SetFunction()ed a routine before you, since your debugger will not
normally release its handle on the second task's function.  Whenever
possible, install jump table based debuggers before any other
SetFunction()ing program (but after SetPatch of course).

Some debuggers interpret the return address of the caller.  When a
debugger jumps (JMP) to (what it thinks is) the original function, there
will be no problem.  However, if a debugger performs a JSR to a second
debugging function which interprets the return address, the second
debugging function will receive the first debugging function's return
address (the one that performed the JSR) rather than the return address of
the application that called the library function in the first place. This
can confuse the second debugger.  Two good examples of this are Scratcher
and MungWall, which both SetFunction() FreeMem().  MungWall looks at the
return address of the caller.  Since Scratcher calls the old FreeMem()
function with a JSR instruction, it would mislead MungWall if run after
it.  Preferably, debuggers that interpret the return address should be
started after other debuggers.

Although it is not common, some library functions call other library
functions and depend on certain scratch registers to contain valid values.
SetFunction()ing one of these functions is likely to change the values in
these scratch registers, leading to problems.  Because these dependencies
are not always documented, you might innocently run into one.  Scratcher
is an excellent tool for finding such dependencies.

In the past, some system functions did not have a JMP vector in their
entry in the LVO table.  Instead, the actual function was in the jump
table.  SetFunction() will not work on such a function.

Any debugging routine should be careful not to call the function it has
patched with SetFunction(), either directly or indirectly.  Doing so will
likely cause a stack overflow and crash the machine.  This may seem a bit
obvious until you consider how easy it is to indirectly call a system
routine.   Many system functions are not atomic.  They have to call lower
level system functions.  If you call a higher level system functions in
the debugging code and you have SetFunction()ed one of the routines the
high level function uses, the machine will probably crash from a stack
overflow.

Using SetFunction() on disk-based libraries and devices requires a little
extra care.  Unlike a ROM library, libraries (and devices) loaded into RAM
can be expunged when memory gets low.  To prevent the system from
expunging a library (or device) you have SetFunction()ed, either keep the
library (or device) opened, or use SetFunction() to patch the library's
expunge function.

Remember that when you install a wedge, another program can call it almost
instantly.  Because of this, the wedge should be completely set up before
you install it.

Note that dos.library is now a standard library and can be SetFunction()ed
as of V36.  Before V36 you would have to Forbid(), get the six original
bytes of the entry in the function vector table, install the new vector,
perform a SumLibrary() and then Permit().

If it is necessary to put debugging code into a Forbid() or Disable()
state, keep it in that state for as little time as possible to limit
system slowdown.  Remember that you cannot Disable() for more than 250
microseconds.  Be sure to read the Disable()/Enable() Autodocs before
using them.

---

## See Also

- [Disable — exec.library](../autodocs/exec.library.md#disable)
- [Enable — exec.library](../autodocs/exec.library.md#enable)
- [Forbid — exec.library](../autodocs/exec.library.md#forbid)
- [FreeMem — exec.library](../autodocs/exec.library.md#freemem)
- [Permit — exec.library](../autodocs/exec.library.md#permit)
- [SetFunction — exec.library](../autodocs/exec.library.md#setfunction)
- [SumLibrary — exec.library](../autodocs/exec.library.md#sumlibrary)
