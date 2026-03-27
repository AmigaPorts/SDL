# 4 / Basic Window Structures and Functions / Windows and Screens


Windows may be opened on one of three screen types:  a custom screen, a
public screen or the Workbench screen.  A custom screen is one created and
controlled by your application.  Once you have set up a custom screen, you
may open a window on it directly by calling one of the three open window
functions.

To open a window on a custom screen, call [OpenWindowTagList()](../Libraries_Manual_guide/node0103.html) (or
[OpenWindowTags()](../Libraries_Manual_guide/node0103.html)) with the [WA_CustomScreen](../Libraries_Manual_guide/node0124.html#line91) tag along with a pointer to the
custom screen.  This must be a pointer to a screen created by your
application.  For systems prior to Release 2, use the [OpenWindow()](../Libraries_Manual_guide/node0103.html) call
with [NewWindow](../Libraries_Manual_guide/node0102.html#line8).Type set to CUSTOMSCREEN and NewWindow.Screen set to a
pointer to your custom screen.

You may choose to open a window on an existing public (shareable) screen
instead of setting up your own custom screen.  Such windows are often
referred to as visitor windows because they "visit" a screen managed by
the system or another application.

For Workbench or other public screens that are not created and managed
directly by your application, you must lock the screen before opening the
window.  This ensures that the screen remains open while your call to open
the window is processed.  One way to obtain a lock on a public screen is
by calling the [LockPubScreen()](../Libraries_Manual_guide/node00E6.html#line34) function (see the "[Intuition Screens](../Libraries_Manual_guide/node00E7.html)"
chapter).

Use [WA_PubScreenName](../Libraries_Manual_guide/node0124.html#line129) with NULL to open a visitor window on the default
public screen (normally the Workbench screen).  If a name is provided and
the named screen exists, the visitor window will open on that named
screen.  In this case the system locks the named screen for you so there
is no need to call [LockPubScreen()](../Libraries_Manual_guide/node00E6.html#line34) directly.  The open window call will
fail if it cannot obtain a lock on the screen.  If the
[WA_PubScreenFallBack](../Libraries_Manual_guide/node0124.html#line137) tag is TRUE, the window will open on the default
public screen when WA_PubScreenName can't be found.

Another method to open a visitor window on a public screen is to use the
[WA_PubScreen](../Libraries_Manual_guide/node0124.html#line121) tag along with a pointer to the [Screen](../Libraries_Manual_guide/node00DE.html#line6) structure of the
public screen obtained via [LockPubScreen()](../Libraries_Manual_guide/node00E6.html#line34).

The application may also request the name of the "next" public screen,
which allows windows to "jump" between public screens.  This is done by
closing the application window on the first screen and opening a new
window on the next screen.  (See the "[Intuition Screens](../Libraries_Manual_guide/node00DA.html)" chapter for more
information on public and custom screens.)

If no action is taken by the programmer to open the window on a specific
screen, the window will open on the default public screen (normally the
Workbench).  This behavior is shown in the above [example](../Libraries_Manual_guide/node05BC.html) using
[OpenWindowTagList()](../Libraries_Manual_guide/node0103.html).

There are two global modes which come into play when a visitor window is
opened on a public screen.  If the global mode SHANGHAI is set, Workbench
application windows will be opened on the default public screen.  A second
global mode, POPPUBSCREEN, forces a public screen to be moved to the front
when a visitor window opens on it.  These modes can be changed using
[SetPubScreenModes()](../Libraries_Manual_guide/node00E6.html#line34), however, these should only be set according to the
preferences of the user.

 [Simple Window on a Public Screen Example](../Libraries_Manual_guide/node05BE.html) 

