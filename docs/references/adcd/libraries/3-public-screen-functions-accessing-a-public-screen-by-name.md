---
title: 3 / Public Screen Functions / Accessing a Public Screen by Name
manual: libraries
chapter: libraries
section: 3-public-screen-functions-accessing-a-public-screen-by-name
functions: [GetScreenData, LockPubScreen, UnlockPubScreen]
libraries: [intuition.library]
---

# 3 / Public Screen Functions / Accessing a Public Screen by Name

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The main calls for accessing an existing [public screen](libraries/3-intuition-screens-public-screen-functions.md) are [LockPubScreen()](libraries/3-intuition-screens-public-screen-functions.md)
and [UnlockPubScreen()](libraries/3-intuition-screens-public-screen-functions.md).  To use these functions you need to know the name
of the public screen you want to access.  If you do not know the name of
the public screen or if you are not sure, you can lock the default public
screen with LockPubScreen(NULL).


```c
    struct Screen *LockPubScreen( UBYTE * )
     VOID        UnlockPubScreen( UBYTE * , struct Screen *)
```
These calls enable the application to determine that a [public screen](libraries/3-intuition-screens-public-screen-functions.md)
exists, and to ensure its continued existence while opening a window on
it.  This function also serves as an improvement over the old
[GetScreenData()](libraries/3-other-screen-functions-miscellaneous-screen-functions.md) function from V34 by returning a pointer to the [Screen](libraries/3-screen-data-structures-other-screen-data-structures.md)
structure of the locked screen so that its attributes can be examined.

Be sure to unlock the [public screen](libraries/3-intuition-screens-public-screen-functions.md) when done with it.  Note that once a
window is open on the screen the program does not need to hold the screen
lock, as the window acts as a lock on the screen.  The pointer to the
screen structure is valid as long as a lock on the screen is held by the
application, or the application has a window open on the screen.

Locks should not be held without reason.  Holding unnecessary locks on
screens may prevent the user from closing a [public screen](libraries/3-intuition-screens-public-screen-functions.md) that has no
apparent activity.  Keep in mind that as long as you have a window open on
a public screen, the window acts as a lock preventing the screen from
closing.

Shown here is a simple example of how to find the [Workbench public screen](libraries/3-public-screen-functions-the-default-public-screen-and.md)
using [LockPubScreen()](libraries/3-intuition-screens-public-screen-functions.md) and [UnlockPubScreen()](libraries/3-intuition-screens-public-screen-functions.md).


```c
     [pubscreenbeep.c](libraries/lib-examples-pubscreenbeep-c.md) 
```

---

## See Also

- [GetScreenData — intuition.library](../autodocs/intuition.library.md#getscreendata)
- [LockPubScreen — intuition.library](../autodocs/intuition.library.md#lockpubscreen)
- [UnlockPubScreen — intuition.library](../autodocs/intuition.library.md#unlockpubscreen)
