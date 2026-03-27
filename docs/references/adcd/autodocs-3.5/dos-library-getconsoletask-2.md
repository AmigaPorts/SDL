---
title: dos.library/GetConsoleTask
manual: autodocs-3.5
chapter: autodocs-3.5
section: dos-library-getconsoletask-2
functions: [Open]
libraries: [dos.library]
---

# dos.library/GetConsoleTask

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	GetConsoleTask -- Returns the default console for the process (V36)

   SYNOPSIS
	port = GetConsoleTask()
	D0

	struct [MsgPort](autodocs-3.5/include-exec-ports-h.md) *GetConsoleTask(void)

   FUNCTION
	Returns the default console task's port (pr_ConsoleTask) for the
	current process.

   RESULT
	port - The pr_MsgPort of the console handler, or NULL.

   SEE ALSO
	[SetConsoleTask()](autodocs-3.5/dos-library-setconsoletask-2.md), [Open()](autodocs-3.5/dos-library-open-2.md)

---

## See Also

- [Open — dos.library](../autodocs/dos.library.md#open)
