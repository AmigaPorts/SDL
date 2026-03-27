/* Source: ADCD 2.1
 * Section: 37-advanced-tag-usage-copying-an-existing-tag-list
 * Library: libraries
 * ADCD reference: libraries/37-advanced-tag-usage-copying-an-existing-tag-list.md
 */

    struct TagItem *otags;      /* Original tag array */
    struct TagItem *tags;       /* New tag array */

    /* Insert a couple of tags into an existing tag array */
    if (tags = MakeNewTagList (GA_LeftEdge, 10,
                               GA_TopEdge, 20,
                               TAG_MORE, otags))
    {
        /* ...do something with the array... */

        /* Free the array when your done with it */
        FreeTagItems (tags);
    }

    /* This function will create a tag array from tag pairs placed on
     * the stack */
    struct TagItem *MakeNewTagList (ULONG data,...)
    {
        struct TagItem *tags = (struct TagItem *) &data;

        return (CloneTagItems (tags));
    }
