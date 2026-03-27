/* Source: ADCD 2.1
 * Section: iv-41-mytextlabelclass-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/iv-41-mytextlabelclass-c.md
 */

    struct localObjData *lod = INST_DATA(cl, o);
    struct TagItem *tags = msg->ops_AttrList;
    struct TagItem *tstate;
    struct TagItem *tag;
    ULONG           tidata;

    /* process rest */
    tstate = tags;
    while (tag = NextTagItem(&tstate))
    {
        tidata = tag->ti_Data;
        switch (tag->ti_Tag)
        {
        case IA_FGPen:
            IM(o)->PlanePick = (UBYTE) tidata;
            break;

        case IA_BGPen:
            IM(o)->PlaneOnOff = (UBYTE) tidata;
            break;

            /* Must be a TextFont pointer. */
        case IA_Font:
            /* Set the font */
            lod->lod_Font = (struct TextFont *) tidata;
            break;

            /* Drawing mode to use */
        case IA_Mode:
            lod->lod_Mode = (UBYTE) tidata;
            break;

        case IA_Data:
            IM(o)->ImageData = (USHORT *) tidata;
            lod->lod_Key = GetLabelKeystroke((STRPTR) tidata);
            break;
        }
    }

    return (1L);
