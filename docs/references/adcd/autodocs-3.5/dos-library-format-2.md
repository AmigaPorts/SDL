---
title: dos.library/Format
manual: autodocs-3.5
chapter: autodocs-3.5
section: dos-library-format-2
functions: [Format]
libraries: [dos.library]
---

# dos.library/Format

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	Format -- Causes a filesystem to initialize itself (V36)

   SYNOPSIS
	success = Format(filesystem, volumename, dostype)
	D0                   D1          D2         D3

	[BOOL](autodocs-3.5/include-exec-types-h.md) Format(STRPTR, [STRPTR](autodocs-3.5/include-exec-types-h.md), ULONG)

   FUNCTION
	Interface for initializing new media on a device.  This causes the
	filesystem to write out an empty disk structure to the media, which
	should then be ready for use.  This assumes the media has been low-
	level formatted and verified already.

	The filesystem should be inhibited before calling Format() to make
	sure you don't get an ERROR_OBJECT_IN_USE.

   INPUTS
	filesystem - Name of device to be formatted.  ':' must be supplied.
	volumename - Name for volume (if supported).  No ':'.
	dostype    - Type of format, if filesystem supports multiple types.

   RESULT
	success - Success/failure indicator.

   BUGS
	Existed, but was non-functional in V36 dos.  (The volumename wasn't
	converted to a BSTR.)  Workaround: require V37, or under V36
	convert volumename to a [BPTR](autodocs-3.5/include-dos-dos-h.md) to a BSTR before calling Format().
	Note: a number of printed packet docs for ACTION_FORMAT are wrong
	as to the arguments.

   SEE ALSO

---

## See Also

- [Format — dos.library](../autodocs/dos.library.md#format)
