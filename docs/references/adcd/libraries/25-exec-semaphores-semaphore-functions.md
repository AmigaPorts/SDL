---
title: 25 Exec Semaphores / Semaphore Functions
manual: libraries
chapter: libraries
section: 25-exec-semaphores-semaphore-functions
functions: []
libraries: []
---

# 25 Exec Semaphores / Semaphore Functions

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

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
 [The Signal Semaphore](libraries/25-semaphore-functions-the-signal-semaphore.md)    [Multiple Semaphores](libraries/25-semaphore-functions-multiple-semaphores.md)    [Semaphore Example](libraries/lib-examples-semaphore-c.md) 

