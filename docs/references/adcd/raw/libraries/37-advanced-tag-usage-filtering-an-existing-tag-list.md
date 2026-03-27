# 37 / / Advanced Tag Usage / Filtering an Existing Tag List


Sometimes it is necessary to only allow certain attributes to be visible
in a tag list.  In order to achieve this, the tag array would need to be
filtered.

A number of functions are provided for filtering items in a tag array.
They are [FilterTagChanges()](../Includes_and_Autodocs_2._guide/node03D4.html), [FilterTagItems()](../Includes_and_Autodocs_2._guide/node03D5.html) and [RefreshTagItemClones()](../Includes_and_Autodocs_2._guide/node03DC.html).



```c
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
```
