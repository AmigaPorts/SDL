---
title: 11 Intuition Special Functions / Intuition and Preferences
manual: libraries
chapter: libraries
section: 11-intuition-special-functions-intuition-and-preferences
functions: [SetPrefs]
libraries: [intuition.library]
---

# 11 Intuition Special Functions / Intuition and Preferences

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The [SetPrefs()](libraries/13-preferences-in-1-3-and-older-versions-setting-1-3.md) function is used to configure Intuition's internal data
states according to a given [Preferences](libraries/13-preferences-1-3-older-versions-preferences-structure-in.md) structure.  This call relies on
the Preferences system used in V34 and earlier versions of the OS.  The
old system has been largely superceded in Release 2.  See the
"[Preferences](libraries/13-preferences.md)" chapter for details.  This routine is called only by:

  * The Preferences program itself after the user changes Preferences

```c
    settings (under V34 and earlier).
```
  * AmigaDOS when the system is being booted up.  AmigaDOS opens the

```c
    devs:system-configuration file and passes the information found there
    to the [SetPrefs()](libraries/13-preferences-in-1-3-and-older-versions-setting-1-3.md) routine.  This way, the user can create an
    environment and have that environment restored every time the system
    is booted.
```
The function takes three arguments:


```c
    struct Preferences *SetPrefs(struct Preferences *prefbuf,
                                 long size, long realThing)
```
The prefbuf argument is a pointer to a Preferences structure that will be
used for Intuition's internal settings.  The  size is the number of bytes
contained in your [Preferences](libraries/13-preferences-1-3-older-versions-preferences-structure-in.md) structure.  Typically, you will use
sizeof(struct Preferences) for this argument.  The realThing argument is a
boolean TRUE or FALSE designating whether or not this is an intermediate
or final version of the Preferences.  The difference is that final changes
to Intuition's internal Preferences settings cause a global broadcast of
NEWPREFS events to every application that is listening for this event.
Intermediate changes may be used, for instance, to update the screen
colors while the user is playing with the color gadgets.


```c
    About SetPrefs().
    -----------------
    The intended use for the [SetPrefs()](libraries/13-preferences-in-1-3-and-older-versions-setting-1-3.md) call is entirely to serve
    the user.  You should never use this routine to make your programming
    or design job easier at the cost of yanking the rug out from beneath
    the user.
```
Refer to the chapter "[Preferences](libraries/13-preferences.md)" for information about the [Preferences](libraries/13-preferences-1-3-older-versions-preferences-structure-in.md)
structure and the new Preferences procedure calls used in Release 2.

---

## See Also

- [SetPrefs — intuition.library](../autodocs/intuition.library.md#setprefs)
