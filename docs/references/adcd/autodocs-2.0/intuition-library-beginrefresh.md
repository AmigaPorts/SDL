---
title: intuition.library/BeginRefresh
manual: autodocs-2.0
chapter: autodocs-2.0
section: intuition-library-beginrefresh
functions: [BeginRefresh, BeginUpdate, EndRefresh, InstallClipRegion, LockLayerInfo, OpenWindow, RefreshGList, RefreshGadgets]
libraries: [intuition.library, layers.library]
---

# intuition.library/BeginRefresh

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    BeginRefresh -- Sets up a window for optimized refreshing.
SYNOPSIS

```c
    BeginRefresh( [Window](autodocs-2.0/includes-intuition-intuition-h.md) )
                  A0

    VOID BeginRefresh( struct [Window](autodocs-2.0/includes-intuition-intuition-h.md) * );
```
FUNCTION

```c
    This routine sets up your window for optimized refreshing.

    Its role is to provide Intuition integrated access to the Layers
    library function [BeginUpdate()](autodocs-2.0/layers-library-beginupdate.md).  Its additional contribution is
    to be sure that locking protocols for layers are followed, by
    locking both layers of a WFLG_GIMMEZEROZERO window only after the
    parent [Layer_Info](autodocs-2.0/includes-graphics-layers-h.md) has been locked.  Also, the WFLG_WINDOWREFRESH
    flag is set in your window, for your information.

    The purpose of [BeginUpdate()](autodocs-2.0/layers-library-beginupdate.md), and hence BeginRefresh(), is to
    restrict rendering in a window (layer) to the region that needs
    refreshing after an operation such as window sizing or uncovering.
    This restriction to the "damage region" persists until you call
    [EndRefresh()](autodocs-2.0/intuition-library-endrefresh.md).

    For instance, if you have a WFLG_SIMPLE_REFRESH window which is
    partially concealed and the user brings it to the front, you can
    receive an IDCMP_REFRESHWINDOW message asking you to refresh your
    display.  If you call BeginRefresh() before doing any of the
    rendering, then the layer that underlies your window will be arranged
    so that the only rendering that will actually take place will be that
    which goes to the newly-revealed areas.  This is very performance-
    efficient, and visually attractive.

    After you have performed your refresh of the display, you should call
    [EndRefresh()](autodocs-2.0/intuition-library-endrefresh.md) to reset the state of the layer and the window.  Then you
    may proceed with rendering to the entire window as usual.

    You learn that your window needs refreshing by receiving either a
    message of class IDCMP_REFRESHWINDOW through the IDCMP, or an input
    event of class IECLASS_REFRESHWINDOW through the Console device.
    Whenever you are told that your window needs refreshing, you should
    call BeginRefresh() and [EndRefresh()](autodocs-2.0/intuition-library-endrefresh.md) to clear the refresh-needed
    state, even if you don't plan on doing any rendering.  You may relieve
    yourself of even this burden by setting the WFLG_NOCAREREFRESH flag
    when opening your window.

    WARNING: You should only perform graphics refreshing operations
    during the period between calling BeginRefresh() and [EndRefresh()](autodocs-2.0/intuition-library-endrefresh.md).
    In particular, do not call [RefreshGadgets()](autodocs-2.0/intuition-library-refreshgadgets.md) or [RefreshGList()](autodocs-2.0/intuition-library-refreshglist.md), since
    the locking protocol internal to Intuition runs the risk of creating
    a deadlock.  Note that Intuition refreshes the gadgets (through
    the damage region) before it sends the IDCMP_REFRESHWINDOW message.

    ANOTHER WARNING: The concept of multiple refresh passes using
    EndRefresh( w, FALSE ) is not completely sound without further
    protection.  The reason is that between two sessions, more
    damage can occur to your window.  Your final EndRefresh( w, TRUE )
    will dispose of all damage, including the new, and your
    initial refreshing pass will never get the chance to refresh
    the new damage.

    To avoid this, you must protect your session using [LockLayerInfo()](autodocs-2.0/layers-library-locklayerinfo.md)
    which will prevent Intuition from performing window operations
    or anything else which might cause further damage from occurring.
    Again, while holding the LayerInfo lock make no Intuition
    function calls dealing with gadgets; just render.

    You can, however, call [InstallClipRegion()](autodocs-2.0/layers-library-installclipregion.md) for the different
    refresh passes, if you have two clip regions.

    SIMILAR WARNING: Your program and Intuition "share" your window
    layer's DamageList.  BeginRefresh() helps arbitrate this
    sharing, but the lower-level function [layers.library/BeginUpdate()](autodocs-2.0/layers-library-beginupdate.md)
    does not.  It isn't really supported to use [BeginUpdate()](autodocs-2.0/layers-library-beginupdate.md) on
    a window's layer, but if you do--for whatever reason--it is
    critical that you first acquire the LayerInfo lock as in
    the above example: even if you only have one pass of refresh
    rendering to do.  Otherwise, the refreshing of your window's
    borders and gadgets can be incomplete, and the problem might
    occur only under certain conditions of task priority and
    system load.
```
EXAMPLE


```c
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
        EndRefresh( window, TRUE );         /* and dispose damage list */

        /* restore and unlock */
        InstallClipRegion( window->WLayer, origclip );
        UnlockLayerInfo( &window->WScreen->LayerInfo );
        break;
    ...
    }
```
INPUTS

```c
    [Window](autodocs-2.0/includes-intuition-intuition-h.md) = pointer to the window structure which needs refreshing
```
RESULT

    None
BUGS

```c
    This function should check the return code of
    [layers.library/BeginUpdate()](autodocs-2.0/layers-library-beginupdate.md), and abort if that function fails.
```
SEE ALSO
   [EndRefresh()](autodocs-2.0/intuition-library-endrefresh.md), [layers.library/BeginUpdate()](autodocs-2.0/layers-library-beginupdate.md), [OpenWindow()](autodocs-2.0/intuition-library-openwindow.md)

```c
    [layer.library/InstallClipRegion()](autodocs-2.0/layers-library-installclipregion.md), [graphics.library/LockLayerInfo()](autodocs-2.0/layers-library-locklayerinfo.md)
    The "Windows" chapter of the Intuition Reference Manual
```

---

## See Also

- [BeginRefresh — intuition.library](../autodocs/intuition.library.md#beginrefresh)
- [BeginUpdate — layers.library](../autodocs/layers.library.md#beginupdate)
- [EndRefresh — intuition.library](../autodocs/intuition.library.md#endrefresh)
- [InstallClipRegion — layers.library](../autodocs/layers.library.md#installclipregion)
- [LockLayerInfo — layers.library](../autodocs/layers.library.md#locklayerinfo)
- [OpenWindow — intuition.library](../autodocs/intuition.library.md#openwindow)
- [RefreshGList — intuition.library](../autodocs/intuition.library.md#refreshglist)
- [RefreshGadgets — intuition.library](../autodocs/intuition.library.md#refreshgadgets)
