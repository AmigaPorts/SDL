/* Source: ADCD 2.1
 * Section: iv-23-boopsi1-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/iv-23-boopsi1-c.md
 */

    struct IntuiMessage *imsg;
    BOOL returnvalue = TRUE;
    ULONG class;
    LONG currval = INITVALUE;
    struct Gadget *g;


    while (returnvalue)
    {
        WaitPort(window->UserPort);
        while (imsg = (struct IntuiMessage *)GetMsg(window->UserPort))
        {
            g = (struct Gadget *)imsg->IAddress;
            class = imsg->Class;
            ReplyMsg((struct Message *)imsg);
            switch (class)
            {
                case IDCMP_CLOSEWINDOW:
                    returnvalue = FALSE;
                    break;
                case IDCMP_GADGETUP:
                    switch (g->GadgetID)
                    {
                        case MYLEFTBUT:
                            currval--;
                            break;
                        case MYRIGHTBUT:
                            currval++;
                            break;
                        case MYPROP:
                            /* read the prop gadget's value */
                            GetAttr(PGA_TOP, prop, &currval);
                            break;
                        case MYSTRING:
                            /* read the string gadget's value */
                            GetAttr(STRINGA_LongVal, string, &currval);
                            break;
                    }
                    /* make sure the value is between 0 and 90 */
                    if (currval < 0L)
                        currval = 0L;
                    else
                        if (currval > PROPWIDTH - PROPVIS)
                            currval = PROPWIDTH - PROPVIS;

                    /* Update the values of the prop and string.
                    ** gadgets (Intuition takes care of the  refresh). */

                    SetGadgetAttrs( prop, window, NULL,
                                    PGA_TOP, currval,
                                TAG_END );

                    SetGadgetAttrs( string, window, NULL,
                                STRINGA_LongVal, currval,
                                    TAG_END );

                    break;
            }
        }
    }
