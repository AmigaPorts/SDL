/* Source: ADCD 2.1
 * Section: 4-basic-window-structures-and-functions-opening-a-window
 * Library: libraries
 * ADCD reference: libraries/4-basic-window-structures-and-functions-opening-a-window.md
 */

    struct Window *OpenWindowTagList( struct NewWindow *newWindow,
                                     struct TagItem *tagList );
    struct Window *OpenWindowTags( struct NewWindow *newWindow,
                                  unsigned long tag1Type, ... );
    struct Window *OpenWindow( struct NewWindow *newWindow );
