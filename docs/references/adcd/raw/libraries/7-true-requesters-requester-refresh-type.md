# 7 / True Requesters / Requester Refresh Type


A requester appears in a [Layer](../Libraries_Manual_guide/node03E4.html).  By default, the requester layer is of
type LAYERSMART, or, in window terminology, [WFLG_SMART_REFRESH](../Libraries_Manual_guide/node0125.html#line115); so
rendering is preserved in the requester when the window is moved or
revealed.

Requesters may also be simple refresh.  This is the recommended type.  If
possible, make the requester a simple refresh layer requester by
specifying the SIMPLEREQ flag.

For all refresh types, Intuition will keep the gadget, border, image and
bitmap imagery properly refreshed.

