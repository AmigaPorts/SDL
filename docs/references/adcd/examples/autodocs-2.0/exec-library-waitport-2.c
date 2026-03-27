/* Source: ADCD 2.1
 * Section: exec-library-waitport
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/exec-library-waitport.md
 */

    More than one message may be at the port when this returns.  It is
    proper to call the [GetMsg()](../Includes_and_Autodocs_2._guide/node035A.html) function in a loop until all messages
    have been handled, then wait for more to arrive.

    To wait for more than one port, combine the signal bits from each
    port into one call to the [Wait()](../Includes_and_Autodocs_2._guide/node038A.html) function, then use a [GetMsg()](../Includes_and_Autodocs_2._guide/node035A.html) loop
    to collect any and all messages.  It is possible to get a signal
    for a port WITHOUT a message showing up.  Plan for this.
