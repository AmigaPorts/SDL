/* Source: ADCD 2.1
 * Section: exec-library-addtask
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/exec-library-addtask.md
 */

    task  - pointer to the task control block (TCB).  All unset fields
            must be zero.
    initialPC - the initial entry point's address
    finalPC - the finalization code entry point's address.  If zero,
              the system will use a general finalizer. This pointer is
              placed on the stack as if it were the outermost return
              address.
