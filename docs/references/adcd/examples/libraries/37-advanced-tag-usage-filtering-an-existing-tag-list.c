/* Source: ADCD 2.1
 * Section: 37-advanced-tag-usage-filtering-an-existing-tag-list
 * Library: libraries
 * ADCD reference: libraries/37-advanced-tag-usage-filtering-an-existing-tag-list.md
 */

    /* We want the text entry gadget to receive the following tags */
    Tag string_attrs[] =
    {
        STRINGA_MaxChars,
        STRINGA_Buffer,
        STRINGA_TextVal,
        TAG_END,
    };

    /* These are attributes that the model understands */
    Tag model_attrs[] =
    {
        CGTA_Total,
        CGTA_Visible,
        CGTA_Top,
        ICA_TARGET,
        ICA_MAP,
        TAG_END,
    };

    struct TagItem *otags;      /* Original tag list */
    struct TagItem *ntags;      /* New, work, tag list */

    /* Make a copy of the original for us to work with */
    ntags = CloneTagItems (otags);

    /* Create a tag list that only contains attributes that are
     * listed in the model_attrs list. */
    if (FilterTagItems (ntags, model_attrs, TAGFILTER_AND))
    {
        /* Work with filtered tag list (ntags) */

        /* Restore the tag list */
        RefreshTagItemClones (ntags, otags);

        /* Create a tag list that only contains attributes that
         * aren't in the model_attrs list. */
        if (FilterTagItems (ntags, model_attrs, TAGFILTER_NOT))
        {
            /* Work with filtered tag list (ntags) */
        }

        /* Restore the tag list */
        RefreshTagItemClones (ntags, otags);

        /* Create a tag list that only contains attributes that
         * are in the string_attrs list. */
        if (FilterTagItems (ntags, string_attrs, TAGFILTER_AND))
        {
            /* Work with filtered tag list (ntags) */
        }
    }

    /* Free work tag list. */
    FreeTagItems (ntags);
