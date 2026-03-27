---
title: 6 / Menu Data Structures / Menu Structure
manual: libraries
chapter: libraries
section: 6-menu-data-structures-menu-structure
functions: [OffMenu, OnMenu]
libraries: [intuition.library]
---

# 6 / Menu Data Structures / Menu Structure

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Here is the specification for a [Menu](autodocs-2.0/includes-intuition-intuition-h.md) structure:


```c
    struct Menu
        {
        struct Menu *NextMenu;
        WORD LeftEdge, TopEdge;
        WORD Width, Height;
        UWORD Flags;
        BYTE *MenuName;
        struct MenuItem *FirstItem;
        WORD JazzX, JazzY, BeatX, BeatY;
        };
```
The variables in the Menu structure have the following meanings:

NextMenu

    This variable points to the next Menu header in the list.  The last
    Menu in the list should have a NextMenu value of NULL.
LeftEdge, TopEdge, Width, Height

```c
    These fields describe the select box of the header.  Currently, any
    values supplied for TopEdge and Height are ignored by Intuition,
    which uses instead the top of the screen for the TopEdge and the
    height of the screen's title bar for the Height.

    LeftEdge is relative to the [LeftEdge](libraries/3-screen-data-structures-the-intuition-screen-data-structure.md) of the screen plus the screen's
    left border width, so if LeftEdge is 0, Intuition puts this header at
    the leftmost allowable position.
```
Flags

```c
    The flag space is shared by the program and Intuition.  The flags are:

    MENUENABLED
        This flag is for Intuition's use and indicates whether or not
        this Menu is currently enabled.  Set this flag before submitting
        the menu strip to Intuition.  If this flag is not set, the menu
        header and all menu items below it will be disabled, and the
        user will be able to view, but not select any of the items.
        After submitting the strip to Intuition, the disabled or enabled
        status may be changed by calling [OnMenu()](libraries/6-setting-up-menus-enabling-and-disabling-menus-and-menu.md) or [OffMenu()](libraries/6-setting-up-menus-enabling-and-disabling-menus-and-menu.md).

    MIDRAWN
        This flag indicates whether or not this menu's items are
        currently displayed to the user.
```
MenuName

    This is a pointer to a NULL terminated character string that is
    printed on the screen's title bar starting at the LeftEdge of this
    menu's select box and at the TopEdge just below the screen title
    bar's top border.  The text is rendered in the screen's font.
FirstItem

```c
    This points to the first [MenuItem](libraries/6-menu-data-structures-menuitem-structure.md) structure in the linked list of
    this menu's items.
```
JazzX, JazzY, BeatX, BeatY

    For internal use only.

---

## See Also

- [OffMenu — intuition.library](../autodocs/intuition.library.md#offmenu)
- [OnMenu — intuition.library](../autodocs/intuition.library.md#onmenu)
