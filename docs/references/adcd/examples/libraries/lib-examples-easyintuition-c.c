/* Source: ADCD 2.1
 * Section: lib-examples-easyintuition-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-easyintuition-c.md
 */

    {
    0,                /* LeftEdge must be zero prior to Release 2 */
    0,                /* TopEdge */
    640,              /* Width (high-resolution) */
    STDSCREENHEIGHT,  /* Height (non-interlace)  */
    2,                /* Depth (4 colors will be available) */
    0,1,              /* Default DetailPen and BlockPen  */
    HIRES,            /* the high-resolution display mode */
    CUSTOMSCREEN | NS_EXTENDED,     /* the screen type */
    NULL,             /* no special font */
    "Our Screen",     /* the screen title */
    NULL,             /* no custom screen gadgets (not supported) */
    NULL,             /* no CustomBitMap */
    ourscreentags     /* tags for additional V37 features */
    };
