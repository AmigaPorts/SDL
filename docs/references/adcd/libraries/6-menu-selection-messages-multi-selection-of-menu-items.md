---
title: 6 / / Menu Selection Messages / Multi-Selection of Menu Items
manual: libraries
chapter: libraries
section: 6-menu-selection-messages-multi-selection-of-menu-items
functions: [ItemAddress]
libraries: [intuition.library]
---

# 6 / / Menu Selection Messages / Multi-Selection of Menu Items

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Each activation of the menu system generates only a single event.  The
user may select none, one or many items using any of the selection
techniques described above; still, only one event is sent.

The program finds out whether or not multiple items have been chosen by
examining the field called [NextSelect](libraries/6-menu-data-structures-menuitem-structure.md) in the [MenuItem](libraries/6-menu-data-structures-menuitem-structure.md) structure.  The
selected items are chained together through this field.  This list is only
valid until the user next activates the menu system, as the items are
chained together through the actual MenuItem structures used in the menu
system.  If the user reselects an item, the NextSelect field of that item
will be overwritten.

In processing the menu events, the application should first take the
appropriate action for the item selected by the user, then check the
[NextSelect](libraries/6-menu-data-structures-menuitem-structure.md) field.  If the number there is equal to the constant [MENUNULL](libraries/6-setting-up-menus-menu-numbers.md),
there is no next selection.  However, if it is not equal to MENUNULL, the
user has selected another option after this one.  The program should
process the next item as well, by checking its NextSelect field, until it
finds a NextSelect equal to MENUNULL.

The following code fragment shows the correct way to process a menu event:


```c
    struct IntuiMessage *msg;
    struct Menu *menuStrip;
    UWORD menuNumber;
    struct MenuItem *item;

    menuNumber = msg->Code;

    while (menuNumber != MENUNULL)
        {
        item = ItemAddress(menuStrip, menuNumber);

        /* process this item */

        menuNumber = item->NextSelect;
        }
```
Intuition specifies which item or sub-item was selected in the
[IDCMP_MENUPICK](libraries/9-event-message-classes-and-flags-menu-flags.md) event by using a shorthand code known as a menu number.
Programs can locate the [MenuItem](libraries/6-menu-data-structures-menuitem-structure.md) structure that corresponds to a given
menu number by using the [ItemAddress()](autodocs-2.0/intuition-library-itemaddress.md) function.  This function translates
a menu number into a pointer to the MenuItem structure represented by the
menu number.


```c
    struct MenuItem *ItemAddress( struct Menu *menuStrip,
                                  unsigned long menuNumber );
```
This allows the application to gain access to the [MenuItem](libraries/6-menu-data-structures-menuitem-structure.md) structure and
to correctly process multi-select events.  Again, when the user performs
multiple selection, the program will receive only one message of class
[IDCMP_MENUPICK](libraries/9-event-message-classes-and-flags-menu-flags.md).  For the program to behave correctly, it must pay
attention to the [NextSelect](libraries/6-menu-data-structures-menuitem-structure.md) field of the MenuItem, which will lead to the
other menu selections.

There may be some cases in an application's logical flow where the
selection of a menu item voids any further menu processing.  For instance,
after processing a "quit" menu selection, the application will, in
general, ignore all further menu selections.

---

## See Also

- [ItemAddress — intuition.library](../autodocs/intuition.library.md#itemaddress)
