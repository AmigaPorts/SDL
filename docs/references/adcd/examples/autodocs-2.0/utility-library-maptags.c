/* Source: ADCD 2.1
 * Section: utility-library-maptags
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/utility-library-maptags.md
 */

    /* Consider this source list: */
        struct [TagItem](../Includes_and_Autodocs_2._guide/node012E.html#line31) list[] = {
            { MY_SIZE,      71 },
            { MY_WEIGHT,    200 },
            { TAG_END,      } };

    /* And the mapping list: */
        struct [TagItem](../Includes_and_Autodocs_2._guide/node012E.html#line31) map[] = {
            { MY_SIZE,      HIS_TALL },
            { TAG_END,      } };

    /* Then after MapTags( list, map, 0 ), 'list' will become: */
            { HIS_TALL, 71 },
            { TAG_IGNORE, },
            { TAG_END, }

    /* Then after MapTags( list, map, 1 ), 'list' will become: */
            { HIS_TALL, 71 },
            { MY_WEIGHT, 200 },
            { TAG_END, }
