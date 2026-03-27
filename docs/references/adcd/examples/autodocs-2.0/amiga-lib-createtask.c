/* Source: ADCD 2.1
 * Section: amiga-lib-createtask
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/amiga-lib-createtask.md
 */

    This function simplifies program creation of sub-tasks by
    dynamically allocating and initializing required structures
    and stack space, and adding the task to Exec's task list
    with the given name and priority. A tc_MemEntry list is provided
    so that all stack and structure memory allocated by CreateTask()
    is automatically deallocated when the task is removed.

    An Exec task may not call dos.library functions or any function
    which might cause the loading of a disk-resident library, device,
    or file (since such functions are indirectly calls to dos.library).
    Only AmigaDOS Processes may call AmigaDOS; see the
    [dos.library/CreateProc()](../Includes_and_Autodocs_2._guide/node028E.html) or the [dos.library/CreateNewProc()](../Includes_and_Autodocs_2._guide/node028D.html)
    functions for more information.

    If other tasks or processes will need to find this task by name,
    provide a complex and unique name to avoid conflicts.

    If your compiler provides automatic insertion of stack-checking
    code, you may need to disable this feature when compiling sub-task
    code since the stack for the subtask is at a dynamically allocated
    location.  If your compiler requires 68000 registers to contain
    particular values for base relative addressing, you may need to
    save these registers from your main process, and restore them
    in your initial subtask code.

    The function entry initPC is generally provided as follows:

    In C:
    extern void functionName();
    char *tname = "unique name";
    task = CreateTask(tname, 0L, functionName, 4000L);

    In assembler:
            PEA     startLabel
