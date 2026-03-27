---
title: graphics.library/CINIT
manual: autodocs-3.5
chapter: autodocs-3.5
section: graphics-library-cinit-2
functions: [CEND, CINIT, CMOVE]
libraries: [graphics.library]
---

# graphics.library/CINIT

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	CINIT -- Initialize user copperlist to accept intermediate
		 user copper instructions.

   SYNOPSIS
 	cl = CINIT( ucl , n )

	cl = UCopperListInit( ucl , n )
			      a0    d0

	struct [CopList](autodocs-3.5/include-graphics-copper-h.md) *UCopperListInit( struct [UCopList](autodocs-3.5/include-graphics-copper-h.md) *, [UWORD](autodocs-3.5/include-exec-types-h.md) );

   FUNCTION
	Allocates and/or initialize copperlist structures/buffers
	internal to a [UCopList](autodocs-3.5/include-graphics-copper-h.md) structure.

	This is a macro that calls UCopListInit. You must pass a
	(non-initialized) [UCopList](autodocs-3.5/include-graphics-copper-h.md) to CINIT (CINIT will NOT allocate
	a new [UCopList](autodocs-3.5/include-graphics-copper-h.md) if ucl==0 ). If (ucl != 0) it will initialize the
	intermediate data buffers internal to a [UCopList](autodocs-3.5/include-graphics-copper-h.md).

	The maximum number of intermediate copper list instructions
	that these internal [CopList](autodocs-3.5/include-graphics-copper-h.md) data buffers contain is specified
	as the parameter n.

   INPUTS
	ucl - pointer to [UCopList](autodocs-3.5/include-graphics-copper-h.md) structure
	n - number of instructions buffer must be able to hold

   RESULTS
	cl- a pointer to a buffer which will accept n intermediate copper
	    instructions.

	NOTE: this is NOT a [UCopList](autodocs-3.5/include-graphics-copper-h.md) pointer, rather a pointer to the
	      UCopList's->FirstCopList sub-structure.

   BUGS
	CINIT will not actually allocate a new [UCopList](autodocs-3.5/include-graphics-copper-h.md) if ucl==0.
	Instead you must allocate a block MEMF_PUBLIC|MEMF_CLEAR, the
	sizeof(struct UCopList) and pass it to this function.

	The system's [FreeVPortCopLists](autodocs-3.5/graphics-library-freevportcoplists-2.md) function will take care of
	deallocating it if they are called.

	Prior to release V36 the  CINIT macro had { } braces surrounding
	the definition, preventing the proper return of the result value.
	These braces have been removed for the V36 include definitions.

   SEE ALSO
 	CINIT() CMOVE() CEND() [graphics/copper.h](autodocs-3.5/include-graphics-copper-h.md)

---

## See Also

- [CEND — graphics.library](../autodocs/graphics.library.md#cend)
- [CINIT — graphics.library](../autodocs/graphics.library.md#cinit)
- [CMOVE — graphics.library](../autodocs/graphics.library.md#cmove)
