/* Source: ADCD 2.1
 * Section: intuition-library-reportmouse
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/intuition-library-reportmouse.md
 */

    Tells Intuition whether or not to broadcast mouse-movement events to
    your window when it's the active one.  The Boolean value specifies
    whether to start or stop broadcasting position information of
    mouse-movement.  If the window is the active one, mouse-movement
    reports start coming immediately afterwards.  This same routine will
    change the current state of the GACT_FOLLOWMOUSE function of a
    currently-selected gadget too.

    Note that calling ReportMouse() when a gadget is selected will only
    temporarily change whether or not mouse movements are reported while
    that gadget remains selected; the next time the gadget is selected, its
    GACT_FOLLOWMOUSE flag is examined anew.

    Note also that calling ReportMouse() when no gadget is currently
    selected will change the state of the window's WFLG_REPORTMOUSE flag,
    but will have no effect on any gadget that may be subsequently
    selected. (This is all fixed in V36.)

    The ReportMouse() function is first performed when [OpenWindow()](../Includes_and_Autodocs_2._guide/node0239.html)
    is first called; if the flag WFLG_REPORTMOUSE is included among
    the options, then all mouse-movement events are reported
    to the opening task and will continue to be reported
    until ReportMouse() is called with a Boolean value of FALSE.
    If WFLG_REPORTMOUSE is not set, then no mouse-movement reports will
    be broadcast until ReportMouse() is called with a Boolean of TRUE.

    Note that the WFLG_REPORTMOUSE flag, as managed by this routine,
    determines IF mouse messages are to be broadcast.  Determining HOW
    they are to be broadcast is determined by the IDCMP_MOUSEMOVE
    IDCMPFlag.
