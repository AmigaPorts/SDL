---
title: D / Errors / Crashes and Memory Corruption
manual: libraries
chapter: libraries
section: d-errors-crashes-and-memory-corruption
functions: []
libraries: []
---

# D / Errors / Crashes and Memory Corruption

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Memory corruption, address errors, and illegal instruction errors are
generally caused by use of an uninitialized, incorrectly initialized, or
already freed/closed pointer or memory.  You may be using the pointer
directly, or it may be one that you placed (or forgot to place) in a
structure passed to system calls.  Or you may be overwriting one of your
arrays, or accidentally modifying or incrementing a pointer later used in
a free/close.  Be sure to test the return of all open/allocation type
functions before using the result, and only close/free things that you
successfully opened/allocated.  Use watchdog/torture utilities such as
Enforcer and MungWall in combination to catch use of uninitialized
pointers or freed memory, and other memory misuse problems.  Use the
debugging tool TNT to get additional debugging information instead of a
Software Error requester.  You may also be overflowing your stack--your
compiler's stack checking option may be able to catch this.  Cut stack
usage by dynamically allocating large structures, buffers, and arrays
which are currently defined inside your functions.

Corruption or crashes can also be caused by passing wrong or missing
arguments to a system call (for example [SetAPen](autodocs-2.0/graphics-library-setapen.md)(3) or SetAPen(win,3),
instead of SetAPen(rp,3)).  C programmers should use function prototypes
to catch such errors.  If using short integers be sure to explicitly type
long constants as long (e.g., 42L). (For example, with short ints, 1 << 17
may become zero).  If corruption is occurring during exit, use [printf()](autodocs-2.0/amiga-lib-printf.md)
(or [KPrintF()](autodocs-2.0/debug-lib-kprintf.md), etc.) with [Delay](autodocs-2.0/dos-library-delay.md)(n) to slow down your cleanup and broadcast
each step. A bad pointer that causes a system crash will often be reported
as an standard 680x0 processor exception $00000003 or 4, or less often a
number in the range of $00000006-B.  Or an Amiga-specific alert number may
result.  See <exec/[alerts.h](autodocs-2.0/includes-exec-alerts-h.md)> for Amiga-specific alert numbers. Also see
"[Crashes--After Exit](libraries/d-errors-crashes-after-exit.md)" below.

