/* Source: ADCD 2.1
 * Section: 17-signals-processing-signals-without-wait-ing
 * Library: libraries
 * ADCD reference: libraries/17-signals-processing-signals-without-wait-ing.md
 */

    /* Get current state of signals */
    signals = SetSignal(0L, 0L);

    /* check for Ctrl-C */
    if (signals & SIGBREAKF_CTRL_C)
    {
        /* The Ctrl-C signal has been set, take care of processing it... */

        /* ...then clear the Ctrl-C signal */
        SetSignal(0L, SIGBREAKF_CTRL_C);
    }
