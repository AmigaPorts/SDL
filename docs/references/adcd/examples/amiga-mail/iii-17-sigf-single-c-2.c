/* Source: ADCD 2.1
 * Section: iii-17-sigf-single-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/iii-17-sigf-single-c.md
 */

                                /* signals the parent using SIGF_SINGLE.     */
    ULONG x;

    /* Wait for a startup signal. This is to allow the parent process to
     * print its banner message and clear SIGF_SINGLE.
     */
    Wait(SIGBREAKF_CTRL_F);

    PutStr("Child Process: I'm alive and starting a 5 second TimeDelay()");
    Flush(Output());

    for (x = 0; x < 5; x++)
    {
        TimeDelay(UNIT_VBLANK, 1, 0);     /* Delay for 5 seconds, printing a */
        FPuts(Output(), " .");            /* dot during each second.         */
        Flush(Output());
    }

    TimeDelay(UNIT_VBLANK, 1, 0);

    PutStr(" Finished.\n");
    PutStr("Child Process: Signalling main process and exiting.  Bye.\n");
    Flush(Output());

    Signal((struct Task *)mainprocess, SIGF_SINGLE);    /* Finished waiting, */
                                                        /* signal the main   */
                                                        /* process and exit  */
                                                        /* child process.    */
