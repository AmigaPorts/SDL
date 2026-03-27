/* Source: ADCD 2.1
 * Section: lib-examples-updatestrgad-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-updatestrgad-c.md
 */

        if((class == IDCMP_GADGETUP)||(class == IDCMP_GADGETDOWN))
                gadget = (struct Gadget *)msg->IAddress;
        ReplyMsg((struct Message *)msg);

        switch (class)
            {
            case IDCMP_ACTIVEWINDOW:
                /* activate the string gadget.  This is how to activate a
                ** string gadget in a new window--wait for the window to
                ** become active by waiting for the IDCMP_ACTIVEWINDOW
                ** event, then activate the gadget.  Here we report on
                ** the success or failure.
                */
                if(ActivateGadget(gad,win,NULL))
                    updateStrGad(win,gad,activated_txt);
                break;
            case IDCMP_CLOSEWINDOW:
                /* here is the way out of the loop and the routine.
                ** be sure that the message was replied...
                */
                return;
                break;
            case IDCMP_GADGETUP:
                /* If user hit RETURN in our string gadget for demonstration,
                ** we will change what he entered.  We only have 1 gadget,
                ** so we don't have to check which gadget.
                */
                updateStrGad(win, &strGad, answers[ansnum]);
