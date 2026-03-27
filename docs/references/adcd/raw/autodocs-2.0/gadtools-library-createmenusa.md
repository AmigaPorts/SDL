# gadtools.library/CreateMenusA



NAME

```c
    CreateMenusA -- Allocate and fill out a menu structure. (V36)
    CreateMenus -- Varargs stub for CreateMenus(). (V36)
```
SYNOPSIS

```c
    menu = CreateMenusA(newmenu, taglist)
    D0                  A0       A1

    struct [Menu](../Includes_and_Autodocs_2._guide/node00D4.html#line61) *CreateMenusA(struct [NewMenu](../Includes_and_Autodocs_2._guide/node0106.html#line122) *, struct [TagItem](../Includes_and_Autodocs_2._guide/node012E.html#line31) *);

    menu = CreateMenus(newmenu, firsttag, ...)

    struct [Menu](../Includes_and_Autodocs_2._guide/node00D4.html#line61) *CreateMenus(struct [NewMenu](../Includes_and_Autodocs_2._guide/node0106.html#line122) *, Tag, ...);
```
FUNCTION

```c
    CreateMenusA() allocates and initializes a complete menu
    structure based on the supplied array of [NewMenu](../Includes_and_Autodocs_2._guide/node0106.html#line122) structures.
    Optionally, CreateMenusA() can allocate and initialize a complete
    set of menu items and sub-items for a single menu title.  This
    is dictated by the contents of the array of NewMenus.
```
INPUTS

```c
    newmenu - Pointer to an array of initialized struct NewMenus.
    taglist - Pointer to a [TagItem](../Includes_and_Autodocs_2._guide/node012E.html#line31) list.
```
TAGS

```c
    GTMN_FrontPen (UBYTE) - Pen number to be used for menu text.
        (defaults to zero).
    GTMN_FullMenu (BOOL) - (GadTools V37 and higher only)
        Requires that the [NewMenu](../Includes_and_Autodocs_2._guide/node0106.html#line122) specification describes a complete
        menu strip, not a fragment.  If a fragment is found,
        CreateMenusA() will fail with a secondary error of
        GTMENU_INVALID.  (defaults to FALSE).
    GTMN_SecondaryError (ULONG *) - (GadTools V37 and higher only)
        Supply a pointer to a NULL-initialized ULONG to receive a
        descriptive error code.  Possible values:
        GTMENU_INVALID - [NewMenu](../Includes_and_Autodocs_2._guide/node0106.html#line122) structure describes an illegal
            menu.  (CreateMenusA() will fail with a NULL result).
        GTMENU_TRIMMED - [NewMenu](../Includes_and_Autodocs_2._guide/node0106.html#line122) structure has too many menus, items,
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
        memory for the menus, or if the [NewMenu](../Includes_and_Autodocs_2._guide/node0106.html#line122) array had an
        illegal arrangement (eg. NM_SUB following NM_TITLE).
        (see also the GTMN_SecondaryError tag above).
```
EXAMPLE

NOTES

```c
    The strings you supply for menu text are not copied, and must
    be preserved for the life of the menu.
    The resulting menus have no positional information.  You will
    want to call [LayoutMenusA()](../Includes_and_Autodocs_2._guide/node03F8.html) (or [LayoutMenuItemsA()](../Includes_and_Autodocs_2._guide/node03F7.html)) to supply that.
    CreateMenusA() automatically provides you with a UserData field
    for each menu, menu-item or sub-item.  Use the GTMENU_USERDATA(menu)
    or GTMENUITEM_USERDATA(menuitem) macro to access it.
```
BUGS

```c
    At present, if you put images into menus using IM_ITEM
    or IM_SUB for a NewMenu->Type, the image you supply must
    be an ordinary struct [Image](../Includes_and_Autodocs_2._guide/node00D4.html#line621).  You may not use a 'custom
    image' (eg. one obtained from a boopsi image-class).
```
SEE ALSO

```c
    [LayoutMenusA()](../Includes_and_Autodocs_2._guide/node03F8.html), [FreeMenus()](../Includes_and_Autodocs_2._guide/node03EC.html), gadtools.h/GTMENU_USERDATA(),
    gadtools.h/GTMENUITEM_USERDATA()
```
