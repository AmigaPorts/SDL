/* Source: ADCD 2.1
 * Section: 4-other-window-functions-requesters-in-the-window
 * Library: libraries
 * ADCD reference: libraries/4-other-window-functions-requesters-in-the-window.md
 */

    LONG EasyRequestArgs( struct Window *window,
                          struct EasyStruct *easyStruct,
                          ULONG *idcmpPtr, APTR args );
    LONG EasyRequest( struct Window *window,
                          struct EasyStruct *easyStruct,
                          ULONG *idcmpPtr, APTR arg1, ... );
