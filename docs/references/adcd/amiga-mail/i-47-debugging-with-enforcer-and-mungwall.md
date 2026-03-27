---
title: I-47: Debugging with Enforcer and Mungwall
manual: amiga-mail
chapter: amiga-mail
section: i-47-debugging-with-enforcer-and-mungwall
functions: []
libraries: []
---

# I-47: Debugging with Enforcer and Mungwall

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

by Carolyn Scheppner


It is almost impossible for a human being to develop software without
including some bugs.  Some bugs make themselves known rather quickly.
Other bugs are not so easy to notice.  For example, two hard to find bugs
that sometimes slip past developers are using uninitialized pointers and
using memory which has already been freed.  These bugs often reference
semi-random memory, which contains semi-random data. Typically the
behavior of the software depends on the data passed to it.   If that data
is erratic, the behavior of the software will also be erratic.  Because
the behavior is erratic and unpredictable, the problem is very hard to
spot.  Quite often, bugs like these go unnoticed until software is running
in a real user's multitasking environment.  Fortunately, debugging tools
like Enforcer and Mungwall (and for assembler programmers, Scratch by Bill
Hawes) help uncover hidden bugs.

Enforcer is a debugging tool written by Bryce Nesbitt.  Its job is to
report any attempts to access regions of the Amiga address space that are
off-limits to applications.  These off-limits accesses include reading and
writing to the lowest 1K range of memory (except for reading ExecBase from
$4), writing to the Kickstart ROM, and reading and writing to non-existent
memory ranges.

Enforcer requires that the CPU has access to an MMU (Memory Management
Unit) to catch reads and writes to memory.  Most 68020 based accelerator
boards have MMU chips on them.  An MMU is built-in to each 68030 and 68040
CPU (currently Enforcer does not support 68040).

When an application tries to read a memory location that has been
read-protected by Enforcer, Enforcer intercepts that memory read, reports
the illegal memory access (known as an ``Enforcer hit''), and shows the
application a zero instead of the contents of the memory address.  The
application has no idea that Enforcer did anything.  When an application
tries to write to a memory location that has been write-protected by
Enforcer, Enforcer prevents the illegal memory write and issues an
Enforcer hit.

Enforcer is even more powerful when used in combination with Mungwall.
Mungwall was written by Ewout Walraven and is based on Memmung by Bryce
Nesbitt and Memwall by Randell Jesup.  The ``mung'' part of Mungwall fills
all of free memory (and all subsequently freed memory) with a large, odd,
32-bit value.  An odd value is likely to cause serious problems for any
program that uses wild or uninitialized pointers, or uses memory after it
has been freed.

Unlike Enforcer, Mungwall does not require any special hardware. Mungwall
can run without Enforcer and on non-MMU machines.

Mungwall uses several special 32-bit values to ``mung'' memory which helps
diagnose problems:

   Except when Enforcer is running, Mungwall sets location zero to
   $C0DEDBAD.  Normally, location zero is $00000000.  By putting an odd,
   non-zero value in location zero, any erroneous references to location
   zero are much more likely to show themselves.  For example, a program
   that references  location zero as character array will see a string
   that starts with the ASCII values $C0 $DE $DB $AD, rather than seeing a
   NULL string.

   When Mungwall starts up, it sets all free memory to $ABADCAFE.  If this
   number shows up while an application is running, it is likely that
   someone is referencing memory in the free list.

   When a program allocates memory, Mungwall sets that memory to $DEADF00D
   (Except when allocating memory with MEMF_CLEAR).  When an application
   accidentally accesses its memory before initializing it, the
   application will find the well-known value $DEADF00D rather than some
   random value that happened to be left in memory.

   Mungwall fills deallocated memory with $DEADBEEF, which makes using
   freed memory bugs much more obvious.

The ``wall'' part of Mungwall allocates extra memory before and after
every memory allocation and fills this memory ``wall'' with a fill pattern
(normally $BB) and some information Mungwall uses to perform certain tests
on an application's memory blocks:

   When an application deallocates memory, Mungwall reports when the size
   of the deallocated memory block does not match its size when it was
   allocated.

   Mungwall reports when a memory block's ``walls'' have been overwritten.

   Mungwall reports allocations and deallocations of memory blocks that
   are zero bytes long and deallocations of memory blocks that start at
   location zero.

   Mungwall has an option to ``snoop'' and report on all memory
   allocations and deallocations for all tasks or specific tasks.  This
   feature can be useful when tracking down memory losses.  Because the
   snoop option can generate so many reports, the output can be run
   through the snoopstrip program which will throw away all matching
   allocate/deallocate pairs.

 [The Debugging Setup](amiga-mail/the-debugging-setup.md) 
 [Sample Enforcer Output](amiga-mail/sample-enforcer-output.md) 
 [Sample Mungwall Output](amiga-mail/sample-mungwall-output.md) 
 [Using Enforcer and Mungwall Together](amiga-mail/using-enforcer-and-mungwall-together.md) 
 [A Sample Debugging Session](amiga-mail/a-sample-debugging-session.md) 
 [More Remote Debugging Tips](amiga-mail/more-remote-debugging-tips.md) 
 [Who Should Use Enforcer and Mungwall](amiga-mail/who-should-use-enforcer-and-mungwall.md) 

