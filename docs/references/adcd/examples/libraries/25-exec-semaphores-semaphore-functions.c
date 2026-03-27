/* Source: ADCD 2.1
 * Section: 25-exec-semaphores-semaphore-functions
 * Library: libraries
 * ADCD reference: libraries/25-exec-semaphores-semaphore-functions.md
 */

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
