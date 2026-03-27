/* Source: ADCD 2.1
 * Section: 25-the-signal-semaphore-obtaining-a-signalsemaphore
 * Library: libraries
 * ADCD reference: libraries/25-the-signal-semaphore-obtaining-a-signalsemaphore.md
 */

    UBYTE *name;
    struct SignalSemaphore *semaphore;

    Forbid();     /* Make sure the semaphore will not go away if found. */
    if (semaphore=FindSemaphore(name))
        ObtainSemaphore(semaphore);
    Permit();
