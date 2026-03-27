---
title: 3 / Public Screen Functions / The Default Public Screen and Workbench
manual: libraries
chapter: libraries
section: 3-public-screen-functions-the-default-public-screen-and
functions: [CloseWorkBench, OpenWorkBench, SetPubScreenModes, WBenchToBack, WBenchToFront]
libraries: [intuition.library]
---

# 3 / Public Screen Functions / The Default Public Screen and Workbench

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

As mentioned earlier, Workbench is a special case [public screen](libraries/3-intuition-screens-public-screen-functions.md) because it
is the initial default public screen.  There are other reasons Workbench
has a special status.  Normally, it's the first thing the user sees
because it is the default user interface on all Amiga computers.  Many
older applications written for V34 and earlier versions of the OS expect
to run in the Workbench screen.  Also, Workbench is currently the only
public screen supported by system Preferences and the only screen
Intuition can automatically open.

Because of its close ties with the operating system, there are some extra
functions available to manipulate the Workbench screen.  One function
which controls both Workbench and other [public screens](libraries/3-intuition-screens-public-screen-functions.md) is
[SetPubScreenModes()](libraries/3-intuition-screens-public-screen-functions.md).  This function controls the global public screen mode
bits, SHANGHAI and POPPUBSCREEN.  If the SHANGHAI mode bit is set, older
applications which expect to open on the Workbench screen will open
instead on the default public screen (which may or may not be the
Workbench screen).  The POPPUBSCREEN bit controls whether public screens
will be popped to the front when a window is opened.  These modes are
documented in the "Intuition Windows" chapter in the section on
"[Windows and Screens](libraries/4-basic-window-structures-and-functions-windows-and-screens.md)".

Other functions which control the Workbench screen are listed in the table
below.


           Table 3-6: Workbench Public Screen Functions
  ______________________________________________________________________
 |                                                                      |
 |    [WBenchToBack()](autodocs-2.0/intuition-library-wbenchtoback.md)  Move the Workbench screen behind all other        |
 |                    screens.                                          |
 |                                                                      |
 |   [WBenchToFront()](autodocs-2.0/intuition-library-wbenchtofront.md)  Move the Workbench screen in front of all other   |
 |                    screens.                                          |
 |                                                                      |
 |   [OpenWorkBench()](autodocs-2.0/intuition-library-openworkbench.md)  Open the Workbench screen.  If the screen is      |
 |                    already open, this call has no effect.  This call |
 |                    will re-awaken the Workbench application if it    |
 |                    was active when CloseWorkBench() was called.      |
 |                                                                      |
 |  [CloseWorkBench()](autodocs-2.0/intuition-library-closeworkbench.md)  Attempt to reclaim memory used for the Workbench  |
 |                    screen.  If successful, this call closes the      |
 |                    screen and puts the Workbench application to      |
 |                    sleep.  This call fails if any application has    |
 |                    windows open or locks on the Workbench screen.    |
 |______________________________________________________________________|


Programs can attempt to reclaim memory used by the Workbench screen by
calling CloseWorkBench().  Programs that have closed Workbench, should
call OpenWorkBench() as they exit or allow the user to re-open the screen
through a menu or gadget.

If Workbench is closed, any of the following events can re-open it:
calling OpenWorkBench(); opening a window on the Workbench (including
[EasyRequests()](libraries/7-intuition-requesters-and-alerts-easy-requesters.md) such as the DOS "Insert Disk" requester); calling
[LockPubScreen](libraries/3-intuition-screens-public-screen-functions.md)("Workbench");  calling LockPubScreen(NULL) when Workbench is
the default [public screen](libraries/3-intuition-screens-public-screen-functions.md).

---

## See Also

- [CloseWorkBench — intuition.library](../autodocs/intuition.library.md#closeworkbench)
- [OpenWorkBench — intuition.library](../autodocs/intuition.library.md#openworkbench)
- [SetPubScreenModes — intuition.library](../autodocs/intuition.library.md#setpubscreenmodes)
- [WBenchToBack — intuition.library](../autodocs/intuition.library.md#wbenchtoback)
- [WBenchToFront — intuition.library](../autodocs/intuition.library.md#wbenchtofront)
