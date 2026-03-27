# 6 / Setting Up Menus / Attribute Items and the Checkmark


Attribute items are items that have two states: selected and unselected.
In the menu system, these items are often represented as items with
checkmarks.  If the checkmark is visible, then the item (or attribute) is
selected.  Otherwise, the attribute is not selected.

Checkmarked items (attributes) may be toggle selected or mutually
exclusive.  Selecting a toggle selected item toggles its state--if it was
selected, it will become unselected; and if it was unselected, it will
become selected.  Selecting a mutually exclusive item puts it in the
selected state, while possibly clearing one or more other items, where it
remains until it is cleared by the selection of some other item.

A menu item is specified as a checkmark item by setting the [CHECKIT](../Libraries_Manual_guide/node019B.html#line3) flag
in the [Flags](../Libraries_Manual_guide/node019A.html#line35) variable of the item's [MenuItem](../Libraries_Manual_guide/node019A.html) structure.

The program can initialize the state of the checkmark (checked or not) by
presetting the item's [CHECKED](../Libraries_Manual_guide/node019B.html#line7) flag.  If this flag is set when the menu
strip is submitted to Intuition, then the item is considered selected and
the checkmark will be drawn.

The program can use the default Intuition checkmark or provide a custom
checkmark for the menus.  To use a custom checkmark, the application must
provide a pointer to the image with the [WA_Checkmark](../Libraries_Manual_guide/node0124.html#line58) tag when the window
is opened.  See the chapter "[Intuition Windows](../Libraries_Manual_guide/node0124.html#line58)" for details about
supplying a custom checkmark.

The application must provide sufficient blank space at the left edge of
the select box for the checkmark imagery.  Constants are provided to
standardize the space reserved in the menu for the checkmark.
LOWCHECKWIDTH gives the amount of space required for checkmarks on low
resolution screens and CHECKWIDTH gives space for all other screens.

These constants specify the space required by the default checkmarks (with
a bit of space for aesthetic purposes).  If the item box would normally be
placed such that the [LeftEdge](../Libraries_Manual_guide/node019A.html#line28) of the item box without the checkmark is 5, the
item box should start at 5 + CHECKWIDTH if [CHECKIT](../Libraries_Manual_guide/node019B.html#line3) is set.  Also, the select
box must be made CHECKWIDTH wider than it would be without the checkmark.
It is generally accepted on the Amiga that only checkmarked items should
be indented by the size of the checkmark, other items are left justified
within their column.

