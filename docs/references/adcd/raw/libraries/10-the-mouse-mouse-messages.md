# 10 / The Mouse / Mouse Messages


Mouse events are broadcast to the application via the IDCMP or the console
device.  See the "[Intuition Input and Output Methods](../Libraries_Manual_guide/node01CE.html)" chapter in this book
for information on the IDCMP.  See the "[Console Device](../Devices_Manual_guide/node0080.html)" chapter in the
Amiga ROM Kernel Reference Manual: Devices for more about the console
device.

Simple mouse button activity not associated with any Intuition function
will be reported to the window as an [IntuiMessage](../Libraries_Manual_guide/node01D9.html) with a [Class](../Libraries_Manual_guide/node01D9.html#line28) of
[IDCMP_MOUSEBUTTONS](../Libraries_Manual_guide/node01DC.html).  The IntuiMessage [Code](../Libraries_Manual_guide/node01D9.html#line33) field will be set to
SELECTDOWN, SELECTUP, MIDDLEDOWN, MIDDLEUP, MENUDOWN or MENUUP to specify
changes in the state of the left, middle and right buttons, respectively.

Direct select button events will not be received by the program if the
select button is pressed while the pointer is positioned over a gadget or
other object which uses the button event.  For example, select button
activity over a gadget is reported with a [Class](../Libraries_Manual_guide/node01D9.html#line28) of [IDCMP_GADGETDOWN](../Libraries_Manual_guide/node01DD.html) or
[IDCMP_GADGETUP](../Libraries_Manual_guide/node01DD.html#line6).  The gadget is said to have consumed the mouse events and
produced gadget events.

If the menu system is enabled, menu selections appear with a [Class](../Libraries_Manual_guide/node01D9.html#line28) of
[IDCMP_MENUPICK](../Libraries_Manual_guide/node01DE.html).  To directly receive menu button events, the application
must set the flag [WFLG_RMBTRAP](../Libraries_Manual_guide/node0125.html#line95) for the window either when the window is
opened or by changing the flag in a single, atomic operation.  See the
chapter "[Intuition Windows](../Libraries_Manual_guide/node0125.html#line95)" for more information on the flag WFLG_RMBTRAP.

The program receives mouse position changes in the event [Class](../Libraries_Manual_guide/node01D9.html#line28)
[IDCMP_MOUSEMOVE](../Libraries_Manual_guide/node01DC.html#line23).  The [MouseX](../Libraries_Manual_guide/node01D9.html#line53) and [MouseY](../Libraries_Manual_guide/node01D9.html#line53) position coordinates describe the
position of the mouse relative to the upper left corner of the reference
window.  These coordinates are always in the resolution of the screen
being used, and may represent any pixel position on the screen, even
though the hardware sprites can be positioned only on the even numbered
pixels of a high resolution screen and on the even numbered rows of an
interlaced screen.  Enabling IDCMP_MOUSEMOVE messages is discussed below
in the section on "[The Pointer](../Libraries_Manual_guide/node01EC.html)".

To get mouse movement reported as deltas (amount of change from the last
position) instead of as absolute positions, set the IDCMP flag
[IDCMP_DELTAMOVE](../Libraries_Manual_guide/node01DC.html#line57).  When IDCMP_DELTAMOVE is set, the [IDCMP_MOUSEMOVE](../Libraries_Manual_guide/node01DC.html#line23)
messages received by the program will have delta values rather than
absolute values.  Note that IDCMP_DELTAMOVE is simply a flag used to
modify the behavior of IDCMP_MOUSEMOVE, and that no messages of class
IDCMP_DELTAMOVE are ever sent.

Each window has a queue limit for the number of [IDCMP_MOUSEMOVE](../Libraries_Manual_guide/node01DC.html#line23) messages
waiting on its IDCMP at any given time.  If the number of mouse move
messages waiting at the IDCMP is equal to the queue limit, then Intuition
will discard additional IDCMP_MOUSEMOVE messages until the application
replies to one of the queued mouse move messages.  The default queue limit
for mouse move messages is five.

Be aware that this may cause some data loss, especially when the
application is using [IDCMP_DELTAMOVE](../Libraries_Manual_guide/node01DC.html#line57), as the information contained in the
discarded messages is not repeated.  When using IDCMP_DELTAMOVE, this
could cause the application to lose track of the actual pointer position.
The application may wish to change the default mouse queue size if it is
unable to reply to messages queued at the IDCMP for an extended period.
The mouse queue can be set when the window is opened by using the
[WA_MouseQueue](../Libraries_Manual_guide/node0124.html#line154) tag, and may later be modified using the [SetMouseQueue()](../Libraries_Manual_guide/node012B.html#line27)
call.  Note that the actual mouse position is always available to the
application through the [Window](../Libraries_Manual_guide/node0121.html) structure [MouseX](../Libraries_Manual_guide/node0121.html#line48) and [MouseY](../Libraries_Manual_guide/node0121.html#line48).

