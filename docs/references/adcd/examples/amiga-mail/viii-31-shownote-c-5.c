/* Source: ADCD 2.1
 * Section: viii-31-shownote-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/viii-31-shownote-c.md
 */

    sockaddr.sin_port = 8769;

    sockaddr.sin_addr.s_addr = INADDR_ANY;

    /*
    ** Having everything set up, we now attempt to allocate the port number
    ** for our socket.  If this fails, we bail.
    */

    if ( bind( snum, (struct sockaddr *)&sockaddr, len ) < 0 )
    {
        AppPanic("Socket Binding:",errno);
    }

    /*
    ** Okay, the socket is as ready as it gets.  Now all we need to do is to
    ** tell the system that the socket is open for business.  In an ideal
    ** world, this needs to be checked for errors, but for the scope of the
    ** example, it isnt necessary.  By the way, the '5' in the listen() call
    ** indicates the "queue size" for number of outstanding requests.
    */

    listen( snum, 5 );

    /*
    ** And last, we pass the socket number back to the main routine.
    */

    return snum;
