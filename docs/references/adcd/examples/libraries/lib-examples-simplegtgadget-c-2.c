/* Source: ADCD 2.1
 * Section: lib-examples-simplegtgadget-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-simplegtgadget-c.md
 */

    {
    if ( (vi = GetVisualInfo(mysc, TAG_END)) != NULL )
        {
        /* GadTools gadgets require this step to be taken */
        gad = CreateContext(&glist);

        /* create a button gadget centered below the window title */
        ng.ng_TextAttr   = &Topaz80;
        ng.ng_VisualInfo = vi;
        ng.ng_LeftEdge   = 150;
        ng.ng_TopEdge    = 20 + mysc->WBorTop + (mysc->Font->ta_YSize + 1);
        ng.ng_Width      = 100;
        ng.ng_Height     = 12;
        ng.ng_GadgetText = "Click Here";
        ng.ng_GadgetID   = MYGAD_BUTTON;
        ng.ng_Flags      = 0;
        gad = CreateGadget(BUTTON_KIND, gad, &ng, TAG_END);

        if (gad != NULL)
            {
            if ( (mywin = OpenWindowTags(NULL,
                    WA_Title,     "GadTools Gadget Demo",
                    WA_Gadgets,   glist,      WA_AutoAdjust,    TRUE,
                    WA_Width,       400,      WA_InnerHeight,    100,
                    WA_DragBar,    TRUE,      WA_DepthGadget,   TRUE,
                    WA_Activate,   TRUE,      WA_CloseGadget,   TRUE,
                    WA_IDCMP, IDCMP_CLOSEWINDOW |
                              IDCMP_REFRESHWINDOW | BUTTONIDCMP,
                    WA_PubScreen,   mysc,
                    TAG_END)) != NULL )
                {
                GT_RefreshWindow(mywin, NULL);

                process_window_events(mywin);

                CloseWindow(mywin);
                }
            }
        /* FreeGadgets() must be called after the context has been
        ** created.  It does nothing if glist is NULL
        */
        FreeGadgets(glist);
        FreeVisualInfo(vi);
        }
    UnlockPubScreen(NULL, mysc);
    }
