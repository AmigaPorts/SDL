---
title: 17 Introduction to Exec / Multitasking
manual: libraries
chapter: libraries
section: 17-introduction-to-exec-multitasking
functions: []
libraries: []
---

# 17 Introduction to Exec / Multitasking

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

A conventional micro-computer spends a lot of its time waiting for things
to happen.  It has to wait for such things as the user to push buttons on
the keyboard or mouse, for data to come in through the serial port, and
for data to go out to a disk drive.  To make efficient use of the CPU's
time, an operating system can have the CPU carry out some other task while
it is waiting for such events to occur.

A multitasking operating system reduces the amount of time it wastes, by
switching to another program when the current one needs to wait for an
event.  A multitasking operating system can have several programs, or
tasks, running at the same time.  Each task runs independently of the
others, without having to worry about what the other tasks are doing.
From a task's point of view, it's as if each task has a computer all to
itself.

The Amiga's multitasking works by switching which task is currently using
the CPU.  A task can be a user's application program, or it can be a task
that controls system resources (like the disk drives or the keyboard).
Each task has a priority assigned to it.  Exec will let the task with the
highest priority use the CPU, but only if the task is ready to run.  A
task can be in one of three states: ready, sleeping, or running.

A ready task is not currently using the CPU but is waiting to use the
processor.  Exec keeps a list of the tasks that are ready.  Exec sorts
this list according to task priority, so Exec can easily find the ready
task with the highest priority.  When Exec switches the task that
currently has control of the CPU, it switches to the task at the top of
this list.

A sleeping task is not currently running and is waiting for some event to
happen.  When that event occurs, Exec will move the sleeping task into the
list of ready tasks.

A running task is currently using the CPU.  It will remain the current
task until one of three things occur:

  * A higher priority task becomes ready, so the OS preempts the current

    task and switches to the higher priority task.
  * The currently running task needs to wait for an event, so it goes to

    sleep and Exec switches to the highest priority task in Exec's ready
    list.
  * The currently running task has had control of the CPU for at least a

```c
    preset time period called a quantum and there is another task of
    equal priority ready to run.  In this case, Exec will preempt the
    current task for the ready one with the same priority.  This is known
    as time-slicing.  When there is a group of tasks of equal priority on
    the top of the ready list, Exec will cycle through them, letting each
    one use the CPU for a quantum (a slice of time).
```
The terms "task" and "process" are often used interchangeably to represent
the generic concept of task.  On the Amiga, this terminology can be a
little confusing because of the names of the data structures that are
associated with Exec tasks.  Each task has a structure associated with it
called a [Task](libraries/21-exec-tasks-task-structure.md) structure (defined in <exec/[tasks.h](autodocs-2.0/includes-exec-tasks-h.md)>).  Most application
tasks use a superset of the Task structure called a Process structure
(defined in <dos/[dosextens.h](autodocs-2.0/includes-dos-dosextens-h.md)>).  These terms are confusing to Amiga
programmers because there is an important distinction between the Exec
task with only a Task structure and an Exec task with a Process structure.

The [Process](autodocs-2.0/includes-dos-dosextens-h.md) structure builds on the [Task](libraries/21-exec-tasks-task-structure.md) structure and contains some extra
fields which allow the DOS library to associate an AmigaDOS environment to
the task.  Some elements of a DOS environment include a current input and
output stream and a current working directory.  These elements are
important to applications that need to do standard input and output using
functions like [printf()](autodocs-2.0/amiga-lib-printf.md).

Exec only pays attention to the [Task](libraries/21-exec-tasks-task-structure.md) structure portion of the [Process](autodocs-2.0/includes-dos-dosextens-h.md)
structure, so, as far as Exec is concerned, there is no difference between
a task with a Task structure and a task with a Process structure.  Exec
considers both of them to be tasks.

An application doesn't normally worry about which structure their task
uses.  Instead, the system that launches the application takes care of it.
Both Workbench and the Shell (CLI) attach a [Process](autodocs-2.0/includes-dos-dosextens-h.md) structure to the
application tasks that they launch.

