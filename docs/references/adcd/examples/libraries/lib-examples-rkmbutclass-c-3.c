/* Source: ADCD 2.1
 * Section: lib-examples-rkmbutclass-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-rkmbutclass-c.md
 */

    Class *cl = NULL;
    extern ULONG HookEntry();     /* defined in amiga.lib */

    if ( cl =  MakeClass( NULL,
                "gadgetclass", NULL,
                sizeof ( struct ButINST ),
                0 ))
    {
        /* initialize the cl_Dispatcher Hook    */
        cl->cl_Dispatcher.h_Entry = HookEntry;
        cl->cl_Dispatcher.h_SubEntry = dispatchRKMButGad;
    }
    return ( cl );
