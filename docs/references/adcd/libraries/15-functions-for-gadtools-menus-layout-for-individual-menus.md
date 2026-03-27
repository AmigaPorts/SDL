---
title: 15 / / Functions for GadTools Menus / Layout for Individual Menus
manual: libraries
chapter: libraries
section: 15-functions-for-gadtools-menus-layout-for-individual-menus
functions: []
libraries: []
---

# 15 / / Functions for GadTools Menus / Layout for Individual Menus

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

[LayoutMenuItems()](autodocs-2.0/gadtools-library-layoutmenuitemsa.md) performs the same function as [LayoutMenus()](libraries/15-functions-for-gadtools-menus-layout-of-the-menus.md), but only
affects the menu items and sub-items of a single menu instead of the whole
menu strip.  Ordinarily, there is no need to call this function after
having called LayoutMenus().  This function is useful for adding menu
items to an extensible menu, such as the Workbench "Tools" menu.

For example, a single [MenuItem](libraries/6-menu-data-structures-menuitem-structure.md) can be created by calling [CreateMenus()](libraries/15-functions-for-gadtools-menus-creating-menus.md)
with a two-entry [NewMenu](libraries/15-gadtools-menus-the-newmenu-structure.md) array whose first entry is of type [NM_ITEM](libraries/15-gadtools-menus-the-newmenu-structure.md) and
whose second is of type [NM_END](libraries/15-gadtools-menus-the-newmenu-structure.md).  The menu strip may then be removed and
this new item linked to the end of an extensible menu by placing its
address in the [NextItem](libraries/6-menu-data-structures-menuitem-structure.md) field of the last MenuItem in the menu.
[LayoutMenuItems()](autodocs-2.0/gadtools-library-layoutmenuitemsa.md) can then be used to to recalculate the layout of just
the items in the extensible menu and, finally, the menu strip can be
reattached to the window.


```c
    BOOL LayoutMenuItemsA( struct MenuItem *firstitem, APTR vi,
                           struct TagItem *taglist );
    BOOL LayoutMenuItems( struct MenuItem *firstitem, APTR vi,
                          Tag tag1, ... );
```
Set firstitem to a pointer to the first [MenuItem](libraries/6-menu-data-structures-menuitem-structure.md) in the linked list of
MenuItems that make up the [Menu](libraries/6-menu-data-structures-menu-structure.md).  (See the "[Intuition Menus](libraries/6-intuition-menus-menu-data-structures.md)" chapter for
more about these structures.)  Set vi to the address of a [VisualInfo](libraries/15-getvisualinfo-and-freevisualinfo.md)
handle obtained from [GetVisualInfo()](libraries/15-getvisualinfo-and-freevisualinfo.md). The tag arguments, tag1 or taglist,
may be set as follows:

GTMN_TextAttr

```c
    A pointer to an openable font ([TextAttr](libraries/29-the-text-function-choosing-the-font.md) structure) to be used for the
    menu item and sub-item text.  The default is to use the screen's font.
```
GTMN_Menu

```c
    Use this tag to provide a pointer to the [Menu](libraries/6-menu-data-structures-menu-structure.md) structure whose
    [FirstItem](libraries/6-menu-data-structures-menu-structure.md) is passed as the first parameter to this function.  This
    tag should always be used.
```
[LayoutMenuItems()](autodocs-2.0/gadtools-library-layoutmenuitemsa.md) returns TRUE if it succeeds and FALSE otherwise.

