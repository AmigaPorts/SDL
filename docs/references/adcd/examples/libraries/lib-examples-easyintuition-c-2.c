/* Source: ADCD 2.1
 * Section: lib-examples-easyintuition-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-easyintuition-c.md
 */

    {
    WIN_LEFTEDGE,
    WIN_TOPEDGE,
    WIN_WIDTH,
    WIN_HEIGHT,
    -1,-1,             /* Means use the screen's Detail and Block pens   */

    IDCMP_CLOSEWINDOW, /* This field specifies the events we want to get */

    /* These flags specify system gadgets and other window attributes    */
    /* including the EXTENDED flag which flags this as an ExtNewWindow   */
    WFLG_CLOSEGADGET | WFLG_SMART_REFRESH | WFLG_ACTIVATE | WFLG_DRAGBAR |
    WFLG_DEPTHGADGET | WFLG_SIZEGADGET  | WFLG_NOCAREREFRESH |
    WFLG_NW_EXTENDED,

    NULL,             /* Pointer to the first gadget  */
    NULL,             /* No checkmark.                */
    "EasyWindow",     /* Window title.                */
    NULL,             /* Attach a screen later.       */
    NULL,             /* Let Intuition set up BitMap  */
    WIN_MINWIDTH,     /* Minimum width.       */
    WIN_MINHEIGHT,    /* Minimum height.      */
    -1,               /* Maximum width (screen size)  */
    -1,               /* Maximum height (screen size) */
    CUSTOMSCREEN,     /* A screen of our own. */
    ourwindowtags     /* tags for additional V37 features */
    };
