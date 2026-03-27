# exec.library/ObtainSemaphoreList



NAME

    ObtainSemaphoreList -- get a list of semaphores.
SYNOPSIS

```c
    ObtainSemaphoreList(list)
                        A0

    void ObtainSemaphoreList(struct [List](../Includes_and_Autodocs_2._guide/node007D.html#line21) *);
```
FUNCTION

```c
    [Signal](../Includes_and_Autodocs_2._guide/node0381.html) semaphores may be linked together into a list. This function
    takes a list of these semaphores and attempts to lock all of them at
    once. This call is preferable to applying [ObtainSemaphore()](../Includes_and_Autodocs_2._guide/node0362.html) to each
    element in the list because it attempts to lock all the elements
    simultaneously, and won't deadlock if someone is attempting to lock
    in some other order.

    This function assumes that only one task at a time will attempt to
    lock the entire list of semaphores.  In other words, there needs to
    be a higher level lock (perhaps another signal semaphore...) that is
    used before someone attempts to lock the semaphore list via
    ObtainSemaphoreList().

    Note that deadlocks may result if this call is used AND someone
    attempts to use [ObtainSemaphore()](../Includes_and_Autodocs_2._guide/node0362.html) to lock more than one semaphore on
    the list.  If you wish to lock more than semaphore (but not all of
    them) then you should obtain the higher level lock (see above)
```
INPUT
   list -- a list of signal semaphores

SEE ALSO

```c
    [InitSemaphore()](../Includes_and_Autodocs_2._guide/node035D.html), [ReleaseSemaphoreList()](../Includes_and_Autodocs_2._guide/node036E.html)
```
