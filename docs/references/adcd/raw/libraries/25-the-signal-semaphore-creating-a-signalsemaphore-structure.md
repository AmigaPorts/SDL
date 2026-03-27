# 25 / / The Signal Semaphore / Creating a SignalSemaphore Structure


To initialize a [SignalSemaphore](../Libraries_Manual_guide/node02F7.html) structure use the [InitSemaphore()](../Includes_and_Autodocs_2._guide/node035D.html)
function.  This function initializes the list structure and the nesting
and queue counters.  It does not change the semaphore's name or priority
fields.

This fragment creates and initializes a semaphore for a data item such as
the [SharedList](../Libraries_Manual_guide/node02F7.html#line37) structure above.


```c
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
```
