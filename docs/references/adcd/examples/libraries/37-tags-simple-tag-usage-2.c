/* Source: ADCD 2.1
 * Section: 37-tags-simple-tag-usage
 * Library: libraries
 * ADCD reference: libraries/37-tags-simple-tag-usage.md
 */

    struct Window *window;

    /* Just pass NULL to show we aren't using a NewWindow */
    window = OpenWindowTags( NULL,
                             WA_CustomScreen, screen,
                             WA_Title, "RKM Test Window",
                             TAG_DONE );
