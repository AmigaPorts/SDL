# exec.library/FindSemaphore



NAME

    FindSemaphore -- find a given system signal semaphore
SYNOPSIS

```c
    signalSemaphore = FindSemaphore(name)
    D0                              A1

    struct [SignalSemaphore](../Includes_and_Autodocs_2._guide/node0082.html#line40) *FindSemaphore(STRPTR);
```
FUNCTION

```c
    This function will search the system signal semaphore list for a
    semaphore with the given name.  The first semaphore matching this
    name will be returned.

    This function does not arbitrate for access to the semaphore list,
    surround the call with a [Forbid()/Permit()](../Includes_and_Autodocs_2._guide/node0369.html) pair.
```
INPUT

    name - name of the semaphore to find
RESULT

    semaphore - a pointer to the signal semaphore, or zero if not
                found.
