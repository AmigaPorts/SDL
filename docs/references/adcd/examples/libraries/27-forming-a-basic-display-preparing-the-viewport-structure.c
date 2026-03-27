/* Source: ADCD 2.1
 * Section: 27-forming-a-basic-display-preparing-the-viewport-structure
 * Library: libraries
 * ADCD reference: libraries/27-forming-a-basic-display-preparing-the-viewport-structure.md
 */

    InitVPort(&viewPort);        /* Initialize the ViewPort.             */
    viewPort.RasInfo = &rasInfo; /* The rasInfo must also be initialized */
    viewPort.DWidth  = WIDTH;
    viewPort.DHeight = HEIGHT;

    /* Under 1.3, you should set viewPort.Modes here to select a display
     * mode. Under Release 2, use VideoControl() with VTAG_NORMAL_DISP_SET
     * to select a display mode by attaching a DisplayInfo structure to
     *  the ViewPort.                                                    */
