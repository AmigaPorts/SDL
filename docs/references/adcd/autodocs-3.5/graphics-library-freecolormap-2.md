---
title: graphics.library/FreeColorMap
manual: autodocs-3.5
chapter: autodocs-3.5
section: graphics-library-freecolormap-2
functions: [GetColorMap, SetRGB4]
libraries: [graphics.library]
---

# graphics.library/FreeColorMap

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
```c
       FreeColorMap -- Free the [ColorMap](autodocs-3.5/include-graphics-view-h.md) structure and return memory
```
						to free memory pool.

   SYNOPSIS

```c
       FreeColorMap( colormap )
                       a0
```
	void FreeColorMap(struct [ColorMap](autodocs-3.5/include-graphics-view-h.md) *);

   FUNCTION
	Return the memory to the free memory pool that was allocated
	with [GetColorMap](autodocs-3.5/graphics-library-getcolormap-2.md).

   INPUTS
	colormap - pointer to [ColorMap](autodocs-3.5/include-graphics-view-h.md) allocated with [GetColorMap](autodocs-3.5/graphics-library-getcolormap-2.md).

		  Passing a NULL pointer (meaning "do nothing") is
		  acceptable (V39).

   RESULT
	The space is made available for others to use.

   BUGS

   SEE ALSO

```c
       [SetRGB4()](autodocs-3.5/graphics-library-setrgb4-2.md) [GetColorMap()](autodocs-3.5/graphics-library-getcolormap-2.md) [graphics/view.h](autodocs-3.5/include-graphics-view-h.md)
```

---

## See Also

- [GetColorMap — graphics.library](../autodocs/graphics.library.md#getcolormap)
- [SetRGB4 — graphics.library](../autodocs/graphics.library.md#setrgb4)
