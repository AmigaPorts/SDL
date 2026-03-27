/* Source: ADCD 2.1
 * Section: exec-library-procure
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/exec-library-procure.md
 */

    This function is used to obtain a message based semaphore lock.  If
    the lock is immediate, Procure() returns a true result, and the
    bidMessage is not used.   If the semaphore is already locked,
    Procure() returns false, and the task must wait for the bidMessage
    to arrive at its reply port.

    Straight "Semaphores" use the message system.  They are therefore
    queueable, and users may wait on several of them at the same time.
    This makes them more powerful than "Signal Semaphores"
