/* Source: ADCD 2.1
 * Section: listening-for-network-and-amiga-events
 * Library: amiga-mail
 * ADCD reference: amiga-mail/listening-for-network-and-amiga-events.md
 */

    long umask;
    fd_set mask;

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
        */

        if (selectwait( 2, &mask, NULL, NULL, NULL, &umask ) == -1 )
        {
            AppPanic("CTRL-C:\nProgram terminating!",0);
        }
