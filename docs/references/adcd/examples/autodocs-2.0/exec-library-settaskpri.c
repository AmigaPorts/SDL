/* Source: ADCD 2.1
 * Section: exec-library-settaskpri
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/exec-library-settaskpri.md
 */

    This function changes the priority of a task regardless of its
    state.  The old priority of the task is returned.  A reschedule is
    performed, and a context switch may result.

    To change the priority of the currently running task, pass the
    result of FindTask(0); as the task pointer.
