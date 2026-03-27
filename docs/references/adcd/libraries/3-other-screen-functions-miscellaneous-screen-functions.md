---
title: 3 / Other Screen Functions / Miscellaneous Screen Functions
manual: libraries
chapter: libraries
section: 3-other-screen-functions-miscellaneous-screen-functions
functions: [DisplayBeep, GetScreenData, LockPubScreen, ShowTitle]
libraries: [intuition.library]
---

# 3 / Other Screen Functions / Miscellaneous Screen Functions

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Three other functions used with screens are DisplayBeep(), [ShowTitle()](autodocs-2.0/intuition-library-showtitle.md) and
[GetScreenData()](autodocs-2.0/intuition-library-getscreendata.md).  DisplayBeep() flashes the screen colors to inform the
user of an error or problem.


```c
    VOID DisplayBeep( struct Screen *myscreen )
```
Since not all users will have speakers attached to the system,
DisplayBeep() can be used to provide a visible bell.  DisplayBeep() can
beep any single screen or, if myscreen is set to NULL, all screens.

[ShowTitle()](autodocs-2.0/intuition-library-showtitle.md) determines whether the screen's title bar will be displayed in
front of or behind any backdrop windows on the screen.


```c
    VOID ShowTitle( struct Screen *myscreen, BOOL infront )
```
By default, the screen's title bar is set to display in front of backdrop
windows.  Call this function with infront set to FALSE to put the screen
title bar behind backdrop windows.  This can also be set when the screen
is opened with the [SA_ShowTitle](libraries/3-custom-screen-functions-screen-attributes.md) tag.

Under 1.3 (V34) and earlier versions of the Amiga OS, applications used
the [GetScreenData()](autodocs-2.0/intuition-library-getscreendata.md) to get a copy of the Workbench [Screen](libraries/3-screen-data-structures-other-screen-data-structures.md) structure in
order to examine its attributes.


```c
    success = BOOL GetScreenData( APTR buffer, UWORD bufsize,
                                  UWORD type, struct Screen *scr)
```
If successful, [GetScreenData()](autodocs-2.0/intuition-library-getscreendata.md) copies a given [Screen](libraries/3-screen-data-structures-other-screen-data-structures.md) structure to a buffer
supplied by the application.  A copy of the Workbench Screen data can be
obtained without knowing its location in memory using GetScreenData(buf,
sizeof(struct Screen), WBENCHSCREEN, NULL).  However, for Release 2 and
later versions of the operating system, this function may return some
false information about the Workbench screen.  This false screen
information helps prevent older applications that used the call from
malfunctioning when run in a Release 2 system that has Workbench set up
with one of the newer modes.

Applications that want to get information on the Workbench screen should
use [GetScreenData()](autodocs-2.0/intuition-library-getscreendata.md) when run under 1.3 and [LockPubScreen()](libraries/3-intuition-screens-public-screen-functions.md) when run under
under Release 2.  For more about LockPubScreen() and [Workbench](libraries/3-public-screen-functions-the-default-public-screen-and.md), see the
section on "[Public Screen Functions](libraries/3-intuition-screens-public-screen-functions.md)" earlier in this chapter.

---

## See Also

- [DisplayBeep — intuition.library](../autodocs/intuition.library.md#displaybeep)
- [GetScreenData — intuition.library](../autodocs/intuition.library.md#getscreendata)
- [LockPubScreen — intuition.library](../autodocs/intuition.library.md#lockpubscreen)
- [ShowTitle — intuition.library](../autodocs/intuition.library.md#showtitle)
