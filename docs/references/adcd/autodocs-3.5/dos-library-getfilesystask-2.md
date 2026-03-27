---
title: dos.library/GetFileSysTask
manual: autodocs-3.5
chapter: autodocs-3.5
section: dos-library-getfilesystask-2
functions: [Open]
libraries: [dos.library]
---

# dos.library/GetFileSysTask

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	GetFileSysTask -- Returns the default filesystem for the process (V36)

   SYNOPSIS
	port = GetFileSysTask()
	D0

	struct [MsgPort](autodocs-3.5/include-exec-ports-h.md) *GetFileSysTask(void)

   FUNCTION
	Returns the default filesystem task's port (pr_FileSystemTask) for the
	current process.

   RESULT
	port - The pr_MsgPort of the filesystem, or NULL.

   SEE ALSO
	[SetFileSysTask()](autodocs-3.5/dos-library-setfilesystask-2.md), [Open()](autodocs-3.5/dos-library-open-2.md)

---

## See Also

- [Open — dos.library](../autodocs/dos.library.md#open)
