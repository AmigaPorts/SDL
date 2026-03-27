/* Source: ADCD 2.1
 * Section: icon-library-addfreelist
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/icon-library-addfreelist.md
 */

    This routine adds the specified memory to the free list.
    The free list will be extended (if required).  If there
    is not enough memory to complete the call, a null is returned.

    Note that AddFreeList does NOT allocate the requested memory.
    It only records the memory in the free list.
