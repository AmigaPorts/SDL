---
title: 3 / Public Screen Functions / Searching the Public Screen List
manual: libraries
chapter: libraries
section: 3-public-screen-functions-searching-the-public-screen-list
functions: [LockPubScreen, LockPubScreenList, NextPubScreen, OpenWindowTagList, UnlockPubScreenList]
libraries: [intuition.library]
---

# 3 / Public Screen Functions / Searching the Public Screen List

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

To access an existing [public screen](libraries/3-intuition-screens-public-screen-functions.md) the application may take one of three
approaches.  To get a lock on the default public screen, either
[LockPubScreen](libraries/3-intuition-screens-public-screen-functions.md)(NULL) or {[WA_PubScreenName](libraries/4-window-attributes-window-attribute-tags.md) , NULL} may be used.

If the name of the screen is known, the application may use
[LockPubScreen()](libraries/3-intuition-screens-public-screen-functions.md) to gain a lock on the screen as shown in the
[example above](libraries/lib-examples-pubscreenbeep-c.md) (or use [OpenWindowTagList()](libraries/4-basic-window-structures-and-functions-opening-a-window.md) with the [WA_PubScreenName](libraries/4-window-attributes-window-attribute-tags.md) tag as
described in the  "[Intuition Windows](libraries/4-basic-window-structures-and-functions-windows-and-screens.md)" chapter).  Failure to lock the
screen or open the window probably indicates that the screen does not
exist.

A third approach is to search the [public screen](libraries/3-intuition-screens-public-screen-functions.md) list for a screen that
meets the requirements of the application.  These requirements may be
related to the name or attributes of the screen.  Here are the functions
to use with the public screen list maintained by Intuition.


                Table 3-7: Public Screen List Functions
  _____________________________________________________________________
 |                                                                     |
 |    [LockPubScreenList()](autodocs-2.0/intuition-library-lockpubscreenlist.md)  Lock the public screen list maintained by   |
 |                         Intuition so that it may be quickly copied. |
 |                                                                     |
 |  [UnlockPubScreenList()](autodocs-2.0/intuition-library-unlockpubscreenlist.md)  Release the lock on the public screen list. |
 |                                                                     |
 |        [NextPubScreen()](autodocs-2.0/intuition-library-nextpubscreen.md)  Find the next screen in the public screen   |
 |                         list.                                       |
 |_____________________________________________________________________|


The main function used to access the [public screen](libraries/3-intuition-screens-public-screen-functions.md) list is
[LockPubScreenList()](autodocs-2.0/intuition-library-lockpubscreenlist.md).  This function, intended for use by the public screen
manager utility, locks the list to allow data from it to be quickly
copied.  The list is stored in an Exec List structure, with each node in
the list being a [PubScreenNode](autodocs-2.0/includes-intuition-screens-h.md) structure.  See <intuition/[screens](autodocs-2.0/includes-intuition-screens-h.md)> for
details.

Do not interpret the list while in a locked state, instead, copy any
values required to local variables and release the lock.  All required
data must be copied, including the name of the screen which is not part of
the structure.  Pointers that reference the list or structures attached to
the list are not valid after releasing the lock.  Once the lock is
released, the screen pointers in the list ([psn_Screen](autodocs-2.0/includes-intuition-screens-h.md)) may be tested for
equality against other screen pointers, but referencing any part of the
screen structure from this pointer is strictly illegal.  After the lock is
released with [UnlockPubScreenList()](autodocs-2.0/intuition-library-unlockpubscreenlist.md), the application may access the data
in the screen structure by obtaining a lock on the screen using
[LockPubScreen()](libraries/3-intuition-screens-public-screen-functions.md) with the name of the screen.

The application should only require accessing three fields in the
[PubScreenNode](autodocs-2.0/includes-intuition-screens-h.md), these are ln_Name, psn_Screen and psn_Flags.  The name of
the [public screen](libraries/3-intuition-screens-public-screen-functions.md) is maintained in the ln_Name field of the Node
(psn_Node) structure.  Access to other information on the screen may be
done by getting a lock on this name and reading the data from the [Screen](libraries/3-screen-data-structures-other-screen-data-structures.md)
structure.  The screen pointer (psn_Screen) may only be used for testing
against other screen pointers, never reference the screen structure from
this value.  Finally, the public screen flags are maintained in psn_Flags.
Currently, only PSNF_PRIVATE is defined for this field.  PSNF_PRIVATE
indicates that the screen is not currently public.

Remember that all information in the [public screen](libraries/3-intuition-screens-public-screen-functions.md) list is transitory,
that is, it may change at any time.  Do not rely on the values in the
list.  The only way to ensure the existence or mode of a screen is to lock
it, either directly with [LockPubScreen()](libraries/3-intuition-screens-public-screen-functions.md) or by opening a window on the
screen.  To update the copy of the list, lock it and copy the data again.
Don't forget to release the lock when finished.

As an alternative to dealing with the [public screen](libraries/3-intuition-screens-public-screen-functions.md) list, [NextPubScreen()](autodocs-2.0/intuition-library-nextpubscreen.md)
can be used.  This call takes the name of a public screen as its argument
and returns the name of the next screen in the public screen list.  This
helps an application move a window through the entire rotation of public
screens.  Repeated calls to NextPubScreen() could be used to get the names
of all public screens one at a time.  Keep in mind though that the list of
public screens is subject to sudden change; the task that owns a public
screen might close it after you obtain the name, but before you access the
screen.

Always use [LockPubScreen()](libraries/3-intuition-screens-public-screen-functions.md) to access screen information after scanning the
[public screen](libraries/3-intuition-screens-public-screen-functions.md) list.

---

## See Also

- [LockPubScreen — intuition.library](../autodocs/intuition.library.md#lockpubscreen)
- [LockPubScreenList — intuition.library](../autodocs/intuition.library.md#lockpubscreenlist)
- [NextPubScreen — intuition.library](../autodocs/intuition.library.md#nextpubscreen)
- [OpenWindowTagList — intuition.library](../autodocs/intuition.library.md#openwindowtaglist)
- [UnlockPubScreenList — intuition.library](../autodocs/intuition.library.md#unlockpubscreenlist)
