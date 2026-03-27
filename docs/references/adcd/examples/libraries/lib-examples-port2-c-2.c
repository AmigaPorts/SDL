/* Source: ADCD 2.1
 * Section: lib-examples-port2-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-port2-c.md
 */

    struct MsgPort *port;

    Forbid();
    port = FindPort(portname);
    if (port) PutMsg(port, message);
    Permit();
    return(port ? TRUE : FALSE); /* FALSE if the port was not found */

         /* Once we've done a Permit(), the port might go away and leave us with an invalid port    */
