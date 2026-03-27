# 4 / Preserving the Window Display / Refreshing Intuition Windows


When the user or an application performs an Intuition operation which
causes damage to a window, Intuition notifies that window's application.
It does this by sending a message of the class [IDCMP_REFRESHWINDOW](../Libraries_Manual_guide/node01E0.html#line7) to that
window's IDCMP.

In response to this message, your application should update the damaged
areas.  Rendering proceeds faster and looks cleaner if it is restricted to
the damaged areas only.  The [BeginRefresh()](../Libraries_Manual_guide/node011E.html)/[EndRefresh()](../Libraries_Manual_guide/node011E.html#line25) pair achieve
that.  The application should call BeginRefresh() for the window, and then
do its rendering.  Any rendering that would have gone into undamaged areas
of the window is automatically discarded; only the area in need of repair
is affected.  Finally, the application should call EndRefresh(), which
removes the restriction on rendering, and informs the system that the
damage region has been dealt with. Even if your application intends to do
no rendering, it must at least call BeginRefresh()/EndRefresh(), to inform
the system that the damage region is no longer needed.  If your
application never needs to render in response to a refresh event, it can
avoid having to call BeginRefresh()/EndRefresh() by setting the
WFLG_NOCAREREFRESH flag or the [WA_NoCareRefresh](../Libraries_Manual_guide/node0125.html#line62) tag in the
[OpenWindowTagList()](../Libraries_Manual_guide/node0103.html) call.

Note that by the time that your application receives notification that
refresh is needed, Intuition will have already refreshed your window's
border and all gadgets in the window, as needed.  Thus, it is unnecessary
to use any of the gadget-refreshing functions in response to an
[IDCMP_REFRESHWINDOW](../Libraries_Manual_guide/node01E0.html#line7) event.

Operations performed between the [BeginRefresh()](../Libraries_Manual_guide/node011E.html)/[EndRefresh()](../Libraries_Manual_guide/node011E.html#line25) pair should
be restricted to simple rendering.  All of the rendering functions in
Intuition library and Graphics library are safe.  Avoid [RefreshGList()](../Libraries_Manual_guide/node0146.html) or
[RefreshGadgets()](../Libraries_Manual_guide/node0177.html#line5), or you risk deadlocking the computer.  Avoid calls that
may lock the [LayerInfo](../Includes_and_Autodocs_2._guide/node00C4.html#line33) or get complicated in Intuition, since
BeginRefresh() leaves the window's layer or layers locked.  Avoid
[AutoRequest()](../Libraries_Manual_guide/node01B4.html#line21) and [EasyRequest()](../Libraries_Manual_guide/node01AC.html), and therefore all direct or indirect disk
related DOS calls.  See the "[Intuition Gadgets](../Libraries_Manual_guide/node0143.html#line10)" chapter for more
information on gadget restrictions with BeginRefresh()/EndRefresh().

 [Simple Refresh](../Libraries_Manual_guide/node011A.html)    [Smart Refresh](../Libraries_Manual_guide/node011B.html)    [SuperBitMap Refresh](../Libraries_Manual_guide/node011C.html) 

