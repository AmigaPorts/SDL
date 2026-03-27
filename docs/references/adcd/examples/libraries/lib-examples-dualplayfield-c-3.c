/* Source: ADCD 2.1
 * Section: lib-examples-dualplayfield-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-dualplayfield-c.md
 */

    {
    /* you can only play with the bits in the Modes field
    ** if the upper half of the screen mode ID is zero!!!
    */
    if ( (screen_modeID & 0xFFFF0000L) == 0L )
        {
        return_code = TRUE;

        Forbid();

        /* Install rinfo for viewport's second playfield */
        scrn->ViewPort.RasInfo->Next = rinfo2;
        scrn->ViewPort.Modes |= DUALPF;

        Permit();

        /* Put viewport change into effect */
        MakeScreen(scrn);
        RethinkDisplay();
        }
    }
