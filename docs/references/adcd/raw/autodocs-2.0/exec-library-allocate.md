# exec.library/Allocate



NAME

    Allocate - allocate a block of memory
SYNOPSIS

```c
    memoryBlock=Allocate(memHeader, byteSize)
    D0                   A0         D0

    void *Allocate(struct [MemHeader](../Includes_and_Autodocs_2._guide/node0089.html#line29) *, ULONG);
```
FUNCTION

```c
    This function is used to allocate blocks of memory from a given
    private free memory pool (as specified by a [MemHeader](../Includes_and_Autodocs_2._guide/node0089.html#line29) and its
    memory chunk list).  Allocate will return the first free block that
    is greater than or equal to the requested size.

    All blocks, whether free or allocated, will be block aligned;
    hence, all allocation sizes are rounded up to the next block even
    value (e.g. the minimum allocation resolution is currently 8
    bytes.  A request for 8 bytes will use up exactly 8 bytes.  A
    request for 7 bytes will also use up exactly 8 bytes.).

    This function can be used to manage an application's internal data
    memory.  Note that no arbitration of the [MemHeader](../Includes_and_Autodocs_2._guide/node0089.html#line29) and associated
    free chunk list is done.  You must be the owner before calling
    Allocate.
```
INPUTS

    memHeader - points to the local memory list header.
    byteSize - the size of the desired block in bytes.
RESULT

    memoryBlock - a pointer to the just allocated free block.
           If there are no free regions large enough to satisfy the
           request, return zero.
EXAMPLE

```c
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
```
NOTE

    If the free list is corrupt, the system will panic with alert
    AN_MemCorrupt, $01000005.
SEE ALSO

```c
    Deallocate, [exec/memory.h](../Includes_and_Autodocs_2._guide/node0089.html)
```
