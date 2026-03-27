# 25 / / The Signal Semaphore / Checking a SignalSemaphore


When you attempt to obtain a semaphore with [ObtainSemaphore()](../Libraries_Manual_guide/node02FA.html), your task
will be put to sleep if the semaphore is not currently available. If you
do not want to wait, you can call [AttemptSemaphore()](../Includes_and_Autodocs_2._guide/node0336.html) instead. If the
semaphore is available for [exclusive locking](../Libraries_Manual_guide/node02FA.html), AttemptSemaphore() obtains
it for you and returns TRUE.  If it is not available, the function returns
FALSE immediately instead of waiting for the semaphore to be released.

To attempt to obtain a semaphore, use the following:


```c
    struct SignalSemaphore *semaphore;
    AttemptSemaphore(semaphore);
```
To make an attempt to obtain a [public](../Libraries_Manual_guide/node02F9.html) semaphore, the following code should
be used:


```c
    UBYTE *name;
    struct SignalSemaphore *semaphore;

    Forbid();
    if (semaphore = FindSemaphore(name)) AttemptSemaphore(semaphore);
    Permit();
```
