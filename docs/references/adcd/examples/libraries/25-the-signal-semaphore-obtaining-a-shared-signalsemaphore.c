/* Source: ADCD 2.1
 * Section: 25-the-signal-semaphore-obtaining-a-shared-signalsemaphore
 * Library: libraries
 * ADCD reference: libraries/25-the-signal-semaphore-obtaining-a-shared-signalsemaphore.md
 */

    UBYTE *name;
    struct SignalSemaphore *semaphore;

    Forbid();
    if (semaphore = FindSemaphore(name))
        ObtainSemaphoreShared(semaphore);
    Permit();
