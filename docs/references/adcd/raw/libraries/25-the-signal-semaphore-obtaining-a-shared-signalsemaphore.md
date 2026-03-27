# 25 / / The Signal Semaphore / Obtaining a Shared SignalSemaphore


For read-only purposes, multiple tasks may have a shared lock on a signal
semaphore.  If a semaphore is already exclusively locked, all attempts to
obtain the semaphore shared will be blocked until the [exclusive lock](../Libraries_Manual_guide/node02FA.html) is
[released](../Libraries_Manual_guide/node02FD.html).  At that point, all shared locks will be obtained and the
calling tasks will wake up.

To obtain a shared semaphore, use:


```c
    struct SignalSemaphore *semaphore;
    ObtainSemaphoreShared(semaphore);
```
To obtain a [public](../Libraries_Manual_guide/node02F9.html) shared semaphore, the following code should be used:


```c
    UBYTE *name;
    struct SignalSemaphore *semaphore;

    Forbid();
    if (semaphore = FindSemaphore(name))
        ObtainSemaphoreShared(semaphore);
    Permit();
```
