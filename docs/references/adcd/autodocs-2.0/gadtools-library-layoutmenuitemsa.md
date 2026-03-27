---
title: gadtools.library/LayoutMenuItemsA
manual: autodocs-2.0
chapter: autodocs-2.0
section: gadtools-library-layoutmenuitemsa
functions: [CreateMenusA, GetVisualInfoA, LayoutMenuItemsA, OpenFont]
libraries: [gadtools.library, graphics.library]
---

# gadtools.library/LayoutMenuItemsA

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    LayoutMenuItemsA -- Position all the menu items. (V36)
    LayoutMenuItems -- Varargs stub for LayoutMenuItemsA(). (V36)
```
SYNOPSIS

```c
    success = LayoutMenuItemsA(menuitem, vi, taglist)
    D0                         A0        A1  A2

    BOOL LayoutMenuItemsA(struct [MenuItem](autodocs-2.0/includes-intuition-intuition-h.md) *, APTR, struct [TagItem](autodocs-2.0/includes-utility-tagitem-h.md) *);

    success = LayoutMenuItems(menuitem, vi, firsttag, ...)

    BOOL LayoutMenuItemsA(struct [MenuItem](autodocs-2.0/includes-intuition-intuition-h.md) *, APTR, Tag, ...);
```
FUNCTION

```c
    Lays out all the menu items and sub-items according to
    the supplied visual information and tag parameters.  You would use this
    if you used [CreateMenusA()](autodocs-2.0/gadtools-library-createmenusa.md) to make a single menu-pane (with sub-items,
    if any), instead of a whole menu strip.
    This routine attempts to columnize and/or shift the MenuItems in
    the event that a menu would be too tall or too wide.
```
INPUTS

```c
    menuitem - Pointer to first [MenuItem](autodocs-2.0/includes-intuition-intuition-h.md) in a linked list of
        items.
    vi - Pointer returned by [GetVisualInfoA()](autodocs-2.0/gadtools-library-getvisualinfoa.md).
    taglist - Pointer to a [TagItem](autodocs-2.0/includes-utility-tagitem-h.md) list.
```
TAGS

```c
    GTMN_TextAttr (struct [TextAttr](autodocs-2.0/includes-graphics-text-h.md) *) - Text Attribute to use for
        menu-items and sub-items.  If not supplied, the screen's
        font will be used.  This font must be openable via [OpenFont()](autodocs-2.0/graphics-library-openfont.md)
        when this function is called.
    GTMN_Menu (struct [Menu](autodocs-2.0/includes-intuition-intuition-h.md) *) - Pointer to the [Menu](autodocs-2.0/includes-intuition-intuition-h.md) structure whose
        FirstItem is the [MenuItem](autodocs-2.0/includes-intuition-intuition-h.md) supplied above.  If the menu items are
        such that they need to be columnized or shifted, the [Menu](autodocs-2.0/includes-intuition-intuition-h.md)
        structure is needed to perform the complete calculation.
        It is suggested you always provide this information.
```
RESULT

```c
    success - TRUE if successful, false otherwise (signifies that
        the [TextAttr](autodocs-2.0/includes-graphics-text-h.md) wasn't openable).
```
EXAMPLE

NOTES

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
- [OpenFont — graphics.library](../autodocs/graphics.library.md#openfont)
