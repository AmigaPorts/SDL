/* Source: ADCD 2.1
 * Section: intuition-library-sysreqhandler
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/intuition-library-sysreqhandler.md
 */

    Handles input for a window returned by either [BuildSysRequest()](../Includes_and_Autodocs_2._guide/node0202.html)
    or BuildEasyRequest().  These functions with SysReqHandler()
    you can perform an "asynchronous" EasyRequest() or [AutoRequest()](../Includes_and_Autodocs_2._guide/node01FF.html).
    That is to say, you can perform other processing while you
    wait for the requester to be satisfied.

    Each time this function is called, it will process all
    IDCMPMessages that the window has received.  If the parameter
    'WaitInput' is non-zero, SysReqHandler() will wait for input
    (by calling [WaitPort()](../Includes_and_Autodocs_2._guide/node038C.html)) if there are no IDCMP messages.

    SysReqHandler() returns the same values as EasyRequest(): A gadget
    ID greater than equal to 0, and  -1 if one of the other IDCMP
    events were received.

    An additional value of -2 is returned if the input processed
    does not satisfy the requester.  In this case, you might
    perform some processing and call SysReqHandler() again.

    Note: this function does NOT terminate the system request.
    Not only must you call [FreeSysRequest()](../Includes_and_Autodocs_2._guide/node0219.html) to eliminate the request,
    but you may also continue processing after an event which would
    normally terminate a normal call to EasyRequest().
