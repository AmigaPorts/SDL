# 6 / Menu Data Structures / MenuItem Flags


Here are the flags that can be set by the application in the [Flags](../Libraries_Manual_guide/node019A.html#line35) field
of the [MenuItem](../Libraries_Manual_guide/node019A.html) structure:

CHECKIT

    Set this flag to inform Intuition that this item is a checkmark item
    and should be preceded by a checkmark if the flag CHECKED is set.
CHECKED

    For an item with the CHECKIT flag set, set this bit to specify that
    the checkmark is displayed.  After the menu strip is submitted to
    Intuition, it will maintain the CHECKED bit based on effects from
    other items' mutual exclusions, or, for MENUTOGGLE items, from user
    accesses to this item.
ITEMTEXT

```c
    Set this flag if the representation of the item pointed to by the
    [ItemFill](../Libraries_Manual_guide/node019A.html#line47) field and, possibly, by [SelectFill](../Libraries_Manual_guide/node019A.html#line64) is text and points to an
    [IntuiText](../Libraries_Manual_guide/node01C7.html) structure.  Clear this bit if the item is graphic and
    points to an [Image](../Libraries_Manual_guide/node01BA.html) structure.
```
COMMSEQ

```c
    If this flag is set, this item has an equivalent command key sequence
    set in the [Command](../Libraries_Manual_guide/node019A.html#line72) field of the [MenuItem](../Libraries_Manual_guide/node019A.html) structure.
```
MENUTOGGLE

    This flag is used in conjunction with the CHECKIT flag.  If
    MENUTOGGLE is set, a checkmark that is turned on may be turned off by
    selecting the item.  This allows the user to toggle between the
    checked and non-checked states by repeatedly selecting the item.
ITEMENABLED

```c
    This flag describes whether or not this item is currently enabled.
    If an item is not enabled, its image will be ghosted and the user
    will not be able to select it.  If this item has sub-items, all of
    the sub-items are disabled when the item is disabled.

    Set this flag before submitting the menu strip to Intuition.  Once
    the menu strip has been submitted to Intuition, enable or disable
    items by calling [OnMenu()](../Libraries_Manual_guide/node0192.html#line15) or [OffMenu()](../Libraries_Manual_guide/node0192.html#line15).
```
HIGHFLAGS


```c
    An item can be highlighted when the user positions the pointer over
    the item.  These bits describe what type of highlighting will be
    used, if any.  One of the following bits must be set, according to
    the type of highlighting desired:

    HIGHCOMP
        This complements all of the bits contained by this item's select
        box.

    HIGHBOX
        This draws a box outside this item's select box.

    HIGHIMAGE
        This displays alternate imagery referenced in SelectFill.  For
        alternate text, make sure that ITEMTEXT is set, and that the
        [SelectFill](../Libraries_Manual_guide/node019A.html#line64) field points to an [IntuiText](../Libraries_Manual_guide/node01C7.html) structure.  For
        alternate image, ITEMTEXT must be cleared, and the SelectFill
        field must point to an [Image](../Libraries_Manual_guide/node01BA.html) structure.

    HIGHNONE
        This specifies no highlighting.
```
The following two flags are used by Intuition:

ISDRAWN

    Intuition sets this flag when this item's sub-items are currently
    displayed to the user and clears it when they are not.
HIGHITEM

    Intuition sets this flag when this item is highlighted and clears it
    when the item is not highlighted.
