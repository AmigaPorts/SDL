---
title: 21 Exec Tasks / Function Reference
manual: libraries
chapter: libraries
section: 21-exec-tasks-function-reference
functions: [AllocTrap, CacheClearE, CacheClearU, CacheControl, CachePostDMA, CachePreDMA, Disable, Enable, FindTask, Forbid, FreeTrap, GetCC, Permit, RemTask, SetSR, SetTaskPri, SuperState, Supervisor, UserState]
libraries: [exec.library]
---

# 21 Exec Tasks / Function Reference

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The following chart gives a brief description of the Exec functions that
control tasks.  See the Amiga ROM Kernel Reference Manual: Includes and
Autodocs for details about each call.


     Table 21-3: Exec Task, Processor and Cache Control Functions
  ___________________________________________________________________
 |                                                                   |
 |      Exec Task                                                    |
 |      Function          Description                                |
 |===================================================================|
 |       [AddTask()](autodocs-2.0/exec-library-addtask.md)  Add a task to the system.                        |
 |     [AllocTrap()](autodocs-2.0/exec-library-alloctrap.md)  Allocate a processor trap vector.                |
 |       [Disable()](autodocs-2.0/exec-library-disable.md)  Disable interrupt processing.                    |
 |        [Enable()](autodocs-2.0/exec-library-enable.md)  Enable interrupt processing.                     |
 |      [FindTask()](autodocs-2.0/exec-library-findtask.md)  Find a specific task.                            |
 |        [Forbid()](autodocs-2.0/exec-library-forbid.md)  Forbid task rescheduling.                        |
 |      [FreeTrap()](autodocs-2.0/exec-library-freetrap.md)  Release a process trap.                          |
 |        [Permit()](autodocs-2.0/exec-library-permit.md)  Permit task rescheduling.                        |
 |    [SetTaskPri()](autodocs-2.0/exec-library-settaskpri.md)  Set the priority of a task.                      |
 |       [RemTask()](autodocs-2.0/exec-library-remtask.md)  Remove a task from the system.                   |
 |-------------------------------------------------------------------|
 |   [CacheClearE()](autodocs-2.0/exec-library-cachecleare.md)  Flush CPU instruction and/or data caches (V37).  |
 |   [CacheClearU()](autodocs-2.0/exec-library-cacheclearu.md)  Flush CPU instruction and data caches (V37).     |
 |  [CacheControl()](autodocs-2.0/exec-library-cachecontrol.md)  Global cache control (V37).                      |
 |  [CachePostDMA()](autodocs-2.0/exec-library-cachepostdma.md)  Perform actions prior to hardware DMA (V37).     |
 |   [CachePreDMA()](autodocs-2.0/exec-library-cachepredma.md)  Perform actions after hardware DMA (V37).        |
 |         [GetCC()](autodocs-2.0/exec-library-getcc.md)  Get processor [condition codes](libraries/21-processor-and-cache-control-condition-code-register.md).                   |
 |         [SetSR()](autodocs-2.0/exec-library-setsr.md)  Get/set processor [status register](libraries/21-processor-and-cache-control-status-register.md).               |
 |    [SuperState()](autodocs-2.0/exec-library-superstate.md)  Set [supervisor mode](libraries/21-processor-and-cache-control-supervisor-mode.md) with user stack.             |
 |    [Supervisor()](autodocs-2.0/exec-library-supervisor.md)  Execute a short supervisor mode function.        |
 |     [UserState()](autodocs-2.0/exec-library-userstate.md)  Return to user mode with user stack.             |
 |-------------------------------------------------------------------|
 |    [CreateTask()](autodocs-2.0/amiga-lib-createtask.md)  Amiga.lib function to setup and add a new task.  |
 |    [DeleteTask()](autodocs-2.0/amiga-lib-deletetask.md)  Amiga.lib function to delete a task created with |
 |                  CreateTask().                                    |
 |___________________________________________________________________|

---

## See Also

- [AllocTrap — exec.library](../autodocs/exec.library.md#alloctrap)
- [CacheClearE — exec.library](../autodocs/exec.library.md#cachecleare)
- [CacheClearU — exec.library](../autodocs/exec.library.md#cacheclearu)
- [CacheControl — exec.library](../autodocs/exec.library.md#cachecontrol)
- [CachePostDMA — exec.library](../autodocs/exec.library.md#cachepostdma)
- [CachePreDMA — exec.library](../autodocs/exec.library.md#cachepredma)
- [Disable — exec.library](../autodocs/exec.library.md#disable)
- [Enable — exec.library](../autodocs/exec.library.md#enable)
- [FindTask — exec.library](../autodocs/exec.library.md#findtask)
- [Forbid — exec.library](../autodocs/exec.library.md#forbid)
- [FreeTrap — exec.library](../autodocs/exec.library.md#freetrap)
- [GetCC — exec.library](../autodocs/exec.library.md#getcc)
- [Permit — exec.library](../autodocs/exec.library.md#permit)
- [RemTask — exec.library](../autodocs/exec.library.md#remtask)
- [SetSR — exec.library](../autodocs/exec.library.md#setsr)
- [SetTaskPri — exec.library](../autodocs/exec.library.md#settaskpri)
- [SuperState — exec.library](../autodocs/exec.library.md#superstate)
- [Supervisor — exec.library](../autodocs/exec.library.md#supervisor)
- [UserState — exec.library](../autodocs/exec.library.md#userstate)
