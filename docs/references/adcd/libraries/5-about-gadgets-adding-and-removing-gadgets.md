---
title: 5 / About Gadgets / Adding and Removing Gadgets
manual: libraries
chapter: libraries
section: 5-about-gadgets-adding-and-removing-gadgets
functions: [AddGList, NewModifyProp, OffGadget, OnGadget, OpenWindowTagList, RefreshGList, RemoveGList]
libraries: [intuition.library]
---

# 5 / About Gadgets / Adding and Removing Gadgets

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Gadgets may be added to a window or requester when the window or requester
is opened, or they may be added later.  To add the gadgets when a window
is opened, use the [WA_Gadgets](libraries/4-window-attributes-window-attribute-tags.md) tag with the [OpenWindowTagList()](libraries/4-basic-window-structures-and-functions-opening-a-window.md) call.  This
technique is demonstrated in the example above.  For a requester, set the
[ReqGadget](libraries/7-intuition-requesters-and-alerts-requester-structure.md) field in the [Requester](libraries/7-intuition-requesters-and-alerts-requester-structure.md) structure to point to the first gadget in
the list.

To add or remove gadgets in a window or requester that is already open,
use [AddGList()](autodocs-2.0/intuition-library-addglist.md) or [RemoveGList()](autodocs-2.0/intuition-library-removeglist.md).  These functions operate on gadgets
arranged in a list.  A gadget list is linked together by the [NextGadget](libraries/5-intuition-gadgets-gadget-structure.md)
field of the Gadget structure (see the description of the [Gadget structure](libraries/5-intuition-gadgets-gadget-structure.md)
later in this chapter).

[AddGList()](autodocs-2.0/intuition-library-addglist.md) adds a gadget list that you specify to the existing gadget list
of a window or requester:


```c
    UWORD AddGList( struct Window *window, struct Gadget *agadget,
                    unsigned long position, long numGad,
                    struct Requester *requester );
```
Up to numGad gadgets will be added from the gadget list you specify
beginning with agadget.  The position argument determines where your
gadgets will be placed in the existing list of gadgets for the window or
requester.  Use (~0) to add your gadget list to the end of the window or
requester's gadget list.  This function returns the actual position where
your gadgets are added in the existing list.

To remove gadgets from a window or requester use [RemoveGList()](autodocs-2.0/intuition-library-removeglist.md):


```c
    UWORD RemoveGList( struct Window *remPtr, struct Gadget *agadget,
                       long numGad );
```
This function removes up to numGad gadgets from a window or requester,
beginning with the specified one.  Starting with V37, if one of the
gadgets that is being removed is the active gadget, this routine will wait
for the user to release the mouse button before deactivating and removing
the gadget.  This function returns the former position of the removed
gadget or -1 if the specified gadget was not found.

The [Gadget](libraries/5-intuition-gadgets-gadget-structure.md) structure should never be directly modified after it has been
added to a window or requester.  To modify a gadget, first remove it with
[RemoveGList()](autodocs-2.0/intuition-library-removeglist.md), modify the structure as needed, and then add the gadget
back to the system with [AddGList()](autodocs-2.0/intuition-library-addglist.md).  Finally, refresh the gadget imagery
with [RefreshGList()](libraries/5-gadget-refreshing-by-the-program-gadget-refresh-function.md). (See the section on "[Gadget Refreshing](libraries/5-intuition-gadgets-gadget-refreshing.md)" below for
more information.)

Some attributes of a gadget may be modified through special Intuition
functions that perform the modification.  When using such functions it is
not necessary to remove, add or refresh the gadget.  These functions, such
as [NewModifyProp()](libraries/5-proportional-gadget-type-modifying-an-existing-gadget.md), [OnGadget()](libraries/5-intuition-gadgets-gadget-enabling-and-disabling.md) and [OffGadget()](libraries/5-intuition-gadgets-gadget-enabling-and-disabling.md), are described later in
this chapter.

---

## See Also

- [AddGList — intuition.library](../autodocs/intuition.library.md#addglist)
- [NewModifyProp — intuition.library](../autodocs/intuition.library.md#newmodifyprop)
- [OffGadget — intuition.library](../autodocs/intuition.library.md#offgadget)
- [OnGadget — intuition.library](../autodocs/intuition.library.md#ongadget)
- [OpenWindowTagList — intuition.library](../autodocs/intuition.library.md#openwindowtaglist)
- [RefreshGList — intuition.library](../autodocs/intuition.library.md#refreshglist)
- [RemoveGList — intuition.library](../autodocs/intuition.library.md#removeglist)
