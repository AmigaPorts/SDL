---
title: exec.library/StackSwap
manual: autodocs-3.5
chapter: autodocs-3.5
section: exec-library-stackswap-2
functions: [RemTask]
libraries: [exec.library]
---

# exec.library/StackSwap

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	StackSwap - EXEC supported method of replacing task's stack      (V37)

   SYNOPSIS
	StackSwap(newStack)
	          A0

	VOID StackSwap(struct [StackSwapStruct](autodocs-3.5/include-exec-tasks-h.md) *);

   FUNCTION
	This function will, in an EXEC supported manner, swap the
	stack of your task with the given values in StackSwap.
	The [StackSwapStruct](autodocs-3.5/include-exec-tasks-h.md) structure will then contain the values
	of the old stack such that the old stack can be restored.
	This function is new in V37.

   NOTE
	If you do a stack swap, only the new stack is set up.
	This function does not copy the stack or do anything else
	other than set up the new stack for the task.  It is
	generally required that you restore your stack before
	exiting.

   INPUTS
	newStack - A structure that contains the values for the
		new upper and lower stack bounds and the new stack
		pointer.  This structure will have its values
		replaced by those in you task such that you can
		restore the stack later.

   RESULTS
	newStack - The structure will now contain the old stack.
		This means that StackSwap(foo); StackSwap(foo);
		will effectively do nothing.

   SEE ALSO
	[AddTask()](autodocs-3.5/exec-library-addtask-2.md), [RemTask()](autodocs-3.5/exec-library-remtask-2.md), [exec/tasks.h](autodocs-3.5/include-exec-tasks-h.md)

---

## See Also

- [RemTask — exec.library](../autodocs/exec.library.md#remtask)
