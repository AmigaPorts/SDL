/* Source: ADCD 2.1
 * Section: 15-getvisualinfo-and-freevisualinfo
 * Library: libraries
 * ADCD reference: libraries/15-getvisualinfo-and-freevisualinfo.md
 */

    init()
    {
    myscreen = LockPubScreen(NULL);
    if (!myscreen)
        {
        cleanup("Failed to lock default public screen");
        }
    vi = GetVisualInfo(myscreen);
    if (!vi)
        {
        cleanup("Failed to GetVisualInfo");
        }
    /* Create gadgets here */
    ng.ng_VisualInfo = vi;
    ...
    }

    void cleanup(STRPTR errorstr)
    {
    /* These functions may be safely called with a NULL parameter: */
    FreeGadgets(glist);
    FreeVisualInfo(vi);

    if (myscreen)
        UnlockPubScreen(NULL, myscreen);

    printf(errorstr);
    }
