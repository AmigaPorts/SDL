---
title: 18 / What is a Library? / Changing the Contents of a Library
manual: libraries
chapter: libraries
section: 18-what-is-a-library-changing-the-contents-of-a-library
functions: [SetFunction]
libraries: [exec.library]
---

# 18 / What is a Library? / Changing the Contents of a Library

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The way in which an Amiga library is organized allows a programmer to
change where the system looks for a library routine.  Exec provides a
function to do this: [SetFunction()](autodocs-2.0/exec-library-setfunction.md).  The SetFunction() routine redirects a
library function call to an application-supplied function. (Although it's
not addressed here, SetFunction() can also be used on Exec devices.)  For
instance, the AmigaDOS command SetPatch uses SetFunction() to replace some
OS routines with improved ones, primarily to fix bugs in ROM libraries.

The format of the [SetFunction()](autodocs-2.0/exec-library-setfunction.md) routine is as follows:


```c
    SetFunction( struct Library *lib, LONG funcOffset, APTR funcEntry)
                                 A1            A0               D0
```
The lib argument is a pointer to the library containing the function entry
to be changed.  The funcOffset is the Library Vector Offset (negative) of
the function and funcEntry is the address of the new function you want to
replace it with.  The [SetFunction()](autodocs-2.0/exec-library-setfunction.md) routine replaces the entry in the
library's vector table at the given Library Vector Offset with a new
address that points to the new routine and returns the old vector address.
The old address can be used in the new routine to call the original
library function.

Normally, programs should not attempt to "improve" library functions.
Because most programmers do not know exactly what system library functions
do internally, OS patches can do more harm than good.  However, a
legitimate use for [SetFunction()](autodocs-2.0/exec-library-setfunction.md) is in a debugger utility.  Using
SetFunction(), a debugger could reroute system calls to a debugging
routine.  The debugging routine can inspect the arguments to a library
function call before calling the original library function (if everything
is OK).  Such a debugger doesn't do any OS patching, it merely inspects.


```c
    [SetFunction()](autodocs-2.0/exec-library-setfunction.md) is for Advanced Users Only.
    -----------------------------------------
    It is very difficult to cleanly exit after performing SetFunction()
    because other tasks may be executing your code and also because
    additional SetFunction()'s may have occurred on the same function.
    Also note that certain libraries (for example the V33 version of DOS
    library) and some individual library function vectors are of
    non-standard format and cannot be replaced via SetFunction().
```
Although useful, performing [SetFunction()](autodocs-2.0/exec-library-setfunction.md) on a library routines poses
several problems.  If a second task performs SetFunction() on the same
library entry, SetFunction() returns the address of the new routine to the
second task, not the original system vector.  In that case, the first task
can no longer exit cleanly since that would leave the second task with an
invalid pointer to a function which it could be relying on.

You also need to know when it is safe to unload your replacement function.
Removing it while another task is executing it will quickly lead to a
crashed system.  Also, the replacement function will have to be
re-entrant, like all Exec library functions.


```c
    Don't Do This!
    --------------
    For those of you who might be thinking about writing down the ROM
    addresses returned by [SetFunction()](autodocs-2.0/exec-library-setfunction.md) and using them in some other
    programs: Forget It.  The address returned by SetFunction() is
    only good on the current system at the current time.
```

---

## See Also

- [SetFunction — exec.library](../autodocs/exec.library.md#setfunction)
