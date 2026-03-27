/* Source: ADCD 2.1
 * Section: 27-ecs-and-genlocking-features-genlock-control
 * Library: libraries
 * ADCD reference: libraries/27-ecs-and-genlocking-features-genlock-control.md
 */

    /* The complete example opened a window, rendered some colorbars,  */
    /* and added gadgets to allow the user to turn the various genlock */
    /* modes on and off.                                               */

    vp = &(genscreen->ViewPort);

    /* Ascertain the current state of the various modes. */

    /* Is borderblanking on? */
    vtags[0].ti_Tag = VTAG_BORDERBLANK_GET;
    vtags[0].ti_Data = NULL;

    /* Is bordertransparent set? */
    vtags[1].ti_Tag = VTAG_BORDERNOTRANS_GET;
    vtags[1].ti_Data = NULL;

    /* Key on bitplane? */
    vtags[2].ti_Tag = VTAG_BITPLANEKEY_GET;
    vtags[2].ti_Tag = NULL;

    /* Get plane which is used to key on */
    vtags[3].ti_Tag = VTAG_CHROMA_PLANE_GET;
    vtags[3].ti_Data = NULL;

    /* Chromakey overlay on? */
    vtags[4].ti_Tag = VTAG_CHROMAKEY_GET;
    vtags[4].ti_Data = NULL;

    for (i = 0; i < 16; i++)
    {
        /* Find out which colors overlay */
        vtags[i + 5].ti_Tag = VTAG_CHROMA_PEN_GET;
        vtags[i + 5].ti_Data = i;
    }

    /* Indicate end of tag array */
    vtags[21].ti_Tag = VTAG_END_CM;
    vtags[21].ti_Data = NULL;

    /* And send the commands. On return the Tags themselves will
    * indicate the genlock settings for this ViewPort's ColorMap.
    */
    error = VideoControl(vp->ColorMap, vtags);

    /* The complete program sets gadgets to reflect current states. */

    /* Will only send single commands from here on. */
    vtags[1].ti_Tag = VTAG_END_CM;

    /* At this point the complete program gets an input event and
       sets/clears the genlock modes as requested using the vtag list and
       VideoControl().
    */

    /* send video command */
    error = VideoControl(vp->ColorMap, vtags);

    /* Now use MakeScreen() and RethinkDisplay() to make the VideoControl()
    *  changes take effect.  If we were using our own ViewPort rather than
    *  borrowing one from a screen, we would instead do:
    *
    *   MakeVPort(ViewAddress(),vp);
    *   MrgCop(ViewAddress());
    *   LoadView(ViewAddres());
    */
    MakeScreen(genscreen);
    RethinkDisplay();
