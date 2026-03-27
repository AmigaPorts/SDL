/* Source: ADCD 2.1
 * Section: identifying-network-events-and-talking-to-the-client
 * Library: amiga-mail
 * ADCD reference: amiga-mail/identifying-network-events-and-talking-to-the-client.md
 */

    /*
    ** Having dealt with the message one way or the other, send the message
    ** back at the remote, then disconnect from the remote and return.
    */

    send( nsock, (char *)&in, sizeof(struct NetNote), 0 );
    s_close( nsock );
