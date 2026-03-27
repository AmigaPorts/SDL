---
title: 15 / / Functions for GadTools Menus / Creating Menus
manual: libraries
chapter: libraries
section: 15-functions-for-gadtools-menus-creating-menus
functions: [CreateMenusA, SetMenuStrip]
libraries: [gadtools.library, intuition.library]
---

# 15 / / Functions for GadTools Menus / Creating Menus

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The [CreateMenus()](autodocs-2.0/gadtools-library-createmenusa.md) function takes an array of [NewMenu](libraries/15-gadtools-menus-the-newmenu-structure.md)s and creates a set of
initialized and linked Intuition [Menu](libraries/6-menu-data-structures-menu-structure.md), [MenuItem](libraries/6-menu-data-structures-menuitem-structure.md), [Image](libraries/8-creating-images-image-structure.md) and [IntuiText](libraries/8-creating-text-intuitext-structure.md)
structures, that need only to be formatted before being used.  Like the
other tag-based functions, there is a [CreateMenusA()](autodocs-2.0/gadtools-library-createmenusa.md) call that takes a
pointer to an array of [TagItem](libraries/37-tags-tag-functions-and-structures.md)s and a CreateMenus() version that expects
to find its tags on the stack.


```c
    struct Menu *CreateMenusA( struct NewMenu *newmenu,
                               struct TagItem *taglist );
    struct Menu *CreateMenus( struct NewMenu *newmenu, Tag tag1, ... );
```
The first argument to these functions, newmenu, is a pointer to an array
of [NewMenu](libraries/15-gadtools-menus-the-newmenu-structure.md) structures as described earlier.  The tag arguments can be any
of the following items:

GTMN_FrontPen (ULONG)

    The pen number to use for menu text and separator bars.  The default
    is zero.
GTMN_FullMenu (BOOL)

```c
    (New for V37, ignored under V36).  This tag instructs [CreateMenus()](autodocs-2.0/gadtools-library-createmenusa.md)
    to fail if the supplied [NewMenu](libraries/15-gadtools-menus-the-newmenu-structure.md) structure does not describe a
    complete [Menu](libraries/6-menu-data-structures-menu-structure.md) structure.  This is useful if the application does not
    have direct control over the NewMenu description, for example if it
    has user-configurable menus.  The default is FALSE.
```
GTMN_SecondaryError (ULONG *)

```c
    (New for V37, ignored under V36).  This tag allows [CreateMenus()](autodocs-2.0/gadtools-library-createmenusa.md) to
    return some secondary error codes.  Supply a pointer to a
    NULL-initialized ULONG, which will receive an appropriate error code
    as follows:

    GTMENU_INVALID
        Invalid menu specification.  For instance, a sub-item directly
        following a menu-title or an incomplete menu.  [CreateMenus()](autodocs-2.0/gadtools-library-createmenusa.md)
        failed in this case, returning NULL.

    GTMENU_NOMEM
        Failed for lack of memory.  [CreateMenus()](autodocs-2.0/gadtools-library-createmenusa.md) returned NULL.

    GTMENU_TRIMMED
        The number of menus, items or sub-items exceeded the maximum
        number allowed so the menu was trimmed.  In this case,
        [CreateMenus()](autodocs-2.0/gadtools-library-createmenusa.md) does not fail but returns a pointer to the trimmed
        [Menu](libraries/6-menu-data-structures-menu-structure.md) structure.

    NULL
        If no error was detected.
```
[CreateMenus()](autodocs-2.0/gadtools-library-createmenusa.md) returns a pointer to the first [Menu](libraries/6-menu-data-structures-menu-structure.md) structure created, while
all the [MenuItem](libraries/6-menu-data-structures-menuitem-structure.md) structures and any other Menu structures are attached
through the appropriate pointers.  If the [NewMenu](libraries/15-gadtools-menus-the-newmenu-structure.md) structure begins with an
entry of type [NM_ITEM](libraries/15-gadtools-menus-the-newmenu-structure.md) or [IM_ITEM](libraries/15-gadtools-menus-the-newmenu-structure.md), then CreateMenus() will return a pointer
to the first MenuItem created, since there will be no first Menu
structure.  If the creation fails, usually due to a lack of memory,
CreateMenus() will return NULL.

Starting with V37, GadTools will not create any menus, menu items or
sub-items in excess of the maximum number allowed by Intuition.  Up to 31
menus may be defined, each menu with up to 63 items, each item with up to
31 sub-items.  See the "[Intuition Menus](libraries/6-about-menus-menu-limitations.md)" chapter for more information on
menus and their limitations.  If the [NewMenu](libraries/15-gadtools-menus-the-newmenu-structure.md) array describes a menu that
is too big, [CreateMenus()](autodocs-2.0/gadtools-library-createmenusa.md) will return a trimmed version.
GTMN_SecondaryError can be used to learn when this happens.

Menus need to be added to the window with Intuition's [SetMenuStrip()](libraries/6-setting-up-menus-submitting-and-removing-menu-strips.md)
function.  Before doing this, they must be formatted with a call to
[LayoutMenus()](libraries/15-functions-for-gadtools-menus-layout-of-the-menus.md).

---

## See Also

- [CreateMenusA — gadtools.library](../autodocs/gadtools.library.md#createmenusa)
- [SetMenuStrip — intuition.library](../autodocs/intuition.library.md#setmenustrip)
