/* Source: ADCD 2.1
 * Section: exec-library-allocate
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/exec-library-allocate.md
 */

    #include [<exec/types.h>](../Includes_and_Autodocs_2._guide/node0096.html)
    #include [<exec/memory.h>](../Includes_and_Autodocs_2._guide/node0089.html)
    void *AllocMem();
    #define BLOCKSIZE 4096L /* Or whatever you want */

    void main()
    {
    struct [MemHeader](../Includes_and_Autodocs_2._guide/node0089.html#line29) *mh;
    struct [MemChunk](../Includes_and_Autodocs_2._guide/node0089.html#line21)  *mc;
    APTR   block1;
    APTR   block2;

        /* Get the [MemHeader](../Includes_and_Autodocs_2._guide/node0089.html#line29) needed to keep track of our new block */
        mh = (struct [MemHeader](../Includes_and_Autodocs_2._guide/node0089.html#line29) *)
             AllocMem((long)sizeof(struct MemHeader), MEMF_CLEAR );
        if( !mh )
            exit(10);

        /* Get the actual block the above [MemHeader](../Includes_and_Autodocs_2._guide/node0089.html#line29) will manage */
        mc = (struct [MemChunk](../Includes_and_Autodocs_2._guide/node0089.html#line21) *)AllocMem( BLOCKSIZE, 0L );
        if( !mc )
            {
            FreeMem( mh, (long)sizeof(struct MemHeader) ); exit(10);
            }

        mh->mh_Node.ln_Type = NT_MEMORY;
        mh->mh_Node.ln_Name = "myname";
        mh->mh_First = mc;
        mh->mh_Lower = (APTR) mc;
        mh->mh_Upper = (APTR) ( BLOCKSIZE + (ULONG) mc );
        mh->mh_Free  = BLOCKSIZE;

        /* Set up first chunk in the freelist */
        mc->mc_Next  = NULL;
        mc->mc_Bytes = BLOCKSIZE;

        block1 = (APTR) Allocate( mh, 20L );
        block2 = (APTR) Allocate( mh, 314L );
        printf("mh=$%lx mc=$%lxn",mh,mc);
        printf("Block1=$%lx, Block2=$%lxn",block1,block2);

        FreeMem( mh, (long)sizeof(struct MemHeader) );
        FreeMem( mc, BLOCKSIZE );
    }
