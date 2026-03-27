/* Source: ADCD 2.1
 * Section: 24-message-ports-how-to-rendezvous-at-a-message-port
 * Library: libraries
 * ADCD reference: libraries/24-message-ports-how-to-rendezvous-at-a-message-port.md
 */

    #include <exec/types.h>
    #include <exec/ports.h>

       BOOL MsgPort SafePutToPort(struct Message *message, STRPTR portname)
       {
           struct MsgPort *port;

           Forbid();
           port = FindPort(portname);
           if (port) PutMsg(port,message);
           Permit();
           return(port ? TRUE : FALSE);
                           /* If FALSE, the port was not found */

           /* Once we've done a Permit(), the port might go away */
           /* and leave us with an invalid port address. So we   */
           /* return just a BOOL to indicate whether the message */
           /* has been sent or not.                              */
       }
