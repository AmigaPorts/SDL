/* Source: ADCD 2.1
 * Section: exec-library-allocate
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/exec-library-allocate.md
 */

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
