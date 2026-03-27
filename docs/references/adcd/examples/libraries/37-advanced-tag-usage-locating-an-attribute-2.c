/* Source: ADCD 2.1
 * Section: 37-advanced-tag-usage-locating-an-attribute
 * Library: libraries
 * ADCD reference: libraries/37-advanced-tag-usage-locating-an-attribute.md
 */

    struct TagItem *tag;

    /* See if they are trying to set a sound */
    if (tag = FindTagItem(MGA_Sound, attrs))
    {
        /* Set the sound attribute to point to the specified sound data */
        tag->ti_Data = sound;
    }
