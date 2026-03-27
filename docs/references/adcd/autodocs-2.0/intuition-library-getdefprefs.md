---
title: intuition.library/GetDefPrefs
manual: autodocs-2.0
chapter: autodocs-2.0
section: intuition-library-getdefprefs
functions: [GetPrefs]
libraries: [intuition.library]
---

# intuition.library/GetDefPrefs

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    GetDefPrefs -- Get a copy of the the Intuition default [Preferences](autodocs-2.0/includes-intuition-preferences-h.md).
```
SYNOPSIS

```c
    Prefs = GetDefPrefs( PrefBuffer, Size )
    D0                   A0          D0

    struct [Preferences](autodocs-2.0/includes-intuition-preferences-h.md) *GetDefPrefs( struct [Preferences](autodocs-2.0/includes-intuition-preferences-h.md) *, WORD );
```
FUNCTION

```c
    Gets a copy of the Intuition default preferences data.  Writes the
    data into the buffer you specify.  The number of bytes you want
    copied is specified by the size argument.

    The default preferences are those that Intuition uses when it
    is first opened.  If no preferences file is found, these are
    the preferences that are used.  These would also be the startup
    preferences in an AmigaDOS-less environment.

    It is legal to take a partial copy of the [Preferences](autodocs-2.0/includes-intuition-preferences-h.md) structure.
    The more pertinent preferences variables have been grouped near
    the top of the structure to facilitate the memory conservation
    that can be had by taking a copy of only some of the [Preferences](autodocs-2.0/includes-intuition-preferences-h.md)
    structure.
```
INPUTS

```c
    PrefBuffer = pointer to the memory buffer to receive your copy of the
            Intuition [Preferences](autodocs-2.0/includes-intuition-preferences-h.md) structure
    Size = the number of bytes in your PrefBuffer, the number of bytes
      you want copied from the system's internal Preference settings
```
RESULT

    Returns your parameter PrefBuffer.
BUGS

SEE ALSO

```c
    [GetPrefs()](autodocs-2.0/intuition-library-getprefs.md)
```

---

## See Also

- [GetPrefs — intuition.library](../autodocs/intuition.library.md#getprefs)
