---
title: Exec
manual: amiga-mail
chapter: amiga-mail
section: exec
functions: [Forbid, Wait]
libraries: [exec.library]
---

# Exec

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

* Do not jump to location $FC0002 as part of performing a system RESET.
  Many RESET functions jumped to what was the start of the ROM under 1.3.
  The 2.0 ROM is twice the size.  We've added a temporary compatibility
  hack called ``Kickety-Split'' to the 2.04 Kickstart ROM.  The ROM is
  split into two halves with a redirecting jump at $FC0002.  This hack
  does not appear on the A3000 and due to space considerations will not
  appear on future machines.

* Everything has moved.

* The Supervisor stack is not in the same place as it was under 1.3.
  This has caused problems for some games that completely take over the
  Amiga.  If your program goes into Supervisor mode, you must either
  respect allocated memory or provide your own Supervisor stack when
  taking over the machine.

* ExecBase is moved to expansion memory if possible.  Previously,
  ExecBase would only end up in one of two fixed locations.  As a result,
  ColdCapture may be called after expansion memory has been configured.
  Great pains were taken to make this compatible.

* Exception/Interrupt vectors may move.  This means the 68010 and above
  Vector Base Register (VBR) may contain a non-zero value.  Poking assumed
  low memory vector addresses may have no effect.  You must read the VBR
  on 68010 and above to find the base.

* No longer tolerant of wild Forbid() counts.  Under 1.3, sometimes this
  bug could go unnoticed.  Make sure that all Forbid's are matched with
  one and only one Permit (and vice versa).

* When an Exec device gets an IORequest, it must validate io_Command.
  If the io_Command is 0 or out of range, the device must return
  IOERR_NOCMD and take no other action.  The filesystem now sends new
  commands and expects older devices to properly ignore them.

* A 2.0 fix to task-switching allows a busy task to properly regain the
  processor after an interrupt until either its quantum (4 vertical
  blanks) is up or a higher priority task preempts it.  This can
  dramatically change the behavior of multitask programs where one task
  busyloops while another same-priority task Wait()s.  See Task Switching
  in the Additional Information section at the end of this document.

---

## See Also

- [Forbid — exec.library](../autodocs/exec.library.md#forbid)
- [Wait — exec.library](../autodocs/exec.library.md#wait)
