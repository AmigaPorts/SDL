---
title: exec.library/Enable
manual: autodocs-2.0
chapter: autodocs-2.0
section: exec-library-enable
functions: [Disable, Enable]
libraries: [exec.library]
---

# exec.library/Enable

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    Enable -- permit system interrupts to resume.
SYNOPSIS

```c
    Enable();

    void Enable(void);
```
FUNCTION

```c
    Allow system interrupts to again occur normally, after a matching
    [Disable()](autodocs-2.0/exec-library-disable.md) has been executed.
```
RESULTS

```c
    [Interrupt](autodocs-2.0/includes-exec-interrupts-h.md) processing is restored to normal operation. The
    programmer must execute exactly one call to Enable() for every call
    to [Disable()](autodocs-2.0/exec-library-disable.md).
```
NOTE

    This call is guaranteed to preserve all registers.
SEE ALSO

    Forbid, Permit, Disable

---

## See Also

- [Disable — exec.library](../autodocs/exec.library.md#disable)
- [Enable — exec.library](../autodocs/exec.library.md#enable)
