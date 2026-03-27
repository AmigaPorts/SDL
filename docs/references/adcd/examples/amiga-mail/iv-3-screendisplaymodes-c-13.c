/* Source: ADCD 2.1
 * Section: iv-3-screendisplaymodes-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/iv-3-screendisplaymodes-c.md
 */

    struct Rectangle rectangle;

    /* Can't fail, already made sure it's a valid displayID */
    QueryOverscan(di->Header.DisplayID, &rectangle, overscantype);


    return (OpenScreenTags(NULL,
                           SA_DisplayID, di->Header.DisplayID,
                           SA_DClip, &rectangle,
                           SA_Title, name,
                           SA_Depth, 2,
                           SA_SysFont, 1,   /* Use the prefered WB screen font */
                           SA_Pens, dri_Pens,
                           TAG_END));
