/* Source: ADCD 2.1
 * Section: ix-1-4play-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/ix-1-4play-c.md
 */

    BOOL done=FALSE;
    UBYTE error;

    /* getport() is an assembly routine that allocates the parallel port
     * and makes all the lines we're interested in "read" lines.
     */
    if(error=getport()) Quit("Parallel port in use",25);
    /* WARNING:
     * This example continuously reads the ports and checks for CTRL_C,
     * thereby eating a lot of CPU time.  Actual applications that expect
     * to be even more system friendly might want to set up some interrupts
     * on the fire button lines, such that the game can read the ports less
     * often, but never miss a "fire" press.
     */

    while(!done)
    {
        read34();       /* read34() is the assembly routine that copies the
                         * relavent data from the port into our variables.
                         */

        /* We'll just print the raw bytes from the read, and leave it as an
         * exercise for the reader to mask out the relevant bits.
         * (Check the pinouts to find which bits the switches appear at.)
         */
        printf("portdata = %u, firedata = %u\n",portdata,firedata);

        /* Check CTRL_C */
        if(SetSignal(0L,0L) & SIGBREAKF_CTRL_C) /* Hit since last check? */
        {
            SetSignal(0L,SIGBREAKF_CTRL_C); /* Clear old status */
            done=TRUE;
        }
    }
    Quit("Ctrl-C was pressed.",0);
