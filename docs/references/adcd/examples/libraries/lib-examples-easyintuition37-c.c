/* Source: ADCD 2.1
 * Section: lib-examples-easyintuition37-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-easyintuition37-c.md
 */

    /* Declare variables here */
    ULONG signalmask, winsignal, signals;
    BOOL done = FALSE;
    UWORD pens[]={~0};

    struct Screen *screen1 = NULL;
    struct Window *window1 = NULL;

    /* Open the Intuition Library */
    IntuitionBase = OpenLibrary( "intuition.library",INTUITION_REV );
    if (IntuitionBase == NULL)
        cleanExit(screen1, window1, RETURN_WARN);

    /* Open any other required libraries and make */
    /* any assignments that were postponed above  */

    /* Open the screen */
    screen1 = OpenScreenTags(NULL,
                             SA_Pens,  (ULONG)pens,
                             SA_DisplayID, HIRES_KEY,
                             SA_Depth, 2,
                             SA_Title, (ULONG)"Our Screen",
                             TAG_DONE);

    if (screen1 == NULL)
        cleanExit(screen1, window1, RETURN_WARN);

    /* ... and open the window */
    window1 = OpenWindowTags(NULL,
                             /* Specify window dimensions and limits */
                             WA_Left,         WIN_LEFTEDGE,
                             WA_Top,          WIN_TOPEDGE,
                             WA_Width,        WIN_WIDTH,
                             WA_Height,       WIN_HEIGHT,
                             WA_MinWidth,     WIN_MINWIDTH,
                             WA_MinHeight,    WIN_MINHEIGHT,
                             WA_MaxWidth,     ~0,
                             WA_MaxHeight,    ~0,
                             /* Specify the system gadgets we want */
                             WA_CloseGadget,  TRUE,
                             WA_SizeGadget,   TRUE,
                             WA_DepthGadget,  TRUE,
                             WA_DragBar,      TRUE,
                             /* Specify other attributes           */
                             WA_Activate,     TRUE,
                             WA_NoCareRefresh,TRUE,

                             /* Specify the events we want to know about */
                             WA_IDCMP,        IDCMP_CLOSEWINDOW,

                             /* Attach the window to the open screen ...*/
                             WA_CustomScreen, screen1,
                             WA_Title,        "EasyWindow",
                             WA_ScreenTitle,  "Our Screen - EasyWindow is Active",
                             TAG_DONE);
    if (window1 == NULL)
        cleanExit(screen1, window1, RETURN_WARN);

    /* Set up the signals for the events we want to hear about ...   */
    winsignal = 1L << window1->UserPort->mp_SigBit;  /* window IDCMP */
    signalmask = winsignal;   /* we are only waiting on IDCMP events */

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
