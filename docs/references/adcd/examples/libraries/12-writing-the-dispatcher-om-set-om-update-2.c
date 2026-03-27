/* Source: ADCD 2.1
 * Section: 12-writing-the-dispatcher-om-set-om-update
 * Library: libraries
 * ADCD reference: libraries/12-writing-the-dispatcher-om-set-om-update.md
 */

     . . .

    struct TagItem tt[2];
    struct opUpdate *msg;
     . . .

    tt[0].ti_Tag  = RKMMOD_CurrVal;  /* make a tag list.  */
    tt[0].ti_Data = mmd->currval;
    tt[1].ti_Tag  = TAG_END;

    DoSuperMethod(cl, o, OM_NOTIFY, tt, msg->opu__GInfo,
                  ((msg->MethodID == OM_UPDATE) ? (msg->opu_Flags) : 0L));
     . . .
