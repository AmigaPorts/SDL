/* Source: ADCD 2.1
 * Section: vii-17-camg-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/vii-17-camg-c.md
 */

    /*
     * Now see if mode is available
     */
    if (GfxBase->lib_Version >= 36)
    {
        /* if mode is not available, try a fallback mode */
        if (ModeNotAvailable(modeid))
            modeid = modefallback(modeid, wide, high, deep);


        if (!(ModeNotAvailable(modeid)))         /* if mode is available */
        {
            /*
             * We have an available mode id Here you may wish to create a
             * custom, or centered, or overscan display clip based on the size
             * of the image.  Or just use one of the standard clips.
             *
             * The 2.0 Display program uses QueryOverscan to get the settings of
             * this modeid's OSCAN_TEXT, OSCAN_STANDARD, and OSCAN_MAX. Display
             * centers the screen (via TopEdge and LeftEdge) within the user's
             * closest OSCAN rectangle, and creates a display clip by using the
             * same values and then clipping the values to be within OSCAN_MAX
             * limits.  If the centered screen ends up lower than user's
             * OSCAN_TEXT settings, I move it up to same MinY as his OSCAN_TEXT
             * --- otherwise his Workbench might peek over the top.
             */

            /*
             * Now use extended OpenScreen or OpenScreenTags for this modeid.
             * (this gives you the benefit of system-supported overscan, etc.)
             */
