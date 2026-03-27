/* Source: ADCD 2.1
 * Section: iv-41-mytextlabelclass-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/iv-41-mytextlabelclass-c.md
 */

    struct localObjData *lod = INST_DATA(cl, o);
    STRPTR          label = (STRPTR) IM(o)->ImageData;
    struct DrawInfo *di = msg->imp_DrInfo;
    struct RastPort *rp = msg->imp_RPort;
    struct TextFont *tf = NULL;
    WORD            len = strlen(label);
    WORD            left, top;
    WORD            height = 0;
    WORD            width = 0;
    WORD            i;

    /* Clear the key */
    lod->lod_Key = NULL;

    /* Get a pointer to the font to use */
    if (!(tf = lod->lod_Font) && di)
    {
        tf = di->dri_Font;
    }

    /* Make sure we have font pointer */
    if (tf)
    {
        /* Set the font */
        SetFont(rp, tf);
    }
    /* Figure out our coordinates */
    top = msg->imp_Offset.Y + IM(o)->TopEdge + rp->TxBaseline;
    left = msg->imp_Offset.X + IM(o)->LeftEdge;

    /* See if we have frame information. */
    if (msg->MethodID == IM_DRAWFRAME)
    {
        /* Center the text inside the frame. */
        width = msg->imp_Dimensions.Width;
        height = msg->imp_Dimensions.Height;
        top += ((height - IM(o)->Height) > 0) ? ((height - IM(o)->Height) / 2) : 0;
        left += ((width - IM(o)->Width) > 0) ? ((width - IM(o)->Width) / 2) : 0;
    }

    /* Set the colors */
    SetAPen(rp, IM(o)->PlanePick);
    SetBPen(rp, IM(o)->PlaneOnOff);

    /* Set the drawing mode */
    SetDrMd(rp, lod->lod_Mode);

    /* Move to the start */
    Move(rp, left, top);



    /* Step through string */
    for (i = 0; i < (len - 1); i++)
    {
        /* Is this an '_' ? */
        if (label[i] == '_')
        {
            WORD            bot = (top + rp->TxHeight - rp->TxBaseline);
            WORD            mark;

            /* Draw the first part of the string */
            Text(rp, label, i);

            /* Remember where we are in the string */
            mark = rp->cp_x;

            /* Draw the underscore */
            Move(rp, mark, bot);
            Draw(rp, (mark + TextLength(rp, &label[(i + 1)], 1L) - 2), bot);

            /* Return to where we were */
            Move(rp, mark, top);

            /*
             * Draw the rest of the string.  This one is done last so that the cursor
             * could be positioned after the text.
             */
            Text(rp, &label[(i + 1)], (len - i - 1));

            /* Return the underlined character */
            lod->lod_Key = (UWORD) label[i];
        }
    }

    /* Do we have an underscore? */
    if (!lod->lod_Key)
    {
        /* Didn't find an '_' sign */
        Text(rp, label, len);
    }
    return (1L);
