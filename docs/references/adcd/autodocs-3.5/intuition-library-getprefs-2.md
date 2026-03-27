---
title: intuition.library/GetPrefs
manual: autodocs-3.5
chapter: autodocs-3.5
section: intuition-library-getprefs-2
functions: [GetDefPrefs, GetPrefs, SetPrefs]
libraries: [intuition.library]
---

# intuition.library/GetPrefs

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	GetPrefs -- Get the current Intuition [Preferences](autodocs-3.5/include-intuition-preferences-h.md) structure.

    SYNOPSIS
	Prefs = GetPrefs( PrefBuffer, Size )
	D0		  A0          D0

	struct [Preferences](autodocs-3.5/include-intuition-preferences-h.md) *GetPrefs( struct [Preferences](autodocs-3.5/include-intuition-preferences-h.md) *, WORD );

    FUNCTION
	Gets a copy of the current Intuition [Preferences](autodocs-3.5/include-intuition-preferences-h.md) structure.
	Writes the data into the buffer you specify.  The number of bytes you
	want copied is specified by the size argument.

	It is legal to take a partial copy of the [Preferences](autodocs-3.5/include-intuition-preferences-h.md) structure.
	The more pertinent preferences variables have been grouped near
	the top of the structure to facilitate the memory conservation
	that can be had by taking a copy of only some of the [Preferences](autodocs-3.5/include-intuition-preferences-h.md)
	structure.

	New for V36:  A new and more extensible method for supplying
	[Preferences](autodocs-3.5/include-intuition-preferences-h.md) has been introduced in V36, and relies on file
	system notification.  The Intuition preferences items rely
	also on the IPrefs program.  Certain elements of the
	[Preferences](autodocs-3.5/include-intuition-preferences-h.md) structure have been superseded by this new method.
	As much as possible, the [Preferences](autodocs-3.5/include-intuition-preferences-h.md) structure returned by
	GetPrefs() reflect the current state of [Preferences](autodocs-3.5/include-intuition-preferences-h.md).  However,
	it is impossible to represent some of the V36-style preferences
	items using the existing [Preferences](autodocs-3.5/include-intuition-preferences-h.md) structure.

    INPUTS
	PrefBuffer = pointer to the memory buffer to receive your copy of the
```c
           Intuition [Preferences](autodocs-3.5/include-intuition-preferences-h.md)
```
	Size = the number of bytes in your PrefBuffer, the number of bytes
           you want copied from the system's internal Preference settings

    RESULT
	Returns your parameter PrefBuffer.

    BUGS

    SEE ALSO
	[GetDefPrefs()](autodocs-3.5/intuition-library-getdefprefs-2.md), [SetPrefs()](autodocs-3.5/intuition-library-setprefs-2.md)

---

## See Also

- [GetDefPrefs — intuition.library](../autodocs/intuition.library.md#getdefprefs)
- [GetPrefs — intuition.library](../autodocs/intuition.library.md#getprefs)
- [SetPrefs — intuition.library](../autodocs/intuition.library.md#setprefs)
