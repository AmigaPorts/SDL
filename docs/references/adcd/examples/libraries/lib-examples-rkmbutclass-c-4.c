/* Source: ADCD 2.1
 * Section: lib-examples-rkmbutclass-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-rkmbutclass-c.md
 */

    struct ButINST *inst;
    ULONG retval = FALSE;
    Object *object;

    /* SAS/C and Manx function to make sure register A4
       contains a pointer to global data */
    geta4();

    switch (msg->MethodID)
    {
        case OM_NEW:       /* First, pass up to superclass */
            if (object = (Object *)DoSuperMethodA(cl, o, msg))
            {
                struct Gadget *g = (struct Gadget *)object;

                            /* Initial local instance data */
                inst = INST_DATA(cl, object);
                inst->midX   = g->LeftEdge + ( (g->Width) / 2);
                inst->midY   = g->TopEdge + ( (g->Height) / 2);

                retval = (ULONG)object;
            }
            break;
        case GM_HITTEST:
                   /* Since this is a rectangular gadget this  */
                   /* method always returns GMR_GADGETHIT.     */
            retval = GMR_GADGETHIT;
            break;
        case GM_GOACTIVE:
            inst = INST_DATA(cl, o);

                    /* Only become active if the GM_GOACTIVE   */
                    /* was triggered by direct user input.     */
            if (((struct gpInput *)msg)->gpi_IEvent)
            {
                       /* This gadget is now active, change    */
                       /* visual state to selected and render. */
                ((struct Gadget *)o)->Flags |= GFLG_SELECTED;
                                RenderRKMBut(cl, (struct Gadget *)o, (struct gpRender *)msg);
                retval = GMR_MEACTIVE;
            }
            else            /* The GM_GOACTIVE was not         */
                            /* triggered by direct user input. */
                retval = GMR_NOREUSE;
            break;
        case GM_RENDER:
            retval = RenderRKMBut(cl, (struct Gadget *)o, (struct gpRender *)msg);
            break;
        case GM_HANDLEINPUT:   /* While it is active, this gadget sends its superclass an        */
                               /* OM_NOTIFY pulse for every IECLASS_TIMER event that goes by     */
                               /* (about one every 10th of a second).  Any object that is        */
                               /* connected to this gadget will get A LOT of OM_UPDATE messages. */
            {
                struct Gadget *g = (struct Gadget *)o;
                struct gpInput *gpi = (struct gpInput *)msg;
                struct InputEvent *ie = gpi->gpi_IEvent;

                inst = INST_DATA(cl, o);

                retval = GMR_MEACTIVE;

                if (ie->ie_Class == IECLASS_RAWMOUSE)
                {
                    switch (ie->ie_Code)
                    {
                        case SELECTUP: /* The user let go of the gadget so return GMR_NOREUSE    */
                                       /* to deactivate and to tell Intuition not to reuse       */
                                       /* this Input Event as we have already processed it.      */

                                       /*If the user let go of the gadget while the mouse was    */
                                       /*over it, mask GMR_VERIFY into the return value so       */
                                       /*Intuition will send a Release Verify (GADGETUP).        */
                            if ( ((gpi->gpi_Mouse).X < g->LeftEdge) ||
                                 ((gpi->gpi_Mouse).X > g->LeftEdge + g->Width) ||
                                 ((gpi->gpi_Mouse).Y < g->TopEdge) ||
                                 ((gpi->gpi_Mouse).Y > g->TopEdge + g->Height) )
                                retval = GMR_NOREUSE | GMR_VERIFY;
                            else
                                retval = GMR_NOREUSE;

                                           /* Since the gadget is going inactive, send a final   */
                                           /* notification to the ICA_TARGET.                    */
                            NotifyPulse(cl , o, 0L, inst->midX, (struct gp_Input *)msg);
                            break;
                        case MENUDOWN: /* The user hit the menu button. Go inactive and let      */
                                       /* Intuition reuse the menu button event so Intuition can */
                                       /* pop up the menu bar.                                   */
                            retval = GMR_REUSE;

                                           /* Since the gadget is going inactive, send a final   */
                                           /* notification to the ICA_TARGET.                    */
                            NotifyPulse(cl , o, 0L, inst->midX, (struct gp_Input *)msg);
                            break;
                        default:
                            retval = GMR_MEACTIVE;
                    }

                }
                else if (ie->ie_Class == IECLASS_TIMER)
                              /* If the gadget gets a timer event, it sends an interim OM_NOTIFY */
                    NotifyPulse(cl, o, OPUF_INTERIM, inst->midX, gpi); /*     to its superclass. */
            }
            break;

        case GM_GOINACTIVE:           /* Intuition said to go inactive.  Clear the GFLG_SELECTED */
                                      /* bit and render using unselected imagery.                */
            ((struct Gadget *)o)->Flags &= ~GFLG_SELECTED;
            RenderRKMBut(cl, (struct Gadget *)o, (struct gpRender *)msg);
            break;
        case OM_SET:/* Although this class doesn't have settable attributes, this gadget class   */
                    /* does have scaleable imagery, so it needs to find out when its size and/or */
                    /* position has changed so it can erase itself, THEN scale, and rerender.    */
            if ( FindTagItem(GA_Width,  ((struct opSet *)msg)->ops_AttrList) ||
                 FindTagItem(GA_Height, ((struct opSet *)msg)->ops_AttrList) ||
                 FindTagItem(GA_Top,    ((struct opSet *)msg)->ops_AttrList) ||
                 FindTagItem(GA_Left,   ((struct opSet *)msg)->ops_AttrList) )
            {
                struct RastPort *rp;
                struct Gadget *g = (struct Gadget *)o;

                WORD x,y,w,h;

                x = g->LeftEdge;
                y = g->TopEdge;
                w = g->Width;
                h = g->Height;

                inst = INST_DATA(cl, o);

                retval = DoSuperMethodA(cl, o, msg);

                                                          /* Get pointer to RastPort for gadget. */
                if (rp = ObtainGIRPort( ((struct opSet *)msg)->ops_GInfo) )
                {
