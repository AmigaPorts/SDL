/* Source: ADCD 2.1
 * Section: devices-apps-ilbmdemo-ilbmdemo-c
 * Library: devices
 * ADCD reference: devices/devices-apps-ilbmdemo-ilbmdemo-c.md
 */

    /* These were set up by our successful showilbm() above */
    win = ilbms[SCR]->win;	/* our window */
    wrp = ilbms[SCR]->wrp;	/* our window's RastPort */
    scr = ilbms[SCR]->scr;	/* our screen */
    vp  = ilbms[SCR]->vp;		/* our screen's ViewPort */

    ScreenToFront(scr);
