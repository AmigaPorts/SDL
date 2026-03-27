---
title: exec.library/AddTask
manual: autodocs-3.5
chapter: autodocs-3.5
section: exec-library-addtask-2
functions: [FindTask, RemTask]
libraries: [exec.library]
---

# exec.library/AddTask

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	AddTask -- add a task to the system

   SYNOPSIS
	result = AddTask(task, initialPC, finalPC)
	 D0               A1    A2         A3

	[APTR](autodocs-3.5/include-exec-types-h.md) AddTask(struct [Task](autodocs-3.5/include-exec-tasks-h.md) *, [APTR](autodocs-3.5/include-exec-types-h.md), APTR);

   FUNCTION
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
	the user to hold additional MemLists (as returned by [AllocEntry()](autodocs-3.5/exec-library-allocentry-2.md)).
	These will be automatically be deallocated at [RemTask()](autodocs-3.5/exec-library-remtask-2.md) time.
	If the code you have used to start the task has already added
	something to the MEMENTRY list, simply use [AddHead](autodocs-3.5/exec-library-addhead-2.md) to add your
	new MemLists in.  If no initialization has been done, a [NewList](autodocs-3.5/amiga-lib-newlist-2.md) will
	need to be performed.

   INPUTS
	task  - pointer to the task control block (TCB).  All unset fields
		must be zero.
	initialPC - the initial entry point's address
	finalPC - the finalization code entry point's address.  If zero,
		  the system will use a general finalizer. This pointer is
		  placed on the stack as if it were the outermost return
		  address.

   RESULTS
	For V36, AddTask returns either a NULL or the address of the new
	task.  Old code need not check this.

   WARNING
	Tasks are a low-level building block, and are unable to call
	dos.library, or any system function that might call dos.library.
	See the AmigaDOS [CreateProc()](autodocs-3.5/dos-library-createproc-2.md) for information on Processes.

   SEE ALSO
	[RemTask()](autodocs-3.5/exec-library-remtask-2.md), [FindTask()](autodocs-3.5/exec-library-findtask-2.md), [amiga.lib/CreateTask()](autodocs-3.5/amiga-lib-createtask-2.md), [dos/CreateProc()](autodocs-3.5/dos-library-createproc-2.md),
	[amiga.lib/NewList()](autodocs-3.5/amiga-lib-newlist-2.md)

---

## See Also

- [FindTask — exec.library](../autodocs/exec.library.md#findtask)
- [RemTask — exec.library](../autodocs/exec.library.md#remtask)
