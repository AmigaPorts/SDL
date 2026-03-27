---
title: DOS
manual: amiga-mail
chapter: amiga-mail
section: dos
functions: [Lock]
libraries: [dos.library]
---

# DOS

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

* DOS is now written in C and assembler, not BCPL.  The BCPL compiler
  artifact which caused D0 function results to also be in D1 is gone.  2.0
  compatibility patches which return some DOS function results in both D0
  and D1 are not guaranteed to remain in the next release.  Fix your
  programs! Use Scratch to find these problems in your code.

* DOS now has a real library base with normal LVO vectors.

* Stack usage has all changed (variables, direction).

* New packet and lock types.  Make sure you are not passing stack
  garbage for the second argument to Lock().

* Process structure is bigger.  ``Rolling your own'' Process structure
  from a Task fails.

* Unless documented otherwise, you must be a process to call DOS
  functions. DOS function dependence on special process structures can
  change with OS revisions.

---

## See Also

- [Lock — dos.library](../autodocs/dos.library.md#lock)
