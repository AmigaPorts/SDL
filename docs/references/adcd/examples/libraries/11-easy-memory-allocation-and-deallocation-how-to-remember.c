/* Source: ADCD 2.1
 * Section: 11-easy-memory-allocation-and-deallocation-how-to-remember
 * Library: libraries
 * ADCD reference: libraries/11-easy-memory-allocation-and-deallocation-how-to-remember.md
 */

    memBlockA = AllocRemember(&rememberKey, SIZE_A,
                              MEMF_CLEAR | MEMF_PUBLIC);
    if (memBlockA == NULL)
        {
        /* error: allocation failed */
        printf("Memory allocation failed.\n");
        }
    else
        {
        /* use the memory here */
        printf("Memory allocation succeeded.\n");
        }
