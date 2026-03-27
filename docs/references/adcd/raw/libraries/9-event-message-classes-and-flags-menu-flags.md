# 9 / / Event Message Classes and Flags / Menu Flags


IDCMP_MENUPICK

```c
    This flag indicates that the user has pressed the menu button.  If a
    menu item was selected, the menu number of the menu item can be found
    in the [Code](../Libraries_Manual_guide/node01D9.html#line33) field of the [IntuiMessage](../Libraries_Manual_guide/node01D9.html).  If no item was selected, the
    Code field will be equal to MENUNULL.
```
IDCMP_MENUVERIFY

```c
    This is a special verification mode which allows the program to
    confirm that it is prepared to handle Intuition rendering, in this
    case, allowing menus to be drawn in the screen.

    This is a special kind of verification, in that any window in the
    entire screen that has this flag set must respond before the menu
    operations may proceed.  Also, the active window of the screen is
    allowed to cancel the menu operation.  This is unique to
    IDCMP_MENUVERIFY.  Refer to the "Intuition Menus" for a complete
    description.

    Also see the "[Verification Functions](../Libraries_Manual_guide/node01E2.html)" section below for more
    information.
```
IDCMP_MENUHELP

```c
    This message is sent by Intuition when the user selects the Help key
    while the menu system is activated.  If a menu item was selected, the
    menu number of the menu item can be found in the [Code](../Libraries_Manual_guide/node01D9.html#line33) field of the
    [IntuiMessage](../Libraries_Manual_guide/node01D9.html).  If no item was selected, the Code field will be equal
    to MENUNULL.

    These messages will only be sent if the [WA_MenuHelp](../Libraries_Manual_guide/node0125.html#line142) attribute is set
    for the window.

    The menu number returned in IDCMP_MENUHELP may specify a position
    that cannot be generated through normal menu activity.  For instance,
    the menu number may indicate one of the menu headers with no item or
    sub-item.  See the chapter on "Intuition [Menus](../Libraries_Manual_guide/node018A.html)" for more information.
```
