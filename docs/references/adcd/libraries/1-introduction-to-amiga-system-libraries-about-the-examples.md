---
title: 1 Introduction to Amiga System Libraries / About the Examples
manual: libraries
chapter: libraries
section: 1-introduction-to-amiga-system-libraries-about-the-examples
functions: []
libraries: []
---

# 1 Introduction to Amiga System Libraries / About the Examples

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

For the most part, the examples in this book are written in C (there are a
few 68000 assembly language examples too).

C examples have been compiled under SAS C, version 5.10a.  The compiler
options used with each example are noted in the comments preceding the
code.

In general, the examples are also compatible with Manx Aztec C 68K,
version 5.0d, and other C compilers, however some changes will usually be
necessary.  Specifically, all the C examples assume that the automatic
Ctrl-C feature of the compiler has been disabled.  For SAS C (and Lattice
C revisions 4.0 and greater) this is handled with:



```c
    /* Add this before main() to override the default Ctrl-C handling
     * provided in SAS (Lattice) C.  Ctrl-C event will be ignored */

    int CXBRK ( void )   { return(0); }
    int chkabort( void ) { return(0); }
```
For Manx Aztec C, replace the above with:



```c
    /* Add this near the top */
            #include <functions.h>

    /* Add this before main() */
            extern int Enable_Abort;   /* reference abort enable */

    /* Add this after main(), as the first active line in the program */
            Enable_Abort=0;         /* turn off CTRL-C */
```
Other changes may be required depending on the example and the C compiler
you are using.  Most of the C examples in this book use the following
special option flags of the SAS/C compiler (set the equivalent option of
whatever compiler you are using):


-b1 = Small data model.
-cf = Check for function prototypes.
  i = Ignore #include statements that are identical to one already given.
  s = Store all literal strings that are identical in the same place.
  t = Enable warnings for structures that are used before they are defined.

 -v = Do not include stack checking code with each function.
 -y = Load register A4 with the data section base address on function


```c
      entry.  The -v and -y flags are are generally only needed for parts
      of the program that are called directly by the system such as
      [interrupt servers](libraries/26-servicing-interrupts-interrupt-servers.md), [subtasks](libraries/21-exec-tasks-task-termination.md), [handlers](libraries/26-servicing-interrupts-interrupt-handlers.md) and [callback hook](libraries/37-utility-library-callback-hooks.md) functions.
```
Except where noted, each example was linked with the standard SAS/C
startup code c.o, the SAS/C linker library lc.lib and the Amiga linker
library amiga.lib.  The SAS/C compiler defaults to 32-bit ints.  If your
development environment uses 16-bit ints you may need to explicitly cast
certain arguments as longs (for example 1L << sigbit instead of 1 <<
sigbit).

The 68000 assembly language examples have been assembled under the
Innovatronics CAPE assembler V2.x, the HiSoft Devpac assembler V1.2, and
the Lake Forest Logic ADAPT assembler 1.0.  No substantial changes should
be required to switch between assemblers.

