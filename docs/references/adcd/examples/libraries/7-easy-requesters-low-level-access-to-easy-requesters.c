/* Source: ADCD 2.1
 * Section: 7-easy-requesters-low-level-access-to-easy-requesters
 * Library: libraries
 * ADCD reference: libraries/7-easy-requesters-low-level-access-to-easy-requesters.md
 */

    struct Window *BuildEasyRequestArgs( struct Window *window,
                                         struct EasyStruct *easyStruct,
                                         unsigned long idcmp, APTR args );

    struct Window *BuildEasyRequest( struct Window *window,
                                     struct EasyStruct *easyStruct,
                                     unsigned long idcmp, APTR arg1, ... );
