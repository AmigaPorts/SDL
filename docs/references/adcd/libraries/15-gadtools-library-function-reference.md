---
title: 15 GadTools Library / Function Reference
manual: libraries
chapter: libraries
section: 15-gadtools-library-function-reference
functions: [BeginRefresh, CreateContext, CreateGadgetA, CreateMenusA, DrawBevelBoxA, EndRefresh, FreeGadgets, FreeMenus, FreeVisualInfo, GT_BeginRefresh, GT_EndRefresh, GT_FilterIMsg, GT_GetIMsg, GT_PostFilterIMsg, GT_RefreshWindow, GT_ReplyIMsg, GT_SetGadgetAttrsA, GetMsg, GetVisualInfoA, LayoutMenuItemsA, LayoutMenusA, ReplyMsg]
libraries: [exec.library, gadtools.library, intuition.library]
---

# 15 GadTools Library / Function Reference

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The following are brief descriptions of the Intuition functions discussed
in this chapter.  See the "Amiga ROM Kernel Reference Manual: Includes and
Autodocs" for details on each function call.  All of these functions
require Release 2 or a later version of the operating system.


               Table 15-2: GadTools Library Functions
  ______________________________________________________________________
 |                                                                      |
 |          Function                  Description                       |
 |======================================================================|
 |       [CreateGadgetA()](autodocs-2.0/gadtools-library-creategadgeta.md)  Allocate GadTools gadget, tag array form.     |
 |        [CreateGadget()](autodocs-2.0/gadtools-library-creategadgeta.md)  Allocate GadTools gadget, varargs form.       |
 |         [FreeGadgets()](autodocs-2.0/gadtools-library-freegadgets.md)  Free all GadTools gadgets.                    |
 |  [GT_SetGadgetAttrsA()](autodocs-2.0/gadtools-library-gt-setgadgetattrsa.md)  Update gadget, tag array form.                |
 |   [GT_SetGadgetAttrs()](autodocs-2.0/gadtools-library-gt-setgadgetattrsa.md)  Update gadget, varargs form.                  |
 |       [CreateContext()](autodocs-2.0/gadtools-library-createcontext.md)  Create a base for adding GadTools gadgets.    |
 |----------------------------------------------------------------------|
 |        [CreateMenusA()](autodocs-2.0/gadtools-library-createmenusa.md)  Allocate GadTools menu structures, tag array  |
 |                        form.                                         |
 |         [CreateMenus()](autodocs-2.0/gadtools-library-createmenusa.md)  Allocate GadTools menu structures, varargs    |
 |                        form.                                         |
 |           [FreeMenus()](autodocs-2.0/gadtools-library-freemenus.md)  Free menus allocated with CreateMenus().      |
 |    [LayoutMenuItemsA()](autodocs-2.0/gadtools-library-layoutmenuitemsa.md)  Format GadTools menu items, tag array form.   |
 |     [LayoutMenuItems()](autodocs-2.0/gadtools-library-layoutmenuitemsa.md)  Format GadTools menu items, varargs form.     |
 |        [LayoutMenusA()](autodocs-2.0/gadtools-library-layoutmenusa.md)  Format GadTools menus, tag array form.        |
 |         [LayoutMenus()](autodocs-2.0/gadtools-library-layoutmenusa.md)  Format GadTools menus, varargs form.          |
 |----------------------------------------------------------------------|
 |          [GT_GetIMsg()](autodocs-2.0/gadtools-library-gt-getimsg.md)  GadTools gadget compatible version of         |
 |                        [GetMsg()](libraries/24-messages-getting-a-message.md).                                     |
 |        [GT_ReplyIMsg()](autodocs-2.0/gadtools-library-gt-replyimsg.md)  GadTools gadget compatible version of         |
 |                        [ReplyMsg()](libraries/24-messages-replying.md).                                   |
 |       [GT_FilterIMsg()](autodocs-2.0/gadtools-library-gt-filterimsg.md)  Process GadTools gadgets with                 |
 |                        GetMsg()/ReplyMsg().                          |
 |   [GT_PostFilterIMsg()](autodocs-2.0/gadtools-library-gt-postfilterimsg.md)  Process GadTools gadgets with                 |
 |                        GetMsg()/ReplyMsg().                          |
 |----------------------------------------------------------------------|
 |    [GT_RefreshWindow()](autodocs-2.0/gadtools-library-gt-refreshwindow.md)  Display GadTools gadget imagery after         |
 |                        creation.                                     |
 |     [GT_BeginRefresh()](autodocs-2.0/gadtools-library-gt-beginrefresh.md)  GadTools gadget compatible version of         |
 |                        [BeginRefresh()](libraries/4-preserving-the-window-display-optimized-window-refreshing.md).                               |
 |       [GT_EndRefresh()](autodocs-2.0/gadtools-library-gt-endrefresh.md)  GadTools gadget compatible version of         |
 |                        [EndRefresh()](libraries/4-preserving-the-window-display-optimized-window-refreshing.md).                                 |
 |----------------------------------------------------------------------|
 |       [DrawBevelBoxA()](autodocs-2.0/gadtools-library-drawbevelboxa.md)  Draw a 3D box, tag array form.                |
 |        [DrawBevelBox()](autodocs-2.0/gadtools-library-drawbevelboxa.md)  Draw a 3D box, varargs form.                  |
 |----------------------------------------------------------------------|
 |      [GetVisualInfoA()](autodocs-2.0/gadtools-library-getvisualinfoa.md)  Get drawing information for GadTools, tag     |
 |                        array form.                                   |
 |       [GetVisualInfo()](autodocs-2.0/gadtools-library-getvisualinfoa.md)  Get drawing information for GadTools, varargs |
 |                        form.                                         |
 |      [FreeVisualInfo()](autodocs-2.0/gadtools-library-freevisualinfo.md)  Free drawing information for GadTools.        |
 |______________________________________________________________________|

---

## See Also

- [BeginRefresh — intuition.library](../autodocs/intuition.library.md#beginrefresh)
- [CreateContext — gadtools.library](../autodocs/gadtools.library.md#createcontext)
- [CreateGadgetA — gadtools.library](../autodocs/gadtools.library.md#creategadgeta)
- [CreateMenusA — gadtools.library](../autodocs/gadtools.library.md#createmenusa)
- [DrawBevelBoxA — gadtools.library](../autodocs/gadtools.library.md#drawbevelboxa)
- [EndRefresh — intuition.library](../autodocs/intuition.library.md#endrefresh)
- [FreeGadgets — gadtools.library](../autodocs/gadtools.library.md#freegadgets)
- [FreeMenus — gadtools.library](../autodocs/gadtools.library.md#freemenus)
- [FreeVisualInfo — gadtools.library](../autodocs/gadtools.library.md#freevisualinfo)
- [GT_BeginRefresh — gadtools.library](../autodocs/gadtools.library.md#gt_beginrefresh)
- [GT_EndRefresh — gadtools.library](../autodocs/gadtools.library.md#gt_endrefresh)
- [GT_FilterIMsg — gadtools.library](../autodocs/gadtools.library.md#gt_filterimsg)
- [GT_GetIMsg — gadtools.library](../autodocs/gadtools.library.md#gt_getimsg)
- [GT_PostFilterIMsg — gadtools.library](../autodocs/gadtools.library.md#gt_postfilterimsg)
- [GT_RefreshWindow — gadtools.library](../autodocs/gadtools.library.md#gt_refreshwindow)
- [GT_ReplyIMsg — gadtools.library](../autodocs/gadtools.library.md#gt_replyimsg)
- [GT_SetGadgetAttrsA — gadtools.library](../autodocs/gadtools.library.md#gt_setgadgetattrsa)
- [GetMsg — exec.library](../autodocs/exec.library.md#getmsg)
- [GetVisualInfoA — gadtools.library](../autodocs/gadtools.library.md#getvisualinfoa)
- [LayoutMenuItemsA — gadtools.library](../autodocs/gadtools.library.md#layoutmenuitemsa)
- [LayoutMenusA — gadtools.library](../autodocs/gadtools.library.md#layoutmenusa)
- [ReplyMsg — exec.library](../autodocs/exec.library.md#replymsg)
