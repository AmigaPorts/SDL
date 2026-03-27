/* Source: ADCD 2.1
 * Section: intuition-library-makeclass
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/intuition-library-makeclass.md
 */

    ULONG __saveds  myDispatcher();
    ULONG   hookEntry();    /* asm-to-C interface glue       */
    struct IClass   *cl;
    struct IClass   *MakeClass();

    if ( cl =  MakeClass( NULL,
                SUPERCLASSID, NULL,  /* superclass is public */
                sizeof (struct MyInstanceData),
                0 ))
    {
        /* initialize the cl_Dispatcher [Hook](../Includes_and_Autodocs_2._guide/node012D.html#line23)       */
        cl->cl_Dispatcher.h_Entry = hookEntry;
        cl->cl_Dispatcher.h_SubEntry = myDispatcher;
        cl->cl_Dispatcher.h_Data = (VOID *) 0xFACE; /* unused */

        cl-cl_UserData = (ULONG) myTable;
    }
    return ( cl );
