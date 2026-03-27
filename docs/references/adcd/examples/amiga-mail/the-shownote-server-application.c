/* Source: ADCD 2.1
 * Section: the-shownote-server-application
 * Library: amiga-mail
 * ADCD reference: amiga-mail/the-shownote-server-application.md
 */

    /*
    ** Attempt to open socket library and initialize socket environment.
    ** If this fails, bail out to the non-returning AppPanic() routine.
    */

    if (SockBase = OpenLibrary("inet:libs/socket.library",0L))
    {
        setup_sockets( 3, &errno );
    }
    else
    {
        AppPanic("Can't open socket.library!",0);
    }
