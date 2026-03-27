/* Source: ADCD 2.1
 * Section: exec-library-waitport
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/exec-library-waitport.md
 */

    This function waits for the given port to become non-empty.  If
    necessary, the [Wait()](../Includes_and_Autodocs_2._guide/node038A.html) function will be called to wait for the port
    signal.  If a message is already present at the port, this function
    will return immediately.  The return value is always a pointer to
    the first message queued (but it is not removed from the queue).
