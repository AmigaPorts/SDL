# 7 / True Requesters / Requester Display Position


The location of [true](../Libraries_Manual_guide/node01A1.html) requesters may be specified in one of three ways.
The requester may either be a constant location, which is an offset from
the top left corner of the window; a location relative to the current
location of the pointer; or a location relative to the center of the
window.

To display the requester as an offset from the upper left corner of the
window, initialize the [TopEdge](../Libraries_Manual_guide/node01AB.html#line39) and [LeftEdge](../Libraries_Manual_guide/node01AB.html#line39) variables and clear the
[POINTREL](../Libraries_Manual_guide/node01AB.html#line113) flag.  This will create a requester with a fixed position
relative to the upper left corner for both normal requesters and
[double menu](../Libraries_Manual_guide/node01A9.html) requesters.

Displaying the requester relative to the pointer can get the user's
attention immediately and closely associates the requester with whatever
the user was doing just before the requester was displayed in the window.
However, only [double menu](../Libraries_Manual_guide/node01A9.html) requesters may be positioned relative to the
pointer position.  See below for more information on double menu
requesters.

Requesters that are not [double menu](../Libraries_Manual_guide/node01A9.html) requesters may be positioned relative
to the center of the window on systems running Release 2 or a later
version of the OS.  This is done by setting the [POINTREL](../Libraries_Manual_guide/node01AB.html#line113) flag and filling
in the relative top and left of the gadget.  Setting [RelTop](../Libraries_Manual_guide/node01AB.html#line48) and [RelLeft](../Libraries_Manual_guide/node01AB.html#line48) to
zero will center the requester in the window.  Positive values of RelTop
and RelLeft will move the requester down and to the right, negative values
will move it up and to the left.

