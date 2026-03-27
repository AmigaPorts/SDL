# 4 / Basic Window Structures and Functions / Closing Windows


Call the [CloseWindow()](../Includes_and_Autodocs_2._guide/node0208.html) function to close a window, remove its imagery from
the display, and clean up any system resources used by the window.
Typically, you call CloseWindow() when Intuition informs you that the user
has selected the window's close gadget but this is not a requirement nor
does the window have to be active to be closed.


```c
    void CloseWindow( struct Window *window );
```
Pass this function a pointer to the [Window](../Libraries_Manual_guide/node0102.html#line8) structure returned by one of
the [OpenWindow()](../Libraries_Manual_guide/node0103.html) calls.

If you call [CloseWindow()](../Includes_and_Autodocs_2._guide/node0208.html) on the active window, the previously active
window (if available) will become the active window.  If the previously
active window has already closed, then the window active prior to that
window will become the active window.  (Applications should not rely on
this behavior.  To make a specific window become active, call the
[ActivateWindow()](../Libraries_Manual_guide/node010F.html#line19) function.)

Intuition does not automatically close a window when the user selects the
close window gadget.  Instead, Intuition sends your program a message
about the user's action.  The program can then perform whatever cleanup is
necessary before closing the window with the [CloseWindow()](../Includes_and_Autodocs_2._guide/node0208.html) function.

