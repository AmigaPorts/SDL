# 15 / / Functions for GadTools Menus / Layout of the Menus


The [Menu](../Libraries_Manual_guide/node0199.html) and [MenuItem](../Libraries_Manual_guide/node019A.html) structures returned by [CreateMenus()](../Libraries_Manual_guide/node0251.html) contain no size
or positional information.  This information is added in a separate layout
step, using [LayoutMenus()](../Includes_and_Autodocs_2._guide/node03F8.html).  As with the other tag-based functions, the
program may call either LayoutMenus() or [LayoutMenusA()](../Includes_and_Autodocs_2._guide/node03F8.html).


```c
    BOOL LayoutMenusA( struct Menu *firstmenu, APTR vi,
                       struct TagItem *taglist );
    BOOL LayoutMenus( struct Menu *firstmenu, APTR vi, Tag tag1, ... );
```
Set firstmenu to a pointer to a [Menu](../Libraries_Manual_guide/node0199.html) structure returned by a previous call
to [CreateMenus()](../Libraries_Manual_guide/node0251.html).  The vi argument is a a [VisualInfo](../Libraries_Manual_guide/node026C.html#line12) handle obtained from
[GetVisualInfo()](../Libraries_Manual_guide/node026C.html).  See the documentation of GadTools gadgets below for more
about this call.  For the tag arguments, tag1 or taglist, [LayoutMenus()](../Includes_and_Autodocs_2._guide/node03F8.html)
recognizes a single tag:

GTMN_TextAttr

```c
    A pointer to an openable font ([TextAttr](../Libraries_Manual_guide/node03D6.html#line21) structure) to be used for the
    menu item and sub-item text.  The default is to use the screen's font.
```
[LayoutMenus()](../Includes_and_Autodocs_2._guide/node03F8.html) fills in all the size, font and position information for the
menu strip.  LayoutMenus() returns TRUE if successful and FALSE if it
fails.  The usual reason for failure is that the font supplied cannot be
opened.

[LayoutMenus()](../Includes_and_Autodocs_2._guide/node03F8.html) takes care of calculating the width, height and position of
each individual menu item and sub-item, as well as the positioning of all
menus and sub-menus.  In the event that a menu would be too tall for the
screen, it is broken up into multiple columns.  Additionally, whole menus
may be shifted left from their normal position to ensure that they fit on
screen.  If a large menu is combined with a large font, it is possible,
even with columnization and shifting, to create a menu too big for the
screen.  GadTools does not currently trim off excess menus, items or
sub-items, but relies on Intuition to clip menus at the edges of the
screen.

It is perfectly acceptable to change the menu layout by calling
[ClearMenuStrip()](../Libraries_Manual_guide/node0181.html#line11) to remove the menus, then [LayoutMenus()](../Includes_and_Autodocs_2._guide/node03F8.html) to make the
change and then [SetMenuStrip()](../Libraries_Manual_guide/node0181.html) to display the new layout.  Do this when
changing the menu's font (this can be handled by a tag to LayoutMenus()),
or when updating the menu's text (to a different language, for instance).
Run-time language switching in menus will be discussed later.

