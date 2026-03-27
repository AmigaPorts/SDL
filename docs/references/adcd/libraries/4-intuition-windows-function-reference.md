---
title: 4 Intuition Windows / Function Reference
manual: libraries
chapter: libraries
section: 4-intuition-windows-function-reference
functions: [ActivateWindow, BeginRefresh, ChangeWindowBox, ClearPointer, CloseWindow, EndRefresh, MoveWindow, MoveWindowInFrontOf, OpenWindow, OpenWindowTagList, RefreshWindowFrame, SetPointer, SetWindowTitles, SizeWindow, WindowLimits, WindowToBack, WindowToFront, ZipWindow]
libraries: [intuition.library]
---

# 4 Intuition Windows / Function Reference

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The following are brief descriptions of the Intuition functions that
relate to the use of Intuition windows.  See the Amiga ROM Kernel
Reference Manual: Includes and Autodocs for details on each function call.


                Table 4-2: Functions for Intuition Windows
  ______________________________________________________________________
 |                                                                      |
 |          Function                  Description                       |
 |======================================================================|
 |    [OpenWindowTagList()](autodocs-2.0/intuition-library-openwindowtaglist.md)  Open a window.                               |
 |       [OpenWindowTags()](autodocs-2.0/intuition-library-openwindowtaglist.md)  Alternate calling sequence for               |
 |                         OpenWindowTagList().                         |
 |           [OpenWindow()](autodocs-2.0/intuition-library-openwindow.md)  Pre-V36 way to open a window.                |
 |          [CloseWindow()](autodocs-2.0/intuition-library-closewindow.md)  Close a window.                              |
 |----------------------------------------------------------------------|
 |         [BeginRefresh()](autodocs-2.0/intuition-library-beginrefresh.md)  Turn on optimized window refresh mode.       |
 |           [EndRefresh()](autodocs-2.0/intuition-library-endrefresh.md)  Turn off optimized window refresh mode.      |
 |   [RefreshWindowFrame()](autodocs-2.0/intuition-library-refreshwindowframe.md)  Redraw the borders and border gadgets of an  |
 |                         open window.                                 |
 |----------------------------------------------------------------------|
 |       [ActivateWindow()](autodocs-2.0/intuition-library-activatewindow.md)  Make an open window active.                  |
 |           [SizeWindow()](autodocs-2.0/intuition-library-sizewindow.md)  Change the size of an open window.           |
 |           [MoveWindow()](autodocs-2.0/intuition-library-movewindow.md)  Change the position of an open window.       |
 |      [ChangeWindowBox()](autodocs-2.0/intuition-library-changewindowbox.md)  Change the size and position of an open      |
 |                         window.                                      |
 |         [WindowLimits()](autodocs-2.0/intuition-library-windowlimits.md)  Change the minimum and maximum sizes of an   |
 |                         open window.                                 |
 |         [WindowToBack()](autodocs-2.0/intuition-library-windowtoback.md)  Move a window behind all other windows.      |
 |        [WindowToFront()](autodocs-2.0/intuition-library-windowtofront.md)  Move a window in front of all other windows. |
 |  [MoveWindowInFrontOf()](autodocs-2.0/intuition-library-movewindowinfrontof.md)  Move a window in front of another window.    |
 |            [ZipWindow()](autodocs-2.0/intuition-library-zipwindow.md)  Change the size of window to its alternate   |
 |                         size.                                        |
 |      [SetWindowTitles()](autodocs-2.0/intuition-library-setwindowtitles.md)  Change the window titles for the window and  |
 |                         the screen.                                  |
 |           [SetPointer()](autodocs-2.0/intuition-library-setpointer.md)  Set up a custom pointer to display whenever  |
 |                         the window is active.                        |
 |         [ClearPointer()](autodocs-2.0/intuition-library-clearpointer.md)  Restore the mouse pointer to its default     |
 |                         imagery.                                     |
 |______________________________________________________________________|

---

## See Also

- [ActivateWindow — intuition.library](../autodocs/intuition.library.md#activatewindow)
- [BeginRefresh — intuition.library](../autodocs/intuition.library.md#beginrefresh)
- [ChangeWindowBox — intuition.library](../autodocs/intuition.library.md#changewindowbox)
- [ClearPointer — intuition.library](../autodocs/intuition.library.md#clearpointer)
- [CloseWindow — intuition.library](../autodocs/intuition.library.md#closewindow)
- [EndRefresh — intuition.library](../autodocs/intuition.library.md#endrefresh)
- [MoveWindow — intuition.library](../autodocs/intuition.library.md#movewindow)
- [MoveWindowInFrontOf — intuition.library](../autodocs/intuition.library.md#movewindowinfrontof)
- [OpenWindow — intuition.library](../autodocs/intuition.library.md#openwindow)
- [OpenWindowTagList — intuition.library](../autodocs/intuition.library.md#openwindowtaglist)
- [RefreshWindowFrame — intuition.library](../autodocs/intuition.library.md#refreshwindowframe)
- [SetPointer — intuition.library](../autodocs/intuition.library.md#setpointer)
- [SetWindowTitles — intuition.library](../autodocs/intuition.library.md#setwindowtitles)
- [SizeWindow — intuition.library](../autodocs/intuition.library.md#sizewindow)
- [WindowLimits — intuition.library](../autodocs/intuition.library.md#windowlimits)
- [WindowToBack — intuition.library](../autodocs/intuition.library.md#windowtoback)
- [WindowToFront — intuition.library](../autodocs/intuition.library.md#windowtofront)
- [ZipWindow — intuition.library](../autodocs/intuition.library.md#zipwindow)
