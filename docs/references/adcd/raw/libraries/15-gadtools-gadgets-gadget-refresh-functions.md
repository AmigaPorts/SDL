# 15 / GadTools Gadgets / Gadget Refresh Functions


Normally, GadTools gadgets are created and then attached to a window when
the window is opened, either through the [WA_Gadget](../Libraries_Manual_guide/node0124.html#line52) tag or the
[NewWindow.FirstGadget](../Libraries_Manual_guide/node0124.html#line52) field.  Alternately, they may be added to a window
after it is open by using the functions [AddGList()](../Libraries_Manual_guide/node0133.html#line7) and [RefreshGList()](../Libraries_Manual_guide/node0146.html).

Regardless of which way gadgets are attached to a window, the program must
then call the [GT_RefreshWindow()](../Includes_and_Autodocs_2._guide/node03F4.html) function to complete the rendering of
GadTools gadgets.  This function takes two arguments.


```c
    void GT_RefreshWindow( struct Window *win, struct Requester *req );
```
This win argument is a pointer to the window that contains the GadTools
gadgets.  The req argument is currently unused and should be set to NULL.
This function should only be called immediately after adding GadTools
gadgets to a window.  Subsequent changes to GadTools gadget imagery made
through calls to [GT_SetGadgetAttrs()](../Libraries_Manual_guide/node025E.html) will be automatically performed by
GadTools when the changes are made.  (There is no need to call
[GT_RefreshWindow()](../Includes_and_Autodocs_2._guide/node03F4.html) in that case.)

As mentioned earlier, applications must always ask for notification of
window refresh events for any window that uses GadTools gadgets.  When the
application receives an [IDCMP_REFRESHWINDOW](../Libraries_Manual_guide/node01E0.html#line7) message for a window,
Intuition has already refreshed its gadgets.  Normally, a program would
then call Intuition's [BeginRefresh()](../Libraries_Manual_guide/node011E.html), perform its own custom rendering
operations, and finally call [EndRefresh()](../Libraries_Manual_guide/node011E.html#line25).  But for a window that uses
GadTools gadgets, the application must call [GT_BeginRefresh()](../Includes_and_Autodocs_2._guide/node03EF.html) and
[GT_EndRefresh()](../Includes_and_Autodocs_2._guide/node03F0.html) in place of BeginRefresh() and EndRefresh().  This allows
the the GadTools gadgets to be fully refreshed.


```c
    void GT_BeginRefresh( struct Window *win );
    void GT_EndRefresh ( struct Window *win, long complete );
```
For both functions, the win argument is a pointer to the window to be
refreshed.  For [GT_EndRefresh()](../Includes_and_Autodocs_2._guide/node03F0.html), set the complete argument to TRUE if
refreshing is complete, set it to FALSE otherwise.  See the discussion of
[BeginRefresh()](../Libraries_Manual_guide/node011E.html) and [EndRefresh()](../Libraries_Manual_guide/node011E.html#line25) in the "Intuition Windows" chapter for
more about window refreshing.

When using GadTools gadgets, the program may not set the window's
[WFLG_NOCAREREFRESH](../Libraries_Manual_guide/node0125.html#line62) flag.  Even if there is no custom rendering to be
performed, GadTools gadgets requires this minimum code to handle
[IDCMP_REFRESHWINDOW](../Libraries_Manual_guide/node01E0.html#line7) messages:


```c
    case IDCMP_REFRESHWINDOW:
        GT_BeginRefresh(win);
        /* custom rendering, if any, goes here */
        GT_EndRefresh(win, TRUE);
        break;
```
