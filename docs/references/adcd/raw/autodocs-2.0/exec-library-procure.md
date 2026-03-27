# exec.library/Procure



NAME

```c
    Procure -- bid for a message lock (semaphore)
```
SYNOPSIS

```c
    result = Procure(semaphore, bidMessage)
    D0               A0         A1

    BYTE Procure(struct [Semaphore](../Includes_and_Autodocs_2._guide/node0082.html#line53) *, struct [Message](../Includes_and_Autodocs_2._guide/node0099.html#line48) *);
```
FUNCTION

```c
    This function is used to obtain a message based semaphore lock.  If
    the lock is immediate, Procure() returns a true result, and the
    bidMessage is not used.   If the semaphore is already locked,
    Procure() returns false, and the task must wait for the bidMessage
    to arrive at its reply port.

    Straight "Semaphores" use the message system.  They are therefore
    queueable, and users may wait on several of them at the same time.
    This makes them more powerful than "Signal Semaphores"
```
INPUT

```c
    semaphore - a semaphore message port.  This port is used to queue
    all pending lockers.  This port should be initialized with the
    PA_IGNORE option, as the MP_SigTask field is used for a pointer to
    the current locker message (not a task). New semaphore ports must
    also have the SM_BIDS word initialized to -1.  If the semaphore is
    public, it should be named, its priority set, and the added with
    [AddPort](../Includes_and_Autodocs_2._guide/node0329.html). [Message](../Includes_and_Autodocs_2._guide/node0099.html#line48) port priority is often used for anti-deadlock
    locking conventions.
```
RESULT

    result - true when the semaphore is free.  In such cases no waiting
    needs to be done.  If false, then the task should wait at its
    bidMessage reply port.
BUGS

```c
    Procure() and [Vacate()](../Includes_and_Autodocs_2._guide/node0389.html) do not have proven reliability.
```
SEE ALSO

```c
    [Vacate()](../Includes_and_Autodocs_2._guide/node0389.html)
```
