/* Source: ADCD 2.1
 * Section: exec-library-wait
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/exec-library-wait.md
 */

    This function will cause the current task to suspend waiting for
    one or more signals.  When one or more of the specified signals
    occurs, the task will return to the ready state, and those signals
    will be cleared.

    If a signal occurred prior to calling Wait(), the wait condition will
    be immediately satisfied, and the task will continue to run without
    delay.
