# 6 / Setting Up Menus / Enabling and Disabling Menus and Menu Items


Disabling menu items makes them unavailable for selection by the user.

Disabled menus and menu items are displayed in a ghosted fashion; that is,
their imagery is overlaid with a faint pattern of dots, making it less
distinct.

Enabling or disabling a menu or menu item is always a safe procedure,
whether or not the user is currently using the menus.  Of course, by the
time you have disabled the item, the user may have already selected it.
Thus, the program may receive a [IDCMP_MENUPICK](../Libraries_Manual_guide/node01DE.html) message for that item, even
though it considers the item disabled.  The program should be prepared to
handle this case and ignore items that it knows are already disabled.
This implies that the program must track internally which items are
enabled and which are disabled.

The [OffMenu()](../Includes_and_Autodocs_2._guide/node0234.html) and [OnMenu()](../Includes_and_Autodocs_2._guide/node0236.html) functions may be used to enable or disable
items while a menu strip is attached to the window.


```c
    void OffMenu( struct Window *window, unsigned long menuNumber );
    void OnMenu( struct Window *window, unsigned long menuNumber );
```
These routines check if the user is currently using the menus and whether
the menus need to be redrawn to reflect the new states.  If the menus are
currently in use, these routines wait for the user to finish before
proceeding.

If the item component referenced by menuNumber equals [NOITEM](../Libraries_Manual_guide/node0188.html#line20), the entire
menu will be disabled or enabled.  If the item component equates to an
actual component number, then that item will be disabled or enabled.  Use
the macros defined below for the construction of menu numbers from their
component parts.

The program can enable or disable whole menus, just the menu items, or
just single sub-items.

  * To enable or disable a whole menu, set the item component of the menu

```c
    number to [NOITEM](../Libraries_Manual_guide/node0188.html#line20).  This will enable or disable all items and any
    sub-items for that menu.
```
  * To enable or disable a single item and all sub-items attached to that

```c
    item, set the item component of the menu number to the item's ordinal
    number.  If the item has a sub-item list, set the sub-item component
    of the menu number to [NOSUB](../Libraries_Manual_guide/node0188.html#line20).  If the item has no sub-item list, the
    sub-item component of the menu number is ignored.
```
  * To enable or disable a single sub-item, set the item and sub-item

    components appropriately.
It is also legal to remove the menu strip from each window that it is
attached to (with [ClearMenuStrip()](../Libraries_Manual_guide/node0181.html#line11) ) change the [ITEMENABLED](../Libraries_Manual_guide/node019B.html#line30) or [MENUENABLED](../Libraries_Manual_guide/node0199.html#line32)
flag of one or more [Menu](../Libraries_Manual_guide/node0199.html) or [MenuItem](../Libraries_Manual_guide/node019A.html) structures and add the menu back
using [ResetMenuStrip()](../Libraries_Manual_guide/node0184.html#line9) (in V36 or higher) or [SetMenuStrip()](../Libraries_Manual_guide/node0181.html) (in any
version of the OS).

