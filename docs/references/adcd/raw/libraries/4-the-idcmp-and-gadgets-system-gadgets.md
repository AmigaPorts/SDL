# 4 / / The IDCMP And Gadgets / System Gadgets


System gadgets on each window provide the user with the ability to manage
the following aspects of the window:  size, position and depth.  These
gadgets are managed by Intuition and the application does not need to take
any action for them to operate properly.  An additional system gadget is
provided for the "close window" function.  The close action is not
directly managed by Intuition; selecting the close gadget will simply send
a message to the application, which is responsible for closing the window.

All of these gadgets are optional, and independent of each other.  The
graphic representations of these gadgets are predefined, and Intuition
always displays them in the same standard locations in the window borders.

The application may choose to be notified when the window changes size, or
it may choose to control the timing of the sizing of the window.
Controlling the timing of sizing operations is done through the use of the
[IDCMP_SIZEVERIFY](../Libraries_Manual_guide/node01E0.html#line28) message.  IDCMP_SIZEVERIFY messages time out if the
application does not respond fast enough.  When these an IDCMP_SIZEVERIFY
message times out the window sizing operation is cancelled by Intuition.

No information is available to the program on user changes to the depth
arrangement of a window.  However a refresh message will be sent if part
of the window needs to be redrawn as a result of a change to the depth
arrangement.

Notification of changes to the position of the window or the size of the
window are available through the [IDCMP_CHANGEWINDOW](../Libraries_Manual_guide/node01E1.html#line104) and [IDCMP_NEWSIZE](../Libraries_Manual_guide/node01E0.html)
flags.  The application specifies the initial size, the maximum and
minimum limits for sizing, and whether the sizing gadget is contained in
the right border, bottom border or both borders.  (See the section on
"[Border Dimensions](../Libraries_Manual_guide/node010A.html)" for information on how the specification of the sizing
gadget affects the border sizes.)

The drag gadget has no imagery other than the implicit imagery of the
title bar.  Setting the window title does not interfere with drag gadget
operation, nor does the drag gadget interfere with the display of the
window title.

