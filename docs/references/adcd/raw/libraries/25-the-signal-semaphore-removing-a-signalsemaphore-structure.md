# 25 / / The Signal Semaphore / Removing a SignalSemaphore Structure


Semaphore resources can only be freed if the semaphore is not locked.  A
[public](../Libraries_Manual_guide/node02F9.html) semaphore should first be removed from the system semaphore list
with the [RemSemaphore()](../Includes_and_Autodocs_2._guide/node0376.html) function. This prevents other tasks from finding
the semaphore and trying to lock it. Once the semaphore is removed from
the system list, the semaphore should be [locked exclusively](../Libraries_Manual_guide/node02FA.html) so no other
task can lock it.  Once the lock is obtained, it can be released again,
and the resources can be deallocated.

The following code should be used to remove a [public](../Libraries_Manual_guide/node02F9.html) semaphore:


```c
    UBYTE *name;
    struct SignalSemaphore *semaphore;

    Forbid();
    if (semaphore=FindSemaphore(name))
    {
        RemSemaphore(semaphore);       /* So no one else can find it... */
        ObtainSemaphore(semaphore);    /* Wait for us to be last user...*/
        ReleaseSemaphore(semaphore);   /* Ready for cleanup...          */
    }
    FreeMem(semaphore, sizeof(struct SignalSemaphore));
    Permit();
```
