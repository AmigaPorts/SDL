---
title: exec.library/CacheControl
manual: autodocs-3.5
chapter: autodocs-3.5
section: exec-library-cachecontrol-2
functions: [CacheClearE, CacheClearU]
libraries: [exec.library]
---

# exec.library/CacheControl

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	CacheControl - Instruction & data cache control

   SYNOPSIS
	oldBits = CacheControl(cacheBits,cacheMask)
	D0                     D0        D1

	ULONG CacheControl(ULONG,ULONG);

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
	exec/execbase.i, [CacheClearU()](autodocs-3.5/exec-library-cacheclearu-2.md), [CacheClearE()](autodocs-3.5/exec-library-cachecleare-2.md)

---

## See Also

- [CacheClearE — exec.library](../autodocs/exec.library.md#cachecleare)
- [CacheClearU — exec.library](../autodocs/exec.library.md#cacheclearu)
