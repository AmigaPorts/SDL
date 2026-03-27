---
title: dos.library/SetFileSysTask
manual: autodocs-3.5
chapter: autodocs-3.5
section: dos-library-setfilesystask-2
functions: [Open]
libraries: [dos.library]
---

# dos.library/SetFileSysTask

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	SetFileSysTask -- Sets the default filesystem for the process (V36)

   SYNOPSIS
	oldport = SetFileSysTask(port)
	D0			  D1

	struct [MsgPort](autodocs-3.5/include-exec-ports-h.md) *SetFileSysTask(struct [MsgPort](autodocs-3.5/include-exec-ports-h.md) *)

   FUNCTION
	Sets the default filesystem task's port (pr_FileSystemTask) for the
	current process.

   INPUTS
	port - The pr_MsgPort of the default filesystem for the process

   RESULT
	oldport - The previous FileSysTask value

   SEE ALSO
	[GetFileSysTask()](autodocs-3.5/dos-library-getfilesystask-2.md), [Open()](autodocs-3.5/dos-library-open-2.md)

---

## See Also

- [Open — dos.library](../autodocs/dos.library.md#open)
