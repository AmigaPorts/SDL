/* Source: ADCD 2.1
 * Section: lib-examples-rkmmodel-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-rkmmodel-c.md
 */

    struct TagItem tt[2];

    tt[0].ti_Tag = RKMMOD_CurrVal; /* make a tag list.  */
    tt[0].ti_Data = mmd->currval;
    tt[1].ti_Tag = TAG_DONE;
                                /* If the RKMMOD_CurrVal changes, we want everyone to know about */
    DoSuperMethod(cl, o,        /* it. Theoretically, the class is supposed to send itself a     */
             OM_NOTIFY,         /* OM_NOTIFY message. Because this class lets its superclass     */
             tt,                /* handle the OM_NOTIFY message, it skips the middleman and      */
             msg->opu_GInfo,    /* sends the OM_NOTIFY directly to its superclass.               */

             ((msg->MethodID == OM_UPDATE) ? (msg->opu_Flags) : 0L)); /* If this is an OM_UPDATE */
                                /* method, make sure the part the OM_UPDATE message adds to the  */
                                /* OM_SET message gets added.  That lets the dispatcher handle   */
