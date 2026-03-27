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
        /* Both memory allocations succeeded.
        ** For the purpose of illustration, FreeRemember() is called at
        ** this point, but only to free the link nodes.  The memory pointed
        ** to by memBlockA and memBlockB is retained.
        */
        FreeRemember(&rememberKey, FALSE);

        /* Individually free the two memory blocks. The Exec FreeMem()
        ** call must be used, as the link nodes are no longer available.
        */
        FreeMem((VOID *)memBlockA, SIZE_A);
        FreeMem((VOID *)memBlockB, SIZE_B);
        }
    }
