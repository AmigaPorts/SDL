/* Source: ADCD 2.1
 * Section: resolving-the-target-host-address
 * Library: amiga-mail
 * ADCD reference: amiga-mail/resolving-the-target-host-address.md
 */

    struct sockaddr_in serv;
    struct hostent *host;
    char *hostnam, *text, *button;

    /*
    ** First we need to try and resolve the host machine as an IP/Internet address.
    ** If that fails, fall back to seaching the hosts file for it.  Later versions of
    ** gethostbyname() may use DNS to find a host name, rather than searching the hosts file.
    */



    bzero( &serv, sizeof(struct sockaddr_in) );
    if ( (serv.sin_addr.s_addr = inet_addr(hostnam)) == INADDR_NONE )
    {
        /*
        ** Okay, the program wasnt handed a dotted decimal address,
        ** so we check and see if it was handed a machine name.
        */

        if ( (host = gethostbyname(hostnam)) == NULL )
        {
            printf("Host not found: %s\n",host);
            FinalExit( RETURN_ERROR );
        }

        /*
        ** It does indeed have a name, so copy the addr field from the
        ** hostent structure into the sockaddr structure.
        */

        bcopy( host->h_addr, (char *)&serv.sin_addr, host->h_length );
    }
