---
title: 21 / Processor and Cache Control / The 68040 and CPU Caches
manual: libraries
chapter: libraries
section: 21-processor-and-cache-control-the-68040-and-cpu-caches
functions: [CacheClearU, CachePostDMA, CachePreDMA, LoadSeg]
libraries: [dos.library, exec.library]
---

# 21 / Processor and Cache Control / The 68040 and CPU Caches

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The 68040 is a much more powerful CPU than its predecessors.  It has 4K of
cache memory for instructions and another 4K cache for data.  The reason
for these two separate caches is so that the CPU core can access data and
CPU instructions at the same time.

Although the 68040 provides greater performance it also brings with it
greater compatibility problems.  Just the fact that the caches are so much
larger than Motorola's 68030 CPU can cause problems.  However, this is not
its biggest obstacle.

The 68040 data cache has a mode that can make the system run much faster
in most cases.  It is called CopyBack mode.  When a program writes data to
memory in this mode, the data goes into the cache but not into the
physical RAM.  That means that if a program or a piece of hardware were to
read that RAM without going through the data cache on the 68040, it will
read old data. CopyBack mode effects two areas of the Amiga: DMA devices
and the CPU's instruction reading.

CopyBack mode effects DMA devices because they read and write data
directly to memory.  Using DMA with CopyBack mode requires a cache flush.
If a DMA device needs to read RAM via DMA, it must first make sure that
data in the caches has been written to memory.  It can do this by calling
the Exec function [CachePreDMA()](libraries/21-processor-and-cache-control-dma-cache-functions.md). If a DMA device is about to write to
memory, it should call CachePreDMA() before the write, do the DMA write,
and then call [CachePostDMA()](libraries/21-processor-and-cache-control-dma-cache-functions.md),  which makes sure that the CPU uses the data
just written to memory.

An added advantage of using the [CachePreDMA()](libraries/21-processor-and-cache-control-dma-cache-functions.md) and [CachePostDMA()](libraries/21-processor-and-cache-control-dma-cache-functions.md) functions
is that they give the OS the chance to tell the DMA device that the
physical addresses and memory sizes are not the same.  This will make it
possible in the future to add features such as virtual memory.  See the
Autodocs for more information on these calls.

The other major compatibility problem with the 68040's CopyBack mode is
with fetching CPU instructions.  CPU instructions have to be loaded into
memory so the CPU can copy them into its instruction cache.  Normally,
instructions that will be executed are written to memory by the CPU (i.e.,
loading a program from disk).  In CopyBack mode, anything the CPU writes
to memory, including CPU instructions, doesn't actually go into memory, it
goes into the data cache.  If instructions are not flushed out of the data
cache to RAM, the 68040 will not be able to find them when it tries to
copy them into the instruction cache for execution.  It will instead find
and attempt to execute whatever garbage data happened to be left at that
location in RAM.

To remedy this, any program that writes instructions to memory must flush
the data cache after writing.  The V37 Exec function [CacheClearU()](autodocs-2.0/exec-library-cacheclearu.md) takes
care of this.  Release 2 of the Amiga OS correctly flushes the caches as
needed after it does the [LoadSeg()](autodocs-2.0/dos-library-loadseg.md) of a program (LoadSeg() loads Amiga
executable programs into memory from disk).  Applications need to do the
same if they write code to memory.  It can do that by calling
CacheClearU() before the call to [CreateProc()](autodocs-2.0/dos-library-createproc.md).  In C that would be:


```c
    extern struct ExecBase *SysBase;
    . . .

    /* If we are in 2.0, call CacheClearU() before CreateProc() */
    if (SysBase->LibNode.lib_Version >= 37) CacheClearU();

    /* Now do the CreateProc() call... */
    proc=CreateProc(... /* whatever your call is like */ ...);
    . . .
```
For those of you programming in assembly language:


```c
    ***********************************************************************
    * Check to see if we are running in V37 ROM or better.  If so, we want
    * to call CacheClearU() to make sure we are safe on future hardware
    * such as the 68040.  This section of code assumes that a6 points at
    * ExecBase.  a0/a1/d0/d1 are trashed in CacheClearU()
    *
            cmpi.w  #37,LIB_VERSION(a6)    ; Check if exec is >= V37
            bcs.s   TooOld                 ; If less than V37, too old...
            jsr     _LVOCacheClearU(a6)    ; Clear the cache...
    TooOld:                                ; Exit gracefully.
    ***********************************************************************
```
Note that [CreateProc()](autodocs-2.0/dos-library-createproc.md) is not the only routine where CopyBack mode could
be a problem.  Any program code copied into memory for execution that is
not done via [LoadSeg()](autodocs-2.0/dos-library-loadseg.md) will need to call [CacheClearU()](autodocs-2.0/exec-library-cacheclearu.md).  Many input device
handlers have been known to allocate and copy the handler code into memory
and then exit back to the system.  These programs also need to have this
call in them.  The above code will work under older versions of the OS,
and will do the correct operations in Release 2 (and beyond).

---

## See Also

- [CacheClearU — exec.library](../autodocs/exec.library.md#cacheclearu)
- [CachePostDMA — exec.library](../autodocs/exec.library.md#cachepostdma)
- [CachePreDMA — exec.library](../autodocs/exec.library.md#cachepredma)
- [LoadSeg — dos.library](../autodocs/dos.library.md#loadseg)
