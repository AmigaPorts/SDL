---
title: dos.library/SetConsoleTask
manual: autodocs-3.5
chapter: autodocs-3.5
section: dos-library-setconsoletask-2
functions: [Open]
libraries: [dos.library]
---

# dos.library/SetConsoleTask

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	SetConsoleTask -- Sets the default console for the process (V36)

   SYNOPSIS
	oldport = SetConsoleTask(port)
	D0			  D1

	struct [MsgPort](autodocs-3.5/include-exec-ports-h.md) *SetConsoleTask(struct [MsgPort](autodocs-3.5/include-exec-ports-h.md) *)

   FUNCTION
	Sets the default console task's port (pr_ConsoleTask) for the
	current process.

   INPUTS
	port - The pr_MsgPort of the default console handler for the process

   RESULT
	oldport - The previous ConsoleTask value.

   SEE ALSO
	[GetConsoleTask()](autodocs-3.5/dos-library-getconsoletask-2.md), [Open()](autodocs-3.5/dos-library-open-2.md)

---

## See Also

- [Open — dos.library](../autodocs/dos.library.md#open)
