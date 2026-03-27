# 6 / Setting Up Menus / Mutual Exclusion


Mutual exclusion allows the selection of an item to cause other items to
become unselected.

For example, for a list of menu items describing the available sizes for a
font, the selection of any size could unselect all other sizes.  Use the
[MutualExclude](../Libraries_Manual_guide/node019A.html#line39) variable in the [MenuItem](../Libraries_Manual_guide/node019A.html) structure to specify other menu
items to be excluded when the user selects an item.  Exclusion also
depends upon the [CHECKED](../Libraries_Manual_guide/node019B.html#line7) and [CHECKIT](../Libraries_Manual_guide/node019B.html#line3) flags of the MenuItem, as explained
below.

  * If [CHECKED](../Libraries_Manual_guide/node019B.html#line7) is not set, then this item is available to be selected.

    If the user selects this item, the CHECKED flag is set and the
    checkmark will be drawn to the left of the item.
  * If the item selected has bits set in the [MutualExclude](../Libraries_Manual_guide/node019A.html#line39) field, the

```c
    [CHECKED](../Libraries_Manual_guide/node019B.html#line7) flag is examined in the excluded items.  If any item is
    currently CHECKED, its checkmark is erased, and its CHECKED flag is
    cleared.
```
  * Mutual exclusion pertains only to items that have the [CHECKIT](../Libraries_Manual_guide/node019B.html#line3) flag

```c
    set.  Attempting to exclude items that do not have the CHECKIT flag
    set has no effect.

    Keep track of deselected items.
    -------------------------------
    It is up to the program to track internally which excluded items have
    been deselected.  See the "[Enabling and Disabling Menus and Menu Items](../Libraries_Manual_guide/node0192.html)"
    section below for more information.
```
In the [MutualExclude](../Libraries_Manual_guide/node019A.html#line39) field, bit 0 refers to the first item in the item
list, bit 1 to the second, bit 2 to the third, and so on.

In the text style example described above, selecting plain excludes any
other style.  The [MutualExclude](../Libraries_Manual_guide/node019A.html#line39) fields of the four items would look like
this:


                     _____________________
                    |                     |
                    |  Plain      0xFFFE  |
                    |  Bold       0x0001  |
                    |  Italic     0x0001  |
                    |  Underline  0x0001  |
                    |_____________________|
"Plain" is the first item on the list.  It excludes all items except the
first one.  All of the other items exclude only the first item, so that
bold, underlined text may be selected, while bold, plain text may not.

