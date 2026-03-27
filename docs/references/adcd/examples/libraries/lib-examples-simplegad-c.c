/* Source: ADCD 2.1
 * Section: lib-examples-simplegad-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-simplegad-c.md
 */

    {
    if (win = OpenWindowTags(NULL,
                            WA_Width, 400,
                            WA_Height, 100,
                            WA_Gadgets, &buttonGad,
                            WA_Activate, TRUE,
                            WA_CloseGadget, TRUE,
                            WA_IDCMP, IDCMP_GADGETDOWN | IDCMP_GADGETUP |
                                      IDCMP_CLOSEWINDOW,
                            TAG_END))
        {
        done = FALSE;
        while (done == FALSE)
            {
            Wait(1L << win->UserPort->mp_SigBit);
            while ( (done == FALSE) &&
                    (msg = (struct IntuiMessage *)GetMsg(win->UserPort)))
                {
                /* Stash message contents and reply, important when message
                ** triggers some lengthy processing
                */
                class = msg->Class;

                /* gadget address is ONLY valid for gadget messages! */
                if ((class == IDCMP_GADGETUP) || (class == IDCMP_GADGETDOWN))
                    gad = (struct Gadget *)(msg->IAddress);

                ReplyMsg((struct Message *)msg);

                /* switch on the type of the event */
                switch (class)
                    {
                    case IDCMP_GADGETUP:
                        /* caused by GACT_RELVERIFY */
                        printf("received an IDCMP_GADGETUP, gadget number %d\n",
                               gad->GadgetID);
                        break;
                    case IDCMP_GADGETDOWN:
                        /* caused by GACT_IMMEDIATE */
                        printf("received an IDCMP_GADGETDOWN, gadget number %d\n",
                               gad->GadgetID);
                        break;
                    case IDCMP_CLOSEWINDOW:
                        /* set a flag that we are done processing events... */
                        printf("received an IDCMP_CLOSEWINDOW\n");
                        done = TRUE;
                        break;
                    }
                }
            }
        CloseWindow(win);
        }
    CloseLibrary(IntuitionBase);
    }
