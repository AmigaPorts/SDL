---
title: dos.library/FindCliProc
manual: autodocs-3.5
chapter: autodocs-3.5
section: dos-library-findcliproc-2
functions: [Cli, Forbid, MaxCli]
libraries: [dos.library, exec.library]
---

# dos.library/FindCliProc

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	FindCliProc -- returns a pointer to the requested CLI process (V36)

   SYNOPSIS
	proc = FindCliProc(num)
	D0             D1

	struct [Process](autodocs-3.5/include-dos-dosextens-h.md) *FindCliProc(ULONG)

   FUNCTION
	This routine returns a pointer to the CLI process associated with the
	given CLI number.  If the process isn't an active CLI process, NULL is
	returned.  NOTE: should normally be called inside a [Forbid()](autodocs-3.5/exec-library-forbid-2.md), if you
	must use this function at all.

   INPUTS
	num  - [Task](autodocs-3.5/include-exec-tasks-h.md) number of CLI process (range 1-N)

   RESULT
	proc - Pointer to given CLI process

   SEE ALSO
	[Cli()](autodocs-3.5/dos-library-cli-2.md), [Forbid()](autodocs-3.5/exec-library-forbid-2.md), [MaxCli()](autodocs-3.5/dos-library-maxcli-2.md)

---

## See Also

- [Cli — dos.library](../autodocs/dos.library.md#cli)
- [Forbid — exec.library](../autodocs/exec.library.md#forbid)
- [MaxCli — dos.library](../autodocs/dos.library.md#maxcli)
