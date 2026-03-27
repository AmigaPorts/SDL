/* Source: ADCD 2.1
 * Section: iv-41-mytextlabelclass-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/iv-41-mytextlabelclass-c.md
 */

    struct localObjData *lod = INST_DATA(cl, o);
    struct TextExtent te =
    {NULL};
    struct RastPort rp;
    STRPTR          label;

    /* maybe look at some flags to handle other types of text someday */
    if (label = (STRPTR) IM(o)->ImageData)
    {
        /* Initialize the RastPort */
        InitRastPort(&rp);

        if (lod->lod_Font)
        {
            SetFont(&rp, lod->lod_Font);
        }
        else if (drinfo && drinfo->dri_Font)
        {
            SetFont(&rp, drinfo->dri_Font);
        }
        /* Get the rectangle for the label */
        aTextExtent(&rp, label, strlen(label), &te);

        /* Set the image structure */
        IM(o)->Width = te.te_Width;
        IM(o)->Height = te.te_Height;
    }
    else
    {
        IM(o)->Width = IM(o)->Height = 0;
    }
