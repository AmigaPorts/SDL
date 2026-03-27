/* Source: ADCD 2.1
 * Section: lib-examples-rgbboxes-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-rgbboxes-c.md
 */

    {
    /* Form the ModeID from values in <displayinfo.h> */
    modeID=DEFAULT_MONITOR_ID | HIRESLACE_KEY;

    /*  Make the ViewExtra structure   */
    if( vextra=GfxNew(VIEW_EXTRA_TYPE) )
        {
        /* Attach the ViewExtra to the View */
        GfxAssociate(&view , vextra);
        view.Modes |= EXTEND_VSTRUCT;

        /* Create and attach a MonitorSpec to the ViewExtra */
        if( monspec=OpenMonitor(NULL,modeID) )
            vextra->Monitor=monspec;
        else
            fail("Could not get MonitorSpec\n");
        }
     else fail("Could not get ViewExtra\n");
     }
