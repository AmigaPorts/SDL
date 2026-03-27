/* Source: ADCD 2.1
 * Section: lib-examples-allocentry-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-allocentry-c.md
 */

    memblocks.mn_head.ml_NumEntries = 4; /* 4! Since the MemEntry starts at 1! */

    /* Describe the first piece of memory we want.  Because of our MemBlocks structure */
    /* setup, we reference the first MemEntry differently when initializing it.        */
    memblocks.mn_head.ml_ME[0].me_Reqs = MEMF_CLEAR;
    memblocks.mn_head.ml_ME[0].me_Length = 4000;

    memblocks.mn_body[0].me_Reqs   = MEMF_CHIP | MEMF_CLEAR;   /* Describe the other pieces of    */
    memblocks.mn_body[0].me_Length = 100000;                   /* memory we want. Additional      */
    memblocks.mn_body[1].me_Reqs   = MEMF_PUBLIC | MEMF_CLEAR; /* MemEntries are initialized this */
    memblocks.mn_body[1].me_Length = 200000;                   /* way. If we wanted even more en- */
    memblocks.mn_body[2].me_Reqs   = MEMF_PUBLIC;              /* tries, we would need to declare */
    memblocks.mn_body[2].me_Length = 25000;                    /* a larger MemEntry array in our  */
                                                               /* MemBlocks structure.            */

    memlist = (struct MemList *)AllocEntry((struct MemList *)&memblocks);

    if ((ULONG)memlist & ALLOCERROR)          /* 'error' bit 31 is set (see below). */
    {
       printf("AllocEntry FAILED\n");
       exit(200);
    }
    /* We got all memory we wanted.  Use it and call FreeEntry() to free it */
    printf("AllocEntry succeeded - now freeing all allocated blocks\n");
    FreeEntry(memlist);
