/* Source: ADCD 2.1
 * Section: exec-library-findport
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/exec-library-findport.md
 */

    #include [<exec/types.h>](../Includes_and_Autodocs_2._guide/node0096.html)
    struct [MsgPort](../Includes_and_Autodocs_2._guide/node0099.html#line29) *FindPort();

    ULONG SafePutToPort(message, portname)
    struct [Message](../Includes_and_Autodocs_2._guide/node0099.html#line48) *message;
    STRPTR          portname;
    {
    struct [MsgPort](../Includes_and_Autodocs_2._guide/node0099.html#line29) *port;

        Forbid();
            port = FindPort(portname);
            if (port)
                PutMsg(port,message);
        Permit();
        return((ULONG)port); /* If zero, the port has gone away */
    }
