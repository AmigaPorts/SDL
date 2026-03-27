# 28 / / Specifying Animation Components / Position of an AnimComp


To specify the placement of each [AnimComp](../Libraries_Manual_guide/node03B9.html#line3) relative to its controlling
[AnimOb](../Libraries_Manual_guide/node03B9.html#line34), you set the AnimComp members [XTrans](../Includes_and_Autodocs_2._guide/node00C3.html#line196) and [YTrans](../Includes_and_Autodocs_2._guide/node00C3.html#line196).  These values can
be positive or negative.

The system is designed so that only one of the [AnimComp](../Libraries_Manual_guide/node03B9.html#line3)s in any given
sequence is "active" (being displayed) at a given point in time.  It is
the only image in the sequence that is (or is about to be) linked into the
[GelsInfo](../Libraries_Manual_guide/node0377.html#line6) list. The [Timer](../Libraries_Manual_guide/node03C1.html) determines how long each Component in the
sequence remains active, as described below.

