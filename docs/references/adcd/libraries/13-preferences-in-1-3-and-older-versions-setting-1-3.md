---
title: 13 / Preferences in 1.3 and Older Versions / Setting 1.3 Preferences
manual: libraries
chapter: libraries
section: 13-preferences-in-1-3-and-older-versions-setting-1-3
functions: [SetPrefs]
libraries: [intuition.library]
---

# 13 / Preferences in 1.3 and Older Versions / Setting 1.3 Preferences

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The instance of the [Preferences](libraries/13-preferences-1-3-older-versions-preferences-structure-in.md) structure in memory can be changed with
the Intuition [SetPrefs()](autodocs-2.0/intuition-library-setprefs.md) function:


```c
    struct Preferences *SetPrefs(struct Preferences *preferences,
                                 LONG size, BOOL inform);
```
In addition to a buffer holding the [Preferences](libraries/13-preferences-1-3-older-versions-preferences-structure-in.md) structure, and the buffer
size, this function takes an argument which indicates whether an
[IDCMP_NEWPREFS](libraries/9-event-message-classes-and-flags-other-flags.md) message should be broadcast to windows which have this flag
set in the [Window](libraries/4-intuition-windows-the-window-structure.md).IDCMPFlags field of their window.


```c
    Avoid Using [SetPrefs()](autodocs-2.0/intuition-library-setprefs.md).
    -----------------------
    This function is normally only used by Preferences-like utilities.
    There should be no need for a normal application to set the system
    Preferences with SetPrefs().
```

---

## See Also

- [SetPrefs — intuition.library](../autodocs/intuition.library.md#setprefs)
