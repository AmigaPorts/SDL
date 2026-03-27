---
title: exec.library/CacheControl
manual: autodocs-2.0
chapter: autodocs-2.0
section: exec-library-cachecontrol
functions: []
libraries: []
---

# exec.library/CacheControl

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

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

    As a side effect, this function clears all caches.
SEE ALSO

```c
    exec/execbase.i, [CacheClearU](autodocs-2.0/exec-library-cacheclearu.md), [CacheClearE](autodocs-2.0/exec-library-cachecleare.md)
```
