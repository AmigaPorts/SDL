/* Source: ADCD 2.1
 * Section: 25-semaphore-functions-multiple-semaphores
 * Library: libraries
 * ADCD reference: libraries/25-semaphore-functions-multiple-semaphores.md
 */

    ObtainSemaphore((struct SignalSemaphore *)SemaphoreList);
    ObtainSemaphoreList(SemaphoreList->sl_List);

    /* At this point the objects are protected, and can be manipulated */

    ReleaseSemaphoreList(SemaphoreList->sl_List);
    ReleaseSemaphore((struct SignalSemaphore *)SemaphoreList);
