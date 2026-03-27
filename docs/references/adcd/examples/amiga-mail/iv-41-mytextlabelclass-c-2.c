/* Source: ADCD 2.1
 * Section: iv-41-mytextlabelclass-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/iv-41-mytextlabelclass-c.md
 */

    struct localObjData *lod;
    Object         *newobj;
    ULONG           retval;

    switch (msg->MethodID)
    {
    case OM_NEW:
        /* Pass up to the superclass... */
        if (newobj = (Object *) DSM(cl, o, msg))
        {
            struct TagItem *attrs = ((struct opSet *) msg)->ops_AttrList;
            struct DrawInfo *drinfo;

            /* Get the DrawInfo */
            drinfo = (struct DrawInfo *) GetTagData(SYSIA_DrawInfo, NULL, attrs);

            /* Get the instance data */
            lod = INST_DATA(cl, newobj);

            /* Establish defaults */
            IM(newobj)->PlanePick = 1;
            lod->lod_Mode = JAM1;

            /* Set the attributes */
            setmyTextLabelAttrs(cl, newobj, (struct opSet *) msg);

            /* Get the bounding rectangle of the label */
            getContentsExtent(cl, newobj, drinfo);
        }
        retval = (ULONG) newobj;
        break;

    case OM_GET:
        retval = getmyTextLabelAttr(cl, o, (struct opGet *) msg);
        break;

    case OM_UPDATE:
    case OM_SET:
        /* Do the superclass first */
        retval = DSM(cl, o, msg);

        /* Call our set routines */
        retval += setmyTextLabelAttrs(cl, o, (struct opSet *) msg);
        break;

    case IM_DRAW:               /* draw the label */
    case IM_DRAWFRAME:          /* drawmyTextLabel() will take care of
                                   extra framing info */
        retval = drawmyTextLabel(cl, o, (struct impDraw *) msg);
        break;

    /* Let the superclass handle everything else */
    default:
        retval = (ULONG) DSM(cl, o, msg);
        break;
    }

    return (retval);
