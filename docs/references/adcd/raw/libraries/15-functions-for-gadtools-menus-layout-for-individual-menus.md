# 15 / / Functions for GadTools Menus / Layout for Individual Menus


[LayoutMenuItems()](../Includes_and_Autodocs_2._guide/node03F7.html) performs the same function as [LayoutMenus()](../Libraries_Manual_guide/node0252.html), but only
affects the menu items and sub-items of a single menu instead of the whole
menu strip.  Ordinarily, there is no need to call this function after
having called LayoutMenus().  This function is useful for adding menu
items to an extensible menu, such as the Workbench "Tools" menu.

For example, a single [MenuItem](../Libraries_Manual_guide/node019A.html) can be created by calling [CreateMenus()](../Libraries_Manual_guide/node0251.html)
with a two-entry [NewMenu](../Libraries_Manual_guide/node024F.html) array whose first entry is of type [NM_ITEM](../Libraries_Manual_guide/node024F.html#line22) and
whose second is of type [NM_END](../Libraries_Manual_guide/node024F.html#line35).  The menu strip may then be removed and
this new item linked to the end of an extensible menu by placing its
address in the [NextItem](../Libraries_Manual_guide/node019A.html#line24) field of the last MenuItem in the menu.
[LayoutMenuItems()](../Includes_and_Autodocs_2._guide/node03F7.html) can then be used to to recalculate the layout of just
the items in the extensible menu and, finally, the menu strip can be
reattached to the window.


```c
    BOOL LayoutMenuItemsA( struct MenuItem *firstitem, APTR vi,
                           struct TagItem *taglist );
    BOOL LayoutMenuItems( struct MenuItem *firstitem, APTR vi,
                          Tag tag1, ... );
```
Set firstitem to a pointer to the first [MenuItem](../Libraries_Manual_guide/node019A.html) in the linked list of
MenuItems that make up the [Menu](../Libraries_Manual_guide/node0199.html).  (See the "[Intuition Menus](../Libraries_Manual_guide/node0198.html)" chapter for
more about these structures.)  Set vi to the address of a [VisualInfo](../Libraries_Manual_guide/node026C.html#line12)
handle obtained from [GetVisualInfo()](../Libraries_Manual_guide/node026C.html). The tag arguments, tag1 or taglist,
may be set as follows:

GTMN_TextAttr

```c
    A pointer to an openable font ([TextAttr](../Libraries_Manual_guide/node03D6.html#line21) structure) to be used for the
    menu item and sub-item text.  The default is to use the screen's font.
```
GTMN_Menu

```c
    Use this tag to provide a pointer to the [Menu](../Libraries_Manual_guide/node0199.html) structure whose
    [FirstItem](../Libraries_Manual_guide/node0199.html#line51) is passed as the first parameter to this function.  This
    tag should always be used.
```
[LayoutMenuItems()](../Includes_and_Autodocs_2._guide/node03F7.html) returns TRUE if it succeeds and FALSE otherwise.

