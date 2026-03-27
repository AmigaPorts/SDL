/* Source: ADCD 2.1
 * Section: iv-41-mytextlabelclass-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/iv-41-mytextlabelclass-c.md
 */

    struct localObjData *lod = INST_DATA(cl, o);

    switch (msg->opg_AttrID)
    {
    case IA_Font:
        *msg->opg_Storage = (ULONG) lod->lod_Font;
        break;

    case IA_Mode:
        *msg->opg_Storage = (ULONG) lod->lod_Mode;
        break;

        /* Let the superclass try */
    default:
        return ((ULONG) DSM(cl, o, msg));
    }

    return (1L);
