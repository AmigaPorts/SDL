---
title: 6 / Menu Data Structures / MenuItem Flags
manual: libraries
chapter: libraries
section: 6-menu-data-structures-menuitem-flags
functions: [OffMenu, OnMenu]
libraries: [intuition.library]
---

# 6 / Menu Data Structures / MenuItem Flags

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Here are the flags that can be set by the application in the [Flags](libraries/6-menu-data-structures-menuitem-structure.md) field
of the [MenuItem](libraries/6-menu-data-structures-menuitem-structure.md) structure:

CHECKIT

    Set this flag to inform Intuition that this item is a checkmark item
    and should be preceded by a checkmark if the flag CHECKED is set.
CHECKED

    For an item with the CHECKIT flag set, set this bit to specify that
    the checkmark is displayed.  After the menu strip is submitted to
    Intuition, it will maintain the CHECKED bit based on effects from
    other items' mutual exclusions, or, for MENUTOGGLE items, from user
    accesses to this item.
ITEMTEXT

```c
    Set this flag if the representation of the item pointed to by the
    [ItemFill](libraries/6-menu-data-structures-menuitem-structure.md) field and, possibly, by [SelectFill](libraries/6-menu-data-structures-menuitem-structure.md) is text and points to an
    [IntuiText](libraries/8-creating-text-intuitext-structure.md) structure.  Clear this bit if the item is graphic and
    points to an [Image](libraries/8-creating-images-image-structure.md) structure.
```
COMMSEQ

```c
    If this flag is set, this item has an equivalent command key sequence
    set in the [Command](libraries/6-menu-data-structures-menuitem-structure.md) field of the [MenuItem](libraries/6-menu-data-structures-menuitem-structure.md) structure.
```
MENUTOGGLE

    This flag is used in conjunction with the CHECKIT flag.  If
    MENUTOGGLE is set, a checkmark that is turned on may be turned off by
    selecting the item.  This allows the user to toggle between the
    checked and non-checked states by repeatedly selecting the item.
ITEMENABLED

```c
    This flag describes whether or not this item is currently enabled.
    If an item is not enabled, its image will be ghosted and the user
    will not be able to select it.  If this item has sub-items, all of
    the sub-items are disabled when the item is disabled.

    Set this flag before submitting the menu strip to Intuition.  Once
    the menu strip has been submitted to Intuition, enable or disable
    items by calling [OnMenu()](libraries/6-setting-up-menus-enabling-and-disabling-menus-and-menu.md) or [OffMenu()](libraries/6-setting-up-menus-enabling-and-disabling-menus-and-menu.md).
```
HIGHFLAGS


```c
    An item can be highlighted when the user positions the pointer over
    the item.  These bits describe what type of highlighting will be
    used, if any.  One of the following bits must be set, according to
    the type of highlighting desired:

    HIGHCOMP
        This complements all of the bits contained by this item's select
        box.

    HIGHBOX
        This draws a box outside this item's select box.

    HIGHIMAGE
        This displays alternate imagery referenced in SelectFill.  For
        alternate text, make sure that ITEMTEXT is set, and that the
        [SelectFill](libraries/6-menu-data-structures-menuitem-structure.md) field points to an [IntuiText](libraries/8-creating-text-intuitext-structure.md) structure.  For
        alternate image, ITEMTEXT must be cleared, and the SelectFill
        field must point to an [Image](libraries/8-creating-images-image-structure.md) structure.

    HIGHNONE
        This specifies no highlighting.
```
The following two flags are used by Intuition:

ISDRAWN

    Intuition sets this flag when this item's sub-items are currently
    displayed to the user and clears it when they are not.
HIGHITEM

    Intuition sets this flag when this item is highlighted and clears it
    when the item is not highlighted.

---

## See Also

- [OffMenu — intuition.library](../autodocs/intuition.library.md#offmenu)
- [OnMenu — intuition.library](../autodocs/intuition.library.md#onmenu)
