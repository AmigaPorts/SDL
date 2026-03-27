/* Source: ADCD 2.1
 * Section: iv-77-optimrefresh-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/iv-77-optimrefresh-c.md
 */

    crp       = *rp;            /* copy the rastport                      */
    crp.Layer = NULL;           /* eliminate bogus clipping from our copy */

    if (taskBusy)
    {
        SetWrMsk(&crp,0xff);    /* if the main task is busy, clear all planes */
    }
    else
    {
        SetWrMsk(&crp,0xfe);    /* otherwise, clear all planes except plane 0 */
    }

    SetAPen(&crp,0);                     /* set the pen to color 0         */
    SetDrMd(&crp,JAM2);                  /* set the rendering mode we need */
    RectFill(&crp,bfm->bf_Bounds.MinX,   /* clear the whole area           */
                  bfm->bf_Bounds.MinY,
                  bfm->bf_Bounds.MaxX,
                  bfm->bf_Bounds.MaxY);
