---
title: More Remote Debugging Tips
manual: amiga-mail
chapter: amiga-mail
section: more-remote-debugging-tips
functions: []
libraries: []
---

# More Remote Debugging Tips

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Debugging with Enforcer and Mungwall is even more effective when an
application sends other debugging information to the serial or parallel
port.  The linker library debug.lib contains a printf()-like function,
kprintf(), to print information to the serial port.  The linker library
ddebug.lib contains a similar function called dprintf() that prints
debugging information to the parallel port.  The output from these
functions intermix with the output from Enforcer and Mungwall, making
it easy to pinpoint which part of the code is causing Enforcer or
Mungwall hits.

Functions like kprintf() and dprintf() are useful, but adding and
removing them from programs can be tedious.  One easy way to deal with
this problem is to include them only when a special label is defined:


```c
    /**********    debug macros     ***********/
    #define MYDEBUG  1
    void kprintf(UBYTE *fmt,...);
    void dprintf(UBYTE *fmt,...);
    #define DEBTIME 0
    #define bug printf
    #if MYDEBUG
    #define D(x) (x); if(DEBTIME>0) Delay(DEBTIME);
    #else
    #define D(x) ;
    #endif /* MYDEBUG */
    /********** end of debug macros **********/
```
Set MYDEBUG to 1 to turn on debugging.  Set ``bug'' to:

```c
    ``printf'' to send debugging information to the default console,
    ``kprintf'' to send debugging information to the serial port
            (link with debug.lib), and
    ``dprintf'' to send debugging information to the parallel port
            (link with ddebug.lib).
```
When using this macro, make sure there two close parentheses before the
semicolon at the end of each D(bug()) statement.

Example macro usage:


```c
        win = OpenWindow(&mynewwin);
        D(bug("Opened window at $%lx\n", win));
```
A different low-level method of figuring out which instructions caused
an Enforcer hit is to disassemble program memory where the hit
occurred.  First, match the disassembly with your own code.  Assembly
programmers could just compare the disassembly to their source.  Others
could take the hex values of a sequence of position-independent 68000
instructions near the hit (i.e.  no addresses except for offsets and
branches) and do a search for this pattern in your object modules.  If
you find the pattern, do a mixed source and object disassembly of that
object module and then look in the output for instructions matching
those where the hit occurred.   For example, with SAS's OMD you could
compile your code with the flag -d1, then do the following:


    1.Ram Disk:> OMD >ram:dump mymodule.o mymodule.c
