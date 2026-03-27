# 5 / Gadget Size and Position / Select Box Position


To specify relative position or size for the gadget's select box, set or
more of the flags [GFLG_RELRIGHT](../Libraries_Manual_guide/node014A.html#line38), [GFLG_RELBOTTOM](../Libraries_Manual_guide/node014A.html#line29), [GFLG_RELWIDTH](../Libraries_Manual_guide/node014A.html#line47) or
[GFLG_RELHEIGHT](../Libraries_Manual_guide/node014A.html#line55) in the [Flags](../Libraries_Manual_guide/node0149.html#line48) field of the [Gadget](../Libraries_Manual_guide/node0149.html) structure.  When using
GFLG_RELxxx flags, the gadget size or position is recomputed each time the
window is sized.


    Positioning the Select Box.
    ---------------------------
    With GFLG_RELxxx gadgets, all of the imagery must be contained
    within the gadget's select box.  This allows Intuition to erase the
    gadget's imagery when the window is sized.  Intuition must be able to
    erase the gadget's imagery since the gadget's position or size will
    change as the window size changes.  If the old one were not removed,
    imagery from both sizes/positions would be visible.

    If a GFLG_RELxxx gadget's imagery must extend outside of its select
    box, position another GFLG_RELxxx gadget with a larger select box
    such that all of the first gadget's imagery is within the second
    gadget's select box. This "shadow" gadget is only used to clear the
    first gadget's imagery and, as such, it should not have imagery nor
    should it generate any messages. It should also be positioned later
    in the gadget list than the first gadget so that its select box does
    not interfere with the first gadget.
The left-right position of the select box is defined by the variable
[LeftEdge](../Libraries_Manual_guide/node0149.html#line33), which is an offset from either the left or right edge of the
display element.  The offset method is determined by the [GFLG_RELRIGHT](../Libraries_Manual_guide/node014A.html#line38)
flag.  For the LeftEdge variable, positive values move toward the right
and negative values move toward the left of the containing display
element.  If GFLG_RELRIGHT is cleared, LeftEdge is an offset (usually a
positive value) from the left edge of the display element.

If [GFLG_RELRIGHT](../Libraries_Manual_guide/node014A.html#line38) is set, [LeftEdge](../Libraries_Manual_guide/node0149.html#line33) is an offset (usually a negative value)
from the right edge of the display element.  When this is set, the
left-right position of the select box in the window is recomputed each
time the window is sized.  The gadget will automatically move with the
left border as the window is sized.

The top-bottom position of the select box is defined by the variable
[TopEdge](../Libraries_Manual_guide/node0149.html#line33), which is an offset from either the top or bottom edge of the
display element (window or requester).  The offset method is determined by
the [GFLG_RELBOTTOM](../Libraries_Manual_guide/node014A.html#line29) flag.  For the TopEdge variable, positive values move
toward the bottom and negative values move toward the top of the
containing display element.

If [GFLG_RELBOTTOM](../Libraries_Manual_guide/node014A.html#line29) is cleared, [TopEdge](../Libraries_Manual_guide/node0149.html#line33) is an offset (usually a positive
value) from the top of the display element.  If GFLG_RELBOTTOM is set,
TopEdge is an offset (usually a negative value) from the bottom of the
display element.  When this is set, the position of the select box is
recomputed each time the window is sized.  The gadget will automatically
move with the bottom border as the window is sized.

