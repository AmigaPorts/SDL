# gadtools.library/LayoutMenuItemsA



NAME

```c
    LayoutMenuItemsA -- Position all the menu items. (V36)
    LayoutMenuItems -- Varargs stub for LayoutMenuItemsA(). (V36)
```
SYNOPSIS

```c
    success = LayoutMenuItemsA(menuitem, vi, taglist)
    D0                         A0        A1  A2

    BOOL LayoutMenuItemsA(struct [MenuItem](../Includes_and_Autodocs_2._guide/node00D4.html#line89) *, APTR, struct [TagItem](../Includes_and_Autodocs_2._guide/node012E.html#line31) *);

    success = LayoutMenuItems(menuitem, vi, firsttag, ...)

    BOOL LayoutMenuItemsA(struct [MenuItem](../Includes_and_Autodocs_2._guide/node00D4.html#line89) *, APTR, Tag, ...);
```
FUNCTION

```c
    Lays out all the menu items and sub-items according to
    the supplied visual information and tag parameters.  You would use this
    if you used [CreateMenusA()](../Includes_and_Autodocs_2._guide/node03E9.html) to make a single menu-pane (with sub-items,
    if any), instead of a whole menu strip.
    This routine attempts to columnize and/or shift the MenuItems in
    the event that a menu would be too tall or too wide.
```
INPUTS

```c
    menuitem - Pointer to first [MenuItem](../Includes_and_Autodocs_2._guide/node00D4.html#line89) in a linked list of
        items.
    vi - Pointer returned by [GetVisualInfoA()](../Includes_and_Autodocs_2._guide/node03EE.html).
    taglist - Pointer to a [TagItem](../Includes_and_Autodocs_2._guide/node012E.html#line31) list.
```
TAGS

```c
    GTMN_TextAttr (struct [TextAttr](../Includes_and_Autodocs_2._guide/node00A8.html#line66) *) - Text Attribute to use for
        menu-items and sub-items.  If not supplied, the screen's
        font will be used.  This font must be openable via [OpenFont()](../Includes_and_Autodocs_2._guide/node0462.html)
        when this function is called.
    GTMN_Menu (struct [Menu](../Includes_and_Autodocs_2._guide/node00D4.html#line61) *) - Pointer to the [Menu](../Includes_and_Autodocs_2._guide/node00D4.html#line61) structure whose
        FirstItem is the [MenuItem](../Includes_and_Autodocs_2._guide/node00D4.html#line89) supplied above.  If the menu items are
        such that they need to be columnized or shifted, the [Menu](../Includes_and_Autodocs_2._guide/node00D4.html#line61)
        structure is needed to perform the complete calculation.
        It is suggested you always provide this information.
```
RESULT

```c
    success - TRUE if successful, false otherwise (signifies that
        the [TextAttr](../Includes_and_Autodocs_2._guide/node00A8.html#line66) wasn't openable).
```
EXAMPLE

NOTES

BUGS

    If a menu ends up being wider than the whole screen, it will
    run off the right-hand side.
SEE ALSO

```c
    [CreateMenusA()](../Includes_and_Autodocs_2._guide/node03E9.html), [GetVisualInfoA()](../Includes_and_Autodocs_2._guide/node03EE.html)
```
