# 6 / / Menu Selection Messages / Multi-Selection of Menu Items


Each activation of the menu system generates only a single event.  The
user may select none, one or many items using any of the selection
techniques described above; still, only one event is sent.

The program finds out whether or not multiple items have been chosen by
examining the field called [NextSelect](../Libraries_Manual_guide/node019A.html#line93) in the [MenuItem](../Libraries_Manual_guide/node019A.html) structure.  The
selected items are chained together through this field.  This list is only
valid until the user next activates the menu system, as the items are
chained together through the actual MenuItem structures used in the menu
system.  If the user reselects an item, the NextSelect field of that item
will be overwritten.

In processing the menu events, the application should first take the
appropriate action for the item selected by the user, then check the
[NextSelect](../Libraries_Manual_guide/node019A.html#line93) field.  If the number there is equal to the constant [MENUNULL](../Libraries_Manual_guide/node0188.html#line20),
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
[IDCMP_MENUPICK](../Libraries_Manual_guide/node01DE.html) event by using a shorthand code known as a menu number.
Programs can locate the [MenuItem](../Libraries_Manual_guide/node019A.html) structure that corresponds to a given
menu number by using the [ItemAddress()](../Includes_and_Autodocs_2._guide/node0223.html) function.  This function translates
a menu number into a pointer to the MenuItem structure represented by the
menu number.


```c
    struct MenuItem *ItemAddress( struct Menu *menuStrip,
                                  unsigned long menuNumber );
```
This allows the application to gain access to the [MenuItem](../Libraries_Manual_guide/node019A.html) structure and
to correctly process multi-select events.  Again, when the user performs
multiple selection, the program will receive only one message of class
[IDCMP_MENUPICK](../Libraries_Manual_guide/node01DE.html).  For the program to behave correctly, it must pay
attention to the [NextSelect](../Libraries_Manual_guide/node019A.html#line93) field of the MenuItem, which will lead to the
other menu selections.

There may be some cases in an application's logical flow where the
selection of a menu item voids any further menu processing.  For instance,
after processing a "quit" menu selection, the application will, in
general, ignore all further menu selections.

