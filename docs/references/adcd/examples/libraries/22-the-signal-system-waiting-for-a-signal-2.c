/* Source: ADCD 2.1
 * Section: 22-the-signal-system-waiting-for-a-signal
 * Library: libraries
 * ADCD reference: libraries/22-the-signal-system-waiting-for-a-signal.md
 */

    signals = SetSignal(0,0);           /* Get current state of signals */

    if (signals & SIGBREAKF_CTRL_C)     /* Check for Ctrl-C.           */
        {
        printf("Break\n");              /* Ctrl-C signal has been set. */
        SetSignal(0, SIGBREAKF_CTRL_C)  /* Clear Ctrl-C signal.        */
        }
