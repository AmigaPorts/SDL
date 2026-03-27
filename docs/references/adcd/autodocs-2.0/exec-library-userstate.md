---
title: exec.library/UserState
manual: autodocs-2.0
chapter: autodocs-2.0
section: exec-library-userstate
functions: []
libraries: []
---

# exec.library/UserState

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    UserState -- return to user state with user stack
SYNOPSIS

```c
    UserState(sysStack)
              D0

    void UserState(APTR);
```
FUNCTION

```c
    Return to user state with user stack, from supervisor state with
    user stack.  This function is normally used in conjunction with the
    [SuperState](autodocs-2.0/exec-library-superstate.md) function above.

    This function must not be called from the user state.
```
INPUT

    sysStack - supervisor stack pointer
BUGS

    This function is broken in V33/34 Kickstart.  Fixed in V1.31 setpatch.
SEE ALSO

```c
    [SuperState/Supervisor](autodocs-2.0/exec-library-supervisor.md)
```
