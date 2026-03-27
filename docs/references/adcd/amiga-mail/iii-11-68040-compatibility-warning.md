---
title: III-11: 68040 Compatibility Warning
manual: amiga-mail
chapter: amiga-mail
section: iii-11-68040-compatibility-warning
functions: [CacheClearU, CachePostDMA, CachePreDMA, LoadSeg, SetFunction]
libraries: [dos.library, exec.library]
---

# III-11: 68040 Compatibility Warning

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

by Michael Sinz



    editor's note: the new exec.library routines referred to in this
    article are part of the 2.04 OS release.
Now that Motorola's 68040ä CPU is available, it will not be long before it
appears in Amiga-based products.  In fact, many Amiga magazines already
have ads for 3rd party 68040 CPU cards.

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
the Exec function CachePreDMA().  If a DMA device is about to write to
memory, it should call CachePreDMA() before the write, do the DMA write,
and then call CachePostDMA(), which  makes sure that the CPU uses the data
just written to memory.

An added advantage of using the CachePreDMA() and CachePostDMA() functions
is that they give the OS the chance to tell the DMA device that the
physical addresses and memory sizes are not the same.  This will make it
possible in the future to add features such as virtual memory.  See the
Autodocs for more information on these calls (the Autodocs have been
included in this article). The other major compatibility problem with the
68040's CopyBack mode is with fetching CPU instructions.  CPU instructions
have to be loaded into memory so the CPU can copy them into its
instruction cache.  Normally, instructions that will beexecuted are
written to memory by the CPU (i.e. loading a program from disk).  In
CopyBack mode, anything the CPU writes to memory, including CPU
instructions, doesn't actually go into memory, it goes into the data
cache.  If instructions are not flushed out of the data cache to RAM, the
68040 will not be able to find them when it tries to copy them into the
instruction cache for execution.  It will instead find and attempt to
execute whatever garbage data happened to be left at that location in RAM.

To remedy this, any program that writes instructions to memory must flush
the data cache after writing.  The V37 Exec function CacheClearU() takes
care of this.  Release 2.0 of the Amiga OS correctly flushes the caches as
needed after it does the LoadSeg() of a program (LoadSeg() loads Amiga
executable programs into memory from disk).  Applications need to do the
same if they write code to memory.  One such example was the article
``Creating Multiple Processes with Re-entrant Code'' from the
November/December 1989 issue of Amiga Mail (Volume I).  For that example
to work with the 68040's CopyBack mode, it needs to flush the cache before
it asks the system to execute the code it wrote to memory (which may still
be in the cache).  It can do that by calling CacheClearU() before the call
to CreateProc().  In C that would be:

extern struct ExecBase *SysBase;




```c
    . . .

    /* If we are in 2.0, call CacheClearU() before CreateProc() */
    if (SysBase->LibNode.lib_Version >= 37) CacheClearU();

    /* Now do the CreateProc() call... */
    proc=CreateProc(... /* whatever your call is like */ ...);

    . . .
```
For those of you programming in assembly:


**************************************************************************
* Check to see if we are running in V37 ROM or better.  If so,
* we want to call CacheClearU() to make sure we are safe on future
* hardware such as the 68040.  This section of code assumes that
* a6 points at ExecBase.  a0/a1/d0/d1 are trashed in CacheClearU()
*
```c
            cmpi.w  #37,LIB_VERSION(a6)     ; Check if exec is >= V37
            bcs.s   TooOld                  ; If less than V37, too old...
            jsr     _LVOCacheClearU(a6)     ; Clear the cache...
```
TooOld:
*
**************************************************************************


Note that CreateProc() is not the only routine where CopyBack mode could
be a problem.  Any program that copies code into memory for execution that
is not done via LoadSeg() (for example, ``Using SetFunction() in a
Debugger'' from the March/April 1991 issue of Amiga Mail), you will need
to call CacheClearU().  Many input.device handlers have been known to
allocate and copy the handler code into memory and then exit back to the
system.  These programs also need to have this call in them.  The above
code will work under pre-2.0 versions of the OS, and will do the correct
operations in 2.04 (and beyond).

Heeding these compatibility guidelines will allow the system to enable
CopyBack mode, enhancing the performance of the Amiga considerably.
Ignoring these guidelines will prevent the Amiga from taking advantage of
CopyBack mode and possibly other advanced features of the 68040 (and
beyond).

 [CacheControl](amiga-mail/cachecontrol.md)      [CacheClearU](amiga-mail/cacheclearu.md)       [CachePreDMA](amiga-mail/cachepredma.md) 
 [CacheClearE](amiga-mail/cachecleare.md)       [CachePostDMA](amiga-mail/cachepostdma.md) 

---

## See Also

- [CacheClearU — exec.library](../autodocs/exec.library.md#cacheclearu)
- [CachePostDMA — exec.library](../autodocs/exec.library.md#cachepostdma)
- [CachePreDMA — exec.library](../autodocs/exec.library.md#cachepredma)
- [LoadSeg — dos.library](../autodocs/dos.library.md#loadseg)
- [SetFunction — exec.library](../autodocs/exec.library.md#setfunction)
