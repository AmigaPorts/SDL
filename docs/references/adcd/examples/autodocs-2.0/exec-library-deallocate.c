/* Source: ADCD 2.1
 * Section: exec-library-deallocate
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/exec-library-deallocate.md
 */

    This function deallocates memory by returning it to the appropriate
    private free memory pool.  This function can be used to free an
    entire block allocated with the above function, or it can be used
    to free a sub-block of a previously allocated block.  Sub-blocks
    must be an even multiple of the memory chunk size (currently 8
    bytes).

    This function can even be used to add a new free region to an
    existing [MemHeader](../Includes_and_Autodocs_2._guide/node0089.html#line29), however the extent pointers in the [MemHeader](../Includes_and_Autodocs_2._guide/node0089.html#line29)
    will no longer be valid.

    If memoryBlock is not on a block boundary (MEM_BLOCKSIZE) then it
    will be rounded down in a manner compatible with [Allocate()](../Includes_and_Autodocs_2._guide/node0330.html).  Note
    that this will work correctly with all the memory allocation
    functions, but may cause surprises if one is freeing only part of a
    region.  The size of the block will be rounded up, so the freed
    block will fill to an even memory block boundary.
