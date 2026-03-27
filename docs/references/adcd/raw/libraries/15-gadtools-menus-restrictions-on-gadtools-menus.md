# 15 / GadTools Menus / Restrictions on GadTools Menus


GadTools menus are regular Intuition menus.  Once the menus have been laid
out, the program may do anything with them, including attaching them or
removing them from windows, enabling or disabling items, checking or
unchecking checkmarked menu items, etc.  See the documentation for
[SetMenuStrip()](../Libraries_Manual_guide/node0181.html), [ClearMenuStrip()](../Libraries_Manual_guide/node0181.html#line11), [ResetMenuStrip()](../Libraries_Manual_guide/node0184.html#line9), [OnMenu()](../Libraries_Manual_guide/node0192.html#line15) and [OffMenu()](../Libraries_Manual_guide/node0192.html#line15)
in the "Intuition Menus" chapter for full details.

If a GadTools-created menu strip is not currently attached to any window,
the program may change the text in the menu headers ([Menu->MenuName](../Libraries_Manual_guide/node0199.html#line45)), the
command-key equivalents ([MenuItem->Command](../Libraries_Manual_guide/node019A.html#line72)) or the text or imagery of menu
items and sub-items, which can be reached as:

```c
    ((struct IntuiText *)MenuItem->ItemFill)->IText
```
or

```c
    ((struct Image *)MenuItem->ItemFill)
```
The application may also link in or unlink menus, menu items or sub-items.
However, do not add sub-items to a menu item that was not created with
sub-items and do not remove all the sub-items from an item that was
created with some.

Any of these changes may be made, provided the program subsequently calls
[LayoutMenus()](../Libraries_Manual_guide/node0252.html) or [LayoutMenuItems()](../Libraries_Manual_guide/node0253.html) as appropriate.  Then, reattach the
menu strip using [SetMenuStrip()](../Libraries_Manual_guide/node0181.html).

Some of these manipulations require walking the menu strip using the usual
Intuition-specified linkages.  Beginning with the first [Menu](../Libraries_Manual_guide/node0199.html) structure,
simply follow its [FirstItem](../Libraries_Manual_guide/node0199.html#line51) pointer to get to the first [MenuItem](../Libraries_Manual_guide/node019A.html).  The
[MenuItem->SubItem](../Libraries_Manual_guide/node019A.html#line84) pointer will lead to the sub-menus.  MenuItems are
connected via the [MenuItem->NextItem](../Libraries_Manual_guide/node019A.html#line24) field.  Successive menus are linked
together with the [Menu->NextMenu](../Libraries_Manual_guide/node0199.html#line15) pointer.  Again, see the chapter
"[Intuition Menus](../Libraries_Manual_guide/node0188.html)" for details.

