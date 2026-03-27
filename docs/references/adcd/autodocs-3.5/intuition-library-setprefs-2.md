---
title: intuition.library/SetPrefs
manual: autodocs-3.5
chapter: autodocs-3.5
section: intuition-library-setprefs-2
functions: [GetDefPrefs, GetPrefs, SetPrefs]
libraries: [intuition.library]
---

# intuition.library/SetPrefs

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	SetPrefs -- Set Intuition preferences data.

    SYNOPSIS
	Prefs = SetPrefs( PrefBuffer, Size, Inform )
	D0		  A0          D0    D1

	struct [Preferences](autodocs-3.5/include-intuition-preferences-h.md) *SetPrefs( struct [Preferences](autodocs-3.5/include-intuition-preferences-h.md) *, [LONG](autodocs-3.5/include-exec-types-h.md), [BOOL](autodocs-3.5/include-exec-types-h.md) );

    FUNCTION
	Sets new preferences values.  Copies the first 'Size' bytes
	from your preferences buffer to the system preferences table,
	and puts them into effect.

	The 'Inform' parameter, if TRUE, indicates that an IDCMP_NEWPREFS
	message is to be sent to all windows that have the IDCMP_NEWPREFS
	IDCMPFlag set.

	It is legal to set a partial copy of the [Preferences](autodocs-3.5/include-intuition-preferences-h.md) structure.
	The most frequently changed values are grouped at the beginning
	of the [Preferences](autodocs-3.5/include-intuition-preferences-h.md) structure.

	New for V36:  A new and more extensible method for supplying
	[Preferences](autodocs-3.5/include-intuition-preferences-h.md) has been introduced in V36, and relies on file
	system notification.  The Intuition preferences items rely
	also on the IPrefs program.  Certain elements of the
	[Preferences](autodocs-3.5/include-intuition-preferences-h.md) structure have been superseded by this new method.
	(Elements are generally superseded as new hardware or software
	features demand more information than fits in struct [Preferences](autodocs-3.5/include-intuition-preferences-h.md).
	Parts of struct [Preferences](autodocs-3.5/include-intuition-preferences-h.md) must be ignored so that applications
	calling [GetPrefs()](autodocs-3.5/intuition-library-getprefs-2.md), modifying some other part of struct [Preferences](autodocs-3.5/include-intuition-preferences-h.md),
	then calling SetPrefs(), don't end up truncating the extended
	data).

	Pointer Preferences:  Starting with V36, pointer changes
	submitted through SetPrefs() are only heeded until the first
	time IPrefs informs Intuition of a V36-style pointer preferences
	file.  In V39 and higher, only the pointer from the initial
	SetPrefs() (i.e. devs:system-configuration) is heeded.

	Palette Preferences:  Starting with V39, color changes submitted
	through SetPrefs() are ignored after the first time IPrefs sends
	Intuition new style palette preferences.

	FontHeight and LaceWB:  These are only respected from
	devs:system-configuration.

	[View](autodocs-3.5/include-graphics-view-h.md) centering and size:  Changes to ViewX/YOffset and
	Row/ColumnSizeChange only apply to the default monitor
	(NTSC or PAL), and not to other monitors such as Productivity.

	Other fields may be superseded in the future.

    INPUTS
	PrefBuffer = pointer to the memory buffer which contains your
	    desired settings for Intuition preferences
	Size = the number of bytes in your PrefBuffer, the number of bytes
           you want copied to the system's internal preference settings
	Inform = whether you want the information of a new preferences
	    setting propagated to all windows.

    NOTES
	Unless you are responding to a user's explicit request to
	change [Preferences](autodocs-3.5/include-intuition-preferences-h.md) (for example, you are writing a [Preferences](autodocs-3.5/include-intuition-preferences-h.md)
	editor), you should probably avoid using this function.
	The user's [Preferences](autodocs-3.5/include-intuition-preferences-h.md) should be respected, not overridden.

    RESULT
	Returns your parameter PrefBuffer.

    BUGS

    SEE ALSO
	[GetDefPrefs()](autodocs-3.5/intuition-library-getdefprefs-2.md), [GetPrefs()](autodocs-3.5/intuition-library-getprefs-2.md)

---

## See Also

- [GetDefPrefs — intuition.library](../autodocs/intuition.library.md#getdefprefs)
- [GetPrefs — intuition.library](../autodocs/intuition.library.md#getprefs)
- [SetPrefs — intuition.library](../autodocs/intuition.library.md#setprefs)
