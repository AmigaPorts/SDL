/* Source: ADCD 2.1
 * Section: lib-examples-remembertest-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-remembertest-c.md
 */

    {
    /*  The memBlockA allocation succeeded; try for memBlockB.  */
    memBlockB = AllocRemember(&rememberKey, SIZE_B, MEMF_CLEAR | MEMF_PUBLIC);
    if (memBlockB)
        {
        /*  Both memory allocations succeeded.
        **  The program may now use this memory.
        */
        }
    }
