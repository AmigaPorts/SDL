---
title: 21 Exec Tasks / Processor and Cache Control
manual: libraries
chapter: libraries
section: 21-exec-tasks-processor-and-cache-control
functions: [CacheClearE, CacheClearU, CacheControl, CachePostDMA, CachePreDMA, GetCC, SetSR, SuperState, Supervisor, UserState]
libraries: [exec.library]
---

# 21 Exec Tasks / Processor and Cache Control

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Exec provides a number of to control the processor mode and, if available,
the caches.  All these functions work independently of the specific M68000
family processor type.  This enables you to write code which correctly
controls the state of both the MC68000 and the MC68040.  Along with
processor mode and cache control, functions are provided to obtain
information about the condition code register (CCR) and status register
(SR).  No functions are provided to control a paged memory management unit
(PMMU) or floating point unit (FPU).


          Table 21-2: Processor and Cache Control Functions
   __________________________________________________________________
  |                                                                  |
  |     Function              Description                            |
  |==================================================================|
  |         [GetCC()](libraries/21-processor-and-cache-control-condition-code-register.md)  Get processor condition codes.                  |
  |         [SetSR()](libraries/21-processor-and-cache-control-status-register.md)  Get/set processor status register.              |
  |    [SuperState()](libraries/21-processor-and-cache-control-supervisor-mode.md)  Set supervisor mode with user stack.            |
  |    [Supervisor()](libraries/21-processor-and-cache-control-supervisor-mode.md)  Execute a short supervisor mode function.       |
  |     [UserState()](libraries/21-processor-and-cache-control-supervisor-mode.md)  Return to user mode with user stack.            |
  |------------------------------------------------------------------|
  |   [CacheClearE()](autodocs-2.0/exec-library-cachecleare.md)  Flush CPU instruction and/or data caches (V37). |
  |   [CacheClearU()](libraries/21-processor-and-cache-control-the-68040-and-cpu-caches.md)  Flush CPU instruction and data caches (V37).    |
  |  [CacheControl()](autodocs-2.0/exec-library-cachecontrol.md)  Global cache control (V37).                     |
  |  [CachePostDMA()](libraries/21-processor-and-cache-control-dma-cache-functions.md)  Perform actions prior to hardware DMA (V37).    |
  |   [CachePreDMA()](libraries/21-processor-and-cache-control-dma-cache-functions.md)  Perform actions after hardware DMA (V37).       |
  |__________________________________________________________________|


 [Supervisor Mode](libraries/21-processor-and-cache-control-supervisor-mode.md)    [Condition Code Register](libraries/21-processor-and-cache-control-condition-code-register.md)    [DMA Cache Functions](libraries/21-processor-and-cache-control-dma-cache-functions.md) 
 [Status Register](libraries/21-processor-and-cache-control-status-register.md)    [Cache Functions](libraries/21-processor-and-cache-control-cache-functions.md)            [The 68040 and CPU Caches](libraries/21-processor-and-cache-control-the-68040-and-cpu-caches.md) 

---

## See Also

- [CacheClearE — exec.library](../autodocs/exec.library.md#cachecleare)
- [CacheClearU — exec.library](../autodocs/exec.library.md#cacheclearu)
- [CacheControl — exec.library](../autodocs/exec.library.md#cachecontrol)
- [CachePostDMA — exec.library](../autodocs/exec.library.md#cachepostdma)
- [CachePreDMA — exec.library](../autodocs/exec.library.md#cachepredma)
- [GetCC — exec.library](../autodocs/exec.library.md#getcc)
- [SetSR — exec.library](../autodocs/exec.library.md#setsr)
- [SuperState — exec.library](../autodocs/exec.library.md#superstate)
- [Supervisor — exec.library](../autodocs/exec.library.md#supervisor)
- [UserState — exec.library](../autodocs/exec.library.md#userstate)
