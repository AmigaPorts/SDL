/* Source: ADCD 2.1
 * Section: 37-advanced-tag-usage-creating-a-new-tag-list
 * Library: libraries
 * ADCD reference: libraries/37-advanced-tag-usage-creating-a-new-tag-list.md
 */

    struct TagItem *tags;
    ULONG tags_needed;

    /* Indicate how many tags we need */
    tags_needed = 10;

    /* Allocate a tag array */
    if (tags = AllocateTagItems(tags_needed))
    {
        /* ...do something with the array... */

        /* Free the array when your done with it */
        FreeTagItems (tags);
    }
