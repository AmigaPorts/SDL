---
title: exec.library/FreeTrap
manual: autodocs-2.0
chapter: autodocs-2.0
section: exec-library-freetrap
functions: []
libraries: []
---

# exec.library/FreeTrap

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    FreeTrap -- free a processor trap
SYNOPSIS

```c
    FreeTrap(trapNum)
             D0

    void FreeTrap(ULONG);
```
FUNCTION

    This function frees a previously allocated trap number for reuse.
    This call must be performed while running in the same task in which
    the trap was allocated.
WARNING

    Traps may not be allocated or freed from exception handling code.
INPUTS

```c
    trapNum - the trap number to free {of 0..15}
```
