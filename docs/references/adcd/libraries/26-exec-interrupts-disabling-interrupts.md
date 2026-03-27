---
title: 26 Exec Interrupts / Disabling Interrupts
manual: libraries
chapter: libraries
section: 26-exec-interrupts-disabling-interrupts
functions: [Disable, Enable]
libraries: [exec.library]
---

# 26 Exec Interrupts / Disabling Interrupts

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

As mentioned in the "[Exec Tasks](libraries/21-task-exclusion-disabling-tasks.md)" chapter, it is sometimes necessary to
disable interrupts when examining or modifying certain shared system data
structures.  However, for proper system operation, interrupts should never
be disabled unless absolutely necessary, and never for more than 250
microseconds.  Interrupt disabling is controlled with the [Disable()](libraries/21-task-exclusion-disabling-tasks.md) and
[Enable()](libraries/21-task-exclusion-disabling-tasks.md) functions. Although assembler DISABLE and ENABLE macros are
provided, we strongly suggest that you use the system functions rather
than the macros for upwards compatibility and smaller code size.

In some system code, there are nested disabled sections.  Such code
requires that interrupts be disabled with the first [Disable()](libraries/21-task-exclusion-disabling-tasks.md) and not
re-enabled until the last [Enable()](libraries/21-task-exclusion-disabling-tasks.md).  The system Enable() and Disable()
functions are designed to permit this sort of nesting.

[Disable()](libraries/21-task-exclusion-disabling-tasks.md) increments a counter to track how many levels of disable have
been issued.  Only 126 levels of nesting are permitted. [Enable()](libraries/21-task-exclusion-disabling-tasks.md)
decrements the counter, and reenables interrupts when the last disable
level has been exited.

---

## See Also

- [Disable — exec.library](../autodocs/exec.library.md#disable)
- [Enable — exec.library](../autodocs/exec.library.md#enable)
