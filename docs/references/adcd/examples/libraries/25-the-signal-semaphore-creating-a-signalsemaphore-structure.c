/* Source: ADCD 2.1
 * Section: 25-the-signal-semaphore-creating-a-signalsemaphore-structure
 * Library: libraries
 * ADCD reference: libraries/25-the-signal-semaphore-creating-a-signalsemaphore-structure.md
 */

    struct SharedList *slist;

    if (slist=(struct SharedList *)
        AllocMem(sizeof(struct SharedList),MEMF_PUBLIC|MEMF_CLEAR))
    {
        NewList(&slist->sl_List);       /* Initialize the MinList       */
        InitSemaphore((struct SignalSemaphore *)slist);
                                        /* And initialize the semaphore */

        /* The semaphore can now be used. */
    }
    else printf("Can't allocate structure\n");
