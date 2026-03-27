---
title: MultiDirectory Assigns
manual: amiga-mail
chapter: amiga-mail
section: multidirectory-assigns
functions: [AssignAdd, AssignLock, GetDeviceProc]
libraries: [dos.library]
---

# MultiDirectory Assigns

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

As of V36 it is possible to have a logical device assignment to more than
one directory (see the dos.library Autodocs for AssignLock()/AssignAdd()).
Since the user can utilize this with the C:Assign command, it is good
practice to support this feature.  The shell itself supports
multidirectory assigns, although not all C: commands do.  In general, when
your application is presented with only a device name to scan, you should
check if it is an assignment.  If it is, use GetDeviceProc() to get the
handler for it, process it, and loop until GetDeviceProc() returns NULL,
indicating there are no more directories for this assign.  See the
Autodocs for details.

The program [Find.c](amiga-mail/ii-49-find-c.md) is a more realistic example of the usage of patterns
and ExAll() and shows a method of supporting multidirectory assigns.  It
scans one or more directories or volumes for the occurrence of a
particular pattern.  This example recursively scans subdirectories which
means that Find.c may need more stack space than normal to keep from
overflowing the stack.  Find.c has two required arguments, a pattern and
one or more directories to examine.  It has two keywords, FILES and DIRS,
to tell it to scan only for files or directories, respectively.  The ALL
keyword instructs Find.c to recurse into subdirectories when it encounters
them.

---

## See Also

- [AssignAdd — dos.library](../autodocs/dos.library.md#assignadd)
- [AssignLock — dos.library](../autodocs/dos.library.md#assignlock)
- [GetDeviceProc — dos.library](../autodocs/dos.library.md#getdeviceproc)
