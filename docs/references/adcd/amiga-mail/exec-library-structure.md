---
title: Exec Library Structure
manual: amiga-mail
chapter: amiga-mail
section: exec-library-structure
functions: [OpenLibrary, SetFunction]
libraries: [exec.library]
---

# Exec Library Structure

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

When a library is opened for the first time, a library node structure, a
jump table, and a data area are created in RAM.

   [Fig. 1 - An Exec Library Base in RAM](amiga-mail/iii-1-diagram1-ilbm.md) 

The library node structure address is the base address of the library.
OpenLibrary() returns this base address.  The library's jump table, which
directly precedes the library node in RAM, consists of six byte long
entries containing a jump instruction (JMP) to a corresponding library
function.  The jump table is initialized when Exec opens the library.
Each function's entry in the jump table (also known as a vector) is always
a constant (negative) offset from the library base. These fixed negative
offsets are known as Library Vector Offsets (LVO). Note that the first
four function vectors are reserved for use by Exec. They point to standard
library functions for opening, closing, and expunging the library, plus
there is space reserved for a fourth function vector.  The base address of
a library is determined dynamically when the library is loaded into RAM.
See the Exec introduction chapter in the ROM Kernel Manual: Libraries and
Devices for more information on libraries.

The SetFunction() routine replaces an LVO address with a new address
which points to the wedge routine.  SetFunction() returns the old vector
address, which the wedge routine can use to call the original library
function from within the wedge.  Note that if another task
SetFunction()s the same library function, SetFunction() returns the
address of your debugging routine (to the second task)  as the old
vector.  At that point your task can no longer exit since that would
mean that that other task has an invalid pointer to your function and
will most likely crash the system when it tries to use your function.

   [Fig. 2 - Calling a Library Function](amiga-mail/iii-1-diagram2-ilbm.md) 

There is a way around this problem.  Instead of SetFunction()ing a library
function with the address of your wedge code, build your own jump table
and use the addresses of its entries as arguments to SetFunction() calls.
This method allows you to unload your code when you want to because if
another task SetFunction()s your routine, that task will get a pointer to
a jump table entry, not your routine.

   [Fig. 3 - Using SetFunction() with a Jump Table](amiga-mail/iii-1-diagram3-ilbm.md) 

   [Fig. 4 - Another Debugger SetFunction()s an Entry in the Jump Table](amiga-mail/iii-1-diagram4-ilbm.md) 

Now when you want to exit, all you need to do is replace the entries in
your jump table which point to your functions with the original function
vectors which were returned by SetFunction().  By not freeing the memory
allocated for the jump table your task can exit any time, regardless of
other tasks which SetFunction()ed the same library routines.  The other
task(s) will never know what happened.

   [Fig. 5 - Original Debugger Removes its Debugging Routine](amiga-mail/iii-1-diagram5-ilbm.md) 

The next time the debugger is executed, it looks for the jump table it
left behind and replaces the entries in it with pointers to its own
functions.  Incidentally, this is an easy way to provide a mechanism to
determine if your debugging program has already been installed.

---

## See Also

- [OpenLibrary — exec.library](../autodocs/exec.library.md#openlibrary)
- [SetFunction — exec.library](../autodocs/exec.library.md#setfunction)
