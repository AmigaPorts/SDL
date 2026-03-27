# 4 / Other Window Functions / Changing Pointer Position Reports


Pointer position messages to a window may be turned on and off by simply
setting or clearing the [WFLG_REPORTMOUSE](../Libraries_Manual_guide/node0125.html#line44) flag bit in [Window->Flags](../Libraries_Manual_guide/node0121.html#line7), in an
atomic way, as explained for the [WA_RMBTrap](../Libraries_Manual_guide/node0125.html#line95) tag in the "Window Attributes"
section above.  Using this direct method of setting the flag avoids the
historic confusion on the ordering of the arguments of the [ReportMouse()](../Libraries_Manual_guide/node01EC.html#line14)
function call.

Mouse reporting may be turned on even if mouse movements were not
activated when the window was opened.  The proper IDCMP flags must be set
for the window to receive the messages.  See the chapter
"[Intuition Mouse and Keyboard](../Libraries_Manual_guide/node01E9.html)" for more details on enabling mouse
reporting in an application.

