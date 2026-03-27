---
title: intuition.library/SetPrefs
manual: autodocs-2.0
chapter: autodocs-2.0
section: intuition-library-setprefs
functions: [GetDefPrefs, GetPrefs, SetPrefs]
libraries: [intuition.library]
---

# intuition.library/SetPrefs

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    SetPrefs -- Set Intuition preferences data.
SYNOPSIS

```c
    Prefs = SetPrefs( PrefBuffer, Size, Inform )
    D0                A0          D0    D1

    struct [Preferences](autodocs-2.0/includes-intuition-preferences-h.md) *SetPrefs( struct [Preferences](autodocs-2.0/includes-intuition-preferences-h.md) *, LONG, BOOL );
```
FUNCTION

```c
    Sets new preferences values.  Copies the first 'Size' bytes
    from your preferences buffer to the system preferences table,
    and puts them into effect.

    The 'Inform' parameter, if TRUE, indicates that an IDCMP_NEWPREFS
    message is to be sent to all windows that have the IDCMP_NEWPREFS
    IDCMPFlag set.

    It is legal to set a partial copy of the [Preferences](autodocs-2.0/includes-intuition-preferences-h.md) structure.
    The most frequently changed values are grouped at the beginning
    of the [Preferences](autodocs-2.0/includes-intuition-preferences-h.md) structure.

    New for V36:  A new and more extensible method for supplying
    [Preferences](autodocs-2.0/includes-intuition-preferences-h.md) has been introduced in V36, and relies on file
    system notification.  The Intuition preferences items rely
    also on the IPrefs program.  Certain elements of the
    [Preferences](autodocs-2.0/includes-intuition-preferences-h.md) structure have been superceded by this new method.
    Pointer changes submitted through SetPrefs() are only heeded
    until the first time IPrefs informs Intuition of a V36-style
    pointer.ilbm preferences file.  The [Preferences](autodocs-2.0/includes-intuition-preferences-h.md) FontHeight and
    LaceWB fields are respected only from the system-configuration
    file, and never thereafter.  As well, the view centering and
    size apply only to the default monitor, and not to such modes
    as Productivity.  Other fields may be superceded in the future.
```
INPUTS

```c
    PrefBuffer = pointer to the memory buffer which contains your
        desired settings for Intuition preferences
    Size = the number of bytes in your PrefBuffer, the number of bytes
       you want copied to the system's internal preference settings
    Inform = whether you want the information of a new preferences
        setting propagated to all windows.
```
NOTES

```c
    Unless you are responding to a user's explicit request to
    change [Preferences](autodocs-2.0/includes-intuition-preferences-h.md) (for example, you are writing a [Preferences](autodocs-2.0/includes-intuition-preferences-h.md)
    editor), you should probably avoid using this function.
    The user's [Preferences](autodocs-2.0/includes-intuition-preferences-h.md) should be respected, not overridden.
```
RESULT

    Returns your parameter PrefBuffer.
BUGS

SEE ALSO

```c
    [GetDefPrefs()](autodocs-2.0/intuition-library-getdefprefs.md), [GetPrefs()](autodocs-2.0/intuition-library-getprefs.md)
```

---

## See Also

- [GetDefPrefs — intuition.library](../autodocs/intuition.library.md#getdefprefs)
- [GetPrefs — intuition.library](../autodocs/intuition.library.md#getprefs)
- [SetPrefs — intuition.library](../autodocs/intuition.library.md#setprefs)
