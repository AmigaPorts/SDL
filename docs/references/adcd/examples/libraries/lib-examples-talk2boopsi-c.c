/* Source: ADCD 2.1
 * Section: lib-examples-talk2boopsi-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-talk2boopsi-c.md
 */

    BOOL done = FALSE;

    if (IntuitionBase = OpenLibrary("intuition.library", 37L))
    {                                /* Open the window--notice that the window's IDCMP port     */
                                     /* does not listen for GADGETUP messages.                   */
        if (w = OpenWindowTags(NULL,
                 WA_Flags,       WFLG_DEPTHGADGET | WFLG_DRAGBAR |
                                     WFLG_CLOSEGADGET | WFLG_SIZEGADGET,
                 WA_IDCMP,       IDCMP_CLOSEWINDOW,
                 WA_MinWidth,    MINWINDOWWIDTH,
                 WA_MinHeight,   MINWINDOWHEIGHT,
                 TAG_END))
        {                                 /* Create a new propgclass object */
            if (prop = (struct Gadget *)NewObject(NULL, "propgclass",
                GA_ID,     PROPGADGET_ID,        /* These are defined by gadgetclass and         */
                GA_Top,    (w->BorderTop) + 5L,  /* correspond to similarly named fields in      */
                GA_Left,   (w->BorderLeft) + 5L, /* the Gadget structure.                        */
                GA_Width,  PROPGADGETWIDTH,
                GA_Height, PROPGADGETHEIGHT,

                ICA_MAP,      prop2intmap, /* The prop gadget's attribute map */

             /* The rest of this gadget's attributes are defined by propgclass. */
                PGA_Total,     TOTAL,          /* This is the integer range of the prop gadget.  */
                PGA_Top,       INITIALVAL,     /* The initial integer value of the prop gadget.  */

                PGA_Visible,   VISIBLE, /* This determines how much of the prop gadget area is   */
                                        /* covered by the prop gadget's knob, or how much of     */
                                        /* the gadget's TOTAL range is taken up by the prop      */
                                        /* gadget's knob.                                        */

                PGA_NewLook,   TRUE,    /* Use new-look prop gadget imagery */
                TAG_END))
            {                           /* create the integer string gadget.                     */
                if (integer = (struct Gadget *)NewObject(NULL, "strgclass",
                    GA_ID,      INTGADGET_ID,         /* Parameters for the Gadget structure     */
                    GA_Top,     (w->BorderTop) + 5L,
                    GA_Left,    (w->BorderLeft) + PROPGADGETWIDTH + 10L,
                    GA_Width,   MINWINDOWWIDTH -
                                  (w->BorderLeft + w->BorderRight +
                                  PROPGADGETWIDTH + 15L),
                    GA_Height,  INTGADGETHEIGHT,

                    ICA_MAP,    int2propmap,           /* The attribute map */
                    ICA_TARGET, prop,                  /* plus the target.  */

                            /* Th GA_Previous attribute is defined by gadgetclass and is used to */
                            /* wedge a new gadget into a list of gadget's linked by their        */
                            /* Gadget.NextGadget field.  When NewObject() creates this gadget,   */
                            /* it inserts the new gadget into this list behind the GA_Previous   */
                            /* gadget. This attribute is a pointer to the previous gadget        */
                            /* (struct Gadget *).  This attribute cannot be used to link new     */
                            /* gadgetsinto the gadget list of an open window or requester,       */
                    GA_Previous, prop,  /* use AddGList() instead.                               */

                    STRINGA_LongVal,  INITIALVAL, /* These attributes are defined by strgclass.  */
                    STRINGA_MaxChars, MAXCHARS,   /* The first contains the value of the         */
                    TAG_END))                     /* integer string gadget. The second is the    */
                                                  /* maximum number of characters the user is    */
                                                  /* allowed to type into the gadget.            */
                 {
                    SetGadgetAttrs(prop, w, NULL, /* Because the integer string gadget did not   */
                        ICA_TARGET, integer,      /* exist when this example created the prop    */
                        TAG_END);                 /* gadget, it had to wait to set the           */
                                                  /* ICA_Target of the prop gadget.              */

                    AddGList(w, prop, -1, -1, NULL);  /* Add the gadgets to the                  */
                    RefreshGList(prop, w, NULL, -1);  /* window and display them.                */

                    while (done == FALSE)     /* Wait for the user to click */
                    {                         /* the window close gadget.   */
                        WaitPort((struct MsgPort *)w->UserPort);
                        while (msg = (struct IntuiMessage *)
                           GetMsg((struct MsgPort *)w->UserPort))
                        {
                            if (msg->Class == IDCMP_CLOSEWINDOW)
                                done = TRUE;
                            ReplyMsg(msg);
                        }
                    }
                    RemoveGList(w, prop, -1);
                    DisposeObject(integer);
                 }
                DisposeObject(prop);
            }
            CloseWindow(w);
        }
        CloseLibrary(IntuitionBase);
    }
