---
title: 21 Exec Tasks / Task Exclusion
manual: libraries
chapter: libraries
section: 21-exec-tasks-task-exclusion
functions: []
libraries: []
---

# 21 Exec Tasks / Task Exclusion

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

From time to time the advanced system program may find it necessary to
access global system data structures.  Because these structures are shared
by the system and by other tasks that execute asynchronously to your task,
a task must prevent other tasks from using these structures while it is
reading from or writing to them.  This can be accomplished by preventing
the operating system from switching tasks by forbidding or disabling.  A
section of code that requires the use of either of these mechanisms to
lock out access by others is termed a critical section.  Use of these
methods is discouraged.  For arbitrating access to data between your
tasks, semaphores are a superior solution.  (See the "[Exec Semaphores](libraries/25-exec-semaphores.md)"
chapter)

 [Forbidding Task Switching](libraries/21-task-exclusion-forbidding-task-switching.md)    [Disabling Tasks](libraries/21-task-exclusion-disabling-tasks.md)    [Task Semaphores](libraries/21-task-exclusion-task-semaphores.md) 

