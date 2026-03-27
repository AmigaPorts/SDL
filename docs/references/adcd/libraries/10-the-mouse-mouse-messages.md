---
title: 10 / The Mouse / Mouse Messages
manual: libraries
chapter: libraries
section: 10-the-mouse-mouse-messages
functions: [SetMouseQueue]
libraries: [intuition.library]
---

# 10 / The Mouse / Mouse Messages

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Mouse events are broadcast to the application via the IDCMP or the console
device.  See the "[Intuition Input and Output Methods](libraries/9-intuition-input-and-output-methods.md)" chapter in this book
for information on the IDCMP.  See the "[Console Device](devices/4-console-device.md)" chapter in the
Amiga ROM Kernel Reference Manual: Devices for more about the console
device.

Simple mouse button activity not associated with any Intuition function
will be reported to the window as an [IntuiMessage](libraries/9-using-the-idcmp-intuimessages.md) with a [Class](libraries/9-using-the-idcmp-intuimessages.md) of
[IDCMP_MOUSEBUTTONS](libraries/9-event-message-classes-and-flags-mouse-flags.md).  The IntuiMessage [Code](libraries/9-using-the-idcmp-intuimessages.md) field will be set to
SELECTDOWN, SELECTUP, MIDDLEDOWN, MIDDLEUP, MENUDOWN or MENUUP to specify
changes in the state of the left, middle and right buttons, respectively.

Direct select button events will not be received by the program if the
select button is pressed while the pointer is positioned over a gadget or
other object which uses the button event.  For example, select button
activity over a gadget is reported with a [Class](libraries/9-using-the-idcmp-intuimessages.md) of [IDCMP_GADGETDOWN](libraries/9-event-message-classes-and-flags-gadget-flags.md) or
[IDCMP_GADGETUP](libraries/9-event-message-classes-and-flags-gadget-flags.md).  The gadget is said to have consumed the mouse events and
produced gadget events.

If the menu system is enabled, menu selections appear with a [Class](libraries/9-using-the-idcmp-intuimessages.md) of
[IDCMP_MENUPICK](libraries/9-event-message-classes-and-flags-menu-flags.md).  To directly receive menu button events, the application
must set the flag [WFLG_RMBTRAP](libraries/4-window-attributes-boolean-window-attribute-tags.md) for the window either when the window is
opened or by changing the flag in a single, atomic operation.  See the
chapter "[Intuition Windows](libraries/4-window-attributes-boolean-window-attribute-tags.md)" for more information on the flag WFLG_RMBTRAP.

The program receives mouse position changes in the event [Class](libraries/9-using-the-idcmp-intuimessages.md)
[IDCMP_MOUSEMOVE](libraries/9-event-message-classes-and-flags-mouse-flags.md).  The [MouseX](libraries/9-using-the-idcmp-intuimessages.md) and [MouseY](libraries/9-using-the-idcmp-intuimessages.md) position coordinates describe the
position of the mouse relative to the upper left corner of the reference
window.  These coordinates are always in the resolution of the screen
being used, and may represent any pixel position on the screen, even
though the hardware sprites can be positioned only on the even numbered
pixels of a high resolution screen and on the even numbered rows of an
interlaced screen.  Enabling IDCMP_MOUSEMOVE messages is discussed below
in the section on "[The Pointer](libraries/10-the-pointer-pointer-position.md)".

To get mouse movement reported as deltas (amount of change from the last
position) instead of as absolute positions, set the IDCMP flag
[IDCMP_DELTAMOVE](libraries/9-event-message-classes-and-flags-mouse-flags.md).  When IDCMP_DELTAMOVE is set, the [IDCMP_MOUSEMOVE](libraries/9-event-message-classes-and-flags-mouse-flags.md)
messages received by the program will have delta values rather than
absolute values.  Note that IDCMP_DELTAMOVE is simply a flag used to
modify the behavior of IDCMP_MOUSEMOVE, and that no messages of class
IDCMP_DELTAMOVE are ever sent.

Each window has a queue limit for the number of [IDCMP_MOUSEMOVE](libraries/9-event-message-classes-and-flags-mouse-flags.md) messages
waiting on its IDCMP at any given time.  If the number of mouse move
messages waiting at the IDCMP is equal to the queue limit, then Intuition
will discard additional IDCMP_MOUSEMOVE messages until the application
replies to one of the queued mouse move messages.  The default queue limit
for mouse move messages is five.

Be aware that this may cause some data loss, especially when the
application is using [IDCMP_DELTAMOVE](libraries/9-event-message-classes-and-flags-mouse-flags.md), as the information contained in the
discarded messages is not repeated.  When using IDCMP_DELTAMOVE, this
could cause the application to lose track of the actual pointer position.
The application may wish to change the default mouse queue size if it is
unable to reply to messages queued at the IDCMP for an extended period.
The mouse queue can be set when the window is opened by using the
[WA_MouseQueue](libraries/4-window-attributes-window-attribute-tags.md) tag, and may later be modified using the [SetMouseQueue()](libraries/4-other-window-functions-changing-message-queue-limits.md)
call.  Note that the actual mouse position is always available to the
application through the [Window](libraries/4-intuition-windows-the-window-structure.md) structure [MouseX](libraries/4-intuition-windows-the-window-structure.md) and [MouseY](libraries/4-intuition-windows-the-window-structure.md).

---

## See Also

- [SetMouseQueue — intuition.library](../autodocs/intuition.library.md#setmousequeue)
