/* Source: ADCD 2.1
 * Section: 25-the-signal-semaphore-removing-a-signalsemaphore-structure
 * Library: libraries
 * ADCD reference: libraries/25-the-signal-semaphore-removing-a-signalsemaphore-structure.md
 */

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
