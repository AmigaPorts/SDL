---
title: graphics.library/AttemptLockLayerRom
manual: autodocs-3.5
chapter: autodocs-3.5
section: graphics-library-attemptlocklayerrom-2
functions: [LockLayerRom, UnlockLayerRom]
libraries: [graphics.library]
---

# graphics.library/AttemptLockLayerRom

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

                           *
   NAME
	AttemptLockLayerRom -- Attempt to [Lock](autodocs-3.5/dos-library-lock-2.md) [Layer](autodocs-3.5/include-graphics-clip-h.md) structure
					 by ROM(gfx lib) code

   SYNOPSIS
	gotit = AttemptLockLayerRom( layer )
	 d0			      a5

	[BOOL](autodocs-3.5/include-exec-types-h.md) AttempLockLayerRom( struct [Layer](autodocs-3.5/include-graphics-clip-h.md) * );

   FUNCTION
	Query the current state of the lock on this [Layer](autodocs-3.5/include-graphics-clip-h.md). If it is
	already locked then return FALSE, could not lock. If the
	[Layer](autodocs-3.5/include-graphics-clip-h.md) was not locked then lock it and return TRUE.
	This call does not destroy any registers.
	This call nests so that callers in this chain will not lock
	themselves out.

   INPUTS
	layer - pointer to [Layer](autodocs-3.5/include-graphics-clip-h.md) structure

   RESULT
	gotit - TRUE or FALSE depending on whether the [Layer](autodocs-3.5/include-graphics-clip-h.md) was
		successfully locked by the caller.

   SEE ALSO
	[LockLayerRom()](autodocs-3.5/graphics-library-locklayerrom-2.md) [UnlockLayerRom()](autodocs-3.5/graphics-library-unlocklayerrom-2.md)

---

## See Also

- [LockLayerRom — graphics.library](../autodocs/graphics.library.md#locklayerrom)
- [UnlockLayerRom — graphics.library](../autodocs/graphics.library.md#unlocklayerrom)
