/* Source: ADCD 2.1
 * Section: iv-77-optimrefresh-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/iv-77-optimrefresh-c.md
 */

    topLine    = 0;
    oldTopLine = 0;

    /* initialize rendering attributes we are going to use */
    render = *window->RPort;
    SetDrMd(&render,JAM2);
    SetWrMsk(&render,1);         /* we only want to render in the first plane */
    SetAPen(&render,1);

    /* initialize clearing attributes we are going to use */
    clear = *window->RPort;
    SetDrMd(&clear,JAM2);
    SetWrMsk(&clear,1);          /* we only want to clear the first plane */
    SetAPen(&clear,0);

    /* render the initial display */
    RefreshView(TRUE);

    /* set the initial scroller position and size */
    SetScroller(window,scroller,linesVisible,numLines,topLine);

    /* we aren't busy, so register that fact */
    BusyState(FALSE);

    while (TRUE)
    {
        /* if the LAYERREFRESH flag is set in the window's layer, it
         * means the layer has some damage we should repair.
         */
        if (LAYERREFRESH & window->WLayer->Flags)
        {
            /* enter optimized repair state */
            BeginRefresh(window);

            /* redraw the whole display through the optimized repair
             * region
             */
            RefreshView(TRUE);

            /* tell the system we are done repairing the window
             */
            EndRefresh(window,TRUE);
        }


        /* nothing left to do but wait for user input */
        WaitPort(window->UserPort);
        intuiMsg = (struct IntuiMessage *)GetMsg(window->UserPort);
        class    = intuiMsg->Class;
        ReplyMsg(intuiMsg);

        /* we got a message, so act on it */
        switch (class)
        {
            /* user clicked on the close gadget, exit the program */
            case IDCMP_CLOSEWINDOW  : return;

            /* user sized the window. We need to redraw the whole
             * display in order to eliminate any garbage. Start by
             * calling BeginRefresh() and EndRefresh() to eliminate
             * the window's damage regions then completely redraw
             * the window contents.
             */
            case IDCMP_NEWSIZE      : BeginRefresh(window);
                                      EndRefresh(window,TRUE);
                                      RefreshView(TRUE);
                                      SetScroller(window,
                                                  scroller,
                                                  linesVisible,
                                                  numLines,
                                                  topLine);
                                      break;

            /* Intuition is telling us damage occured to our layer.
             * Don't bother doing anything, the check at the top of the
             * loop will catch this fact and refresh the display
             *
             * Even though we don't do anything with these events, we
             * still need them to be sent to us so we will wake up and
             * look at the LAYERREFRESH bit.
             */
            case IDCMP_REFRESHWINDOW: break;

            /* user is playing with the scroller. Get the scroller's current
             * top line and synchronize the display to match it
             */
            case IDCMP_GADGETUP     :
            case IDCMP_GADGETDOWN   :
            case IDCMP_MOUSEMOVE    : GetAttr(PGA_Top,scroller,&topLine);
                                      RefreshView(FALSE);
                                      break;

            /* whenever a key is hit, we fake becoming busy for 4
             * seconds. During that time, try to size and depth arrange
             * the window to see what happens to its contents
             */
            case IDCMP_VANILLAKEY   : BusyState(TRUE);
                                      Delay(200);
                                      BusyState(FALSE);
                                      break;
        }
    }
