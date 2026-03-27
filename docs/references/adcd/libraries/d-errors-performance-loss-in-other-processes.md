---
title: D / Errors / Performance Loss in Other Processes
manual: libraries
chapter: libraries
section: d-errors-performance-loss-in-other-processes
functions: [Disable, Forbid]
libraries: [exec.library]
---

# D / Errors / Performance Loss in Other Processes

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

This is often caused by a one program doing one or more of the following:
busy waiting or polling; running at a higher priority; doing lengthy
[Forbid()](libraries/21-task-exclusion-forbidding-task-switching.md)s, [Disable()](libraries/21-task-exclusion-disabling-tasks.md)s, or interrupts.

---

## See Also

- [Disable — exec.library](../autodocs/exec.library.md#disable)
- [Forbid — exec.library](../autodocs/exec.library.md#forbid)
