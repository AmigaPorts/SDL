---
title: layers.library/EndUpdate
manual: autodocs-3.5
chapter: autodocs-3.5
section: layers-library-endupdate-2
functions: [BeginUpdate]
libraries: [layers.library]
---

# layers.library/EndUpdate

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	EndUpdate -- remove damage list and restore state of layer to normal.

    SYNOPSIS
	EndUpdate( l, flag )
	           a0  d0

	void EndUpdate( struct [Layer](autodocs-3.5/include-graphics-clip-h.md) *, UWORD);

    FUNCTION
	After the programmer has redrawn his picture he calls this
	routine to restore the ClipRects to point to his standard
	layer tiling. The layer is then unlocked for access by the
	layer library.

	Note: use flag = FALSE if you are only making a partial update.
	    You may use the other region functions (graphics functions such as
	    [OrRectRegion](autodocs-3.5/graphics-library-orrectregion-2.md), [AndRectRegion](autodocs-3.5/graphics-library-andrectregion-2.md), and [XorRectRegion](autodocs-3.5/graphics-library-xorrectregion-2.md) ) to clip adjust
	    the DamageList to reflect a partial update.

    INPUTS
	l - pointer to a layer
	flag - use TRUE if update was completed. The damage list is cleared.
	       use FALSE if update not complete. The damage list is retained.


    EXAMPLE
	-- begin update for first part of two-part refresh --
	BeginUpdate(my_layer);

	-- do some refresh, but not all --
	my_partial_refresh_routine(my_layer);

	-- end update, false (not completely done refreshing yet) --
	EndUpdate(my_layer, FALSE);

	-- begin update for last part of refresh --
	BeginUpdate(my_layer);

	-- do rest of refresh --
	my_complete_refresh_routine(my_layer);

	-- end update, true (completely done refreshing now) --
	EndUpdate(my_layer, TRUE);

    BUGS

    SEE ALSO
	[BeginUpdate()](autodocs-3.5/layers-library-beginupdate-2.md), [graphics/layers.h](autodocs-3.5/include-graphics-layers-h.md), [graphics/clip.h](autodocs-3.5/include-graphics-clip-h.md)

---

## See Also

- [BeginUpdate — layers.library](../autodocs/layers.library.md#beginupdate)
