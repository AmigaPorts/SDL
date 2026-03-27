---
title: 5 Intuition Gadgets / Function Reference
manual: libraries
chapter: libraries
section: 5-intuition-gadgets-function-reference
functions: [ActivateGadget, AddGList, AddGadget, ModifyProp, NewModifyProp, OffGadget, OnGadget, RefreshGList, RefreshGadgets, RemoveGList, RemoveGadget, SetEditHook]
libraries: [intuition.library]
---

# 5 Intuition Gadgets / Function Reference

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The following are brief descriptions of the Intuition functions that
relate to the use of Intuition gadgets. See the Amiga ROM Kernel Reference
Manual: Includes and Autodocs for details on each function call.


               Table 5-3: Functions for Intuition Gadgets
  _______________________________________________________________________
 |                                                                       |
 |      Function                      Description                        |
 |=======================================================================|
 |       [AddGadget()](autodocs-2.0/intuition-library-addgadget.md)  Add a gadget to an open window or requester.       |
 |        [AddGList()](autodocs-2.0/intuition-library-addglist.md)  Add some gadgets to an open window or requester.   |
 |    [RemoveGadget()](autodocs-2.0/intuition-library-removegadget.md)  Remove a gadget from an open window or requester.  |
 |     [RemoveGList()](autodocs-2.0/intuition-library-removeglist.md)  Remove some gadgets from an open window or         |
 |                    requester.                                         |
 |  [RefreshGadgets()](autodocs-2.0/intuition-library-refreshgadgets.md)  Refresh all gadgets for the window or requester.   |
 |    [RefreshGList()](autodocs-2.0/intuition-library-refreshglist.md)  Refresh some gadgets from the window or requester. |
 |-----------------------------------------------------------------------|
 |      [ModifyProp()](autodocs-2.0/intuition-library-modifyprop.md)  Change the values of an open [proportional](libraries/5-intuition-gadgets-proportional-gadget-type.md) gadget.  |
 |   [NewModifyProp()](autodocs-2.0/intuition-library-newmodifyprop.md)  Optimized version of ModifyProp().                 |
 |-----------------------------------------------------------------------|
 |        [OnGadget()](autodocs-2.0/intuition-library-ongadget.md)  Enable an open gadget.                             |
 |       [OffGadget()](autodocs-2.0/intuition-library-offgadget.md)  Disable an open gadget.                            |
 |-----------------------------------------------------------------------|
 |  [ActivateGadget()](autodocs-2.0/intuition-library-activategadget.md)  Activate an open [string](libraries/5-intuition-gadgets-string-gadget-type.md) gadget.                    |
 |     [SetEditHook()](autodocs-2.0/intuition-library-setedithook.md)  Change the global edit hook for string gadgets.    |
 |_______________________________________________________________________|

---

## See Also

- [ActivateGadget — intuition.library](../autodocs/intuition.library.md#activategadget)
- [AddGList — intuition.library](../autodocs/intuition.library.md#addglist)
- [AddGadget — intuition.library](../autodocs/intuition.library.md#addgadget)
- [ModifyProp — intuition.library](../autodocs/intuition.library.md#modifyprop)
- [NewModifyProp — intuition.library](../autodocs/intuition.library.md#newmodifyprop)
- [OffGadget — intuition.library](../autodocs/intuition.library.md#offgadget)
- [OnGadget — intuition.library](../autodocs/intuition.library.md#ongadget)
- [RefreshGList — intuition.library](../autodocs/intuition.library.md#refreshglist)
- [RefreshGadgets — intuition.library](../autodocs/intuition.library.md#refreshgadgets)
- [RemoveGList — intuition.library](../autodocs/intuition.library.md#removeglist)
- [RemoveGadget — intuition.library](../autodocs/intuition.library.md#removegadget)
- [SetEditHook — intuition.library](../autodocs/intuition.library.md#setedithook)
