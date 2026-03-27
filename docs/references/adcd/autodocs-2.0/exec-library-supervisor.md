---
title: exec.library/Supervisor
manual: autodocs-2.0
chapter: autodocs-2.0
section: exec-library-supervisor
functions: [Supervisor]
libraries: [exec.library]
---

# exec.library/Supervisor

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    Supervisor -- trap to a short supervisor mode function
SYNOPSIS

```c
    result = Supervisor(userFunc)
    Rx                   A5

    ULONG Supervisor(void *);
```
FUNCTION

```c
    Allow a normal user-mode program to execute a short assembly language
    function in the supervisor mode of the processor.  Supervisor() does
    not modify or save registers; the user function has full access to the
    register set.   All rules that apply to interrupt code must be
    followed.  In addition, no system calls are permitted.  The function
    must end with an RTE instruction.
```
EXAMPLE

```c
            ;Obtain the Exception Vector base.  68010 or greater only!
            MOVECtrap:      movec.l VBR,d0  ;$4e7a,$0801
                            rte
```
INPUTS

    userFunc - A pointer to a short assembly language function ending
               in RTE.  The function has full access to the register set.
RESULTS

    result   - Whatever values the userFunc left in the registers.
SEE ALSO

```c
    [SuperState](autodocs-2.0/exec-library-superstate.md),[UserState](autodocs-2.0/exec-library-userstate.md)
```

---

## See Also

- [Supervisor — exec.library](../autodocs/exec.library.md#supervisor)
