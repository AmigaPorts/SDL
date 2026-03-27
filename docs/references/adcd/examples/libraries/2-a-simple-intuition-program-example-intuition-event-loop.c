/* Source: ADCD 2.1
 * Section: 2-a-simple-intuition-program-example-intuition-event-loop
 * Library: libraries
 * ADCD reference: libraries/2-a-simple-intuition-program-example-intuition-event-loop.md
 */

    winsignal = 1L << window1->UserPort->mp_SigBit;  /* window signal */
    signalmask = winsignal;   /* example only waits for window events */

    while( !done )  {
        signals = Wait(signalmask);
        if (signals & winsignal)
            done = handleIDCMP(window1);
    }
