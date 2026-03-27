---
title: graphics.library/FreeVPortCopLists
manual: autodocs-3.5
chapter: autodocs-3.5
section: graphics-library-freevportcoplists-2
functions: [FreeMem]
libraries: [exec.library]
---

# graphics.library/FreeVPortCopLists

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME

       FreeVPortCopLists -- deallocate all intermediate copper lists and
       their headers from a viewport
   SYNOPSIS

```c
       FreeVPortCopLists(vp)
                         a0
```
	void FreeVPortCopLists(struct [ViewPort](autodocs-3.5/include-graphics-view-h.md) *);

   FUNCTION

```c
       Search display, color, sprite, and user copper
       lists and call [FreeMem()](autodocs-3.5/exec-library-freemem-2.md) to deallocate them from memory
```
   INPUTS

```c
       vp - pointer to [ViewPort](autodocs-3.5/include-graphics-view-h.md) structure
```
   RESULTS
       The memory allocated to the various copper lists will be returned
	to the system's free memory pool, and the following fields in
	the viewport structure will be set to NULL:

		DspIns, Sprins, ClrIns, UCopIns

   BUGS

       none known
   SEE ALSO
	[graphics/view.h](autodocs-3.5/include-graphics-view-h.md)

---

## See Also

- [FreeMem — exec.library](../autodocs/exec.library.md#freemem)
