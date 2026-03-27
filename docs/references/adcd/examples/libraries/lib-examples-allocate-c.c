/* Source: ADCD 2.1
 * Section: lib-examples-allocate-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-allocate-c.md
 */

    struct MemHeader *mh;
    struct MemChunk  *mc;
    APTR   block1, block2;

    /* Get the MemHeader needed to keep track of our new block. */
    mh = (struct MemHeader *)AllocMem((LONG)sizeof(struct MemHeader), MEMF_CLEAR);
    if (!mh) exit(10);

    /* Get the actual block the above MemHeader will manage. */
    if ( !(mc = (struct MemChunk *)AllocMem(BLOCKSIZE, 0)) );
    {
        FreeMem(mh, (LONG)sizeof(struct MemHeader));
        exit(10);
    }
    mh->mh_Node.ln_Type = NT_MEMORY;
    mh->mh_First        = mc;
    mh->mh_Lower        = (APTR)mc;
    mh->mh_Upper        = (APTR)(BLOCKSIZE + (ULONG)mc);
    mh->mh_Free         = BLOCKSIZE;

    mc->mc_Next  = NULL;                     /* Set up first chunk in the freelist */
    mc->mc_Bytes = BLOCKSIZE;

    block1 = (APTR)Allocate(mh,20);
    block2 = (APTR)Allocate(mh, 314);

    printf("Our MemHeader struct at $%lx. Our block of memory at $%lx\n", mh, mc);
    printf("Allocated from our pool: block1 at $%lx, block2 at $%lx\n", block1, block2);

    FreeMem(mh, (LONG)sizeof(struct MemHeader));
    FreeMem(mc, (LONG)BLOCKSIZE);
