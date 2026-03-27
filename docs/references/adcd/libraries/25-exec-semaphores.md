---
title: 25 Exec Semaphores
manual: libraries
chapter: libraries
section: 25-exec-semaphores
functions: []
libraries: []
---

# 25 Exec Semaphores

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Semaphores are a feature of Exec which provide a general method for tasks
to arbitrate for the use of memory or other system resources they may be
sharing.  This chapter describes the structure of Exec semaphores and the
various support functions provided for their use.  Since the semaphore
system uses Exec lists and signals, some familiarity with these concepts
is helpful for understanding semaphores.

In any multitasking or multi-processing system there is a need to share
data among independently executing tasks.  If the data is static (that is,
it never changes), then there is no problem.  However, if the data is
variable, then there must be some way for a task that is about to make a
change to keep other tasks from looking at the data.

For example, to add a node to a linked list of data, a task would normally
just add the node.  However, if the list is shared with other tasks, this
could be dangerous.  Another task could be walking down the list while the
change is being made and pick up an incorrect pointer.  The problem is
worse if two tasks attempt to add an item to the list at the same time.
Exec semaphores provide a way to prevent such problems.

A semaphore is much like getting a key to a locked data item.  When you
have the key (semaphore), you can access the data item without worrying
about other tasks causing problems.  Any other tasks that try to obtain
the semaphore will be put to sleep until the semaphore becomes available.
When you have completed your work with the data, you return the semaphore.

For semaphores to work correctly, there are two restrictions that must be
observed at all times:

 1) All tasks using shared data that is protected by a semaphore must

    always ask for the semaphore first before accessing the data. If some
    task accesses the data directly without first going through the
    semaphore, the data may be corrupted.  No task will have safe access
    to the data.
 2) A deadlock will occur if a task that owns an [exclusive](libraries/25-the-signal-semaphore-obtaining-a-signalsemaphore.md) semaphore on

```c
    some data inadvertently calls another task which tries to get an
    exclusive semaphore on that same data in blocking mode.  Deadlocks
    and other such issues are beyond the scope of this manual.  For more
    details on deadlocks and other problems of shared data in a
    multitasking system and the methods used to prevent them, refer to a
    textbook in computer science such as Operating Systems by Tannenbaum
    (Prentice-Hall).
```
 [Semaphore Functions](libraries/25-exec-semaphores-semaphore-functions.md)    [Function Reference](libraries/25-exec-semaphores-function-reference.md) 

