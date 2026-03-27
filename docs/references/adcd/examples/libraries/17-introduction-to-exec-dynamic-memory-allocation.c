/* Source: ADCD 2.1
 * Section: 17-introduction-to-exec-dynamic-memory-allocation
 * Library: libraries
 * ADCD reference: libraries/17-introduction-to-exec-dynamic-memory-allocation.md
 */

    APTR  my_mem;

    if (my_mem = AllocMem(100, MEMF_ANY))
    {
        /* Your code goes here */
        FreeMem(my_mem, 100);
    }
    else  { /* couldn't get memory, exit with an error */ }
