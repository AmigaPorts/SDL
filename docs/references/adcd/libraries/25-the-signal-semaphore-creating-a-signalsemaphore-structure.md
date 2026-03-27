---
title: 25 / / The Signal Semaphore / Creating a SignalSemaphore Structure
manual: libraries
chapter: libraries
section: 25-the-signal-semaphore-creating-a-signalsemaphore-structure
functions: [InitSemaphore]
libraries: [exec.library]
---

# 25 / / The Signal Semaphore / Creating a SignalSemaphore Structure

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

To initialize a [SignalSemaphore](libraries/25-semaphore-functions-the-signal-semaphore.md) structure use the [InitSemaphore()](autodocs-2.0/exec-library-initsemaphore.md)
function.  This function initializes the list structure and the nesting
and queue counters.  It does not change the semaphore's name or priority
fields.

This fragment creates and initializes a semaphore for a data item such as
the [SharedList](libraries/25-semaphore-functions-the-signal-semaphore.md) structure above.


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

---

## See Also

- [InitSemaphore — exec.library](../autodocs/exec.library.md#initsemaphore)
