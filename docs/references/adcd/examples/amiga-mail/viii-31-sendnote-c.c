/* Source: ADCD 2.1
 * Section: viii-31-sendnote-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/viii-31-sendnote-c.md
 */

    struct RDArgs *rdargs;      /* ReadArgs() return information */

    struct sockaddr_in serv;    /* Server's Internet Address */

    struct hostent *host;       /* The located host info */

    struct NetNote out;         /* Message packet for send/recv */

    long opts[OPT_COUNT] =  {
                            0L,
                            (long)"== PING! ==",
                            (long)"OK"
                            };

    int sock;                   /* The working socket */

    char *hostnam,                  /* Arg of hostname */
         *text,                 /* Arg of text to be sent */
         *button;               /* Arg of button text */

    /*
    ** Process arguments using new (2.0) dos calls.
    */

    rdargs = (struct RDArgs *)ReadArgs( (UBYTE *)TEMPLATE, opts, NULL );
    if(rdargs == NULL)
    {
        puts("Command line not accepted!");
        FinalExit( RETURN_ERROR );
    }

    hostnam = (char *)opts[OPT_HOST];
    text = (char *)opts[OPT_TEXT];
    button  = (char *)opts[OPT_BUTTON];

    /*
    **  Open socket.library and intialize socket space
    */

    if (SockBase = OpenLibrary("inet:libs/socket.library", 0L))
    {
        setup_sockets( 1, &errno );
    }
    else
    {
        puts("Can't open socket.library!");
        FinalExit( RETURN_ERROR );
    }

    /*
    ** First we need to try and resolve the host machine as a
    ** normal IP/Internet address.  If that fails, fall back to seaching
    ** the hosts file for it.  Before anything, we need to clear out
    ** the buffer (serv) where the information will be placed, using
    ** the bzero() call (actually a macro in sys/types.h).
    */

    bzero( &serv, sizeof(struct sockaddr_in) );
    if ( (serv.sin_addr.s_addr = inet_addr(hostnam)) == INADDR_NONE )
    {
        /*
        ** Okay, the program wasnt handed a dotted decimal address,
        ** so we check and see if it was handed a machine name.
        **
        ** NOTE:  Grab the information you need before you use the
        **        gethostbyname() call again.  Subsequent calls
        **        will overwrite the buffer it hands back.
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
