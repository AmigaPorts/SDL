/* Source: ADCD 2.1
 * Section: exec-library-initsemaphore
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/exec-library-initsemaphore.md
 */

    This function initializes a signal semaphore and prepares it for
    use.  It does not allocate anything, but does initialize list
    pointers and the semaphore counters.

    Semaphores are often used to protect critical data structures
    or hardware that can only be accessed by one task at a time.
    After initialization, the address of the [SignalSemaphore](../Includes_and_Autodocs_2._guide/node0082.html#line40) may be
    made available to any number of tasks.  Typically a task will
    try to [ObtainSemaphore()](../Includes_and_Autodocs_2._guide/node0362.html), passing this address in.  If no other
    task owns the semaphore, then the call will lock and return
    quickly.  If more tasks try to [ObtainSemaphore()](../Includes_and_Autodocs_2._guide/node0362.html), they will
    be put to sleep.  When the owner of the semaphore releases
    it, the next waiter in turn will be woken up.

    Semaphores are often preferable to the old-style [Forbid()/Permit()](../Includes_and_Autodocs_2._guide/node0369.html)
    type arbitration.  With [Forbid()/Permit()](../Includes_and_Autodocs_2._guide/node0369.html) *all* other tasks are
    prevented from running.  With semaphores, only those tasks that
    need access to whatever the semaphore protects are subject
    to waiting.
