---
title: 3 Intuition Screens / Function Reference
manual: libraries
chapter: libraries
section: 3-intuition-screens-function-reference
functions: [CloseScreen, CloseWorkBench, FreeScreenDrawInfo, GetDefaultPubScreen, GetScreenData, GetScreenDrawInfo, LockPubScreen, LockPubScreenList, MakeScreen, MoveScreen, NextPubScreen, OpenScreen, OpenScreenTagList, OpenWorkBench, PubScreenStatus, QueryOverscan, RemakeDisplay, RethinkDisplay, ScreenToBack, ScreenToFront, SetDefaultPubScreen, SetPubScreenModes, ShowTitle, UnlockPubScreen, UnlockPubScreenList, ViewAddress, ViewPortAddress, WBenchToBack, WBenchToFront]
libraries: [intuition.library]
---

# 3 Intuition Screens / Function Reference

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The following are brief descriptions of the Intuition functions that
relate to the use of Intuition screens.  See the Amiga ROM Kernel
Reference Manual: Includes and Autodocs for details on each function call.


             Table 3-10: Functions for Intuition Screens
  ______________________________________________________________________
 |                                                                      |
 |          Function                  Description                       |
 |======================================================================|
 |    [OpenScreenTagList()](autodocs-2.0/intuition-library-openscreentaglist.md)  Open a screen.                               |
 |       [OpenScreenTags()](autodocs-2.0/intuition-library-openscreentaglist.md)  Alternate calling sequence for               |
 |                         OpenScreenTagList().                         |
 |           [OpenScreen()](autodocs-2.0/intuition-library-openscreen.md)  Pre-V36 open screen function.                |
 |          [CloseScreen()](autodocs-2.0/intuition-library-closescreen.md)  Close an open screen.                        |
 |----------------------------------------------------------------------|
 |           [MoveScreen()](autodocs-2.0/intuition-library-movescreen.md)  Change the position of an open screen.       |
 |         [ScreenToBack()](autodocs-2.0/intuition-library-screentoback.md)  Move a screen behind all other screens.      |
 |        [ScreenToFront()](autodocs-2.0/intuition-library-screentofront.md)  Move a screen in front of all other screens. |
 |            [ShowTitle()](autodocs-2.0/intuition-library-showtitle.md)  Show the screen in front of through backdrop |
 |                         windows.                                     |
 |----------------------------------------------------------------------|
 |    [GetScreenDrawInfo()](autodocs-2.0/intuition-library-getscreendrawinfo.md)  Get the DrawInfo information for an open     |
 |                         screen.                                      |
 |   [FreeScreenDrawInfo()](autodocs-2.0/intuition-library-freescreendrawinfo.md)  Free the DrawInfo information for a screen.  |
 |----------------------------------------------------------------------|
 |        [QueryOverscan()](autodocs-2.0/intuition-library-queryoverscan.md)  Find overscan information for a specific     |
 |                         display type.                                |
 |----------------------------------------------------------------------|
 |        [LockPubScreen()](autodocs-2.0/intuition-library-lockpubscreen.md)  Obtain a lock on a public screen.            |
 |      [UnlockPubScreen()](autodocs-2.0/intuition-library-unlockpubscreen.md)  Release a lock on a public screen.           |
 |        [NextPubScreen()](autodocs-2.0/intuition-library-nextpubscreen.md)  Return the name of the next public screen in |
 |                         the list.                                    |
 |      [PubScreenStatus()](autodocs-2.0/intuition-library-pubscreenstatus.md)  Make a public screen private or private      |
 |                         screen public.                               |
 |----------------------------------------------------------------------|
 |    [LockPubScreenList()](autodocs-2.0/intuition-library-lockpubscreenlist.md)  Lock the public screen list (for a public    |
 |                         screen utility).                             |
 |  [UnlockPubScreenList()](autodocs-2.0/intuition-library-unlockpubscreenlist.md)  Unlock the public screen list.               |
 |  [SetDefaultPubScreen()](autodocs-2.0/intuition-library-setdefaultpubscreen.md)  Change the default public screen.            |
 |    [SetPubScreenModes()](autodocs-2.0/intuition-library-setpubscreenmodes.md)  Establish global public screen behavior.     |
 |  [GetDefaultPubScreen()](autodocs-2.0/intuition-library-getdefaultpubscreen.md)  Copies the name of the default public screen |
 |                         to a buffer.                                 |
 |----------------------------------------------------------------------|
 |        [OpenWorkBench()](autodocs-2.0/intuition-library-openworkbench.md)  Open the Workbench screen, if closed.        |
 |       [CloseWorkBench()](autodocs-2.0/intuition-library-closeworkbench.md)  Close the Workbench screen, if possible.     |
 |         [WBenchToBack()](autodocs-2.0/intuition-library-wbenchtoback.md)  Move the Workbench screen behind all other   |
 |                         screens.                                     |
 |        [WBenchToFront()](autodocs-2.0/intuition-library-wbenchtofront.md)  Move the Workbench screen in front of all    |
 |                         other screens.                               |
 |        [GetScreenData()](autodocs-2.0/intuition-library-getscreendata.md)  Pre-V36 way to return information on an open |
 |                         screen.                                      |
 |----------------------------------------------------------------------|
 |          [ViewAddress()](autodocs-2.0/intuition-library-viewaddress.md)  Return the address of a screen's View.       |
 |      [ViewPortAddress()](autodocs-2.0/intuition-library-viewportaddress.md)  Use &screen->ViewPort instead.               |
 |----------------------------------------------------------------------|
 |           [MakeScreen()](autodocs-2.0/intuition-library-makescreen.md)  Low level screen handling--rebuild Copper    |
 |                         list.                                        |
 |       [RethinkDisplay()](autodocs-2.0/intuition-library-rethinkdisplay.md)  Low level screen handling--incorporate       |
 |                         Copper list changes.                         |
 |        [RemakeDisplay()](autodocs-2.0/intuition-library-remakedisplay.md)  MakeScreen() for all screens, then           |
 |                         RethinkDisplay().                            |
 |______________________________________________________________________|

---

## See Also

- [CloseScreen — intuition.library](../autodocs/intuition.library.md#closescreen)
- [CloseWorkBench — intuition.library](../autodocs/intuition.library.md#closeworkbench)
- [FreeScreenDrawInfo — intuition.library](../autodocs/intuition.library.md#freescreendrawinfo)
- [GetDefaultPubScreen — intuition.library](../autodocs/intuition.library.md#getdefaultpubscreen)
- [GetScreenData — intuition.library](../autodocs/intuition.library.md#getscreendata)
- [GetScreenDrawInfo — intuition.library](../autodocs/intuition.library.md#getscreendrawinfo)
- [LockPubScreen — intuition.library](../autodocs/intuition.library.md#lockpubscreen)
- [LockPubScreenList — intuition.library](../autodocs/intuition.library.md#lockpubscreenlist)
- [MakeScreen — intuition.library](../autodocs/intuition.library.md#makescreen)
- [MoveScreen — intuition.library](../autodocs/intuition.library.md#movescreen)
- [NextPubScreen — intuition.library](../autodocs/intuition.library.md#nextpubscreen)
- [OpenScreen — intuition.library](../autodocs/intuition.library.md#openscreen)
- [OpenScreenTagList — intuition.library](../autodocs/intuition.library.md#openscreentaglist)
- [OpenWorkBench — intuition.library](../autodocs/intuition.library.md#openworkbench)
- [PubScreenStatus — intuition.library](../autodocs/intuition.library.md#pubscreenstatus)
- [QueryOverscan — intuition.library](../autodocs/intuition.library.md#queryoverscan)
- [RemakeDisplay — intuition.library](../autodocs/intuition.library.md#remakedisplay)
- [RethinkDisplay — intuition.library](../autodocs/intuition.library.md#rethinkdisplay)
- [ScreenToBack — intuition.library](../autodocs/intuition.library.md#screentoback)
- [ScreenToFront — intuition.library](../autodocs/intuition.library.md#screentofront)
- [SetDefaultPubScreen — intuition.library](../autodocs/intuition.library.md#setdefaultpubscreen)
- [SetPubScreenModes — intuition.library](../autodocs/intuition.library.md#setpubscreenmodes)
- [ShowTitle — intuition.library](../autodocs/intuition.library.md#showtitle)
- [UnlockPubScreen — intuition.library](../autodocs/intuition.library.md#unlockpubscreen)
- [UnlockPubScreenList — intuition.library](../autodocs/intuition.library.md#unlockpubscreenlist)
- [ViewAddress — intuition.library](../autodocs/intuition.library.md#viewaddress)
- [ViewPortAddress — intuition.library](../autodocs/intuition.library.md#viewportaddress)
- [WBenchToBack — intuition.library](../autodocs/intuition.library.md#wbenchtoback)
- [WBenchToFront — intuition.library](../autodocs/intuition.library.md#wbenchtofront)
