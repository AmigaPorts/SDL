/* Source: ADCD 2.1
 * Section: exec-library-forbid
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/exec-library-forbid.md
 */

    The current task will not be rescheduled as long as it is ready to
    run.  In the event that the current task enters a wait state, other
    tasks may be scheduled.  Upon return from the wait state, the original
    task will continue to run without disturbing the Forbid().

    Calls to Forbid() nest. In order to restore normal task rescheduling,
    the programmer must execute exactly one call to [Permit()](../Includes_and_Autodocs_2._guide/node0369.html) for every
    call to Forbid().
