/* Source: ADCD 2.1
 * Section: 37-advanced-tag-usage-sequential-access-of-tag-lists
 * Library: libraries
 * ADCD reference: libraries/37-advanced-tag-usage-sequential-access-of-tag-lists.md
 */

    struct TagItem *tags = msg->ops_AttrList;
    struct TagItem *tstate;
    struct TagItem *tag;
    ULONG tidata;

    /* Start at the beginning */
    tstate = tags;

    /* Step through the tag list while there are still items in the
     * list */
    while (tag = NextTagItem (&tstate))
    {
        /* Cache the data for the current element */
        tidata = tag->ti_Data;

        /* Handle each attribute that we understand */
        switch (tag->ti_Tag)
        {
            /* Put a case statement here for each attribute that your
             * function understands */
            case PGA_Freedom:
                lod->lod_Flags |= tidata;
                break;

            case GTLV_Labels:
                lod->lod_List = (struct List *) tidata;
                break;

            /* We don't understand this attribute */
            default:
                break;
        }
    }
