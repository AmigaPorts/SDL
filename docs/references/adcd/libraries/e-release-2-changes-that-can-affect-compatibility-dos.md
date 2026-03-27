---
title: E / Release 2 Changes That Can Affect Compatibility / DOS
manual: libraries
chapter: libraries
section: e-release-2-changes-that-can-affect-compatibility-dos
functions: [CreateNewProc, Lock]
libraries: [dos.library]
---

# E / Release 2 Changes That Can Affect Compatibility / DOS

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

  * DOS is now written in C and assembler, not BCPL.  The BCPL compiler

    artifact which caused D0 function results to also be in D1 is gone.
    System patches in Release 2 that return some DOS function results in
    both D0 and D1 are not guaranteed to remain in the next release. Fix
    your programs!  Use Scratch to find these problems in your code.
  * DOS now has a real library base with normal [LVO](libraries/17-libraries-and-devices-library-vector-offsets-lvos.md) vectors.

  * Stack usage has all changed (variables, direction).

  * New packet and lock types.  Make sure you are not passing stack

```c
    garbage for the second argument to [Lock()](autodocs-2.0/dos-library-lock.md).
```
  * [Process](libraries/17-introduction-to-exec-multitasking.md) structure is bigger.  "Rolling your own" Process structure

```c
    from a [Task](libraries/21-exec-tasks-task-structure.md) fails.  Use dos.library [System() or CreateNewProc()](libraries/1-design-dos-system-createnewproc-and-con-enhancements.md).
```
  * Unless documented otherwise, you must be a process to call DOS

    functions. DOS function dependence on special process structures can
    change with OS revisions.

---

## See Also

- [CreateNewProc — dos.library](../autodocs/dos.library.md#createnewproc)
- [Lock — dos.library](../autodocs/dos.library.md#lock)
