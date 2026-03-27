/* Source: ADCD 2.1
 * Section: exec-library-alloctrap
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/exec-library-alloctrap.md
 */

    Allocate a trap number from the current task's pool.  These trap
    numbers are those associated with the 68000 TRAP type instructions.
    Either a particular number, or the next free number may be
    allocated.

    If the trap is already in use (or no free traps are available) a -1
    is returned.

    This function only affects the currently running task.

    Traps are sent to the trap handler pointed at by tc_TrapCode.
    Unless changed by user code, this points to a standard trap
    handler.  The stack frame of the exception handler will be:

            0(SP) = Exception vector number.  This will be in the
                    range of 32 to 47 (corresponding to the
                    Trap #1...Trap #15 instructions).
            4(SP) = 68000/68010/68020/68030, etc. exception frame

    tc_TrapData is not used.
