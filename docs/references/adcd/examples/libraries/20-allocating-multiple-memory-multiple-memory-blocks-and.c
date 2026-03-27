/* Source: ADCD 2.1
 * Section: 20-allocating-multiple-memory-multiple-memory-blocks-and
 * Library: libraries
 * ADCD reference: libraries/20-allocating-multiple-memory-multiple-memory-blocks-and.md
 */

    struct Task *tc;
    struct MemList *ml;

    /* First initialize the task pointer and AllocEntry() the memlist ml */

    if(!tc->tc_MemEntry)
        NewList(tc->tc_MemEntry);  /* Initialize the task's memory    */
                                   /* list header. Do this once only! */
    AddTail(tc->tc_MemEntry, ml);
