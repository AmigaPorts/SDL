/* Source: ADCD 2.1
 * Section: 27-forming-a-basic-display-preparing-the-view-structure
 * Library: libraries
 * ADCD reference: libraries/27-forming-a-basic-display-preparing-the-view-structure.md
 */

    /* Form the ModeID from values in <displayinfo.h> */
    modeID=DEFAULT_MONITOR_ID | HIRESLACE_KEY;

    /* Make the ViewExtra structure */
    if( vextra=GfxNew(VIEW_EXTRA_TYPE) )
        {
        /* Attach the ViewExtra to the View */
        GfxAssociate(&view , vextra);
        view.Modes |= EXTEND_VSTRUCT;

        /* Initialize the MonitorSpec field of the ViewExtra */
        if( monspec=OpenMonitor(NULL,modeID) )
            vextra->Monitor=monspec;
        else
            fail("Could not get MonitorSpec\n");
        }
     else fail("Could not get ViewExtra\n");
