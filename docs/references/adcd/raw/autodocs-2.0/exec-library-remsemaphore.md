# exec.library/RemSemaphore



NAME

    RemSemaphore -- remove a signal semaphore from the system
SYNOPSIS

```c
    RemSemaphore(signalSemaphore)
                 A1

    void RemSemaphore(struct [SignalSemaphore](../Includes_and_Autodocs_2._guide/node0082.html#line40) *);
```
FUNCTION

    This function removes a signal semaphore structure from the
    system's signal semaphore list.  Subsequent attempts to
    rendezvous by name with this semaphore will fail.
INPUTS
   signalSemaphore -- an initialized signal semaphore structure

SEE ALSO

```c
    [AddSemaphore](../Includes_and_Autodocs_2._guide/node032B.html), [FindSemaphore](../Includes_and_Autodocs_2._guide/node0351.html)
```
