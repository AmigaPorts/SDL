/* Source: ADCD 2.1
 * Section: dos-library-dopkt
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/dos-library-dopkt.md
 */

    Sends a packet to a handler and waits for it to return.  Any secondary
    return will be available in D1 AND from [IoErr()](../Includes_and_Autodocs_2._guide/node02C2.html).  DoPkt() will work
    even if the caller is an exec task and not a process; however it will
    be slower, and may fail for some additional reasons, such as being
    unable to allocate a signal.  DoPkt() uses your pr_MsgPort for the
    reply, and will call pr_PktWait.  (See BUGS regarding tasks, though).

    Only allows 5 arguments to be specified.  For more arguments (packets
    support a maximum of 7) create a packet and use [SendPkt()/WaitPkt()](../Includes_and_Autodocs_2._guide/node030F.html).
