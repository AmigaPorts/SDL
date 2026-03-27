# 15 / / The Kinds of GadTools Gadgets / Listview Gadgets


Listview gadgets (LISTVIEW_KIND) are scrolling lists.  They consist of a
scroller with arrows, an area where the list itself is visible and
optionally a place where the current selection is displayed, which may be
editable.  The user can browse through the list using the scroller or its
arrows and may select an entry by clicking on that item.

There are a number of tags that are used with listviews:

GTLV_Labels (struct List *)

```c
    An Exec list whose nodes' [ln_Name](../Libraries_Manual_guide/node02D9.html#line38) fields are to be displayed as items
    in the scrolling list.  If the list is empty, an empty [List](../Libraries_Manual_guide/node02DB.html#line23) structure
    or a NULL value may be used for GTLV_Labels.  This tag accepts a
    value of "~0" to detach the list from the listview, defined below.
    The default is NULL.  (Create and set.)
```
GTLV_Top (UWORD)

```c
    The ordinal number of the top item visible in the listview.  The
    default is zero.  (Create and set.)
```
GTLV_ReadOnly (BOOL)

```c
    Set this to TRUE for a read-only listview, which the user can browse,
    but not select items from.  A read-only listview can be recognized
    because the list area is recessed, not raised.  The default is FALSE.
    (Create only.)
```
GTLV_ScrollWidth (UWORD)

```c
    The width of the scroller to be used in the listview.  Any value
    specified must be reasonably bigger than zero.  The default is 16.
    (Create only.)
```
GTLV_ShowSelected (struct Gadget *)

```c
    Use this tag to show the currently selected entry displayed
    underneath the listview.  Set its value to NULL to get a read-only
    ([TEXT_KIND](../Libraries_Manual_guide/node0269.html)) display of the currently selected entry or set it to a
    pointer to an already-created GadTools [STRING_KIND](../Libraries_Manual_guide/node0261.html) gadget to allow
    the user to directly edit the current entry.  By default, there is no
    display of the currently selected entry.  (Create only.)
```
GTLV_Selected (UWORD)

```c
    Ordinal number of the item to be placed into the display of the
    current selection under the listview.  This tag is ignored if
    GTLV_ShowSelected is not used.  Set it to "~0" to have no current
    selection.  The default is "~0".  (Create and set.)
```
LAYOUTA_Spacing (UWORD)

```c
    Extra space, in pixels, to be placed between the entries in the
    listview.  The default is zero.  (Create only.)
```
The program will only hear from a listview when the user selects an item
from the list.  The program will then receive an [IDCMP_GADGETUP](../Libraries_Manual_guide/node01DD.html#line6)
[IntuiMessage](../Libraries_Manual_guide/node01D9.html).  This message will contain the ordinal number of the item
within the list that was selected in the [Code](../Libraries_Manual_guide/node01D9.html#line33) field of the message.  This
number is independent of the displayed listview, it is the offset from the
start of the list of items.

If the program attaches a display gadget by using the [TagItem](../Libraries_Manual_guide/node0497.html)
{GTLV_ShowSelected, NULL}, then whenever the user clicks on an entry in
the listview it will be copied into the display gadget.

If the display gadget is to be editable, then the program must first
create a GadTools [STRING_KIND](../Libraries_Manual_guide/node0261.html) gadget whose width matches the width of the
listview.  The [TagItem](../Libraries_Manual_guide/node0497.html) {GTLV_ShowSelected, stringgad} is used to install
the editable gadget, where stringgad is the pointer returned by
[CreateGadget()](../Libraries_Manual_guide/node025A.html).  When the user selects any entry from the listview, it
gets copied into the string gadget.  The user can edit the string and the
program will hear normal string gadget [IDCMP_GADGETUP](../Libraries_Manual_guide/node01DD.html#line6) messages from the
STRING_KIND gadget.

The Exec [List](../Libraries_Manual_guide/node02DB.html#line23) and its [Node](../Libraries_Manual_guide/node02D9.html#line19) structures may not be modified while they are
attached to the listview, since the list might be needed at any time.  If
the program has prepared an entire new list, including a new List
structure and all new nodes, it may replace the currently displayed list
in a single step by calling [GT_SetGadgetAttrs()](../Libraries_Manual_guide/node025E.html) with the [TagItem](../Libraries_Manual_guide/node0497.html)
{GTLV_Labels, newlist}.  If the program needs to operate on the list that
has already been passed to the listview, it should detach the list by
setting the GTLV_Labels attribute to "~0".  When done modifying the list,
resubmit it by setting GTLV_Labels to once again point to it.  This is
better than first setting the labels to NULL and later back to the list,
since setting GTLV_Labels to NULL will visually clear the listview.  If
the GTLV_Labels attribute is set to "~0", the program is expected to set
it back to something determinate, either a list or NULL, soon after.

The height specified for the listview will determine the number of lines
in the list area.  When creating a listview, it will be no bigger than the
size specified in the [NewGadget](../Libraries_Manual_guide/node0259.html) structure.  The size will include the
current-display gadget, if any, that has been requested via the
GTLV_ShowSelected tag.  The listview may end up being less tall than the
application asked for, since the calculated height assumes an integral
number of lines in the list area.

By default, the gadget label will be placed above the listview.  This may
be overridden using [ng_Flags](../Libraries_Manual_guide/node0259.html#line27).

Currently, a listview may not be disabled.

