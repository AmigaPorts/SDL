---
title: CacheControl
manual: amiga-mail
chapter: amiga-mail
section: cachecontrol
functions: []
libraries: []
---

# CacheControl

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

exec.library/CacheControl                        exec.library/CacheControl

NAME

    CacheControl - Instruction & data cache control
SYNOPSIS

```c
    oldBits = CacheControl(cacheBits,cacheMask)
    D0                     D0        D1

    ULONG CacheControl(ULONG,ULONG);
```
FUNCTION

    This function provides global control of any instruction or data
    caches that may be connected to the system.  All settings are
    global -- per task control is not provided.

    The action taken by this function will depend on the type of
    CPU installed.  This function may be patched to support external
    caches, or different cache architectures.  In all cases the function
    will attempt to best emulate the provided settings.  Use of this
    function may save state specific to the caches involved.

    The list of supported settings is provided in the exec/execbase.i
    include file.  The bits currently defined map directly to the Motorola
    68030 CPU CACR register.  Alternate cache solutions may patch into
    the Exec cache functions.  Where possible, bits will be interpreted to
    have the same meaning on the installed cache.
INPUTS

    cacheBits - new values for the bits specified in cacheMask.

    cacheMask - a mask with ones for all bits to be changed.
RESULT

    oldBits   - the complete prior values for all settings.
NOTE
```c
    As a side effect, this function clears all caches.

    Selected bit definitions for Cache manipulation calls from
    <exec/execbase.i>

    BITDEF  CACR,EnableI,0          ;Enable instruction cache
    BITDEF  CACR,FreezeI,1          ;Freeze instruction cache
    BITDEF  CACR,ClearI,3           ;Clear instruction cache
    BITDEF  CACR,IBE,4              ;Instruction burst enable
    BITDEF  CACR,EnableD,8          ;68030 Enable data cache
    BITDEF  CACR,FreezeD,9          ;68030 Freeze data cache
    BITDEF  CACR,ClearD,11          ;68030 Clear data cache
    BITDEF  CACR,DBE,12             ;68030 Data burst enable
    BITDEF  CACR,WriteAllocate,13   ;68030 Write-Allocate mode (must
                                    ;always be set)
    BITDEF  CACR,EnableE,30
```
*
*   With this bit set, the external cache states then match the internal
*   cache states.  That is, if the internal data cache is turned on,
*   the external data cache is turned on.  Same for instruction caches.
*   If the external cache only exists as a single unified cache,
*   this will turn on if the data cache is on.  (This is done for
*   compatibility reasons)  With this bit clear, the external caches
*   are turned off.



```c
    BITDEF  CACR,CopyBack,31    ;Master enable for copyback caches


    BITDEF  DMA,Continue,1      ;Continuation flag for CachePreDMA
    BITDEF  DMA,NoModify,2      ;Set if DMA does not update memory
```
SEE ALSO

    exec/execbase.i, CacheClearU, CacheClearE
