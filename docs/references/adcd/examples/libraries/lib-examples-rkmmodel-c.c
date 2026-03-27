/* Source: ADCD 2.1
 * Section: lib-examples-rkmmodel-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-rkmmodel-c.md
 */

    Class *cl;
    extern ULONG HookEntry();  /*      <-------   defined in amiga.lib.     */

    if ( cl =  MakeClass( NULL,
                "modelclass", NULL,
                sizeof ( struct RKMModData ),
                0 ))
    {
        cl->cl_Dispatcher.h_Entry = HookEntry;           /* initialize the  */
        cl->cl_Dispatcher.h_SubEntry = dispatchRKMModel; /* cl_Dispatcher   */
                                                         /* Hook.           */
    }
    return ( cl );
