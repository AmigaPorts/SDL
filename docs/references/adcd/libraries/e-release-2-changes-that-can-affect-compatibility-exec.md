---
title: E / Release 2 Changes That Can Affect Compatibility / Exec
manual: libraries
chapter: libraries
section: e-release-2-changes-that-can-affect-compatibility-exec
functions: [Forbid, Permit, Wait]
libraries: [exec.library]
---

# E / Release 2 Changes That Can Affect Compatibility / Exec

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

  * Do not jump to location $FC0002 -- the start of the ROM under

    1.3 -- as part of performing a system RESET.  The 2.04 Kickstart
    ROM has a temporary compatibility hack called "Kickety-Split" which
    is a redirecting jump at $FC0002.  This hack does not appear on the
    A3000 ROM and due to space considerations will not appear on future
    machines.
  * Everything has moved.

  * The Supervisor stack is not in the same place as it was under 1.3.

```c
    This has caused problems for some games that completely take over the
    Amiga.  If your program goes into [Supervisor mode](libraries/21-processor-and-cache-control-supervisor-mode.md), you must either
    respect allocated memory or provide your own Supervisor stack when
    taking over the machine.
```
  * [ExecBase](autodocs-2.0/includes-exec-execbase-h.md) is moved to expansion memory if possible.  Before, ExecBase

    would only end up in one of two fixed locations.  Now, ColdCapture
    may be called after expansion memory has been configured.
  * Exception/Interrupt vectors may move.  This means the 68010 and above

```c
    Vector Base Register (VBR) may contain a non-zero value.  Poking
    assumed low memory vector addresses may have no effect.  You must
    read the VBR on 68010 and above to find the base.
```
  * No longer tolerant of wild [Forbid()](libraries/21-task-exclusion-forbidding-task-switching.md) counts.  Under 1.3, sometimes

```c
    this bug could go unnoticed.  Make sure that all Forbid()s are
    matched with one and only one [Permit()](libraries/21-task-exclusion-forbidding-task-switching.md) (and vice versa).
```
  * When an Exec device gets an [IORequest](libraries/19-accessing-a-device-creating-an-i-o-request.md), it must validate [io_Command](autodocs-2.0/includes-exec-io-h.md).

```c
    If the io_Command is 0 or out of range, the device must return
    [IOERR_NOCMD](autodocs-2.0/includes-exec-errors-h.md) and take no other action.  The filesystem now sends new
    commands and expects older devices to properly ignore them.
```
  * A fix to task-switching in Release 2 allows a busy task to properly

```c
    regain the processor after an interrupt until either its quantum (4
    vertical blanks) is up or a higher priority task preempts it.  This
    can dramatically change the behavior of multitask programs where one
    task busyloops while another same-priority task [Wait()](libraries/22-the-signal-system-waiting-for-a-signal.md)s.  See
    "[Task Switching](libraries/e-additional-information-task-switching.md)" in the "Additional Information" section below.
```

---

## See Also

- [Forbid — exec.library](../autodocs/exec.library.md#forbid)
- [Permit — exec.library](../autodocs/exec.library.md#permit)
- [Wait — exec.library](../autodocs/exec.library.md#wait)
