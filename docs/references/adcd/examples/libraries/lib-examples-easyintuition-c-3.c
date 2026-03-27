/* Source: ADCD 2.1
 * Section: lib-examples-easyintuition-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-easyintuition-c.md
 */

    /* Declare variables here */
    ULONG signalmask, winsignal, signals;
    BOOL done = FALSE;
    struct Screen *screen1 = NULL;
    struct Window *window1 = NULL;

    /* Open Intuition Library.  NOTE - We are accepting version 33 (1.2)
     * or higher because we are opening our display in a compatible manner.
     * However - If you add to this example, do NOT use any NEW V37
     * functions unless IntuitionBase->lib_Version is >= 37
     */
    IntuitionBase = OpenLibrary( "intuition.library",INTUITION_REV );
    if (IntuitionBase == NULL)
        cleanExit(screen1, window1, RETURN_WARN);

    /* Open any other required libraries and make */
    /* any assignments that were postponed above  */

    /* Open the screen */
    screen1 = OpenScreen(&fullHires);
    if (screen1 == NULL)
        cleanExit(screen1, window1, RETURN_WARN);

    /* Attach the window to the open screen ... */
    easyWindow.Screen = screen1;

    /* ... and open the window */
    window1 = OpenWindow(&easyWindow);
    if (window1 == NULL)
        cleanExit(screen1, window1, RETURN_WARN);

    /* Set up the signals for the events we want to hear about ...   */
    winsignal = 1L << window1->UserPort->mp_SigBit;  /* window IDCMP */
    signalmask = winsignal;     /* we will only wait on IDCMP events */

    /* Here's the main input event loop where we wait for events.    */
    /* We have asked Intuition to send us CLOSEWINDOW IDCMP events   */
    /* Exec will wake us if any event we are waiting for occurs.     */
    while( !done )
    {
        signals = Wait(signalmask);

        /* An event occurred - now act on the signal(s) we received.*/
        /* We were only waiting on one signal (winsignal) in our    */
        /* signalmask, so we actually know we received winsignal.   */
        if(signals & winsignal)
            done = handleIDCMP(window1);    /* done if close gadget */
    }
    cleanExit(screen1, window1, RETURN_OK); /* Exit the program     */
