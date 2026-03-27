/* Source: ADCD 2.1
 * Section: exec-library-findsemaphore
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/exec-library-findsemaphore.md
 */

    This function will search the system signal semaphore list for a
    semaphore with the given name.  The first semaphore matching this
    name will be returned.

    This function does not arbitrate for access to the semaphore list,
    surround the call with a [Forbid()/Permit()](../Includes_and_Autodocs_2._guide/node0369.html) pair.
