/* Source: ADCD 2.1
 * Section: identifying-network-events-and-talking-to-the-client
 * Library: amiga-mail
 * ADCD reference: amiga-mail/identifying-network-events-and-talking-to-the-client.md
 */

    if (FD_ISSET( socket, &mask ))
    {
        HandleMsg( socket );
    }
    else
    {
        AppPanic("Network Signal Error!",0);
    }
