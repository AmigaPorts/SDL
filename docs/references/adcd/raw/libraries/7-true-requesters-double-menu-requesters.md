# 7 / True Requesters / Double Menu Requesters


A double menu requester is exactly like other requesters with one
exception: it is displayed only when the user double clicks the mouse menu
button.  Double menu requesters block input in exactly the same manner as
other [true](../Libraries_Manual_guide/node01A1.html) requesters.  A double menu requester is attached to a window by
calling [SetDMRequest()](../Includes_and_Autodocs_2._guide/node0250.html).


```c
    BOOL SetDMRequest( struct Window *window,
                       struct Requester *requester );
```
This call does not display the requester, it simply prepares it for
display.  The requester will be brought up when the user double clicks the
mouse menu button.  The parent window will receive [IDCMP_REQSET](../Libraries_Manual_guide/node01AA.html#line5) and
[IDCMP_REQCLEAR](../Libraries_Manual_guide/node01AA.html#line10) messages when the requester is added and removed.

To prevent the user from bringing up a double menu requester, unlink it
from the window by calling [ClearDMRequest()](../Includes_and_Autodocs_2._guide/node0204.html).  If a double menu request is
set for a window, ClearDMRequest() should be called to remove the
requester before that window is closed.


```c
    BOOL ClearDMRequest( struct Window *window );
```
This function unlinks the requester from the window and disables the
ability of the user to bring it up.  [ClearDMRequest()](../Includes_and_Autodocs_2._guide/node0204.html) will fail if the
double menu request is currently being displayed.

Double menu requesters can be positioned relative to the current mouse
pointer position.  For a mouse relative requester, specify [POINTREL](../Libraries_Manual_guide/node01AB.html#line113) in the
[Flags](../Libraries_Manual_guide/node01AB.html#line110) field and initialize the [RelLeft](../Libraries_Manual_guide/node01AB.html#line48) and [RelTop](../Libraries_Manual_guide/node01AB.html#line48) variables.  RelLeft and
RelTop describe the offset of the upper, left corner of the requester from
the pointer position at the time the requester is displayed.  These values
can be either negative or positive.

The values of [RelLeft](../Libraries_Manual_guide/node01AB.html#line48) and [RelTop](../Libraries_Manual_guide/node01AB.html#line48) are only advisory; the actual position
will be restricted such that the requester is entirely contained within
the borders of its parent window, if possible.  The actual top and left
positions are stored in the [TopEdge](../Libraries_Manual_guide/node01AB.html#line39) and [LeftEdge](../Libraries_Manual_guide/node01AB.html#line39) variables.

Positioning relative to the mouse pointer is possible only with double
menu requesters.  Setting [POINTREL](../Libraries_Manual_guide/node01AB.html#line113) in a requester which is not a double
menu requester will position the requester relative to the center of the
window.

