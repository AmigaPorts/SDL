/* Source: ADCD 2.1
 * Section: 37-advanced-tag-usage-mapping-tag-attributes
 * Library: libraries
 * ADCD reference: libraries/37-advanced-tag-usage-mapping-tag-attributes.md
 */

    struct TagItem map_list[] =
    {
        /* Original     New */
        {MGA_LeftEdge,  GA_LeftEdge},
        {MGA_TopEdge,   GA_TopEdge},
        {MGA_Width,     GA_Width},
        {MGA_Height,    GA_Height},

        /* Terminate the array */
        {TAG_END},
    }

    /* Map the tags to the new attributes, keeping all attributes that
     * aren't included in the mapping array */
    MapTags(tags, map_list, TRUE);
