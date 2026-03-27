---
title: graphics.library/OwnBlitter
manual: autodocs-3.5
chapter: autodocs-3.5
section: graphics-library-ownblitter-2
functions: [DisownBlitter, OwnBlitter, WaitBlit]
libraries: [graphics.library]
---

# graphics.library/OwnBlitter

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME

       OwnBlitter -- get the blitter for private usage
   SYNOPSIS

```c
       OwnBlitter()
```
	void OwnBlitter( void );

   FUNCTION
	If blitter is available return immediately with the blitter
	locked for your exclusive use. If the blitter is not available
	put task to sleep. It will be awakened as soon as the blitter
	is available. When the task first owns the blitter the blitter
	may still be finishing up a blit for the previous owner. You
	must do a [WaitBlit](autodocs-3.5/graphics-library-waitblit-2.md) before actually using the blitter registers.

	Calls to OwnBlitter() do not nest. If a task that owns the
	blitter calls OwnBlitter() again, a lockup will result.
	(Same situation if the task calls a system function
	that tries to own the blitter).

   INPUTS
	NONE

   RETURNS
	NONE

   SEE ALSO
	[DisownBlitter()](autodocs-3.5/graphics-library-disownblitter-2.md) [WaitBlit()](autodocs-3.5/graphics-library-waitblit-2.md)

---

## See Also

- [DisownBlitter — graphics.library](../autodocs/graphics.library.md#disownblitter)
- [OwnBlitter — graphics.library](../autodocs/graphics.library.md#ownblitter)
- [WaitBlit — graphics.library](../autodocs/graphics.library.md#waitblit)
