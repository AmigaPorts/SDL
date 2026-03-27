/* Source: ADCD 2.1
 * Section: viii-31-shownote-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/viii-31-shownote-c.md
 */

    int     socket;         /* The socket */

    fd_set  sockmask,       /* Mask of open sockets */
            mask;           /* Return value of socketwait() */

    long    umask;          /* AmigaDOS signal mask */



    /*
    ** Call TG_Init to prepare the generic Amiga stuff for use...
    */

    TG_Init();

    /*
    ** ...and SS_Init for the socket-specific arrangements, keeping
    ** track of what it hands back.
    */

    socket = SS_Init();

    /*
    ** First, prepare the various masks for signal processing
    */

    FD_ZERO( &sockmask );
    FD_SET( socket, &sockmask );


    /*
    ** And we enter the event loop itself
    */

    while(1)
    {
        /*
        ** Reset the mask values for another pass
        */

        mask = sockmask;
        umask = SIGBREAKF_CTRL_C;

        /*
        ** selectwait is a combo network and Amiga Wait() rolled into
        ** a single call.  It allows the app to respond to both Amiga
        ** signals (CTRL-C in this case) and to network events.
        **
        ** Here, if the selectwait event is the SIGBREAK signal, we
        ** bail and AppPanic() but otherwise its a network event.
        ** This is a very crude way of handling the exit, but it
        ** is an effective one
        */

        if (selectwait( 2, &mask, NULL, NULL, NULL, &umask ) == -1 )
        {
            AppPanic("CTRL-C:\nProgram terminating!",0);
        }

        /*
        ** Since the contact between the client and server is so
        ** quick, an iterative server is adeqaute.  For cases where
        ** extended connections or concurrent connections are needed,
        ** either a state-machine or concurrent server would be a
        ** better choice.
        **/

        /*
        ** Here, we accept the pending connection (the only case
        ** possible with this mechanism) and dispatch to a routine
        ** which actually handles the client-server communication.
        */

        if (FD_ISSET( socket, &mask ))
        {
            HandleMsg( socket );
        }
        else
        {
            AppPanic("Network Signal Error!",0);
        }
    }
