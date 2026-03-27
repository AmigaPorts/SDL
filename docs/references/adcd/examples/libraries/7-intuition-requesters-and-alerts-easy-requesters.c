/* Source: ADCD 2.1
 * Section: 7-intuition-requesters-and-alerts-easy-requesters
 * Library: libraries
 * ADCD reference: libraries/7-intuition-requesters-and-alerts-easy-requesters.md
 */

    LONG EasyRequest( struct Window *window,
                      struct EasyStruct *easyStruct,
                      ULONG *idcmpPtr, APTR arg1, ... );

    LONG EasyRequestArgs( struct Window *window,
                          struct EasyStruct *easyStruct,
                          ULONG *idcmpPtr, APTR args );
