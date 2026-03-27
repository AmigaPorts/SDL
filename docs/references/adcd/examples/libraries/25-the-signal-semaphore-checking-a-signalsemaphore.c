/* Source: ADCD 2.1
 * Section: 25-the-signal-semaphore-checking-a-signalsemaphore
 * Library: libraries
 * ADCD reference: libraries/25-the-signal-semaphore-checking-a-signalsemaphore.md
 */

    UBYTE *name;
    struct SignalSemaphore *semaphore;

    Forbid();
    if (semaphore = FindSemaphore(name)) AttemptSemaphore(semaphore);
    Permit();
