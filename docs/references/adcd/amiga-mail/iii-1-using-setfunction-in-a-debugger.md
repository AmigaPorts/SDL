---
title: III-1: Using SetFunction() in a Debugger
manual: amiga-mail
chapter: amiga-mail
section: iii-1-using-setfunction-in-a-debugger
functions: [SetFunction]
libraries: [exec.library]
---

# III-1: Using SetFunction() in a Debugger

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

By Ewout Walraven


The Amiga OS consists of a set of libraries (and devices), which reside in
ROM or on disk.  These libraries provide a set of routines which are
shared by the Amiga tasks (hence the name shared library).

The way in which an Amiga library is organized allows a programmer to
change where the system looks for a library routine.  Exec provides a
function to do this: SetFunction().  The SetFunction() routine redirects a
library function call to an application-supplied function (Although this
article doesn't address it, SetFunction() can also be used on Exec
devices).  The SetPatch utility uses SetFunction().  SetPatch is a program
which replaces some OS routines with improved ones, primarily to fix bugs
in ROM libraries.

Normally, programs should not attempt to ``improve'' library functions.
Because most programmers do not know exactly what system library functions
do internally, OS patches can do more harm than good. However, a useful
place to use SetFunction() is in a debugger.  Using SetFunction(), a
debugger can reroute library calls to a debugging function.  The debugging
function can inspect the arguments to a library function call before
calling the original library routine (if everything is OK).  Such a
debugging function doesn't do any OS patching, it merely inspects.

SetFunction() is also useful for testing an application under conditions
it does not encounter normally.  For example, a debugging program can
force a program's memory allocations to fail or prevent a program's window
from opening.  This allows a programmer to find bugs that only arise under
special circumstances.  Some programs that use SetFunction() for debugging
purposes are IO_Torture, Memoration and MungWall.  A real watchdog is
Wedge, which, as its name implies, allows you to install a wedge for
practically every function of a standard library and inform you about the
register values passed to the function.  These types of debugging tools
helped debug release 2.0 of the OS and found bugs and 1.3 dependencies in
commercial applications.

Although useful, SetFunction()ing library routines poses several problems.
First of all, the wedge routine will have to be re-entrant, like all Exec
library functions.  Secondly, there is always a problem with removing the
wedge.  If another task has SetFunction()ed the same library routine as
the debugger (a very real possibility), it is not normally possible to
remove the first wedge, since the other task depends on the presence of
your task's code.  This would force your task to hang around, waiting for
the other task(s) to remove their wedges. You also need to know when it is
safe to unload your debugging code. Removing it while another task is
executing it will quickly lead to a hopelessly crashed system.

For those of you who might be thinking about writing down the ROM
addresses returned by SetFunction() and using them in some other programs:
Forget It.  The address returned by SetFunction() is only good on the
current system at the current time.  Blindly jumping into ROM will cause
your programs to break.

 [Exec Library Structure](amiga-mail/exec-library-structure.md) 
 [Caveats](amiga-mail/caveats.md) 
 [An Example Debugger](amiga-mail/an-example-debugger.md) 

---

## See Also

- [SetFunction — exec.library](../autodocs/exec.library.md#setfunction)
