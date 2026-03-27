/* Source: ADCD 2.1
 * Section: intuition-library-freesysrequest
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/intuition-library-freesysrequest.md
 */

    This routine frees up all memory allocated by a successful call to
    the [BuildSysRequest()](../Includes_and_Autodocs_2._guide/node0202.html) procedure.  If [BuildSysRequest()](../Includes_and_Autodocs_2._guide/node0202.html) returned a
    pointer to a window, then you are able to wait on the message port
    of that window to detect an event which satisfies the requester.
    When you want to remove the requester, you call this procedure.  It
    ends the requester and deallocates any memory used in the creation
    of the requester.  It also closes the special window that was opened
    for your system requester.

    For V36: It's OK if you pass a NULL or a TRUE (1) value to
    this function.  Also, this function properly disposes of
    requesters gotten using BuildEasyRequest().
