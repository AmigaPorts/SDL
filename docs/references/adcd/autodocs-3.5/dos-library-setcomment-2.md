---
title: dos.library/SetComment
manual: autodocs-3.5
chapter: autodocs-3.5
section: dos-library-setcomment-2
functions: [SetComment, SetProtection]
libraries: [dos.library]
---

# dos.library/SetComment

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	SetComment -- Change a files' comment string

    SYNOPSIS
	success = SetComment( name, comment )
	D0		      D1    D2

	[BOOL](autodocs-3.5/include-exec-types-h.md) SetComment(STRPTR, STRPTR)

    FUNCTION
	SetComment() sets a comment on a file or directory. The comment is
	a pointer to a null-terminated string of up to 80 characters in the
	current ROM filesystem (and RAM:).  Note that not all filesystems
	will support comments (for example, NFS usually will not), or the
	size of comment supported may vary.

    INPUTS
	name    - pointer to a null-terminated string
	comment - pointer to a null-terminated string

    RESULTS
	success - boolean

    SEE ALSO
	[Examine()](autodocs-3.5/dos-library-examine-2.md), [ExNext()](autodocs-3.5/dos-library-exnext-2.md), [SetProtection()](autodocs-3.5/dos-library-setprotection-2.md)

---

## See Also

- [SetComment — dos.library](../autodocs/dos.library.md#setcomment)
- [SetProtection — dos.library](../autodocs/dos.library.md#setprotection)
