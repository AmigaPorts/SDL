---
title: graphics.library/WaitTOF
manual: autodocs-2.0
chapter: autodocs-2.0
section: graphics-library-waittof
functions: [Signal, Wait, WaitTOF]
libraries: [exec.library, graphics.library]
---

# graphics.library/WaitTOF

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    WaitTOF -- Wait for the top of the next video frame.
SYNOPSIS

```c
    WaitTOF()

    void WaitTOF( void );
```
FUNCTION

    Wait  for vertical blank to occur and all vertical blank
    interrupt routines to complete before returning to caller.
INPUTS

    none
RESULT

    Places this task on the TOF wait queue. When the vertical blank
    interupt comes around, the interrupt service routine will fire off
    signals to all the tasks doing WaitTOF. The highest priority task
    ready will get to run then.
BUGS

SEE ALSO

```c
    [exec.library/Wait()](autodocs-2.0/exec-library-wait.md) [exec.library/Signal()](autodocs-2.0/exec-library-signal.md)
```

---

## See Also

- [Signal — exec.library](../autodocs/exec.library.md#signal)
- [Wait — exec.library](../autodocs/exec.library.md#wait)
- [WaitTOF — graphics.library](../autodocs/graphics.library.md#waittof)
