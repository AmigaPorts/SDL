---
title: graphics.library/WaitTOF
manual: autodocs-3.5
chapter: autodocs-3.5
section: graphics-library-waittof-2
functions: [Signal, Wait, WaitTOF]
libraries: [exec.library, graphics.library]
---

# graphics.library/WaitTOF

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME

```c
       WaitTOF -- [Wait](autodocs-3.5/exec-library-wait-2.md) for the top of the next video frame.
```
   SYNOPSIS

```c
       WaitTOF()
```
	void WaitTOF( void );

   FUNCTION

```c
       [Wait](autodocs-3.5/exec-library-wait-2.md)  for vertical blank to occur and all vertical blank
       interrupt routines to complete before returning to caller.
```
   INPUTS

       none
   RESULT
	Places this task on the TOF wait queue. When the vertical blank
	interrupt comes around, the interrupt service routine will fire off
	signals to all the tasks doing WaitTOF. The highest priority task
	ready will get to run then.

   BUGS

   SEE ALSO
	[exec.library/Wait()](autodocs-3.5/exec-library-wait-2.md) [exec.library/Signal()](autodocs-3.5/exec-library-signal-2.md)

---

## See Also

- [Signal — exec.library](../autodocs/exec.library.md#signal)
- [Wait — exec.library](../autodocs/exec.library.md#wait)
- [WaitTOF — graphics.library](../autodocs/graphics.library.md#waittof)
