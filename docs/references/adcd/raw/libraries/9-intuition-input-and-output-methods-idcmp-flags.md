# 9 Intuition Input and Output Methods / IDCMP Flags


The application specifies the information it wants Intuition to send to it
via the IDCMP by setting IDCMP flags.  These may be set either when
opening the window or by calling [ModifyIDCMP()](../Libraries_Manual_guide/node01E3.html#line5).

The flags set may be viewed as a filter, in that Intuition will only post
[IntuiMessage](../Libraries_Manual_guide/node01D9.html)s to an IDCMP if the matching flag is set.  Thus, the
application will only receive the IDCMP messages whose [Class](../Libraries_Manual_guide/node01D9.html#line28) matches one
of the bits set in the window's IDCMP.

For many of these messages, there is a separation of the act of filtering
these messages and causing Intuition to send the messages in the first
place.  For instance, menu help events may be activated for a window by
setting the [WA_MenuHelp](../Libraries_Manual_guide/node0125.html#line142) attribute when the window is opened.  However, the
IDCMP will only receive the messages if the [IDCMP_MENUHELP](../Libraries_Manual_guide/node01DE.html#line21) flag is set.
If this flag is not set, then the events are passed downstream in the
input and may be picked up by the console device.

 [Event Message Classes and Flags](../Libraries_Manual_guide/node01DB.html)    [Verification Functions](../Libraries_Manual_guide/node01E2.html) 

