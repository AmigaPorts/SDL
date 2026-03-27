/* Source: ADCD 2.1
 * Section: 20-allocating-multiple-memory-blocks-result
 * Library: libraries
 * ADCD reference: libraries/20-allocating-multiple-memory-blocks-result.md
 */

    #define ALLOCERROR 0x80000000
    struct  MemList *ml;
    APTR    data, moredata;

    if ( ! ((ULONG)ml & ALLOCERROR)))    /* After calling AllocEntry to */
                                         /* allocate ml */
    {
        data     = ml->ml_ME[0].me_Addr;
        moredata = ml->ml_ME[1].me_Addr;
    }
    else  exit(200);                     /* error during AllocEntry */
