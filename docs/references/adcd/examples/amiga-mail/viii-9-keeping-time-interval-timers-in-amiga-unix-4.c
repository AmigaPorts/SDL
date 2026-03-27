/* Source: ADCD 2.1
 * Section: viii-9-keeping-time-interval-timers-in-amiga-unix
 * Library: amiga-mail
 * ADCD reference: amiga-mail/viii-9-keeping-time-interval-timers-in-amiga-unix.md
 */

    This timer counts down only when your process is running.  If your
    process makes a system call, or is preempted, this timer will stop
    counting.  The timer will resume when your process resumes execution.
    When this timer reaches zero, the process will receive a SIGVTALRM
    signal.

    Possible uses for this timer include checkpointing (saving data after
    some period of execution) and multithreading.  The virtual timer is
    more desireable for these applications since it counts only when the
    process is running; there is no reason to perform a checkpoint or
    switch threads if the process has been idle.
