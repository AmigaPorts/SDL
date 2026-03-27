# 25 Exec Semaphores / Semaphore Functions


Exec provides a variety of useful functions for setting, checking and
freeing semaphores.  The prototypes for these functions are as follows.


```c
    VOID  AddSemaphore ( struct SignalSemaphore *sigSem );
    ULONG AttemptSemaphore( struct SignalSemaphore *sigSem );
    struct SignalSemaphore *FindSemaphore( UBYTE *sigSem );
    VOID InitSemaphore( struct SignalSemaphore *sigSem );

    VOID ObtainSemaphore( struct SignalSemaphore *sigSem );
    VOID ObtainSemaphoreList( struct List *sigSem );
    void ObtainSemaphoreShared( struct SignalSemaphore *sigSem );

    VOID ReleaseSemaphore( struct SignalSemaphore *sigSem );
    VOID ReleaseSemaphoreList( struct List *sigSem );
    VOID RemSemaphore( struct SignalSemaphore *sigSem );
```
 [The Signal Semaphore](../Libraries_Manual_guide/node02F7.html)    [Multiple Semaphores](../Libraries_Manual_guide/node02FF.html)    [Semaphore Example](../Libraries_Manual_guide/node058D.html) 

