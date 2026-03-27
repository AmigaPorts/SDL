/* Source: ADCD 2.1
 * Section: exec-library-allocsignal
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/exec-library-allocsignal.md
 */

    Allocate a signal bit from the current tasks' pool.  Either a
    particular bit, or the next free bit may be allocated.  The signal
    associated with the bit will be properly initialized (cleared).  At
    least 16 user signals are available per task.  Signals should be
    deallocated before the task exits.

    If the signal is already in use (or no free signals are available)
    a -1 is returned.

    Allocated signals are only valid for use with the task that
    allocated them.
