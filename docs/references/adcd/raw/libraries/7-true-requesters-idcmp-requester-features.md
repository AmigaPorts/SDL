# 7 / True Requesters / IDCMP Requester Features


Intuition can notify your application about user activity in the requester
by sending a message to the parent window's IDCMP port ([Window.UserPort](../Libraries_Manual_guide/node01D6.html#line16)).
When using the IDCMP for input, the following IDCMP flags control how
requester input events will be handled.

[IDCMP_REQSET](../Libraries_Manual_guide/node01DF.html)

    With this flag set, the program will receive a message whenever a
    requester opens in its window.  The application will receive one
    IDCMP_REQSET event for each requester opened in the window.
[IDCMP_REQCLEAR](../Libraries_Manual_guide/node01DF.html#line4)

    With this flag set, the program will receive a message whenever a
    requester is cleared from its window.  The application will receive
    one IDCMP_REQCLEAR event for each requester closed in the window.  By
    counting the number of IDCMP_REQSET and IDCMP_REQCLEAR events, the
    application may determine how many requesters are currently open in a
    window.
[IDCMP_REQVERIFY](../Libraries_Manual_guide/node01DF.html#line8)

```c
    With this flag set, the application can ensure that it is ready to
    allow a requester to appear in the window before the requester is
    displayed.

    When the program receives an IDCMP_REQVERIFY message, it must reply
    to that message before the requester is added to the window.  If
    multiple requesters are opened in the window at the same time, only
    the first one will cause an IDCMP_REQVERIFY event.  It is assumed
    that once a requester is in a window others may be added without the
    program's consent.  After the requester count drops to zero and there
    are no open requesters in the window, the next requester to open will
    cause another IDCMP_REQVERIFY event.

    IDCMP_REQVERIFY is ignored by the [Request()](../Libraries_Manual_guide/node01A2.html#line12) function.  Since
    Request() is controlled by the application, it is assumed that the
    program is prepared to handle the request when calling this function.
    Since the system does not render [true](../Libraries_Manual_guide/node01A1.html) requesters into an
    application's window ([EasyRequest()](../Libraries_Manual_guide/node01AC.html) and [AutoRequest()](../Libraries_Manual_guide/node01B4.html#line21) come up in
    their own window, not in the application's window), IDCMP_REQVERIFY
    will only control the timing of [double menu](../Libraries_Manual_guide/node01A9.html) requesters.
```
These flags are set when the parent window is first opened by using either
the [WA_IDCMP](../Libraries_Manual_guide/node0124.html#line35) tag or NewWindow.IDCMPFlags.  They can also be set after the
parent window is open by using the [ModifyIDCMP()](../Libraries_Manual_guide/node01E3.html#line5) call.  See the chapter
entitled "[Intuition Input and Output Methods](../Libraries_Manual_guide/node01DF.html)," for further information
about these IDCMP flags.  See the "[Intuition Windows](../Libraries_Manual_guide/node010D.html)" chapter for details
on setting IDCMP flags when a window is opened.

