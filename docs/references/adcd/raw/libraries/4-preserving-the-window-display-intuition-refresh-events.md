# 4 / Preserving the Window Display / Intuition Refresh Events


When using a Simple Refresh or a Smart Refresh windows, the program may
receive refresh events, informing it to update the display.  See the above
discussion for information on when refresh events are sent.

A message of the class [IDCMP_REFRESHWINDOW](../Libraries_Manual_guide/node01E0.html#line7) arrives at the IDCMP, informing
the program of the need to update the display.  The program must take some
action when it receives a refresh event, even if it is just the acceptable
minimum action described below.

On receiving a refresh event, [BeginRefresh()](../Libraries_Manual_guide/node011E.html) must be called, then the
program should redraw its display, and, finally, call [EndRefresh()](../Libraries_Manual_guide/node011E.html#line25).  The
minimum required action is to call the BeginRefresh()/EndRefresh() pair.
This allows Intuition and the [Layers library](../Libraries_Manual_guide/node03E3.html#line22) keep things sorted and
organized.

