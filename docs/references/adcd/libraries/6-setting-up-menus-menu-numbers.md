---
title: 6 / Setting Up Menus / Menu Numbers
manual: libraries
chapter: libraries
section: 6-setting-up-menus-menu-numbers
functions: []
libraries: []
---

# 6 / Setting Up Menus / Menu Numbers

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The menu numbers Intuition provides in the [IDCMP_MENUPICK](libraries/9-event-message-classes-and-flags-menu-flags.md) messages,
describe the ordinal position of the menu in the linked list of menus, the
ordinal position of the menu item beneath that menu, and (if applicable)
the ordinal position of the sub-item beneath that menu item.  Ordinal
means the successive number of the linked items, in this case, starting
from 0.

To determine which menus and menu items (sub-items are special cases of
menu items) were selected, use the following macros:


            Table 6-1: Macros Used with Intuition Menus
  _______________________________________________________________
 |                                                               |
 |  MENUNUM(num)  Extracts the ordinal menu number from num.     |
 |  ITEMNUM(num)  Extracts the ordinal item number from num.     |
 |   SUBNUM(num)  Extracts the ordinal sub-item number from num. |
 |_______________________________________________________________|


MENUNULL is the constant describing "no menu selection made."  Likewise,
NOMENU, NOITEM, and NOSUB describe the conditions "no menu chosen," "no
item chosen" and "no sub-item chosen."

For example:


```c
    if (menuNumber == MENUNULL)
        /* no menu selection was made */ ;
    else
        {
        /* if there were no sub-items attached to that item,
        ** SubNumber will equal NOSUB.
        */
        menuNum = MENUNUM(menuNumber);
        itemNum = ITEMNUM(menuNumber);
        subNum  = SUBNUM(menuNumber);
        }
```
The menu number received by the program is always set to either MENUNULL
or a valid menu selection.  If the menu number represents a valid
selection, it will always have at least a menu number and a menu item
number.  Users can never select the menu text itself, but they always
select at least an item within a menu.  Therefore, the program always gets
at least the menu selected and the menu item selected.  If the menu item
selected has a sub-item, a sub-item number will also be received.

Just as it is not possible to select an entry in the menu bar, it is not
possible to select a menu item that has attached sub-items.  The user must
select one of the options in the sub-item list before the program hears
about the action as a valid menu selection.


```c
    Help Is Available.
    ------------------
    The restrictions on what can be selected do not apply to
    [IDCMP_MENUHELP](libraries/9-event-message-classes-and-flags-menu-flags.md) messages.  Using menu help, a user can select any
    component of a menu, including the menu header itself.
```
 [How Menu Numbers Really Work](libraries/6-menu-numbers-how-menu-numbers-really-work.md) 

