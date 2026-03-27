/* Source: ADCD 2.1
 * Section: gadtools-library-createcontext
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/gadtools-library-createcontext.md
 */

    struct [Gadget](../Includes_and_Autodocs_2._guide/node00D4.html#line215) *gad;
    struct [Gadget](../Includes_and_Autodocs_2._guide/node00D4.html#line215) *glist = NULL;
    gad = CreateContext(&glist);
    /*  Other creation calls go here */
    if (gad)
    {
        myNewWindow.FirstGadget = glist;
        if ( myWindow = OpenWindow(&myNewWindow) )
        {
            GT_RefreshWindow(win);
            /* other stuff */
            CloseWindow(myWindow);
        }
    }
    FreeGadgets(glist);
