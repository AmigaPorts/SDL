---
title: 15 / GadTools Menus / The NewMenu Structure
manual: libraries
chapter: libraries
section: 15-gadtools-menus-the-newmenu-structure
functions: []
libraries: []
---

# 15 / GadTools Menus / The NewMenu Structure

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The NewMenu structure used to specify GadTools menus is defined in
<libraries/[gadtools.h](autodocs-2.0/includes-libraries-gadtools-h.md)> as follows:


```c
    struct NewMenu
        {
        UBYTE nm_Type;
        STRPTR nm_Label;
        STRPTR nm_CommKey;
        UWORD nm_Flags;
        LONG nm_MutualExclude;
        APTR nm_UserData;
        };
```
nm_Type

```c
    The first field, nm_Type, defines what this particular NewMenu
    describes.  The defined types provide an unambiguous and convenient
    representation of the application's menus.

    NM_TITLE
        Used to signify a textual menu heading.  Each NM_TITLE signifies
        the start of a new menu within the menu strip.

    NM_ITEM or IM_ITEM
        Used to signify a textual (NM_ITEM) or graphical (IM_ITEM) menu
        item.  Each NM_ITEM or IM_ITEM becomes a menu item in the
        current menu.

    NM_SUB or IM_SUB
        Used to signify a textual (NM_SUB) or graphical (IM_SUB) menu
        sub-item.  All the consecutive NM_SUBs and IM_SUBs that follow a
        menu item (NM_ITEM or IM_ITEM) compose that item's sub-menu.  A
        subsequent NM_ITEM or IM_ITEM would indicate the start of the
        next item in the original menu, while a subsequent NM_TITLE
        would begin the next menu.

    NM_END
        Used to signify the end of the NewMenu structure array.  The
        last element of the array must have NM_END as its type.
```
nm_Label

```c
    NM_TITLE, NM_ITEM and NM_SUB are used for textual menu headers, menu
    items and sub-items respectively, in which case nm_Label points to
    the string to be used.  This string is not copied, but rather a
    pointer to it is kept.  Therefore the string must remain valid for
    the active life of the menu.

    Menus don't have to use text, GadTools also supports graphical menu
    items and sub-items (graphical menu headers are not possible since
    they are not supported by Intuition). Simply use IM_ITEM and IM_SUB
    instead and point nm_Label at a valid [Image](libraries/8-creating-images-image-structure.md) structure.  The Image
    structure can contain just about any graphic image (see the chapter
    on "[Intuition Images, Line Drawing and Text](libraries/8-intuition-images-line-drawing-and-text-intuition-graphic.md)" for more on this).

    Sometimes it is a good idea to put a separator between sets of menu
    items or sub-items.  The application may want to separate drastic
    menu items such as "Quit" or "Delete" from more mundane ones.
    Another good idea is to group related checkmarked items by using
    separator bars.

    NM_BARLABEL
        GadTools will provide a separator bar if the special constant
        NM_BARLABEL is supplied for the nm_Label field of an NM_ITEM or
        NM_SUB.
```
nm_CommKey

```c
    A single character string used as the Amiga-key equivalent for the
    menu item or sub-item.

    Menu headers cannot have command keys.  Note that assigning a
    command-key equivalent to a menu item that has sub-items is
    meaningless and should be avoided.

    The nm_CommKey field is a pointer to a string and not a character
    itself.  This was done in part because routines to support different
    languages typically return strings, not characters.  The first
    character of the string is actually copied into the resulting
    [MenuItem](libraries/6-menu-data-structures-menuitem-structure.md) structure.
```
nm_Flags

```c
    The nm_Flags field of the NewMenu structure corresponds roughly to
    the Flags field of the Intuition's lower-level [Menu](libraries/6-menu-data-structures-menu-structure.md) and [MenuItem](libraries/6-menu-data-structures-menuitem-structure.md)
    structures.

    For programmer convenience the sense of the Intuition MENUENABLED and
    ITEMENABLED flags are inverted.  When using GadTools, menus, menu
    items and sub-items are enabled by default.

    NM_MENUDISABLED
        To specify a disabled menu, set the NM_MENUDISABLED flag in this
        field.

    NM_ITEMDISABLED
        To disable an item or sub-item, set the NM_ITEMDISABLED flag.

    The Intuition flag bits COMMSEQ (indication of a command-key
    equivalent), ITEMTEXT (indication of a textual or graphical item) and
    HIGHFLAGS (method of highlighting) will be automatically set
    depending on other attributes of the menus.  Do not set these values
    in nm_Flags.

    The nm_Flags field is also used to specify checkmarked menu items.
    To get a checkmark that the user can toggle, set the CHECKIT and
    MENUTOGGLE flags in the nm_Flags field.  Also set the CHECKED flag if
    the item or sub-item is to start in the checked state.
```
nm_MutualExclude

```c
    For specifying mutual exclusion of checkmarked items.  All the items
    or sub-items that are part of a mutually exclusive set should have
    the CHECKIT flag set.

    This field is a bit-wise representation of the items (or sub-items),
    in the same menu or sub-menu, that are excluded by this item (or
    sub-item).  In the simple case of mutual exclusion, where each choice
    excludes all others, set nm_MutualExclude to ~(1<<item number) or ~1,
    ~2, ~4, ~8, etc.  Separator bars count as items and should be
    included in the position calculation.  See the "[Intuition Menus](libraries/6-setting-up-menus-mutual-exclusion.md)"
    chapter for more details on menu mutual exclusion.
```
nm_UserData

```c
    The NewMenu structure also has a user data field.  This data is
    stored with the Intuition [Menu](libraries/6-menu-data-structures-menu-structure.md) or [MenuItem](libraries/6-menu-data-structures-menuitem-structure.md) structures that GadTools
    creates. Use the macros GTMENU_USERDATA(menu) and
    GTMENUITEM_USERDATA(menuitem) defined in <libraries/[gadtools.h](autodocs-2.0/includes-libraries-gadtools-h.md)> to
    extract or change the user data fields of menus and menu items,
    respectively.

    The application may place index numbers in this field and perform a
    switch statement on them, instead of using the Intuition menu
    numbers.  The advantage of this is that the numbers chosen remain
    valid even if the menus are rearranged, while the Intuition menu
    numbers would change when the menus are rearranged.

    Alternately, an efficient technique for menu handling is to create a
    handler function for each menu item and put a pointer to that
    function in the corresponding item's UserData field.  When the
    program receives a [IDCMP_MENUPICK](libraries/9-event-message-classes-and-flags-menu-flags.md) message it may call the selected
    item's function through this field.
```
