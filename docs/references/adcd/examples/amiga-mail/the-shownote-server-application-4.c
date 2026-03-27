/* Source: ADCD 2.1
 * Section: the-shownote-server-application
 * Library: amiga-mail
 * ADCD reference: amiga-mail/the-shownote-server-application.md
 */

    if ( bind( snum, (struct sockaddr *)&sockaddr, len ) < 0 )
    {
        AppPanic("Socket Binding:",errno);
    }

    /*
    ** Okay, the socket is as ready as it gets.  Now all we need to do is to
    ** tell the system that the socket is open for business.
    */

    listen( snum, 5 );
