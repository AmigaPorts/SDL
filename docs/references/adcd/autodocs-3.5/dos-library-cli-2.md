---
title: dos.library/Cli
manual: autodocs-3.5
chapter: autodocs-3.5
section: dos-library-cli-2
functions: [Cli]
libraries: [dos.library]
---

# dos.library/Cli

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	Cli -- Returns a pointer to the CLI structure of the process (V36)

   SYNOPSIS
	cli_ptr = Cli()
	D0

	struct [CommandLineInterface](autodocs-3.5/include-dos-dosextens-h.md) *Cli(void)

   FUNCTION
	Returns a pointer to the CLI structure of the current process, or NULL
	if the process has no CLI structure.

   RESULT
	cli_ptr - pointer to the CLI structure, or NULL.

   SEE ALSO

---

## See Also

- [Cli — dos.library](../autodocs/dos.library.md#cli)
