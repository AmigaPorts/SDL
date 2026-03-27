/* Source: ADCD 2.1
 * Section: lib-examples-gadtoolsgadgets-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-gadtoolsgadgets-c.md
 */

    {
    Wait (1 << mywin->UserPort->mp_SigBit);

    /* GT_GetIMsg() returns an IntuiMessage with more friendly information for
    ** complex gadget classes.  Use it wherever you get IntuiMessages where
    ** using GadTools gadgets.
    */
    while ((!terminated) &&
           (imsg = GT_GetIMsg(mywin->UserPort)))
        {
        /* Presuming a gadget, of course, but no harm...
        ** Only dereference this value (gad) where the Class specifies
        ** that it is a gadget event.
        */
        gad = (struct Gadget *)imsg->IAddress;

        imsgClass = imsg->Class;
        imsgCode = imsg->Code;

        /* Use the toolkit message-replying function here... */
        GT_ReplyIMsg(imsg);

        switch (imsgClass)
            {
            /*  --- WARNING --- WARNING --- WARNING --- WARNING --- WARNING ---
            ** GadTools puts the gadget address into IAddress of IDCMP_MOUSEMOVE
            ** messages.  This is NOT true for standard Intuition messages,
            ** but is an added feature of GadTools.
            */
            case IDCMP_GADGETDOWN:
            case IDCMP_MOUSEMOVE:
            case IDCMP_GADGETUP:
                handleGadgetEvent(mywin, gad, imsgCode, slider_level, my_gads);
                break;
            case IDCMP_VANILLAKEY:
                handleVanillaKey(mywin, imsgCode, slider_level, my_gads);
                break;
            case IDCMP_CLOSEWINDOW:
                terminated = TRUE;
                break;
            case IDCMP_REFRESHWINDOW:
                /* With GadTools, the application must use GT_BeginRefresh()
                ** where it would normally have used BeginRefresh()
                */
                GT_BeginRefresh(mywin);
                GT_EndRefresh(mywin, TRUE);
                break;
            }
        }
    }
