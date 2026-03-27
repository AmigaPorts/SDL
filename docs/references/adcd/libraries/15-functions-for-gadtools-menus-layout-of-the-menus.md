---
title: 15 / / Functions for GadTools Menus / Layout of the Menus
manual: libraries
chapter: libraries
section: 15-functions-for-gadtools-menus-layout-of-the-menus
functions: [ClearMenuStrip, LayoutMenusA, SetMenuStrip]
libraries: [gadtools.library, intuition.library]
---

# 15 / / Functions for GadTools Menus / Layout of the Menus

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The [Menu](libraries/6-menu-data-structures-menu-structure.md) and [MenuItem](libraries/6-menu-data-structures-menuitem-structure.md) structures returned by [CreateMenus()](libraries/15-functions-for-gadtools-menus-creating-menus.md) contain no size
or positional information.  This information is added in a separate layout
step, using [LayoutMenus()](autodocs-2.0/gadtools-library-layoutmenusa.md).  As with the other tag-based functions, the
program may call either LayoutMenus() or [LayoutMenusA()](autodocs-2.0/gadtools-library-layoutmenusa.md).


```c
    BOOL LayoutMenusA( struct Menu *firstmenu, APTR vi,
                       struct TagItem *taglist );
    BOOL LayoutMenus( struct Menu *firstmenu, APTR vi, Tag tag1, ... );
```
Set firstmenu to a pointer to a [Menu](libraries/6-menu-data-structures-menu-structure.md) structure returned by a previous call
to [CreateMenus()](libraries/15-functions-for-gadtools-menus-creating-menus.md).  The vi argument is a a [VisualInfo](libraries/15-getvisualinfo-and-freevisualinfo.md) handle obtained from
[GetVisualInfo()](libraries/15-getvisualinfo-and-freevisualinfo.md).  See the documentation of GadTools gadgets below for more
about this call.  For the tag arguments, tag1 or taglist, [LayoutMenus()](autodocs-2.0/gadtools-library-layoutmenusa.md)
recognizes a single tag:

GTMN_TextAttr

```c
    A pointer to an openable font ([TextAttr](libraries/29-the-text-function-choosing-the-font.md) structure) to be used for the
    menu item and sub-item text.  The default is to use the screen's font.
```
[LayoutMenus()](autodocs-2.0/gadtools-library-layoutmenusa.md) fills in all the size, font and position information for the
menu strip.  LayoutMenus() returns TRUE if successful and FALSE if it
fails.  The usual reason for failure is that the font supplied cannot be
opened.

[LayoutMenus()](autodocs-2.0/gadtools-library-layoutmenusa.md) takes care of calculating the width, height and position of
each individual menu item and sub-item, as well as the positioning of all
menus and sub-menus.  In the event that a menu would be too tall for the
screen, it is broken up into multiple columns.  Additionally, whole menus
may be shifted left from their normal position to ensure that they fit on
screen.  If a large menu is combined with a large font, it is possible,
even with columnization and shifting, to create a menu too big for the
screen.  GadTools does not currently trim off excess menus, items or
sub-items, but relies on Intuition to clip menus at the edges of the
screen.

It is perfectly acceptable to change the menu layout by calling
[ClearMenuStrip()](libraries/6-setting-up-menus-submitting-and-removing-menu-strips.md) to remove the menus, then [LayoutMenus()](autodocs-2.0/gadtools-library-layoutmenusa.md) to make the
change and then [SetMenuStrip()](libraries/6-setting-up-menus-submitting-and-removing-menu-strips.md) to display the new layout.  Do this when
changing the menu's font (this can be handled by a tag to LayoutMenus()),
or when updating the menu's text (to a different language, for instance).
Run-time language switching in menus will be discussed later.

---

## See Also

- [ClearMenuStrip — intuition.library](../autodocs/intuition.library.md#clearmenustrip)
- [LayoutMenusA — gadtools.library](../autodocs/gadtools.library.md#layoutmenusa)
- [SetMenuStrip — intuition.library](../autodocs/intuition.library.md#setmenustrip)
