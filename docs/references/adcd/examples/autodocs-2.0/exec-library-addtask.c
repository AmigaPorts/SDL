/* Source: ADCD 2.1
 * Section: exec-library-addtask
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/exec-library-addtask.md
 */

    Add a task to the system.  A reschedule will be run; the task with
    the highest priority in the system will start to execute (this may
    or may not be the new task).

    Certain fields of the task control block must be initialized and a
    stack allocated prior to calling this function.  The absolute
    smallest stack that is allowable is something in the range of 100
    bytes, but in general the stack size is dependent on what
    subsystems are called. In general 256 bytes is sufficient if only
    Exec is called, and 4K will do if anything in the system is called.
    DO NOT UNDERESTIMATE.  If you use a stack sniffing utility,
    leave a healthy pad above the minimum value.  The system guarantees
    that its stack operations will leave the stack longword aligned.

    This function will temporarily use space from the new task's stack
    for the task's initial set of registers.  This space is allocated
    starting at the SPREG location specified in the task control block
    (not from SPUPPER).  This means that a task's stack may contain
    static data put there prior to its execution.  This is useful for
    providing initialized global variables or some tasks may want to
    use this space for passing the task its initial arguments.

    A task's initial registers are set to zero (except the PC).

    The TC_MEMENTRY field of the task structure may be extended by
    the user to hold additional MemLists (as returned by [AllocEntry()](../Includes_and_Autodocs_2._guide/node0331.html)).
    These will be automatically be deallocated at [RemTask()](../Includes_and_Autodocs_2._guide/node0378.html) time.
    If the code you have used to start the task has already added
    something to the MEMENTRY list, simply use [AddHead](../Includes_and_Autodocs_2._guide/node0325.html) to add your
    new MemLists in.  If no initialization has been done, a [NewList](../Includes_and_Autodocs_2._guide/node0161.html) will
    need to be performed.
