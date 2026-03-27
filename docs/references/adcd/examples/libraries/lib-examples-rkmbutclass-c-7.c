/* Source: ADCD 2.1
 * Section: lib-examples-rkmbutclass-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-rkmbutclass-c.md
 */

    struct ButINST *inst = INST_DATA(cl, (Object *)g);
    struct RastPort *rp;
    ULONG retval = TRUE;
    UWORD *pens = msg->gpr_GInfo->gi_DrInfo->dri_Pens;

    if (msg->MethodID == GM_RENDER)   /* If msg is truly a GM_RENDER message (not a gpInput that */
                                      /* looks like a gpRender), use the rastport within it...   */
        rp = msg->gpr_RPort;
    else                              /* ...Otherwise, get a rastport using ObtainGIRPort().     */
        rp = ObtainGIRPort(msg->gpr_GInfo);

    if (rp)
    {
        UWORD back, shine, shadow, w, h, x, y;

        if (g->Flags & GFLG_SELECTED) /* If the gadget is selected, reverse the meanings of the  */
        {                             /* pens.                                                   */
            back   = pens[FILLPEN];
            shine  = pens[SHADOWPEN];
            shadow = pens[SHINEPEN];
        }
        else
        {
            back   = pens[BACKGROUNDPEN];
            shine  = pens[SHINEPEN];
            shadow = pens[SHADOWPEN];
        }
        SetDrMd(rp, JAM1);

        SetAPen(rp, back);          /* Erase the old gadget.       */
        RectFill(rp, g->LeftEdge,
                     g->TopEdge,
                     g->LeftEdge + g->Width,
                     g->TopEdge + g->Height);

        SetAPen(rp, shadow);     /* Draw shadow edge.            */
        Move(rp, g->LeftEdge + 1, g->TopEdge + g->Height);
        Draw(rp, g->LeftEdge + g->Width, g->TopEdge + g->Height);
        Draw(rp, g->LeftEdge + g->Width, g->TopEdge + 1);

        w = g->Width / 4;       /* Draw Arrows - Sorry, no frills imagery */
        h = g->Height / 2;
        x = g->LeftEdge + (w/2);
        y = g->TopEdge + (h/2);

        Move(rp, x, inst->midY);
        Draw(rp, x + w, y);
        Draw(rp, x + w, y + (g->Height) - h);
        Draw(rp, x, inst->midY);

        x = g->LeftEdge + (w/2) + g->Width / 2;

        Move(rp, x + w, inst->midY);
        Draw(rp, x, y);
        Draw(rp, x, y  + (g->Height) - h);
        Draw(rp, x + w, inst->midY);

        SetAPen(rp, shine);    /* Draw shine edge.           */
        Move(rp, g->LeftEdge, g->TopEdge + g->Height - 1);
        Draw(rp, g->LeftEdge, g->TopEdge);
        Draw(rp, g->LeftEdge + g->Width - 1, g->TopEdge);

        if (msg->MethodID != GM_RENDER) /* If we allocated a rastport, give it back.             */
            ReleaseGIRPort(rp);
    }
    else retval = FALSE;
    return(retval);
