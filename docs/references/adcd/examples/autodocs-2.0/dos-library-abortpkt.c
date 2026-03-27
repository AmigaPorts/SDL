/* Source: ADCD 2.1
 * Section: dos-library-abortpkt
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/dos-library-abortpkt.md
 */

    This attempts to abort a packet sent earlier with [SendPkt](../Includes_and_Autodocs_2._guide/node02F0.html) to a
    handler.  There is no guarantee that any given handler will allow
    a packet to be aborted, or if it is aborted whether function
    requested completed first or completely.  After calling AbortPkt(),
    you must wait for the packet to return before reusing it or
    deallocating it.
