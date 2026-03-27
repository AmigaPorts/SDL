---
title: 1 / General Development Guidelines / 68010/020/030/040 Compatibility
manual: libraries
chapter: libraries
section: 1-general-development-guidelines-68010-020-030-040
functions: [CacheClearU, GetCC]
libraries: [exec.library]
---

# 1 / General Development Guidelines / 68010/020/030/040 Compatibility

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Special care must be taken to be compatible with the entire family of
68000 processors:

  * Do not use the upper 8 bits of a pointer for storing unrelated

    information.  The 68020, 68030, and 68040 use all 32 bits for
    addressing.
  * Do not use signed variables or signed math for addresses.

  * Do not use software delay loops, and do not make assumptions about

    the order in which asynchronous tasks will finish.
  * The stack frame used for exceptions is different on each member of

    the 68000 family.  The type identification in the frame must be
    checked! In addition, the interrupt autovectors may reside in a
    different location on processors with a VBR register.
  * Do not use the MOVE SR,<dest> instruction!  This 68000 instruction

```c
    acts differently on other members of the 68000 family.  If you want
    to get a copy of the processor condition codes, use the Exec library
    [GetCC()](libraries/21-processor-and-cache-control-condition-code-register.md) function.
```
  * Do not use the CLR instruction on a hardware register which is

    triggered by Write access.  The 68020 CLR instruction does a single
    Write access.  The 68000 CLR instruction does a Read access first,
    then a Write access.  This can cause a hardware register to be
    triggered twice.  Use MOVE.x #0, <address> instead.
  * Self-modifying code is strongly discouraged.  All 68000 family

```c
    processors have a [pre-fetch](libraries/21-processor-and-cache-control-cache-functions.md) feature.  This means the CPU loads
    instructions ahead of the current program counter.  Hence, if your
    code modifies or decrypts itself just ahead of the program counter,
    the pre-fetched instructions may not match the modified instructions.
    The more advanced processors prefetch more words.  If self-modifying
    code must be used, flushing the cache is the safest way to prevent
    troubles.
```
  * The 68020, 68030 and 68040 processors all have instruction caches.

```c
    These caches store recently used instructions, but do not monitor
    writes.  After modifying or directly loading instructions, the cache
    must be flushed.  See the Exec library [CacheClearU()](autodocs-2.0/exec-library-cacheclearu.md) Autodoc for more
    details.  If your code takes over the machine, flushing the cache
    will be trickier.  You can account for the current processors, and
    hope the same techniques will work in the future:

        CACRF_ClearI  EQU     $0008     ;Bit for clear instruction cache
        ;
        ;Supervisor mode only. Use this only if you have taken over
        ;the machine.  Read and store the ExecBase processor AttnFlags
        ;flags at boot time, call this code only if the "68020 or
        ; better" bit was set.
        ;
        ClearICache:  dc.w    $4E7A,$0002  ;MOVEC CACR,D0
                      tst.w   d0           ;movec does not affect CC's
                      bmi.s   cic_040      ;A 68040 with enabled cache!
                      ori.w   #CACRF_ClearI,d0
                      dc.w    $4E7B,$0002  ;MOVEC D0,CACR
                      bra.s   cic_exit
        cic_040:      dc.w    $f4b8        ;CPUSHA (IC)
        cic_exit:
```

---

## See Also

- [CacheClearU — exec.library](../autodocs/exec.library.md#cacheclearu)
- [GetCC — exec.library](../autodocs/exec.library.md#getcc)
