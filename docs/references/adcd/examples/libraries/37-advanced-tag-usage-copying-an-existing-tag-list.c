/* Source: ADCD 2.1
 * Section: 37-advanced-tag-usage-copying-an-existing-tag-list
 * Library: libraries
 * ADCD reference: libraries/37-advanced-tag-usage-copying-an-existing-tag-list.md
 */

    struct TagItem *otags;      /* Original tag array */
    struct TagItem *ntags;      /* New tag array */

    /* Make sure there is a TagItem array */
    if (otags)
    {
        /* Copy the original tags into a new tag array */
        if (ntags = CloneTagItems(otags))
        {
            /* ...do something with the array... */

            /* Free the array when your done with it */
            FreeTagItems (ntags);
        }
    }
