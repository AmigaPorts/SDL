---
title: intuition.library/BeginRefresh
manual: autodocs-3.5
chapter: autodocs-3.5
section: intuition-library-beginrefresh-2
functions: [BeginRefresh, BeginUpdate, DrawBorder, DrawImage, EndRefresh, InstallClipRegion, LockIBase, LockLayerInfo, OpenWindow, PrintIText, RefreshGList, RefreshGadgets, RefreshWindowFrame, SetPointer]
libraries: [intuition.library, layers.library]
---

# intuition.library/BeginRefresh

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	BeginRefresh -- Sets up a window for optimized refreshing.

    SYNOPSIS
	BeginRefresh( [Window](autodocs-3.5/include-intuition-intuition-h.md) )
		      A0

	VOID BeginRefresh( struct [Window](autodocs-3.5/include-intuition-intuition-h.md) * );

    FUNCTION
	This routine sets up your window for optimized refreshing.

	Its role is to provide Intuition integrated access to the Layers
	library function [BeginUpdate()](autodocs-3.5/layers-library-beginupdate-2.md).  Its additional contribution is
	to be sure that locking protocols for layers are followed, by
	locking both layers of a WFLG_GIMMEZEROZERO window only after the
	parent [Layer_Info](autodocs-3.5/include-graphics-layers-h.md) has been locked.  Also, the WFLG_WINDOWREFRESH
	flag is set in your window, for your information.

	The purpose of [BeginUpdate()](autodocs-3.5/layers-library-beginupdate-2.md), and hence BeginRefresh(), is to
	restrict rendering in a window (layer) to the region that needs
	refreshing after an operation such as window sizing or uncovering.
	This restriction to the "damage region" persists until you call
	[EndRefresh()](autodocs-3.5/intuition-library-endrefresh-2.md).

	For instance, if you have a WFLG_SIMPLE_REFRESH window which is
	partially concealed and the user brings it to the front, you can
	receive an IDCMP_REFRESHWINDOW message asking you to refresh your
	display.  If you call BeginRefresh() before doing any of the
	rendering, then the layer that underlies your window will be arranged
	so that the only rendering that will actually take place will be that
	which goes to the newly-revealed areas.  This is very performance-
	efficient, and visually attractive.

	After you have performed your refresh of the display, you should call
	[EndRefresh()](autodocs-3.5/intuition-library-endrefresh-2.md) to reset the state of the layer and the window.  Then you
	may proceed with rendering to the entire window as usual.

	You learn that your window needs refreshing by receiving either a
	message of class IDCMP_REFRESHWINDOW through the IDCMP, or an input
	event of class IECLASS_REFRESHWINDOW through the Console device.
	Whenever you are told that your window needs refreshing, you should
	call BeginRefresh() and [EndRefresh()](autodocs-3.5/intuition-library-endrefresh-2.md) to clear the refresh-needed
	state, even if you don't plan on doing any rendering.  You may relieve
	yourself of even this burden by setting the WFLG_NOCAREREFRESH flag
	when opening your window.

    NOTES
	WARNING: You should only perform simple graphics refreshing
	operations between BeginRefresh() and [EndRefresh()](autodocs-3.5/intuition-library-endrefresh-2.md).  These include
	any graphics.library drawing functions or the simple Intuition
	rendering functions (DrawImage(), [PrintIText()](autodocs-3.5/intuition-library-printitext-2.md), [DrawBorder()](autodocs-3.5/intuition-library-drawborder-2.md), and
	so on).  In particular, do not call [RefreshGadgets()](autodocs-3.5/intuition-library-refreshgadgets-2.md), [RefreshGList()](autodocs-3.5/intuition-library-refreshglist-2.md),
	[RefreshWindowFrame()](autodocs-3.5/intuition-library-refreshwindowframe-2.md), etc., since any of the complex Intuition
	functions run the risk of creating a deadlock.  Also avoid any
	other high-level calls in Intuition or ones that might invoke
	Intuition.  This means no calling [SetPointer()](autodocs-3.5/intuition-library-setpointer-2.md), no calling
	[LockIBase()](autodocs-3.5/intuition-library-lockibase-2.md), no dos.library functions (since an EasyRequest()
	might result), etc.  Keep it simple.

	By the time the application receives its IDCMP_REFRESHWINDWOW
	message, Intuition has already repaired any damaged regions
	of the window border or the gadgets in the window, so attempts
	to redraw gadgets or borders are as unnecessary as they are
	dangerous.

	ANOTHER WARNING: The concept of multiple refresh passes using
	EndRefresh( w, FALSE ) is not completely sound without further
	protection.  The reason is that between two sessions, more
	damage can occur to your window.  Your final EndRefresh( w, TRUE )
	will dispose of all damage, including the new, and your
	initial refreshing pass will never get the chance to refresh
	the new damage.

	To avoid this, you must protect your session using [LockLayerInfo()](autodocs-3.5/layers-library-locklayerinfo-2.md)
	which will prevent Intuition from performing window operations
	or anything else which might cause further damage from occurring.
	Again, while holding the LayerInfo lock make no Intuition
	function calls dealing with gadgets; just render.

	You can, however, call [InstallClipRegion()](autodocs-3.5/layers-library-installclipregion-2.md) for the different
	refresh passes, if you have two clip regions.

	SIMILAR WARNING: Your program and Intuition "share" your window
	layer's DamageList.  BeginRefresh() helps arbitrate this
	sharing, but the lower-level function [layers.library/BeginUpdate()](autodocs-3.5/layers-library-beginupdate-2.md)
	does not.  It isn't really supported to use [BeginUpdate()](autodocs-3.5/layers-library-beginupdate-2.md) on
	a window's layer, but if you do--for whatever reason--it is
	critical that you first acquire the LayerInfo lock as in
	the above example: even if you only have one pass of refresh
	rendering to do.  Otherwise, the refreshing of your window's
	borders and gadgets can be incomplete, and the problem might
	occur only under certain conditions of task priority and
	system load.

    EXAMPLE
	Code fragment for "two pass" window refreshing, in response
	to an IDCMP_REFRESHWINDOW message:
	switch ( imsg->Class )
	{
	...
	case IDCMP_REFRESHWINDOW:
	    window = imsg->IDCMPWindow;

	    /* this lock only needed for "two-pass" refreshing */
	    LockLayerInfo( &window->WScreen->LayerInfo );

	    /* refresh pass for region 1 */
	    origclip = InstallClipRegion( window->WLayer, region1 );
	    BeginRefresh( window );
	    myRefreshRegion1( window );
	    EndRefresh( window, FALSE );

	    /* refresh pass for region 2 */
	    InstallClipRegion( window->WLayer, region2 );
	    BeginRefresh( window );
	    myRefreshRegion2( window );
	    EndRefresh( window, TRUE );		/* and dispose damage list */

	    /* restore and unlock */
	    InstallClipRegion( window->WLayer, origclip );
	    UnlockLayerInfo( &window->WScreen->LayerInfo );
	    break;
	...
	}


    INPUTS
	[Window](autodocs-3.5/include-intuition-intuition-h.md) = pointer to the window structure which needs refreshing

    RESULT
	None

    BUGS
	This function should check the return code of
	[layers.library/BeginUpdate()](autodocs-3.5/layers-library-beginupdate-2.md), and abort if that function fails.

```c
    SEE ALSO
       [EndRefresh()](autodocs-3.5/intuition-library-endrefresh-2.md), [layers.library/BeginUpdate()](autodocs-3.5/layers-library-beginupdate-2.md), [OpenWindow()](autodocs-3.5/intuition-library-openwindow-2.md)
```
	[layer.library/InstallClipRegion()](autodocs-3.5/layers-library-installclipregion-2.md), [layers.library/LockLayerInfo()](autodocs-3.5/layers-library-locklayerinfo-2.md)
	The "Windows" chapter of the Intuition Reference Manual

---

## See Also

- [BeginRefresh — intuition.library](../autodocs/intuition.library.md#beginrefresh)
- [BeginUpdate — layers.library](../autodocs/layers.library.md#beginupdate)
- [DrawBorder — intuition.library](../autodocs/intuition.library.md#drawborder)
- [DrawImage — intuition.library](../autodocs/intuition.library.md#drawimage)
- [EndRefresh — intuition.library](../autodocs/intuition.library.md#endrefresh)
- [InstallClipRegion — layers.library](../autodocs/layers.library.md#installclipregion)
- [LockIBase — intuition.library](../autodocs/intuition.library.md#lockibase)
- [LockLayerInfo — layers.library](../autodocs/layers.library.md#locklayerinfo)
- [OpenWindow — intuition.library](../autodocs/intuition.library.md#openwindow)
- [PrintIText — intuition.library](../autodocs/intuition.library.md#printitext)
- [RefreshGList — intuition.library](../autodocs/intuition.library.md#refreshglist)
- [RefreshGadgets — intuition.library](../autodocs/intuition.library.md#refreshgadgets)
- [RefreshWindowFrame — intuition.library](../autodocs/intuition.library.md#refreshwindowframe)
- [SetPointer — intuition.library](../autodocs/intuition.library.md#setpointer)
