---
title: exec.library/Permit
manual: autodocs-2.0
chapter: autodocs-2.0
section: exec-library-permit
functions: [Forbid, Permit]
libraries: [exec.library]
---

# exec.library/Permit

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    Permit -- permit task rescheduling.
SYNOPSIS

```c
    Permit()

    void Permit(void);
```
FUNCTION

```c
    Allow other tasks to be scheduled to run by the dispatcher, after a
    matching [Forbid()](autodocs-2.0/exec-library-forbid.md) has been executed.
```
RESULTS

```c
    Other tasks will be rescheduled as they are ready to run. In order
    to restore normal task rescheduling, the programmer must execute
    exactly one call to Permit() for every call to [Forbid()](autodocs-2.0/exec-library-forbid.md).
```
NOTE

    This call is guaranteed to preserve all registers.
SEE ALSO

    Forbid, Disable, Enable

---

## See Also

- [Forbid — exec.library](../autodocs/exec.library.md#forbid)
- [Permit — exec.library](../autodocs/exec.library.md#permit)
