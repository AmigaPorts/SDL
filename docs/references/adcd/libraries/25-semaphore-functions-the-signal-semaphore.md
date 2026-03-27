---
title: 25 / Semaphore Functions / The Signal Semaphore
manual: libraries
chapter: libraries
section: 25-semaphore-functions-the-signal-semaphore
functions: [ObtainSemaphoreList]
libraries: [exec.library]
---

# 25 / Semaphore Functions / The Signal Semaphore

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Exec semaphores are signal based. Using signal semaphores is the easiest
way to protect shared, single-access resources in the Amiga.  Your task
will sleep until the semaphore is available for use.  The [SignalSemaphore](autodocs-2.0/includes-exec-semaphores-h.md)
structure is as follows:


```c
    struct SignalSemaphore {
        struct  Node ss_Link;
        SHORT   ss_NestCount;
        struct  MinList ss_WaitQueue;
        struct  SemaphoreRequest ss_MultipleLink;
        struct  Task *ss_Owner;
        SHORT   ss_QueueCount;
    };
```
ss_Link

```c
    is the node structure used to link semaphores together.  The [ln_Pri](libraries/23-list-structure-node-structure-definition.md)
    and [ln_Name](libraries/23-list-structure-node-structure-definition.md) fields are used to set the priority of the semaphore in a
    list and to name the semaphore for [public](libraries/25-making-a-signalsemaphore-available-to-the-public.md) access.  If a semaphore is
    not public the ln_Name and ln_Pri fields may be left NULL.
```
ss_NestCount

    is the count of number of locks the current owner has on the
    semaphore.
ss_WaitQueue

```c
    is the [List](libraries/23-list-structure-list-header-structure-definition.md) header for the list of other tasks waiting for this
    semaphore.
```
ss_MultipleLink

```c
    is the [SemaphoreRequest](autodocs-2.0/includes-exec-semaphores-h.md) used by [ObtainSemaphoreList()](libraries/25-semaphore-functions-multiple-semaphores.md).
```
ss_Owner

    is the pointer to the current owning task.
ss_QueueCount

    is the number of other tasks waiting for the semaphore.
A practical application of a SignalSemaphore would be to use it as the
base of a shared data structure.  For example:


```c
    struct SharedList {
        struct SignalSemaphore sl_Semaphore;
        struct MinList         sl_List;
    };
```
 [Creating a SignalSemaphore Structure](libraries/25-the-signal-semaphore-creating-a-signalsemaphore-structure.md) 
 [Making a SignalSemaphore Available to the Public](libraries/25-making-a-signalsemaphore-available-to-the-public.md) 
 [Obtaining a SignalSemaphore Exclusively](libraries/25-the-signal-semaphore-obtaining-a-signalsemaphore.md) 
 [Obtaining a Shared SignalSemaphore](libraries/25-the-signal-semaphore-obtaining-a-shared-signalsemaphore.md) 
 [Checking a SignalSemaphore](libraries/25-the-signal-semaphore-checking-a-signalsemaphore.md) 
 [Releasing a SignalSemaphore](libraries/25-the-signal-semaphore-releasing-a-signalsemaphore.md) 
 [Removing a SignalSemaphore Structure](libraries/25-the-signal-semaphore-removing-a-signalsemaphore-structure.md) 

---

## See Also

- [ObtainSemaphoreList — exec.library](../autodocs/exec.library.md#obtainsemaphorelist)
