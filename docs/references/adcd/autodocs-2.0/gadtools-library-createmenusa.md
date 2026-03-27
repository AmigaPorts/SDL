---
title: gadtools.library/CreateMenusA
manual: autodocs-2.0
chapter: autodocs-2.0
section: gadtools-library-createmenusa
functions: [CreateMenusA, FreeMenus, LayoutMenuItemsA, LayoutMenusA]
libraries: [gadtools.library]
---

# gadtools.library/CreateMenusA

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    CreateMenusA -- Allocate and fill out a menu structure. (V36)
    CreateMenus -- Varargs stub for CreateMenus(). (V36)
```
SYNOPSIS

```c
    menu = CreateMenusA(newmenu, taglist)
    D0                  A0       A1

    struct [Menu](autodocs-2.0/includes-intuition-intuition-h.md) *CreateMenusA(struct [NewMenu](autodocs-2.0/includes-libraries-gadtools-h.md) *, struct [TagItem](autodocs-2.0/includes-utility-tagitem-h.md) *);

    menu = CreateMenus(newmenu, firsttag, ...)

    struct [Menu](autodocs-2.0/includes-intuition-intuition-h.md) *CreateMenus(struct [NewMenu](autodocs-2.0/includes-libraries-gadtools-h.md) *, Tag, ...);
```
FUNCTION

```c
    CreateMenusA() allocates and initializes a complete menu
    structure based on the supplied array of [NewMenu](autodocs-2.0/includes-libraries-gadtools-h.md) structures.
    Optionally, CreateMenusA() can allocate and initialize a complete
    set of menu items and sub-items for a single menu title.  This
    is dictated by the contents of the array of NewMenus.
```
INPUTS

```c
    newmenu - Pointer to an array of initialized struct NewMenus.
    taglist - Pointer to a [TagItem](autodocs-2.0/includes-utility-tagitem-h.md) list.
```
TAGS

```c
    GTMN_FrontPen (UBYTE) - Pen number to be used for menu text.
        (defaults to zero).
    GTMN_FullMenu (BOOL) - (GadTools V37 and higher only)
        Requires that the [NewMenu](autodocs-2.0/includes-libraries-gadtools-h.md) specification describes a complete
        menu strip, not a fragment.  If a fragment is found,
        CreateMenusA() will fail with a secondary error of
        GTMENU_INVALID.  (defaults to FALSE).
    GTMN_SecondaryError (ULONG *) - (GadTools V37 and higher only)
        Supply a pointer to a NULL-initialized ULONG to receive a
        descriptive error code.  Possible values:
        GTMENU_INVALID - [NewMenu](autodocs-2.0/includes-libraries-gadtools-h.md) structure describes an illegal
            menu.  (CreateMenusA() will fail with a NULL result).
        GTMENU_TRIMMED - [NewMenu](autodocs-2.0/includes-libraries-gadtools-h.md) structure has too many menus, items,
            or subitems (CreateMenusA() will succeed, returning a
            trimmed-down menu structure).
        GTMENU_NOMEM - CreateMenusA() ran out of memory.
```
RESULT

```c
    menu - Pointer to the resulting initialized menu structure (or
        the resulting FirstItem), with all the links for menu items
        and subitems in place.
        The result will be NULL if CreateMenusA() could not allocate
        memory for the menus, or if the [NewMenu](autodocs-2.0/includes-libraries-gadtools-h.md) array had an
        illegal arrangement (eg. NM_SUB following NM_TITLE).
        (see also the GTMN_SecondaryError tag above).
```
EXAMPLE

NOTES

```c
    The strings you supply for menu text are not copied, and must
    be preserved for the life of the menu.
    The resulting menus have no positional information.  You will
    want to call [LayoutMenusA()](autodocs-2.0/gadtools-library-layoutmenusa.md) (or [LayoutMenuItemsA()](autodocs-2.0/gadtools-library-layoutmenuitemsa.md)) to supply that.
    CreateMenusA() automatically provides you with a UserData field
    for each menu, menu-item or sub-item.  Use the GTMENU_USERDATA(menu)
    or GTMENUITEM_USERDATA(menuitem) macro to access it.
```
BUGS

```c
    At present, if you put images into menus using IM_ITEM
    or IM_SUB for a NewMenu->Type, the image you supply must
    be an ordinary struct [Image](autodocs-2.0/includes-intuition-intuition-h.md).  You may not use a 'custom
    image' (eg. one obtained from a boopsi image-class).
```
SEE ALSO

```c
    [LayoutMenusA()](autodocs-2.0/gadtools-library-layoutmenusa.md), [FreeMenus()](autodocs-2.0/gadtools-library-freemenus.md), gadtools.h/GTMENU_USERDATA(),
    gadtools.h/GTMENUITEM_USERDATA()
```

---

## See Also

- [CreateMenusA — gadtools.library](../autodocs/gadtools.library.md#createmenusa)
- [FreeMenus — gadtools.library](../autodocs/gadtools.library.md#freemenus)
- [LayoutMenuItemsA — gadtools.library](../autodocs/gadtools.library.md#layoutmenuitemsa)
- [LayoutMenusA — gadtools.library](../autodocs/gadtools.library.md#layoutmenusa)
