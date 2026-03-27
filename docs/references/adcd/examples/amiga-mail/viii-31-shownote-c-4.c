/* Source: ADCD 2.1
 * Section: viii-31-shownote-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/viii-31-shownote-c.md
 */

    struct sockaddr_in  sockaddr;

    int snum, len = sizeof(sockaddr);

    /*
    ** Attempt to open socket library and initialize socket environ.
    ** If this fails, bail out to the non-returning AppPanic() routine.
    */

    /*
    ** The errno variable is a part of ANSI, and is defined in the c.o
    ** startup code.  Essentially, its where ANSI functions put their
    ** error codes when they fail.  For more information, consult a
    ** reference to ANSI C.
    */

    if (SockBase = OpenLibrary("inet:libs/socket.library",0L))
    {
        setup_sockets( 3, &errno );
    }
    else
    {
        AppPanic("Can't open socket.library!",0);
    }

    /*
    ** Open the initial socket on which incoming messages will queue for
    ** handling.  While the server is iterative, I do it this way so that
    ** SIGBREAKF_CTRL_C will continue to function.
    */


    if ((snum = socket( AF_INET, SOCK_STREAM, 0 )) == -1)
    {
        AppPanic("Socket Creation:",errno);
    }

    /*
    ** Here we clear and prepare the information to give our socket
    ** a real address on the system.
    */

    memset( &sockaddr, 0, len );
    sockaddr.sin_family = AF_INET;
