/* Source: ADCD 2.1
 * Section: im-draw
 * Library: amiga-mail
 * ADCD reference: amiga-mail/im-draw.md
 */

    UWORD *pens = (imp->imp_DrInfo) ? imp->imp_DrInfo->dri_Pens : NULL;

    if (pens)
    {
        SetAPen (imp->imp_RPort, pens[SHADOWPEN]);
    }
