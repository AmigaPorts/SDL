---
title: 6 / Menu Data Structures / MenuItem Structure
manual: libraries
chapter: libraries
section: 6-menu-data-structures-menuitem-structure
functions: []
libraries: []
---

# 6 / Menu Data Structures / MenuItem Structure

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The [MenuItem](autodocs-2.0/includes-intuition-intuition-h.md) structure is used for both items and sub-items.  There is no
internal difference between items and sub-items, other than how they are
linked into the menu strip.  Items are linked directly to [Menu](libraries/6-menu-data-structures-menu-structure.md) structures
through the [FirstItem](libraries/6-menu-data-structures-menu-structure.md) field, sub-items are linked to MenuItem structures
through the SubItem field.

Here is the specification:


```c
    struct MenuItem
        {
        struct MenuItem *NextItem;
        WORD LeftEdge, TopEdge;
        WORD Width, Height;
        UWORD Flags;
        LONG MutualExclude;
        APTR ItemFill;
        APTR SelectFill;
        BYTE Command;
        struct MenuItem *SubItem;
        UWORD NextSelect;
        };
```
The fields have the following meanings:

NextItem

    This field is a pointer to the next item in the list.  The last item
    in the list should have a NextItem value of NULL.
LeftEdge, TopEdge, Width, Height

```c
    These fields describe the select box of the MenuItem.  The LeftEdge
    is relative to the [LeftEdge](libraries/6-menu-data-structures-menu-structure.md) of the [Menu](libraries/6-menu-data-structures-menu-structure.md). The TopEdge is relative to
    the topmost position Intuition allows.  TopEdge is based on the way
    the user has the system configured--which font, which resolution, and
    so on.  Use 0 for the topmost position.
```
Flags

```c
    The flag space is shared by the program and Intuition. See
    "[MenuItem Flags](libraries/6-menu-data-structures-menuitem-flags.md)" below for a description of the flag bits.
```
MutualExclude

    Use these bits to describe which of the other items, if any, are
    mutually excluded by this one.  This long word refers to the items in
    the same menu as this one.  A maximum of 32 items may be described by
    this variable, and they must be the first 32 items in the menu.  This
    does not mean that there cannot be more than 32 items in any given
    menu, just that only the first 32 can be mutually excluded.
ItemFill

```c
    This points to the data used in rendering this MenuItem.  It can
    point to either an instance of an [IntuiText](libraries/8-creating-text-intuitext-structure.md) structure with text for
    this MenuItem or an instance of an [Image](libraries/8-creating-images-image-structure.md) structure with image data.
    The program tells Intuition the type of data pointed to by this
    variable by setting or clearing the MenuItem flag bit [ITEMTEXT](libraries/6-menu-data-structures-menuitem-flags.md).  (See
    "[MenuItem Flags](libraries/6-menu-data-structures-menuitem-flags.md)" below for more details about ITEMTEXT.)

    Note that the [IntuiText](libraries/8-creating-text-intuitext-structure.md) or [Image](libraries/8-creating-images-image-structure.md) data need not be simple imagery,
    either of them may consist of multiple objects of the same type
    chained together, described in "[Intuition Images,Line Drawing and Text](libraries/8-intuition-images-line-drawing-and-text-intuition-graphic.md)"
    chapter. By chaining multiple IntuiText structures, the application
    may "fine tune" the positioning of text within each item. This is
    especially important for proportional fonts, where the width of the
    individual characters is not constant.  This also allows items to
    have part of the text left justified and part right justified.
```
SelectFill

```c
    If [HIGHIMAGE](libraries/6-menu-data-structures-menuitem-flags.md) is set in the Flags variable as the MenuItem
    highlighting mode, Intuition substitutes this alternate image or text
    for the original rendering described by ItemFill.  The type of this
    structure must be the same as ItemFill.  SelectFill can point to
    either an [Image](libraries/8-creating-images-image-structure.md) or an [IntuiText](libraries/8-creating-text-intuitext-structure.md), where the type is determined by the
    setting of the [ITEMTEXT](libraries/6-menu-data-structures-menuitem-flags.md) flag.
```
Command

```c
    This variable is storage for a single alphanumeric character to be
    used as the command key substitute for this menu item.  The command
    key sequence will be rendered in the menu display to the right of the
    item's select area, with a fancy, reverse-video A, followed by the
    command character.  Case is ignored.

    If the flag [COMMSEQ](libraries/6-menu-data-structures-menuitem-flags.md) is set, the user can hold down the right Amiga
    key on the keyboard (to mimic using the right mouse menu button) and
    press the indicated key as a shortcut for using the mouse to select
    this item.
```
SubItem

    If this item has a sub-item list, this variable should point to the
    MenuItem structure describing the first sub-item in the list.

    There Is No Such Thing as a Sub-sub-item.
    -----------------------------------------
    A sub-item cannot have a sub-item attached to it.  If this
    MenuItem structure is not an item, this variable is ignored.
NextSelect

```c
    This field is filled in by Intuition when this MenuItem is selected
    by the user.  After an item has been selected by the user, the
    program should process the request and then check the NextSelect
    field.  If the NextSelect field is equal to [MENUNULL](libraries/6-setting-up-menus-menu-numbers.md), no other items
    were selected;  otherwise, there is another item to process.  See
    "[Menu Numbers](libraries/6-setting-up-menus-menu-numbers.md)" and "[Menu Selection Messages](libraries/6-setting-up-menus-menu-selection-messages.md)" above for more information
    about user selections.
```
