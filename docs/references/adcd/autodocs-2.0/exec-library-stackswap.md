---
title: exec.library/StackSwap
manual: autodocs-2.0
chapter: autodocs-2.0
section: exec-library-stackswap
functions: []
libraries: []
---

# exec.library/StackSwap

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    StackSwap - EXEC supported method of replacing task's stack      (V37)
```
SYNOPSIS

```c
    StackSwap(newStack)
              A0

    VOID StackSwap(struct [StackSwapStruct](autodocs-2.0/includes-exec-tasks-h.md) *);
```
FUNCTION

```c
    This function will, in an EXEC supported manner, swap the
    stack of your task with the given values in StackSwap.
    The [StackSwapStruct](autodocs-2.0/includes-exec-tasks-h.md) structure will then contain the values
    of the old stack such that the old stack can be restored.
    This function is new in V37.
```
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

```c
    newStack - The structure will now contain the old stack.
            This means that StackSwap(foo); StackSwap(foo);
            will effectively do nothing.
```
SEE ALSO

```c
    [AddTask](autodocs-2.0/exec-library-addtask.md), [RemTask](autodocs-2.0/exec-library-remtask.md), [exec/tasks.h](autodocs-2.0/includes-exec-tasks-h.md)
```
