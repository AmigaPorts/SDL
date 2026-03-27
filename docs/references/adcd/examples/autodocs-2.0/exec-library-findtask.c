/* Source: ADCD 2.1
 * Section: exec-library-findtask
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/exec-library-findtask.md
 */

    This function will check all task queues for a task with the given
    name, and return a pointer to its task control block.  If a NULL
    name pointer is given a pointer to the current task will be
    returned.

    Finding oneself with a NULL for the name is very quick.  Finding a
    task by name is very system expensive, and will disable interrupts
    for a long time.  Since a task may remove itself at any time,
    a [Forbid()/Permit()](../Includes_and_Autodocs_2._guide/node0369.html) pair may be needed to ensure the pointer
    returned by FindTask() is still valid when used.
