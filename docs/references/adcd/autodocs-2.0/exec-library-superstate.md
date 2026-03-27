---
title: exec.library/SuperState
manual: autodocs-2.0
chapter: autodocs-2.0
section: exec-library-superstate
functions: [SuperState]
libraries: [exec.library]
---

# exec.library/SuperState

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    SuperState -- enter supervisor state with user stack
SYNOPSIS

```c
    oldSysStack = SuperState()
    D0

    APTR SuperState(void);
```
FUNCTION

    Enter supervisor mode while running on the user's stack. The user
    still has access to user stack variables.  Be careful though, the
    user stack must be large enough to accommodate space for all
    interrupt data -- this includes all possible nesting of interrupts.
    This function does nothing when called from supervisor state.
RESULTS

```c
    oldSysStack - system stack pointer; save this.  It will come in
                  handy when you return to user state.  If the system
                  is already in supervisor mode, oldSysStack is zero.
```
SEE ALSO

```c
    [UserState/Supervisor](autodocs-2.0/exec-library-supervisor.md)
```

---

## See Also

- [SuperState — exec.library](../autodocs/exec.library.md#superstate)
