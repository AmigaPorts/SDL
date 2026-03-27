/* Source: ADCD 2.1
 * Section: lib-examples-lines-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-lines-c.md
 */

    {
    /* Whenever you want to wait on just one message port */
    /* you can use WaitPort(). WaitPort() doesn't require */
    /* the setting of a signal bit. The only argument it  */
    /* requires is the pointer to the window's UserPort   */
    WaitPort(Win->UserPort);
    while (msg = (struct IntuiMessage *)GetMsg(Win->UserPort))
        {
        switch (msg->Class)
            {
            case IDCMP_CLOSEWINDOW:
                flag = FALSE;
                break;
            case IDCMP_NEWSIZE:
                doNewSize();
    		doDrawStuff();
                break;
            case IDCMP_GADGETDOWN:
                currentGadget = GADGETID(msg);
                break;
            case IDCMP_GADGETUP:
                checkGadget(currentGadget);
                currentGadget = NO_GADGET;
                break;
            case IDCMP_INTUITICKS:
                checkGadget(currentGadget);
                break;
            }
        ReplyMsg((struct Message *)msg);
        }
    }
