---
title: D / Errors / Hang--Whole System
manual: libraries
chapter: libraries
section: d-errors-hang-whole-system
functions: [Disable, Enable]
libraries: [exec.library]
---

# D / Errors / Hang--Whole System

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

This is generally caused by a [Disable()](libraries/21-task-exclusion-disabling-tasks.md) without a corresponding [Enable()](libraries/21-task-exclusion-disabling-tasks.md).
It can also be caused by memory corruption, especially corruption of low
memory.  See "[Crashes and Memory Corruption](libraries/d-errors-crashes-and-memory-corruption.md)".

---

## See Also

- [Disable — exec.library](../autodocs/exec.library.md#disable)
- [Enable — exec.library](../autodocs/exec.library.md#enable)
