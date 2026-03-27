# 4 / Other Window Functions / Program Control of Window Arrangement


[MoveWindow()](../Includes_and_Autodocs_2._guide/node022C.html), [SizeWindow()](../Includes_and_Autodocs_2._guide/node025A.html), [WindowToFront()](../Includes_and_Autodocs_2._guide/node0265.html) and [WindowToBack()](../Includes_and_Autodocs_2._guide/node0264.html) allow the
program to modify the size and placement of its windows.  These calls are
available in all versions of the operating system.

[MoveWindowInFrontOf()](../Includes_and_Autodocs_2._guide/node022D.html), [ChangeWindowBox()](../Includes_and_Autodocs_2._guide/node0203.html) and [ZipWindow()](../Includes_and_Autodocs_2._guide/node0266.html) have been added
in Release 2 to provide more flexible control over the size and placement
of windows.

All of these functions are asynchronous.  The window will not be affected
by them immediately, rather, Intuition will act on the request the next
time it receives an input event.  Currently this happens at a minimum rate
of ten times per second, and a maximum of sixty times per second.  There
is no guarantee that the operation has taken place when the function
returns.  In some cases, there are IDCMP messages which will inform the
application when the change has completed (for example, an [IDCMP_NEWSIZE](../Libraries_Manual_guide/node01E0.html)
event indicates that a resize operation has completed).

Use the [MoveWindow()](../Includes_and_Autodocs_2._guide/node022C.html) function to move a window to a new position in the
screen.  Use [SizeWindow()](../Includes_and_Autodocs_2._guide/node025A.html) to change the size of the window:


```c
    void MoveWindow( struct Window *window, long dx, long dy );
    void SizeWindow( struct Window *window, long dx, long dy );
```
Note that both [MoveWindow()](../Includes_and_Autodocs_2._guide/node022C.html) and [SizeWindow()](../Includes_and_Autodocs_2._guide/node025A.html) take the amount of change in
each axis (delta values instead of absolute coordinates).  To specify the
coordinates as absolute numbers, use [ChangeWindowBox()](../Includes_and_Autodocs_2._guide/node0203.html).  The SizeWindow()
function will respect the window's maximum and minimum dimensions only if
the window has a sizing gadget.

A new function in Release 2, [ChangeWindowBox()](../Includes_and_Autodocs_2._guide/node0203.html), allows an application to
change the window size and position in a single call:


```c
    void ChangeWindowBox( struct Window *window, long left, long top,
                          long width, long height );
```
Note that the position and size values are absolutes and not deltas.  The
window's maximum and minimum dimensions are always respected.

To depth arrange windows under program control, use [WindowToFront()](../Includes_and_Autodocs_2._guide/node0265.html) and
[WindowToBack()](../Includes_and_Autodocs_2._guide/node0264.html):


```c
    void WindowToFront( struct Window *window );
    void WindowToBack( struct Window *window );
```
[WindowToFront()](../Includes_and_Autodocs_2._guide/node0265.html) depth arranges a given window in front of all other
windows on its screen.  [WindowToBack()](../Includes_and_Autodocs_2._guide/node0264.html) depth arranges a given window
behind all other windows on its screen.

To move a window in front of a specific, given window (as opposed to all
windows), use [MoveWindowInFrontOf()](../Includes_and_Autodocs_2._guide/node022D.html):


```c
    void MoveWindowInFrontOf( struct Window *window,
                              struct Window *behindWindow );
```
[MoveWindowInFrontOf()](../Includes_and_Autodocs_2._guide/node022D.html) is a new call provided in Release 2 and is not
available in older versions of the OS.

To toggle the window size between its two zoom settings use [ZipWindow()](../Includes_and_Autodocs_2._guide/node0266.html).
This performs the same action that occurs when the user selects the zoom
gadget:


```c
    void ZipWindow( struct Window *window );
```
The two zoom settings are the initial size and position of the window when
it was first opened and the alternate position specified with the [WA_Zoom](../Libraries_Manual_guide/node0124.html#line143)
tag.  If no WA_Zoom tag is provided, the alternate position is taken from
the window's minimum dimensions, unless the window was opened at its
minimum dimension.  In that case, the alternate position is taken from the
window's maximum dimension.  [ZipWindow()](../Includes_and_Autodocs_2._guide/node0266.html) is a new call provided in Release
2 and is not available in older versions of the OS.

