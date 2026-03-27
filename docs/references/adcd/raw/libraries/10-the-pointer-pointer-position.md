# 10 / The Pointer / Pointer Position


There are two ways to determine the position of the pointer: by direct
examination of variables in the window structure at any time, and by
examining messages sent by Intuition which inform the application of
pointer movement.  The pointer coordinates are relative to the upper left
corner of the window and are reported in the resolution of the screen,
even though the pointer's visible resolution is always in low-resolution
pixels (note that the pointer is actually a sprite).

The [MouseX](../Libraries_Manual_guide/node0121.html#line48) and [MouseY](../Libraries_Manual_guide/node0121.html#line48) fields of the [Window](../Libraries_Manual_guide/node0121.html) structure always contain the
current pointer x and y coordinates, whether or not the window is the
active one.  If the window is a [GimmeZeroZero](../Libraries_Manual_guide/node0116.html) window, the variables
[GZZMouseX](../Libraries_Manual_guide/node0121.html#line48) and [GZZMouseY](../Libraries_Manual_guide/node0121.html#line48) in the Window structure contain the position of
the mouse relative to the upper left corner of the inner window.

If the window is receiving mouse move messages, it will get a set of x,y
coordinates each time the pointer moves.  To receive messages about
pointer movements, the [WFLG_REPORTMOUSE](../Libraries_Manual_guide/node0125.html#line44) flag must be set in the [Window](../Libraries_Manual_guide/node0121.html)
structure.  This flag can be set when the window is opened.  The flag can
also be modified after the window is open by calling [ReportMouse()](../Includes_and_Autodocs_2._guide/node0248.html),
however C programmers should avoid this function.  ReportMouse() has
problems due to historic confusion about the ordering of its C language
arguments.  Do not use ReportMouse() unless you are programming in
assembler.  C programmers should set the flag directly in the Window
structure using an atomic operation.

Most compilers generate atomic code for operations such as mywindow->flags
|= [WFLG_REPORTMOUSE](../Libraries_Manual_guide/node0125.html#line44) or mywindow->flags &= ~WFLG_REPORTMOUSE.  If you are
unsure of getting an atomic operation from your compiler, you may wish to
do this operation in assembler, or bracket the code with a
[Forbid()/Permit()](../Libraries_Manual_guide/node02D0.html#line10) pair.

After the [WFLG_REPORTMOUSE](../Libraries_Manual_guide/node0125.html#line44) flag is set, whenever the window is active it
will be sent an [IDCMP_MOUSEMOVE](../Libraries_Manual_guide/node01DC.html#line23) messages each time the pointer position
changes. The window must have the IDCMP flag IDCMP_MOUSEMOVE set to
receive these messages.

Mouse movements can cause a very large number of messages to be sent to
the IDCMP, the application should be prepared to handle them efficiently.

Messages about pointer movements may also be activated by setting the flag
[GACT_FOLLOWMOUSE](../Libraries_Manual_guide/node014B.html#line40) in an application [Gadget](../Libraries_Manual_guide/node0149.html) structure. When this flag is set
in a gadget, changes in the pointer position are reported as long as the
gadget is selected by the user. These messages are also sent as
[IDCMP_MOUSEMOVE](../Libraries_Manual_guide/node01DC.html#line23) messages.

