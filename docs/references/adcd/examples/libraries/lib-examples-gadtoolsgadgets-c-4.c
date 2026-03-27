/* Source: ADCD 2.1
 * Section: lib-examples-gadtoolsgadgets-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-gadtoolsgadgets-c.md
 */

    {
    if (NULL == (mysc = LockPubScreen(NULL)))
        errorMessage( "Couldn't lock default public screen");
    else
        {
        if (NULL == (vi = GetVisualInfo(mysc, TAG_END)))
            errorMessage( "GetVisualInfo() failed");
        else
            {
            /* Here is how we can figure out ahead of time how tall the  */
            /* window's title bar will be:                               */
            topborder = mysc->WBorTop + (mysc->Font->ta_YSize + 1);

            if (NULL == createAllGadgets(&glist, vi, topborder,
                                         slider_level, my_gads))
                errorMessage( "createAllGadgets() failed");
            else
                {
                if (NULL == (mywin = OpenWindowTags(NULL,
                        WA_Title,     "GadTools Gadget Demo",
                        WA_Gadgets,   glist,      WA_AutoAdjust,    TRUE,
                        WA_Width,       400,      WA_MinWidth,        50,
                        WA_InnerHeight, 140,      WA_MinHeight,       50,
                        WA_DragBar,    TRUE,      WA_DepthGadget,   TRUE,
                        WA_Activate,   TRUE,      WA_CloseGadget,   TRUE,
                        WA_SizeGadget, TRUE,      WA_SimpleRefresh, TRUE,
                        WA_IDCMP, IDCMP_CLOSEWINDOW | IDCMP_REFRESHWINDOW |
                            IDCMP_VANILLAKEY | SLIDERIDCMP | STRINGIDCMP |
                            BUTTONIDCMP,
                        WA_PubScreen, mysc,
                        TAG_END)))
                    errorMessage( "OpenWindow() failed");
                else
                    {
                    /* After window is open, gadgets must be refreshed with a
                    ** call to the GadTools refresh window function.
                    */
                    GT_RefreshWindow(mywin, NULL);

                    process_window_events(mywin, &slider_level, my_gads);

                    CloseWindow(mywin);
                    }
                }
            /* FreeGadgets() even if createAllGadgets() fails, as some
            ** of the gadgets may have been created...If glist is NULL
            ** then FreeGadgets() will do nothing.
            */
            FreeGadgets(glist);
            FreeVisualInfo(vi);
            }
        UnlockPubScreen(NULL, mysc);
        }
    CloseFont(font);
    }
