# D / Errors / Windows--Borders Flicker after Resize


Set the [NOCAREREFESH](../Libraries_Manual_guide/node0125.html#line62) flag.  Even [SMART_REFRESH](../Libraries_Manual_guide/node0125.html#line115) windows may generate
refresh events if there is a sizing gadget.  If you don't have specific
code to handle this, you must set the NOCAREREFRESH flag.  If you do have
refresh code, be sure to use the [Begin](../Libraries_Manual_guide/node011E.html)/[EndRefresh()](../Libraries_Manual_guide/node011E.html#line25) calls.  Failure to
do one or the other will leave Intuition in an intermediate state, and
slow down operation for all windows on the screen.

