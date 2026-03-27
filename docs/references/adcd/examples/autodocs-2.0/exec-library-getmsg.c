/* Source: ADCD 2.1
 * Section: exec-library-getmsg
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/exec-library-getmsg.md
 */

    This function receives a message from a given message port. It
    provides a fast, non-copying message receiving mechanism. The
    received message is removed from the message port.

    This function will not wait.  If a message is not present this
    function will return zero.  If a program must wait for a message,
    it can [Wait()](../Includes_and_Autodocs_2._guide/node038A.html) on the signal specified for the port or use the
    [WaitPort()](../Includes_and_Autodocs_2._guide/node038C.html) function.  There can only be one task waiting for any
    given port.

    Getting a message does not imply to the sender that the message is
    free to be reused by the sender.  When the receiver is finished
    with the message, it may [ReplyMsg()](../Includes_and_Autodocs_2._guide/node0379.html) it back to the sender.


    Getting a signal does NOT always imply a message is ready.  More
    than one message may arrive per signal, and signals may show up
    without messages.  Typically you must loop to GetMsg() until it
    returns zero, then [Wait()](../Includes_and_Autodocs_2._guide/node038A.html) or [WaitPort()](../Includes_and_Autodocs_2._guide/node038C.html).
