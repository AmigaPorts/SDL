# gadtools.library/LayoutMenusA



NAME

```c
    LayoutMenusA -- Position all the menus and menu items. (V36)
    LayoutMenus -- Varargs stub for LayoutMenusA(). (V36)
```
SYNOPSIS

```c
    success = LayoutMenusA(menu, vi, taglist)
    D0                     A0    A1  A2

    BOOL LayoutMenusA(struct [Menu](../Includes_and_Autodocs_2._guide/node00D4.html#line61) *, APTR, struct [TagItem](../Includes_and_Autodocs_2._guide/node012E.html#line31) *);

    success = LayoutMenus(menu, vi, firsttag, ...)

    BOOL LayoutMenus(struct [Menu](../Includes_and_Autodocs_2._guide/node00D4.html#line61) *, APTR, Tag, ...);
```
FUNCTION

    Lays out all the menus, menu items and sub-items in the supplied
    menu according to the supplied visual information and tag parameters.
    This routine attempts to columnize and/or shift the MenuItems in
    the event that a menu would be too tall or too wide.
INPUTS

```c
    menu - Pointer to menu obtained from [CreateMenusA()](../Includes_and_Autodocs_2._guide/node03E9.html).
    vi - Pointer returned by [GetVisualInfoA()](../Includes_and_Autodocs_2._guide/node03EE.html).
    taglist - Pointer to a [TagItem](../Includes_and_Autodocs_2._guide/node012E.html#line31) list.
```
TAGS

```c
    GTMN_TextAttr (struct [TextAttr](../Includes_and_Autodocs_2._guide/node00A8.html#line66) *) - Text Attribute to use for
        menu-items and sub-items.  If not supplied, the screen's
        font will be used.  This font must be openable via [OpenFont()](../Includes_and_Autodocs_2._guide/node0462.html)
        when this function is called.
```
RESULT

```c
    success - TRUE if successful, false otherwise (signifies that
        the [TextAttr](../Includes_and_Autodocs_2._guide/node00A8.html#line66) wasn't openable).
```
EXAMPLE

NOTES

```c
    When using this function, there is no need to also call
    [LayoutMenuItemsA()](../Includes_and_Autodocs_2._guide/node03F7.html).
```
BUGS

    If a menu ends up being wider than the whole screen, it will
    run off the right-hand side.
SEE ALSO

```c
    [CreateMenusA()](../Includes_and_Autodocs_2._guide/node03E9.html), [GetVisualInfoA()](../Includes_and_Autodocs_2._guide/node03EE.html)
```
