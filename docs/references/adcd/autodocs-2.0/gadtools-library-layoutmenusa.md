---
title: gadtools.library/LayoutMenusA
manual: autodocs-2.0
chapter: autodocs-2.0
section: gadtools-library-layoutmenusa
functions: [CreateMenusA, GetVisualInfoA, LayoutMenuItemsA, LayoutMenusA, OpenFont]
libraries: [gadtools.library, graphics.library]
---

# gadtools.library/LayoutMenusA

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    LayoutMenusA -- Position all the menus and menu items. (V36)
    LayoutMenus -- Varargs stub for LayoutMenusA(). (V36)
```
SYNOPSIS

```c
    success = LayoutMenusA(menu, vi, taglist)
    D0                     A0    A1  A2

    BOOL LayoutMenusA(struct [Menu](autodocs-2.0/includes-intuition-intuition-h.md) *, APTR, struct [TagItem](autodocs-2.0/includes-utility-tagitem-h.md) *);

    success = LayoutMenus(menu, vi, firsttag, ...)

    BOOL LayoutMenus(struct [Menu](autodocs-2.0/includes-intuition-intuition-h.md) *, APTR, Tag, ...);
```
FUNCTION

    Lays out all the menus, menu items and sub-items in the supplied
    menu according to the supplied visual information and tag parameters.
    This routine attempts to columnize and/or shift the MenuItems in
    the event that a menu would be too tall or too wide.
INPUTS

```c
    menu - Pointer to menu obtained from [CreateMenusA()](autodocs-2.0/gadtools-library-createmenusa.md).
    vi - Pointer returned by [GetVisualInfoA()](autodocs-2.0/gadtools-library-getvisualinfoa.md).
    taglist - Pointer to a [TagItem](autodocs-2.0/includes-utility-tagitem-h.md) list.
```
TAGS

```c
    GTMN_TextAttr (struct [TextAttr](autodocs-2.0/includes-graphics-text-h.md) *) - Text Attribute to use for
        menu-items and sub-items.  If not supplied, the screen's
        font will be used.  This font must be openable via [OpenFont()](autodocs-2.0/graphics-library-openfont.md)
        when this function is called.
```
RESULT

```c
    success - TRUE if successful, false otherwise (signifies that
        the [TextAttr](autodocs-2.0/includes-graphics-text-h.md) wasn't openable).
```
EXAMPLE

NOTES

```c
    When using this function, there is no need to also call
    [LayoutMenuItemsA()](autodocs-2.0/gadtools-library-layoutmenuitemsa.md).
```
BUGS

    If a menu ends up being wider than the whole screen, it will
    run off the right-hand side.
SEE ALSO

```c
    [CreateMenusA()](autodocs-2.0/gadtools-library-createmenusa.md), [GetVisualInfoA()](autodocs-2.0/gadtools-library-getvisualinfoa.md)
```

---

## See Also

- [CreateMenusA — gadtools.library](../autodocs/gadtools.library.md#createmenusa)
- [GetVisualInfoA — gadtools.library](../autodocs/gadtools.library.md#getvisualinfoa)
- [LayoutMenuItemsA — gadtools.library](../autodocs/gadtools.library.md#layoutmenuitemsa)
- [LayoutMenusA — gadtools.library](../autodocs/gadtools.library.md#layoutmenusa)
- [OpenFont — graphics.library](../autodocs/graphics.library.md#openfont)
