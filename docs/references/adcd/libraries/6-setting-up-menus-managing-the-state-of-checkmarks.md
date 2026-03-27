---
title: 6 / Setting Up Menus / Managing the State of Checkmarks
manual: libraries
chapter: libraries
section: 6-setting-up-menus-managing-the-state-of-checkmarks
functions: [ClearMenuStrip]
libraries: [intuition.library]
---

# 6 / Setting Up Menus / Managing the State of Checkmarks

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

To correctly handle checkmarked menu items, from time to time the
application will need to read the [CHECKED](libraries/6-menu-data-structures-menuitem-flags.md) bit of its [CHECKIT](libraries/6-menu-data-structures-menuitem-flags.md) [MenuItem](libraries/6-menu-data-structures-menuitem-structure.md)s.
It is not adequate to infer which items are checked by tracking what their
state must have become.  There are several reasons for this (although it's
not important to understand the details; just the implication):

  * Using multi-selection of menus, the user can toggle the state of a

```c
    [MENUTOGGLE](libraries/6-menu-data-structures-menuitem-flags.md) item several times, yet the application will receive only
    a single [IDCMP_MENUPICK](libraries/9-event-message-classes-and-flags-menu-flags.md) event, and that item will only appear once
    one the [NextSelect](libraries/6-menu-data-structures-menuitem-structure.md) chain.
```
  * When the user selects a mutually exclusive menu item, the

```c
    [IDCMP_MENUPICK](libraries/9-event-message-classes-and-flags-menu-flags.md) event refers to that item, but Intuition doesn't
    notify your application of other items that may have been deselected
    through mutual exclusion.
```
  * Prior to V36, unusually complex multi-selection operations could

```c
    orphan menu selections.  That is to say, some items that were
    selected may not even appear on the [NextSelect](libraries/6-menu-data-structures-menuitem-structure.md) chain.  If such an
    item had a checkmark, the state of that checkmark could nevertheless
    have changed.
```
  * For complex multi-selection operations, the [NextSelect](libraries/6-menu-data-structures-menuitem-structure.md) chain will not

```c
    be in select-order (a side-effect of the fact that the same [MenuItem](libraries/6-menu-data-structures-menuitem-structure.md)
    cannot appear twice in the same NextSelect chain combined with the
    fix to the orphaning problems mentioned above).  With certain mutual
    exclusion arrangements, it is impossible to predict the state of the
    checkmarks.
```
  * If the user begins multi-selection in the menus and hits several

```c
    checkmarked items, but then presses the help key, the application
    will receive an [IDCMP_MENUHELP](libraries/9-event-message-classes-and-flags-menu-flags.md) message.  No [IDCMP_MENUPICK](libraries/9-event-message-classes-and-flags-menu-flags.md) message
    will have been sent.  Thus, some checkmark changes could have gone
    unnoticed by the application.
```
It is legal to examine the [CHECKED](libraries/6-menu-data-structures-menuitem-flags.md) state of a [MenuItem](libraries/6-menu-data-structures-menuitem-structure.md) while that MenuItem
is still attached to a window.  It is unnecessary to first call
[ClearMenuStrip()](libraries/6-setting-up-menus-submitting-and-removing-menu-strips.md).

---

## See Also

- [ClearMenuStrip — intuition.library](../autodocs/intuition.library.md#clearmenustrip)
