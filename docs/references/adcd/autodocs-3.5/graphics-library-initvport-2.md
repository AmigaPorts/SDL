---
title: graphics.library/InitVPort
manual: autodocs-3.5
chapter: autodocs-3.5
section: graphics-library-initvport-2
functions: [MakeVPort]
libraries: [graphics.library]
---

# graphics.library/InitVPort

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME   
	InitVPort - Initialize [ViewPort](autodocs-3.5/include-graphics-view-h.md) structure.

   SYNOPSIS
	InitVPort( vp )
		   a0

	void InitViewPort( struct [ViewPort](autodocs-3.5/include-graphics-view-h.md) * );

   FUNCTION
	Initialize [ViewPort](autodocs-3.5/include-graphics-view-h.md) structure to default values.

   INPUTS
	vp - pointer to a [ViewPort](autodocs-3.5/include-graphics-view-h.md) structure

   RESULT
	[ViewPort](autodocs-3.5/include-graphics-view-h.md) structure set to all 0's. (1.0,1.1)

```c
       New field added SpritePriorities, initialized to 0x24 (1.2)
```
   BUGS

   SEE ALSO
	[MakeVPort()](autodocs-3.5/graphics-library-makevport-2.md) [graphics/view.h](autodocs-3.5/include-graphics-view-h.md)

---

## See Also

- [MakeVPort — graphics.library](../autodocs/graphics.library.md#makevport)
