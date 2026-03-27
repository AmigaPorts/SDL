---
title: 13 / Preferences in 1.3 and Older Versions / Reading 1.3 Preferences
manual: libraries
chapter: libraries
section: 13-preferences-in-1-3-and-older-versions-reading-1-3
functions: [GetDefPrefs, GetPrefs]
libraries: [intuition.library]
---

# 13 / Preferences in 1.3 and Older Versions / Reading 1.3 Preferences

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Applications can obtain a copy of Preferences by calling the Intuition
function [GetPrefs()](autodocs-2.0/intuition-library-getprefs.md).  In a system in which there is no
devs:system-configuration file, [GetDefPrefs()](autodocs-2.0/intuition-library-getdefprefs.md) can be used to obtain the
Intuition default Preference settings.


```c
    struct Preferences *GetPrefs(struct Preferences *preferences,
                                 LONG size);
    struct Preferences *GetDefPrefs(struct Preferences *preferences,
                                    LONG size);
```
[GetPrefs()](autodocs-2.0/intuition-library-getprefs.md) and [GetDefPrefs()](autodocs-2.0/intuition-library-getdefprefs.md) have two arguments, a pointer to a buffer to
receive the copy of the user Preferences and the size of this buffer.  The
most commonly used data is grouped near the beginning of the [Preferences](libraries/13-preferences-1-3-older-versions-preferences-structure-in.md)
structure and you are free to read only as much as you need.  So, if you
are only interested in the first part of the Preferences structure, you do
not need to allocate a buffer large enough to hold the entire structure.
These functions return a pointer to your buffer if successful, NULL
otherwise.

If you are using Intuition IDCMP for input, you can set the IDCMP flag
[IDCMP_NEWPREFS](libraries/9-event-message-classes-and-flags-other-flags.md) (formerly the NEWPREFS flag under V34 and earlier versions
of the OS).  With this flag set, your program will receive an [IntuiMessage](libraries/9-using-the-idcmp-intuimessages.md)
informing you changes have been made to Preferences.  To get the latest
settings, you would again call [GetPrefs()](autodocs-2.0/intuition-library-getprefs.md).

---

## See Also

- [GetDefPrefs — intuition.library](../autodocs/intuition.library.md#getdefprefs)
- [GetPrefs — intuition.library](../autodocs/intuition.library.md#getprefs)
