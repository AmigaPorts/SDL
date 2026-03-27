---
title: dos.library/MaxCli
manual: autodocs-3.5
chapter: autodocs-3.5
section: dos-library-maxcli-2
functions: [Cli, FindCliProc, MaxCli]
libraries: [dos.library]
---

# dos.library/MaxCli

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	MaxCli -- returns the highest CLI process number possibly in use (V36)

   SYNOPSIS
	number = MaxCli()
	D0

	[LONG](autodocs-3.5/include-exec-types-h.md) MaxCli(void)

   FUNCTION
	Returns the highest CLI number that may be in use.  CLI numbers are
	reused, and are usually as small as possible.  To find all CLIs, scan
	using [FindCliProc()](autodocs-3.5/dos-library-findcliproc-2.md) from 1 to MaxCLI().  The number returned by
	MaxCli() may change as processes are created and destroyed.

   RESULT
	number - The highest CLI number that _may_ be in use.

   SEE ALSO
	[FindCliProc()](autodocs-3.5/dos-library-findcliproc-2.md), [Cli()](autodocs-3.5/dos-library-cli-2.md)

---

## See Also

- [Cli — dos.library](../autodocs/dos.library.md#cli)
- [FindCliProc — dos.library](../autodocs/dos.library.md#findcliproc)
- [MaxCli — dos.library](../autodocs/dos.library.md#maxcli)
